//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2000, 2003 - Matt Saettler (EDuke Enhancements)
Copyright (C) 2004, 2007 - EDuke32 developers
Copyright (C) 2009 - dimag0g

This file is part of eRampage port for Redneck Rampage series, derived from EDuke32

eRampage is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License version 2
as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
//-------------------------------------------------------------------------

//#include <conio.h>
#include <stdio.h>
#include <string.h>

#include "fx_man.h"
#include "music.h"
#include "duke3d.h"
#include "util_lib.h"
#include "osd.h"

#define LOUDESTVOLUME 150

int32_t backflag,g_numEnvSoundsPlaying,g_maxSoundPos = 0;

#define MUSIC_ID  -65536

static int32_t MusicIsWaveform = 0;
static char * MusicPtr = 0;
static int32_t MusicLen = 0;
static int32_t MusicVoice = -1;
static int32_t MusicPaused = 0;

/*
===================
=
= SoundStartup
=
===================
*/

void S_SoundStartup(void) {
    int32_t fxdevicetype;
    void * initdata = 0;

    if (ud.config.FXDevice >= 0)
        fxdevicetype = ASS_AutoDetect;
    else return;

#ifdef WIN32
    initdata = (void *) win_gethwnd();
#endif

    initprintf("Initializing sound...\n");

    if (FX_Init(fxdevicetype, ud.config.NumVoices, ud.config.NumChannels, ud.config.NumBits, ud.config.MixRate, initdata) != FX_Ok) {
        sprintf(tempbuf, "Sound startup error: %s", FX_ErrorString(FX_Error));
        G_GameExit(tempbuf);
    }

    FX_SetVolume(ud.config.FXVolume);
    FX_SetReverseStereo(ud.config.ReverseStereo);
    FX_SetCallBack(S_Callback);
}

/*
===================
=
= SoundShutdown
=
===================
*/

void S_SoundShutdown(void) {
    if (ud.config.FXDevice < 0)
        return;

    if (MusicVoice >= 0)
        S_MusicShutdown();

    if (FX_Shutdown() != FX_Ok) {
        Bsprintf(tempbuf, "S_SoundShutdown(): error: %s", FX_ErrorString(FX_Error));
        G_GameExit(tempbuf);
    }
}

/*
===================
=
= MusicStartup
=
===================
*/

void S_MusicStartup(void) {
    if (ud.config.MusicDevice < 0)
        return;

    initprintf("Initializing music...\n");

    if (MUSIC_Init(ud.config.MusicDevice, 0) == MUSIC_Ok || MUSIC_Init((ud.config.MusicDevice = 0), 0) == MUSIC_Ok) {
        MUSIC_SetVolume(ud.config.MusicVolume);
        return;
    }

    initprintf("S_MusicStartup(): failed initializing\n");
}

/*
===================
=
= MusicShutdown
=
===================
*/

void S_MusicShutdown(void) {
    if (ud.config.MusicDevice < 0)
        return;

    S_StopMusic();

    if (MUSIC_Shutdown() != MUSIC_Ok)
        Error(MUSIC_ErrorString(MUSIC_ErrorCode));
}

void S_PauseMusic(int32_t onf) {
    if (MusicPaused == onf || (MusicIsWaveform && MusicVoice < 0))
        return;

    MusicPaused = onf;

    if (MusicIsWaveform) {
        FX_PauseVoice(MusicVoice, onf);
        return;
    }

    if (onf)
        MUSIC_Pause();
    else
        MUSIC_Continue();
}

void S_MusicVolume(int32_t volume) {
    if (MusicIsWaveform && MusicVoice >= 0)
        FX_SetPan(MusicVoice, volume, volume, volume);

    MUSIC_SetVolume(volume);
}

void S_MenuSound(void) {
    static int32_t SoundNum=0;
    static const uint8_t menusnds[] = {
        LASERTRIP_EXPLODE,
        DUKE_GRUNT,
        DUKE_LAND_HURT,
        CHAINGUN_FIRE,
        SQUISHED,
        KICK_HIT,
        PISTOL_RICOCHET,
        PISTOL_BODYHIT,
        PISTOL_FIRE,
        SHOTGUN_FIRE,
        BOS1_WALK,
        RPG_EXPLODE,
        PIPEBOMB_BOUNCE,
        PIPEBOMB_EXPLODE,
        NITEVISION_ONOFF,
        RPG_SHOOT,
        SELECT_WEAPON
    };

    S_PlaySound(menusnds[SoundNum++ % (sizeof(menusnds)/sizeof(menusnds[0]))]);
}

int32_t S_PlayMusic(const char *fn, const int32_t sel) {
    char *ofn = (char *)fn, *testfn, *extension;
    int32_t fp;
    const char *alt = 0;

    if (ud.config.MusicToggle == 0) return 0;
    if (ud.config.MusicDevice < 0) return 0;

    if (MapInfo[sel].alt_musicfn != NULL)
        alt = fn = MapInfo[sel].alt_musicfn;

    testfn = (char *) Bmalloc(strlen(fn) + 5);
    strcpy(testfn, fn);
    extension = strrchr(testfn, '.');

    do {
        if (extension && !Bstrcasecmp(extension, ".mid")) {
            // we've been asked to load a .mid file, but first let's see
            // if there's an ogg with the same base name lying around
            strcpy(extension, ".ogg");
            fp = kopen4loadfrommod(testfn, 0);
            if (fp >= 0) {
                Bfree(testfn);
                break;
            }
        }

        Bfree(testfn);

        // just use what we've been given
        fp = kopen4loadfrommod((char *)fn, 0);

        if (alt && fp < 0)
            fp = kopen4loadfrommod(ofn, 0);
    } while (0);

    if (fp < 0) {
        OSD_Printf(OSD_ERROR "S_PlayMusic(): error: can't open '%s' for playback!\n",fn);
        return 0;
    }

    S_StopMusic();

    MusicLen = kfilelength(fp);
    MusicPtr = (char *) Bmalloc(MusicLen);

    if ((g_musicSize = kread(fp, (char *)MusicPtr, MusicLen)) != MusicLen) {
        OSD_Printf(OSD_ERROR "S_PlayMusic(): error: read %d bytes from '%s', expected %d\n",g_musicSize, fn, MusicLen);
        kclose(fp);
        g_musicSize = 0;
        return 0;
    }

    kclose(fp);

    if (!Bmemcmp(MusicPtr, "MThd", 4)) {
        MUSIC_PlaySong(MusicPtr, MUSIC_LoopSong);
        MusicIsWaveform = 0;
    } else {
        if ((MusicVoice = FX_PlayLoopedAuto(MusicPtr, MusicLen, 0, 0, 0, ud.config.MusicVolume,
                                            ud.config.MusicVolume, ud.config.MusicVolume,
                                            FX_MUSIC_PRIORITY, MUSIC_ID)) >= FX_Ok)
            MusicIsWaveform = 1;
    }
    return (alt != 0);
}

void S_StopMusic(void) {
    MusicPaused = 0;

    if (MusicIsWaveform && MusicVoice >= 0) {
        FX_StopSound(MusicVoice);
        MusicVoice = -1;
        MusicIsWaveform = 0;
    }

    MUSIC_StopSong();

    if (MusicPtr) {
        Bfree(MusicPtr);
        MusicPtr = NULL;
        g_musicSize = MusicLen = 0;
    }
}

// returns number of bytes read
int32_t S_LoadSound(uint32_t num) {
    int32_t   fp = -1, l;

    if ((int32_t)num > g_maxSoundPos || ud.config.SoundToggle == 0 || ud.config.FXDevice < 0) return 0;

    if (g_sounds[num].filename == NULL && g_sounds[num].filename1 == NULL) {
        OSD_Printf(OSD_ERROR "Sound (#%d) not defined!\n",num);
        return 0;
    }

    if (g_sounds[num].filename1) fp = kopen4loadfrommod(g_sounds[num].filename1,g_loadFromGroupOnly);
    if (fp == -1) fp = kopen4loadfrommod(g_sounds[num].filename,g_loadFromGroupOnly);
    if (fp == -1) {
        OSD_Printf(OSDTEXT_RED "Sound %s(#%d) not found!\n",g_sounds[num].filename,num);
        return 0;
    }

    g_sounds[num].soundsiz = l = kfilelength(fp);
    g_soundlocks[num] = 200;

    allocache((intptr_t *)&g_sounds[num].ptr, l, (char *)&g_soundlocks[num]);
    l = kread(fp, g_sounds[num].ptr , l);
    kclose(fp);

    return l;
}

int32_t S_PlaySound3D(int32_t num, int32_t i, const vec3_t *pos) {
    vec3_t *c;
    int32_t sndist, j = 0;
    int32_t cs;
    int32_t voice, sndang, ca, pitch;

    if (num > g_maxSoundPos ||
            ud.config.FXDevice < 0 ||
            ((g_sounds[num].m&8) && ud.lockout) ||
            ud.config.SoundToggle == 0 ||
            g_sounds[num].num >= MAXSOUNDINSTANCES ||
            FX_VoiceAvailable(g_sounds[num].pr) == 0 ||
            (g_player[myconnectindex].ps->timebeforeexit > 0 && g_player[myconnectindex].ps->timebeforeexit <= GAMETICSPERSEC*3) ||
            g_player[myconnectindex].ps->gm&MODE_MENU) return -1;

    if (g_sounds[num].m&128) {
        if (g_sounds[num].num < MAXSOUNDINSTANCES && i >= 0 && i < MAXSPRITES) {
            while (j < MAXSOUNDINSTANCES && g_sounds[num].SoundOwner[j].voice > 0)
                j++;

            if (j >= MAXSOUNDINSTANCES) {
                OSD_Printf(OSD_ERROR "%s %d: WTF?\n", __FILE__, __LINE__);
                return -1;
            }

            if ((voice = S_PlaySound(num)) >= FX_Ok) {
                g_sounds[num].SoundOwner[j].i = i;
                g_sounds[num].num++;
                return (g_sounds[num].SoundOwner[j].voice = voice);
            }

            return -1;
        }
        return -1;
    }

    // Duke talk
    if (g_sounds[num].m&4) {
        if ((g_netServer || ud.multimode > 1) && PN == APLAYER && sprite[i].yvel != screenpeek) { // other player sound
            if (!(ud.config.VoiceToggle&4))
                return -1;
        } else if (!(ud.config.VoiceToggle&1))
            return -1;

        // don't play if any Duke talk sounds are already playing
        for (j=g_maxSoundPos; j>=0; j--)
            if ((g_sounds[j].m&4) && g_sounds[j].num > 0)
                return -1;
    }

    c = (vec3_t *)&ud.camera;
    cs = ud.camerasect;
    ca = ud.cameraang;

    sndist = FindDistance3D((c->x-pos->x),(c->y-pos->y),(c->z-pos->z)>>4);

    if (i >= 0 && (g_sounds[num].m&16) == 0 && PN == MUSICANDSFX && SLT < 999 && (sector[SECT].lotag&0xff) < 9)
        sndist = divscale14(sndist,(SHT+1));

    sndist += g_sounds[num].vo;

    if (sndist < 0) sndist = 0;

    if (cs > -1 && sndist && PN != MUSICANDSFX && !cansee(c->x,c->y,c->z-(24<<8),cs,SX,SY,SZ-(24<<8),SECT))
        sndist += sndist>>5;

    pitch = (j = klabs(g_sounds[num].pe-g_sounds[num].ps)) ?
        (g_sounds[num].ps < g_sounds[num].pe ? g_sounds[num].ps : g_sounds[num].pe ) + rand()%j :
            g_sounds[num].ps;

    switch (num) {
    case PIPEBOMB_EXPLODE:
    case LASERTRIP_EXPLODE:
    case RPG_EXPLODE:
        if (sndist > (6144))
            sndist = 6144;
        if (g_player[screenpeek].ps->cursectnum > -1 && sector[g_player[screenpeek].ps->cursectnum].lotag == 2)
            pitch -= 1024;
        break;
    default:
        if (g_player[screenpeek].ps->cursectnum > -1 && sector[g_player[screenpeek].ps->cursectnum].lotag == 2 && (g_sounds[num].m&4) == 0)
            pitch = -768;
        break;
    }

    if (g_player[screenpeek].ps->sound_pitch) pitch += g_player[screenpeek].ps->sound_pitch;

    if (g_sounds[num].num > 0 && PN != MUSICANDSFX)
        S_StopEnvSound(num, i);

    if (PN == APLAYER && sprite[i].yvel == screenpeek)
        sndang = sndist = 0;
    else {
        sndang = 2048 + ca - getangle(c->x-pos->x,c->y-pos->y);
        sndang &= 2047;
    }

    if (g_sounds[num].ptr == 0) {
        if (S_LoadSound(num) == 0)
            return -1;
    } else if (g_soundlocks[num] < 200)
        g_soundlocks[num] = 200;
    else g_soundlocks[num]++;

    if (g_sounds[num].m&16) sndist = 0;

    if (sndist < ((255-LOUDESTVOLUME)<<6))
        sndist = ((255-LOUDESTVOLUME)<<6);

    j = 0;

    while (j < MAXSOUNDINSTANCES && g_sounds[num].SoundOwner[j].voice > 0)
        j++;

    if (j >= MAXSOUNDINSTANCES) {
        g_soundlocks[num]--;
        return -1;
    }

    if (g_sounds[num].m&1) {
        if (g_sounds[num].num > 0) return -1;

        voice = FX_PlayLoopedAuto(g_sounds[num].ptr, g_sounds[num].soundsiz, 0, -1,
                                  pitch,sndist>>6,sndist>>6,0,g_sounds[num].pr,(num * MAXSOUNDINSTANCES) + j);
    } else {
        voice = FX_PlayAuto3D(g_sounds[ num ].ptr, g_sounds[num].soundsiz, pitch,sndang>>4,sndist>>6, g_sounds[num].pr,
                              (num * MAXSOUNDINSTANCES) + j);
    }

    if (voice >= FX_Ok) {
        g_sounds[num].SoundOwner[j].i = i;
        g_sounds[num].num++;
        return (g_sounds[num].SoundOwner[j].voice = voice);
    }

    g_soundlocks[num]--;
    return -1;
}

int32_t S_PlaySound(int32_t num) {
    int32_t pitch,cx;
    int32_t voice;

    if (ud.config.FXDevice < 0) return -1;
    if (ud.config.SoundToggle==0) return -1;
    if (!(ud.config.VoiceToggle&1) && (g_sounds[num].m&4)) return -1;
    if ((g_sounds[num].m&8) && ud.lockout) return -1;
    if (FX_VoiceAvailable(g_sounds[num].pr) == 0) return -1;
    if (num > g_maxSoundPos || (g_sounds[num].filename == NULL && g_sounds[num].filename1 == NULL)) {
        OSD_Printf("WARNING: invalid sound #%d\n",num);
        return -1;
    }

    pitch = (cx = klabs(g_sounds[num].pe-g_sounds[num].ps)) ?
            (g_sounds[num].ps < g_sounds[num].pe ? g_sounds[num].ps :
         g_sounds[num].pe ) + rand()%cx : g_sounds[num].ps;

    if (g_sounds[num].ptr == 0) {
        if (S_LoadSound(num) == 0)
            return -1;
    } else if (g_soundlocks[num] < 200)
        g_soundlocks[num] = 200;
    else g_soundlocks[num]++;

    voice = (g_sounds[num].m&1) ?
            FX_PlayLoopedAuto(g_sounds[num].ptr, g_sounds[num].soundsiz, 0, -1,
                              pitch,LOUDESTVOLUME,LOUDESTVOLUME,LOUDESTVOLUME,g_sounds[num].soundsiz,num * MAXSOUNDINSTANCES) :
            FX_PlayAuto3D(g_sounds[ num ].ptr, g_sounds[num].soundsiz, pitch,0,255-LOUDESTVOLUME,g_sounds[num].pr, num * MAXSOUNDINSTANCES);

    if (voice < FX_Ok) {
        g_soundlocks[num]--;
        return -1;
    }

    return voice;
}

int32_t A_PlaySound(uint32_t num, int32_t i) {
    if ((int32_t)num > g_maxSoundPos) return -1;
    return i < 0 ? S_PlaySound(num) : S_PlaySound3D(num, i, (vec3_t *)&sprite[i]);
}

void S_StopSound(int32_t num) {
    if (num < 0 || num > g_maxSoundPos || g_sounds[num].num <= 0)
        return;

    {
        int32_t j=MAXSOUNDINSTANCES-1;

        for (; j>=0; j--)
            if (g_sounds[num].SoundOwner[j].voice)
                FX_StopSound(g_sounds[num].SoundOwner[j].voice);
    }
}

void S_StopEnvSound(int32_t num,int32_t i) {
    if (num < 0 || num > g_maxSoundPos || g_sounds[num].num <= 0)
        return;

    {
        int32_t j=MAXSOUNDINSTANCES-1;

        for (; j>=0; j--)
            if (g_sounds[num].SoundOwner[j].i == i && g_sounds[num].SoundOwner[j].voice)
                FX_StopSound(g_sounds[num].SoundOwner[j].voice);
    }
}

void S_Pan3D(void) {
    vec3_t *s, *c;
    int32_t sndist,sndang,ca,j,k,i,cs;

    g_numEnvSoundsPlaying = 0;

    if (ud.camerasprite == -1) {
        c = (vec3_t *)&ud.camera;
        cs = ud.camerasect;
        ca = ud.cameraang;
    } else {
        c = (vec3_t *)&sprite[ud.camerasprite];
        cs = sprite[ud.camerasprite].sectnum;
        ca = sprite[ud.camerasprite].ang;
    }

    j = g_maxSoundPos;

    do {
        for (k=MAXSOUNDINSTANCES-1; k>=0; k--) {
            i = g_sounds[j].SoundOwner[k].i;

            if (i < 0 || i >= MAXSPRITES || g_sounds[j].num == 0 || g_sounds[j].SoundOwner[k].voice < FX_Ok)
                continue;

            s = (vec3_t *)&sprite[i];

            if (PN == APLAYER && sprite[i].yvel == screenpeek)
                sndang = sndist = 0;
            else {
                sndang = 2048 + ca - getangle(c->x-s->x, c->y-s->y);
                sndang &= 2047;
                sndist = FindDistance3D(c->x-s->x, c->y-s->y, (c->z-s->z)>>4);
                if (i >= 0 && (g_sounds[j].m&16) == 0 && PN == MUSICANDSFX && SLT < 999 && (sector[SECT].lotag&0xff) < 9)
                    sndist = divscale14(sndist,(SHT+1));
            }

            sndist += g_sounds[j].vo;
            if (sndist < 0) sndist = 0;

            if (cs > -1 && sndist && PN != MUSICANDSFX && !cansee(c->x,c->y,c->z-(24<<8),cs,s->x,s->y,s->z-(24<<8),SECT))
                sndist += sndist>>5;

            if (PN == MUSICANDSFX && SLT < 999)
                g_numEnvSoundsPlaying++;

            switch (j) {
            case PIPEBOMB_EXPLODE:
            case LASERTRIP_EXPLODE:
            case RPG_EXPLODE:
                if (sndist > 6144)
                    sndist = 6144;
                break;
            }

            if (g_sounds[j].m&16) sndist = 0;

            if (sndist < ((255-LOUDESTVOLUME)<<6))
                sndist = ((255-LOUDESTVOLUME)<<6);

            FX_Pan3D(g_sounds[j].SoundOwner[k].voice, sndang>>4, sndist>>6);
        }
    } while (j--);
}

void S_Callback(uint32_t num) {
    if ((int32_t)num == MUSIC_ID)
        return;

    // negative index is RTS playback
    if ((int32_t)num < 0) {
        if (lumplockbyte[-(int32_t)num] >= 200)
            lumplockbyte[-(int32_t)num]--;
        return;
    }

    {
        int32_t j = num & (MAXSOUNDINSTANCES-1);
        num = (num - j) / MAXSOUNDINSTANCES;

        if (g_sounds[num].num > 0) {
            int32_t i = g_sounds[num].SoundOwner[j].i;

            // MUSICANDSFX uses temp_data[0] to control restarting the sound
            if (sprite[i].picnum == MUSICANDSFX && sector[sprite[i].sectnum].lotag < 3 && sprite[i].lotag < 999)
                ActorExtra[i].temp_data[0] = 0;

            g_sounds[num].SoundOwner[j].i = -1;
            g_sounds[num].SoundOwner[j].voice = 0;

            g_sounds[num].num--;
        }
    }
    g_soundlocks[num]--;
}

void S_ClearSoundLocks(void) {
    int32_t i;

    for (i=g_maxSoundPos; i >= 0 ; i--)
        if (g_soundlocks[i] >= 200)
            g_soundlocks[i] = 199;

    for (i=0; i<11; i++)
        if (lumplockbyte[i] >= 200)
            lumplockbyte[i] = 199;
}

int32_t A_CheckSoundPlaying(int32_t i, int32_t num) {
    if (num > g_maxSoundPos || num < 0) return 0;

    if (g_sounds[num].num > 0 && i >= 0) {
        int32_t j=MAXSOUNDINSTANCES-1;

        for (; j>=0; j--)
            if (g_sounds[num].SoundOwner[j].i == i)
                return 1;
    }

    return (i == -1) ? g_sounds[num].num : 0;
}

int32_t S_CheckSoundPlaying(int32_t i, int32_t num) {
    if (num > g_maxSoundPos || num < 0) return 0;
    return (i == -1) ? (g_soundlocks[num] >= 200) : g_sounds[num].num;
}
