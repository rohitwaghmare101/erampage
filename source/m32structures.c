//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment
Copyright (C) 2000, 2003 - Matt Saettler (EDuke Enhancements)
Copyright (C) 2004, 2007 - EDuke32 developers

This file is part of EDuke32

EDuke32 is free software; you can redistribute it and/or
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

// this is all the crap for accessing the game's structs through the CON VM
// I got a 3-4 fps gain by inlining these...

#include "compat.h"
#include "m32script.h"
#include "m32def.h"


// how: bitfield: 1=set? 2=vars? 4=use spriteext[].tspr? (otherwise use tsprite[])
#define ACCESS_SET 1
#define ACCESS_USEVARS 2
#define ACCESS_SPRITEEXT 4


static int32_t __fastcall X_AccessWall(int32_t how, int32_t lVar1, int32_t lLabelID, int32_t lVar2) {
    int32_t lValue;
    int32_t i = (how&ACCESS_USEVARS) ? Gv_GetVarX(lVar1) : lVar1;

    if (i<0 || i >= numwalls)
        goto badwall;

    if (how&ACCESS_SET) {
        if (WallLabels[lLabelID].flags & 1)
            goto readonly;

        lValue = (how&ACCESS_USEVARS) ? Gv_GetVarX(lVar2) : lVar2;

        asksave = 1;

        if (WallLabels[lLabelID].min != 0 || WallLabels[lLabelID].max != 0) {
            if (lValue < WallLabels[lLabelID].min)
                lValue = WallLabels[lLabelID].min;
            if (lValue > WallLabels[lLabelID].max)
                lValue = WallLabels[lLabelID].max;
        }

        switch (lLabelID) {
        case WALL_X:
            wall[i].x=lValue;
            break;
        case WALL_Y:
            wall[i].y=lValue;
            break;
        case WALL_POINT2:
            wall[i].point2=lValue;
            break;
        case WALL_NEXTWALL:
            wall[i].nextwall=lValue;
            break;
        case WALL_NEXTSECTOR:
            wall[i].nextsector=lValue;
            break;
        case WALL_CSTAT:
            wall[i].cstat = lValue&0x03ff;
            break;
        case WALL_PICNUM:
            wall[i].picnum=lValue;
            break;
        case WALL_OVERPICNUM:
            wall[i].overpicnum=lValue;
            break;
        case WALL_SHADE:
            wall[i].shade=lValue;
            break;
        case WALL_PAL:
            wall[i].pal=lValue;
            break;
        case WALL_XREPEAT:
            wall[i].xrepeat=lValue;
            break;
        case WALL_YREPEAT:
            wall[i].yrepeat=lValue;
            break;
        case WALL_XPANNING:
            wall[i].xpanning=lValue;
            break;
        case WALL_YPANNING:
            wall[i].ypanning=lValue;
            break;
        case WALL_LOTAG:
            wall[i].lotag=lValue;
            break;
        case WALL_HITAG:
            wall[i].hitag=lValue;
            break;
        case WALL_EXTRA:
            wall[i].extra=lValue;
            break;
        default:
            return -1;
        }

        return 0;
    } else {
        switch (lLabelID) {
        case WALL_X:
            lValue=wall[i].x;
            break;
        case WALL_Y:
            lValue=wall[i].y;
            break;
        case WALL_POINT2:
            lValue=wall[i].point2;
            break;
        case WALL_NEXTWALL:
            lValue=wall[i].nextwall;
            break;
        case WALL_NEXTSECTOR:
            lValue=wall[i].nextsector;
            break;
        case WALL_CSTAT:
            lValue=wall[i].cstat;
            break;
        case WALL_PICNUM:
            lValue=wall[i].picnum;
            break;
        case WALL_OVERPICNUM:
            lValue=wall[i].overpicnum;
            break;
        case WALL_SHADE:
            lValue=wall[i].shade;
            break;
        case WALL_PAL:
            lValue=wall[i].pal;
            break;
        case WALL_XREPEAT:
            lValue=wall[i].xrepeat;
            break;
        case WALL_YREPEAT:
            lValue=wall[i].yrepeat;
            break;
        case WALL_XPANNING:
            lValue=wall[i].xpanning;
            break;
        case WALL_YPANNING:
            lValue=wall[i].ypanning;
            break;
        case WALL_LOTAG:
            lValue=wall[i].lotag;
            break;
        case WALL_HITAG:
            lValue=wall[i].hitag;
            break;
        case WALL_EXTRA:
            lValue=wall[i].extra;
            break;
        default:
            return -1;
        }

        if (how&ACCESS_USEVARS)
            Gv_SetVarX(lVar2, lValue);

        return lValue;
    }

badwall:
    OSD_Printf(CON_ERROR "Invalid wall %d\n",g_errorLineNum,keyw[g_tw],i);
    return -1;
readonly:
    OSD_Printf(CON_ERROR "Wall structure member `%s' is read-only.\n",g_errorLineNum,keyw[g_tw],WallLabels[lLabelID].name);
    return -1;
}

// how: bitfield: 1=set? 2=vars?
static int32_t __fastcall X_AccessSector(int32_t how, int32_t lVar1, int32_t lLabelID, int32_t lVar2) {
    int32_t lValue;
    int32_t i = (how&ACCESS_USEVARS) ? sprite[vm.g_i].sectnum : lVar1;

    if ((how&ACCESS_USEVARS) && lVar1 != g_iThisActorID)
        i = Gv_GetVarX(lVar1);

    if (i<0 || i >= numsectors)
        goto badsector;

    if (how&ACCESS_SET) {
        if (SectorLabels[lLabelID].flags & 1)
            goto readonly;

        lValue = (how&ACCESS_USEVARS) ? Gv_GetVarX(lVar2) : lVar2;

        asksave = 1;

        if (SectorLabels[lLabelID].min != 0 || SectorLabels[lLabelID].max != 0) {
            if (lValue < SectorLabels[lLabelID].min)
                lValue = SectorLabels[lLabelID].min;
            if (lValue > SectorLabels[lLabelID].max)
                lValue = SectorLabels[lLabelID].max;
        }

        switch (lLabelID) {
        case SECTOR_WALLPTR:
            sector[i].wallptr=lValue;
            break;
        case SECTOR_WALLNUM:
            sector[i].wallnum=lValue;
            break;
        case SECTOR_CEILINGZ:
            sector[i].ceilingz=lValue;
            break;
        case SECTOR_FLOORZ:
            sector[i].floorz=lValue;
            break;
        case SECTOR_CEILINGSTAT:
            sector[i].ceilingstat = lValue&0x01fd;
            break;
        case SECTOR_FLOORSTAT:
            sector[i].floorstat = lValue&0x01fd;
            break;
        case SECTOR_CEILINGPICNUM:
            sector[i].ceilingpicnum=lValue;
            break;
        case SECTOR_CEILINGSLOPE:
            sector[i].ceilingheinum = lValue;
            if (lValue) sector[i].ceilingstat |= 2;
            else sector[i].ceilingstat &= ~2;
            break;
        case SECTOR_CEILINGSHADE:
            sector[i].ceilingshade=lValue;
            break;
        case SECTOR_CEILINGPAL:
            sector[i].ceilingpal=lValue;
            break;
        case SECTOR_CEILINGXPANNING:
            sector[i].ceilingxpanning=lValue;
            break;
        case SECTOR_CEILINGYPANNING:
            sector[i].ceilingypanning=lValue;
            break;
        case SECTOR_FLOORPICNUM:
            sector[i].floorpicnum=lValue;
            break;
        case SECTOR_FLOORSLOPE:
            sector[i].floorheinum = lValue;
            if (lValue) sector[i].floorstat |= 2;
            else sector[i].floorstat &= ~2;
            break;
        case SECTOR_FLOORSHADE:
            sector[i].floorshade=lValue;
            break;
        case SECTOR_FLOORPAL:
            sector[i].floorpal=lValue;
            break;
        case SECTOR_FLOORXPANNING:
            sector[i].floorxpanning=lValue;
            break;
        case SECTOR_FLOORYPANNING:
            sector[i].floorypanning=lValue;
            break;
        case SECTOR_VISIBILITY:
            sector[i].visibility=lValue;
            break;
        case SECTOR_ALIGNTO:
            sector[i].filler=lValue;
            break;
        case SECTOR_LOTAG:
            sector[i].lotag=lValue;
            break;
        case SECTOR_HITAG:
            sector[i].hitag=lValue;
            break;
        case SECTOR_EXTRA:
            sector[i].extra=lValue;
            break;
        default:
            return -1;
        }

        return 0;
    } else {
        switch (lLabelID) {
        case SECTOR_WALLPTR:
            lValue=sector[i].wallptr;
            break;
        case SECTOR_WALLNUM:
            lValue=sector[i].wallnum;
            break;
        case SECTOR_CEILINGZ:
            lValue=sector[i].ceilingz;
            break;
        case SECTOR_FLOORZ:
            lValue=sector[i].floorz;
            break;
        case SECTOR_CEILINGSTAT:
            lValue=sector[i].ceilingstat;
            break;
        case SECTOR_FLOORSTAT:
            lValue=sector[i].floorstat;
            break;
        case SECTOR_CEILINGPICNUM:
            lValue=sector[i].ceilingpicnum;
            break;
        case SECTOR_CEILINGSLOPE:
            lValue=sector[i].ceilingheinum;
            break;
        case SECTOR_CEILINGSHADE:
            lValue=sector[i].ceilingshade;
            break;
        case SECTOR_CEILINGPAL:
            lValue=sector[i].ceilingpal;
            break;
        case SECTOR_CEILINGXPANNING:
            lValue=sector[i].ceilingxpanning;
            break;
        case SECTOR_CEILINGYPANNING:
            lValue=sector[i].ceilingypanning;
            break;
        case SECTOR_FLOORPICNUM:
            lValue=sector[i].floorpicnum;
            break;
        case SECTOR_FLOORSLOPE:
            lValue=sector[i].floorheinum;
            break;
        case SECTOR_FLOORSHADE:
            lValue=sector[i].floorshade;
            break;
        case SECTOR_FLOORPAL:
            lValue=sector[i].floorpal;
            break;
        case SECTOR_FLOORXPANNING:
            lValue=sector[i].floorxpanning;
            break;
        case SECTOR_FLOORYPANNING:
            lValue=sector[i].floorypanning;
            break;
        case SECTOR_VISIBILITY:
            lValue=sector[i].visibility;
            break;
        case SECTOR_ALIGNTO:
            lValue=sector[i].filler;
            break;
        case SECTOR_LOTAG:
            lValue=sector[i].lotag;
            break;
        case SECTOR_HITAG:
            lValue=sector[i].hitag;
            break;
        case SECTOR_EXTRA:
            lValue=sector[i].extra;
            break;
        default:
            return -1;
        }

        if (how&ACCESS_USEVARS)
            Gv_SetVarX(lVar2, lValue);

        return lValue;
    }

badsector:
    OSD_Printf(CON_ERROR "Invalid sector %d\n",g_errorLineNum,keyw[g_tw],i);
    return -1;
readonly:
    OSD_Printf(CON_ERROR "Sector structure member `%s' is read-only.\n",g_errorLineNum,keyw[g_tw],SectorLabels[lLabelID].name);
    return -1;
}

// how: bitfield: 1=set? 2=vars?
static int32_t __fastcall X_AccessSprite(int32_t how, int32_t lVar1, int32_t lLabelID, int32_t lVar2) {
    int32_t lValue;
    register int32_t i = (how&ACCESS_USEVARS) ? vm.g_i : lVar1;

    if ((how&ACCESS_USEVARS) && lVar1 != g_iThisActorID)
        i = Gv_GetVarX(lVar1);

    if (i < 0 || i >= MAXSPRITES)
        goto badactor;

    if (how&ACCESS_SET) {
        if (SpriteLabels[lLabelID].flags & 1)
            goto readonly;

        lValue = (how&ACCESS_USEVARS) ? Gv_GetVarX(lVar2) : lVar2;

        asksave = 1;

        if (SpriteLabels[lLabelID].min != 0 || SpriteLabels[lLabelID].max != 0) {
            if (lValue < SpriteLabels[lLabelID].min)
                lValue = SpriteLabels[lLabelID].min;
            if (lValue > SpriteLabels[lLabelID].max)
                lValue = SpriteLabels[lLabelID].max;
        }

        switch (lLabelID) {
        case SPRITE_X:
            sprite[i].x=lValue;
            break;
        case SPRITE_Y:
            sprite[i].y=lValue;
            break;
        case SPRITE_Z:
            sprite[i].z=lValue;
            break;
        case SPRITE_CSTAT:
            sprite[i].cstat = lValue&0xe3ff;
            break;
        case SPRITE_PICNUM:
            sprite[i].picnum=lValue;
            break;
        case SPRITE_SHADE:
            sprite[i].shade=lValue;
            break;
        case SPRITE_PAL:
            sprite[i].pal=lValue;
            break;
        case SPRITE_CLIPDIST:
            sprite[i].clipdist=lValue;
            break;
        case SPRITE_DETAIL:
            sprite[i].filler=lValue;
            break;
        case SPRITE_XREPEAT:
            sprite[i].xrepeat=lValue;
            break;
        case SPRITE_YREPEAT:
            sprite[i].yrepeat=lValue;
            break;
        case SPRITE_XOFFSET:
            sprite[i].xoffset=lValue;
            break;
        case SPRITE_YOFFSET:
            sprite[i].yoffset=lValue;
            break;
        case SPRITE_SECTNUM:
            changespritesect(i,lValue);
            break;
        case SPRITE_STATNUM:
            changespritestat(i,lValue);
            break;
        case SPRITE_ANG:
            sprite[i].ang = lValue&2047;
            break;
        case SPRITE_OWNER:
            sprite[i].owner=lValue;
            break;
        case SPRITE_XVEL:
            sprite[i].xvel=lValue;
            break;
        case SPRITE_YVEL:
            sprite[i].yvel=lValue;
            break;
        case SPRITE_ZVEL:
            sprite[i].zvel=lValue;
            break;
        case SPRITE_LOTAG:
            sprite[i].lotag=lValue;
            break;
        case SPRITE_HITAG:
            sprite[i].hitag=lValue;
            break;
        case SPRITE_EXTRA:
            sprite[i].extra=lValue;
            break;
        default:
            return -1;
        }

        return 0;
    } else {
        switch (lLabelID) {
        case SPRITE_X:
            lValue=sprite[i].x;
            break;
        case SPRITE_Y:
            lValue=sprite[i].y;
            break;
        case SPRITE_Z:
            lValue=sprite[i].z;
            break;
        case SPRITE_CSTAT:
            lValue=sprite[i].cstat;
            break;
        case SPRITE_PICNUM:
            lValue=sprite[i].picnum;
            break;
        case SPRITE_SHADE:
            lValue=sprite[i].shade;
            break;
        case SPRITE_PAL:
            lValue=sprite[i].pal;
            break;
        case SPRITE_CLIPDIST:
            lValue=sprite[i].clipdist;
            break;
        case SPRITE_DETAIL:
            lValue=sprite[i].filler;
            break;
        case SPRITE_XREPEAT:
            lValue=sprite[i].xrepeat;
            break;
        case SPRITE_YREPEAT:
            lValue=sprite[i].yrepeat;
            break;
        case SPRITE_XOFFSET:
            lValue=sprite[i].xoffset;
            break;
        case SPRITE_YOFFSET:
            lValue=sprite[i].yoffset;
            break;
        case SPRITE_SECTNUM:
            lValue=sprite[i].sectnum;
            break;
        case SPRITE_STATNUM:
            lValue=sprite[i].statnum;
            break;
        case SPRITE_ANG:
            lValue=sprite[i].ang;
            break;
        case SPRITE_OWNER:
            lValue=sprite[i].owner;
            break;
        case SPRITE_XVEL:
            lValue=sprite[i].xvel;
            break;
        case SPRITE_YVEL:
            lValue=sprite[i].yvel;
            break;
        case SPRITE_ZVEL:
            lValue=sprite[i].zvel;
            break;
        case SPRITE_LOTAG:
            lValue=sprite[i].lotag;
            break;
        case SPRITE_HITAG:
            lValue=sprite[i].hitag;
            break;
        case SPRITE_EXTRA:
            lValue=sprite[i].extra;
            break;
        default:
            return -1;
        }

        if (how&ACCESS_USEVARS)
            Gv_SetVarX(lVar2, lValue);

        return lValue;
    }
badactor:
//    OSD_Printf(CON_ERROR "tried to set %s on invalid target sprite (%d) from spr %d pic %d gv %s\n",g_errorLineNum,keyw[g_tw],
//               SpriteLabels[lLabelID].name,i,vm.g_i,vm.g_sp->picnum,
//               (lVar1<MAXGAMEVARS)?aGameVars[lVar1].szLabel:"extended");
    OSD_Printf(CON_ERROR "tried to set %s on invalid target sprite (%d)\n",g_errorLineNum,keyw[g_tw],
               SpriteLabels[lLabelID].name,i);
    return -1;
readonly:
    OSD_Printf(CON_ERROR "Sprite structure member `%s' is read-only.\n",g_errorLineNum,keyw[g_tw],SpriteLabels[lLabelID].name);
    return -1;
}

// how: bitfield: 1=set? 2=vars? 4=use spriteext[].tspr? (otherwise use tsprite[])
static int32_t __fastcall X_AccessTsprite(int32_t how, int32_t lVar1, int32_t lLabelID, int32_t lVar2) {
    int32_t lValue;
    int32_t i = (how&ACCESS_USEVARS) ? vm.g_i : lVar1;
    spritetype *datspr;

    if ((how&ACCESS_USEVARS) && lVar1 != g_iThisActorID)
        i = Gv_GetVarX(lVar1);

    if (how&ACCESS_SPRITEEXT) {
        if (i < 0 || i >= MAXSPRITES)
            goto badsprite;
        datspr = spriteext[i].tspr;
        if (!datspr)
            goto badtspr;
    } else {
        if (i<0 || i>=spritesortcnt)
            goto badsprite;
        datspr = &tsprite[i];
    }

    if (how&ACCESS_SET) {
        lValue = (how&ACCESS_USEVARS) ? Gv_GetVarX(lVar2) : lVar2;

        switch (lLabelID) {
        case SPRITE_X:
            datspr->x=lValue;
            break;
        case SPRITE_Y:
            datspr->y=lValue;
            break;
        case SPRITE_Z:
            datspr->z=lValue;
            break;
        case SPRITE_CSTAT:
            datspr->cstat = lValue&0xe3ff;
            break;
        case SPRITE_PICNUM:
            datspr->picnum=lValue;
            break;
        case SPRITE_SHADE:
            datspr->shade=lValue;
            break;
        case SPRITE_PAL:
            datspr->pal=lValue;
            break;
        case SPRITE_CLIPDIST:
            datspr->clipdist=lValue;
            break;
        case SPRITE_DETAIL:
            datspr->filler=lValue;
            break;
        case SPRITE_XREPEAT:
            datspr->xrepeat=lValue;
            break;
        case SPRITE_YREPEAT:
            datspr->yrepeat=lValue;
            break;
        case SPRITE_XOFFSET:
            datspr->xoffset=lValue;
            break;
        case SPRITE_YOFFSET:
            datspr->yoffset=lValue;
            break;
        case SPRITE_SECTNUM:
            datspr->sectnum=lValue;
            break;
        case SPRITE_STATNUM:
            datspr->statnum=lValue;
            break;
        case SPRITE_ANG:
            datspr->ang = lValue&2047;
            break;
        case SPRITE_OWNER:
            datspr->owner=lValue;
            break;
        case SPRITE_XVEL:
            datspr->xvel=lValue;
            break;
        case SPRITE_YVEL:
            datspr->yvel=lValue;
            break;
        case SPRITE_ZVEL:
            datspr->zvel=lValue;
            break;
        case SPRITE_LOTAG:
            datspr->lotag=lValue;
            break;
        case SPRITE_HITAG:
            datspr->hitag=lValue;
            break;
        case SPRITE_EXTRA:
            datspr->extra=lValue;
            break;
        default:
            return -1;
        }

        return 0;
    } else {
        switch (lLabelID) {
        case SPRITE_X:
            lValue=datspr->x;
            break;
        case SPRITE_Y:
            lValue=datspr->y;
            break;
        case SPRITE_Z:
            lValue=datspr->z;
            break;
        case SPRITE_CSTAT:
            lValue=datspr->cstat;
            break;
        case SPRITE_PICNUM:
            lValue=datspr->picnum;
            break;
        case SPRITE_SHADE:
            lValue=datspr->shade;
            break;
        case SPRITE_PAL:
            lValue=datspr->pal;
            break;
        case SPRITE_CLIPDIST:
            lValue=datspr->clipdist;
            break;
        case SPRITE_DETAIL:
            lValue=datspr->filler;
            break;
        case SPRITE_XREPEAT:
            lValue=datspr->xrepeat;
            break;
        case SPRITE_YREPEAT:
            lValue=datspr->yrepeat;
            break;
        case SPRITE_XOFFSET:
            lValue=datspr->xoffset;
            break;
        case SPRITE_YOFFSET:
            lValue=datspr->yoffset;
            break;
        case SPRITE_SECTNUM:
            lValue=datspr->sectnum;
            break;
        case SPRITE_STATNUM:
            lValue=datspr->statnum;
            break;
        case SPRITE_ANG:
            lValue=datspr->ang;
            break;
        case SPRITE_OWNER:
            lValue=datspr->owner;
            break;
        case SPRITE_XVEL:
            lValue=datspr->xvel;
            break;
        case SPRITE_YVEL:
            lValue=datspr->yvel;
            break;
        case SPRITE_ZVEL:
            lValue=datspr->zvel;
            break;
        case SPRITE_LOTAG:
            lValue=datspr->lotag;
            break;
        case SPRITE_HITAG:
            lValue=datspr->hitag;
            break;
        case SPRITE_EXTRA:
            lValue=datspr->extra;
            break;
        default:
            return -1;
        }

        if (how&ACCESS_USEVARS)
            Gv_SetVarX(lVar2, lValue);

        return lValue;
    }

badsprite:
    OSD_Printf(CON_ERROR "invalid target sprite (%d)\n",g_errorLineNum,keyw[g_tw],i);
    return -1;
badtspr:
    OSD_Printf(CON_ERROR "Internal bug, tsprite is unavailable\n",g_errorLineNum,keyw[g_tw]);
    return -1;
}

#undef ACCESS_SET
#undef ACCESS_USEVARS
#undef ACCESS_SPRITEEXT
