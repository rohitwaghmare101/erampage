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

#include "names.h"


#define SECTOREFFECTOR__STATIC SECTOREFFECTOR

#define ACTIVATOR__STATIC ACTIVATOR
#define JAILDOOR__STATIC JAILDOOR

#define TOUCHPLATE__STATIC TOUCHPLATE

#define ACTIVATORLOCKED__STATIC ACTIVATORLOCKED

#define DOORLOCK__STATIC DOORLOCK

#define MUSICANDSFX__STATIC MUSICANDSFX

#define LOCATORS__STATIC LOCATORS

#define CYCLER__STATIC CYCLER

#define MASTERSWITCH__STATIC MASTERSWITCH

#define RESPAWN__STATIC RESPAWN

#define GPSPEED__STATIC GPSPEED

#define FOF__STATIC FOF

#define ARROW__STATIC ARROW

#define FIRSTGUNSPRITE__STATIC FIRSTGUNSPRITE

#define CHAINGUNSPRITE__STATIC CHAINGUNSPRITE

#define RPGSPRITE__STATIC RPGSPRITE

#define BUZSAWSPRITE__STATIC BUZSAWSPRITE

#define ALIENARMGUNSPRITE__STATIC ALIENARMGUNSPRITE

#define HEAVYHBOMB__STATIC HEAVYHBOMB

#define POWDERKEGSPRITE__STATIC POWDERKEGSPRITE

#define SHOTGUNSPRITE__STATIC SHOTGUNSPRITE

#define TEATGUNSPRITE__STATIC TEATGUNSPRITE

#define HEALTHBOX__STATIC HEALTHBOX

#define AMMOBOX__STATIC AMMOBOX

#define GROWSPRITEICON__STATIC GROWSPRITEICON

#define INVENTORYBOX__STATIC INVENTORYBOX

#define BUZSAWAMMO__STATIC BUZSAWAMMO

#define AMMO__STATIC AMMO

#define BATTERYAMMO__STATIC BATTERYAMMO

#define TEATGUNAMMO__STATIC TEATGUNAMMO

#define RPGAMMO__STATIC RPGAMMO

#define GROWAMMO__STATIC GROWAMMO

#define ALIENBLASTERAMMO__STATIC ALIENBLASTERAMMO

#define HBOMBAMMO__STATIC HBOMBAMMO

#define AMMOLOTS__STATIC AMMOLOTS

#define SHOTGUNAMMO__STATIC SHOTGUNAMMO

#define COLA__STATIC COLA

#define SIXPAK__STATIC SIXPAK

#define FIRSTAID__STATIC FIRSTAID

#define SHIELD__STATIC SHIELD

#define STEROIDS__STATIC STEROIDS

#define AIRTANK__STATIC AIRTANK

#define JETPACK__STATIC JETPACK

#define HEATSENSOR__STATIC HEATSENSOR

#define ACCESSCARD__STATIC ACCESSCARD

#define BOOTS__STATIC BOOTS

#define MIRRORBROKE__STATIC MIRRORBROKE

#define CLOUDYOCEAN__STATIC CLOUDYOCEAN

#define CLOUDYSKIES__STATIC CLOUDYSKIES

#define MOONSKY1__STATIC MOONSKY1

#define MOONSKY2__STATIC MOONSKY2

#define MOONSKY3__STATIC MOONSKY3

#define MOONSKY4__STATIC MOONSKY4

#define BIGORBIT1__STATIC BIGORBIT1

#define BIGORBIT2__STATIC BIGORBIT2

#define BIGORBIT3__STATIC BIGORBIT3

#define BIGORBIT4__STATIC BIGORBIT4

#define BIGORBIT5__STATIC BIGORBIT5

#define LA__STATIC LA

#define REDSKY1__STATIC REDSKY1

#define REDSKY2__STATIC REDSKY2

#define ATOMICHEALTH__STATIC ATOMICHEALTH

#define TECHLIGHT2__STATIC TECHLIGHT2

#define TECHLIGHTBUST2__STATIC TECHLIGHTBUST2

#define TECHLIGHT4__STATIC TECHLIGHT4

#define TECHLIGHTBUST4__STATIC TECHLIGHTBUST4

#define WALLLIGHT4__STATIC WALLLIGHT4

#define WALLLIGHTBUST4__STATIC WALLLIGHTBUST4

#define ACCESSSWITCH__STATIC ACCESSSWITCH

#define SLOTDOOR__STATIC SLOTDOOR

#define LIGHTSWITCH__STATIC LIGHTSWITCH

#define SPACEDOORSWITCH__STATIC SPACEDOORSWITCH

#define SPACELIGHTSWITCH__STATIC SPACELIGHTSWITCH

#define FRANKENSTINESWITCH__STATIC FRANKENSTINESWITCH

#define NUKEBUTTON__STATIC NUKEBUTTON

#define MULTISWITCH__STATIC MULTISWITCH
#define MULTISWITCH2__STATIC MULTISWITCH2

#define DOORTILE5__STATIC DOORTILE5

#define DOORTILE6__STATIC DOORTILE6

#define DOORTILE1__STATIC DOORTILE1

#define DOORTILE2__STATIC DOORTILE2

#define DOORTILE3__STATIC DOORTILE3

#define DOORTILE4__STATIC DOORTILE4

#define DOORTILE7__STATIC DOORTILE7

#define DOORTILE8__STATIC DOORTILE8

#define DOORTILE9__STATIC DOORTILE9

#define DOORTILE10__STATIC DOORTILE10

#define DOORSHOCK__STATIC DOORSHOCK

#define DIPSWITCH__STATIC DIPSWITCH

#define DIPSWITCH2__STATIC DIPSWITCH2

#define TECHSWITCH__STATIC TECHSWITCH

#define DIPSWITCH3__STATIC DIPSWITCH3

#define ACCESSSWITCH2__STATIC ACCESSSWITCH2

#define REFLECTWATERTILE__STATIC REFLECTWATERTILE

#define FLOORSLIME__STATIC FLOORSLIME

#define BIGFORCE__STATIC BIGFORCE

#define EPISODE__STATIC EPISODE

#define MASKWALL9__STATIC MASKWALL9

#define W_LIGHT__STATIC W_LIGHT

#define SCREENBREAK1__STATIC SCREENBREAK1

#define SCREENBREAK2__STATIC SCREENBREAK2

#define SCREENBREAK3__STATIC SCREENBREAK3

#define SCREENBREAK4__STATIC SCREENBREAK4

#define SCREENBREAK5__STATIC SCREENBREAK5

#define SCREENBREAK6__STATIC SCREENBREAK6

#define SCREENBREAK7__STATIC SCREENBREAK7

#define SCREENBREAK8__STATIC SCREENBREAK8

#define SCREENBREAK9__STATIC SCREENBREAK9

#define SCREENBREAK10__STATIC SCREENBREAK10

#define SCREENBREAK11__STATIC SCREENBREAK11

#define SCREENBREAK12__STATIC SCREENBREAK12

#define SCREENBREAK13__STATIC SCREENBREAK13

#define MASKWALL1__STATIC MASKWALL1

#define W_TECHWALL1__STATIC W_TECHWALL1

#define W_TECHWALL2__STATIC W_TECHWALL2

#define W_TECHWALL15__STATIC W_TECHWALL15

#define W_TECHWALL3__STATIC W_TECHWALL3

#define W_TECHWALL4__STATIC W_TECHWALL4

#define W_TECHWALL10__STATIC W_TECHWALL10

#define W_TECHWALL16__STATIC W_TECHWALL16

#define WATERTILE2__STATIC WATERTILE2

#define BPANNEL1__STATIC BPANNEL1

#define PANNEL1__STATIC PANNEL1

#define PANNEL2__STATIC PANNEL2

#define WATERTILE__STATIC WATERTILE

#define STATIC__STATIC STATIC

#define W_SCREENBREAK__STATIC W_SCREENBREAK

#define W_HITTECHWALL3__STATIC W_HITTECHWALL3

#define W_HITTECHWALL4__STATIC W_HITTECHWALL4

#define W_HITTECHWALL2__STATIC W_HITTECHWALL2

#define W_HITTECHWALL1__STATIC W_HITTECHWALL1

#define MASKWALL10__STATIC MASKWALL10

#define MASKWALL11__STATIC MASKWALL11

#define DOORTILE22__STATIC DOORTILE22

#define FANSPRITE__STATIC FANSPRITE

#define FANSPRITEBROKE__STATIC FANSPRITEBROKE

#define FANSHADOW__STATIC FANSHADOW

#define FANSHADOWBROKE__STATIC FANSHADOWBROKE

#define DOORTILE18__STATIC DOORTILE18

#define DOORTILE19__STATIC DOORTILE19

#define DOORTILE20__STATIC DOORTILE20

#define SATELLITE__STATIC SATELLITE

#define VIEWSCREEN2__STATIC VIEWSCREEN2

#define VIEWSCREENBROKE__STATIC VIEWSCREENBROKE

#define VIEWSCREEN__STATIC VIEWSCREEN

#define GLASS__STATIC GLASS

#define GLASS2__STATIC GLASS2

#define STAINGLASS1__STATIC STAINGLASS1

#define MASKWALL5__STATIC MASKWALL5

#define SATELITE__STATIC SATELITE

#define FUELPOD__STATIC FUELPOD

#define SLIMEPIPE__STATIC SLIMEPIPE

#define CRACK1__STATIC CRACK1

#define CRACK2__STATIC CRACK2

#define CRACK3__STATIC CRACK3

#define CRACK4__STATIC CRACK4

#define FOOTPRINTS__STATIC FOOTPRINTS

#define DOMELITE__STATIC DOMELITE

#define CAMERAPOLE__STATIC CAMERAPOLE

#define CHAIR1__STATIC CHAIR1

#define CHAIR2__STATIC CHAIR2

#define BROKENCHAIR__STATIC BROKENCHAIR

#define MIRROR__STATIC MIRROR

#define WATERFOUNTAIN__STATIC WATERFOUNTAIN

#define WATERFOUNTAINBROKE__STATIC WATERFOUNTAINBROKE

#define FEMMAG1__STATIC FEMMAG1

#define TOILET__STATIC TOILET

#define STALL__STATIC STALL

#define STALLBROKE__STATIC STALLBROKE

#define FEMMAG2__STATIC FEMMAG2

#define REACTOR2__STATIC REACTOR2

#define REACTOR2BURNT__STATIC REACTOR2BURNT

#define REACTOR2SPARK__STATIC REACTOR2SPARK

#define GRATE1__STATIC GRATE1

#define BGRATE1__STATIC BGRATE1

#define SOLARPANNEL__STATIC SOLARPANNEL

#define NAKED1__STATIC NAKED1

#define ANTENNA__STATIC ANTENNA

#define MASKWALL12__STATIC MASKWALL12

#define TOILETBROKE__STATIC TOILETBROKE

#define PIPE2__STATIC PIPE2

#define PIPE1B__STATIC PIPE1B

#define PIPE3__STATIC PIPE3

#define PIPE1__STATIC PIPE1

#define CAMERA1__STATIC CAMERA1

#define BRICK__STATIC BRICK

#define SPLINTERWOOD__STATIC SPLINTERWOOD

#define PIPE2B__STATIC PIPE2B

#define BOLT1__STATIC BOLT1

#define W_NUMBERS__STATIC 640

#define WATERDRIP__STATIC WATERDRIP

#define WATERBUBBLE__STATIC WATERBUBBLE

#define WATERBUBBLEMAKER__STATIC WATERBUBBLEMAKER

#define W_FORCEFIELD__STATIC 663

#define VACUUM__STATIC VACUUM

#define FOOTPRINTS2__STATIC FOOTPRINTS2

#define FOOTPRINTS3__STATIC FOOTPRINTS3

#define FOOTPRINTS4__STATIC FOOTPRINTS4

#define EGG__STATIC EGG

#define SCALE__STATIC SCALE

#define CHAIR3__STATIC CHAIR3

#define CAMERALIGHT__STATIC CAMERALIGHT

#define MOVIECAMERA__STATIC MOVIECAMERA

#define IVUNIT__STATIC IVUNIT

#define POT1__STATIC POT1

#define POT2__STATIC POT2

#define POT3__STATIC POT3

#define PIPE3B__STATIC PIPE3B

#define WALLLIGHT3__STATIC WALLLIGHT3

#define WALLLIGHTBUST3__STATIC WALLLIGHTBUST3

#define WALLLIGHT1__STATIC WALLLIGHT1

#define WALLLIGHTBUST1__STATIC WALLLIGHTBUST1

#define WALLLIGHT2__STATIC WALLLIGHT2

#define WALLLIGHTBUST2__STATIC WALLLIGHTBUST2

#define LIGHTSWITCH2__STATIC LIGHTSWITCH2

#define WAITTOBESEATED__STATIC WAITTOBESEATED

#define DOORTILE14__STATIC DOORTILE14

#define STATUE__STATIC STATUE

#define MIKE__STATIC MIKE

#define VASE__STATIC VASE

#define SUSHIPLATE1__STATIC SUSHIPLATE1

#define SUSHIPLATE2__STATIC SUSHIPLATE2

#define SUSHIPLATE3__STATIC SUSHIPLATE3

#define SUSHIPLATE4__STATIC SUSHIPLATE4

#define DOORTILE16__STATIC DOORTILE16

#define SUSHIPLATE5__STATIC SUSHIPLATE5

#define OJ__STATIC OJ

#define MASKWALL13__STATIC MASKWALL13

#define HURTRAIL__STATIC HURTRAIL

#define POWERSWITCH1__STATIC POWERSWITCH1

#define LOCKSWITCH1__STATIC LOCKSWITCH1

#define POWERSWITCH2__STATIC POWERSWITCH2

#define ATM__STATIC ATM

#define STATUEFLASH__STATIC STATUEFLASH

#define ATMBROKE__STATIC ATMBROKE

#define BIGHOLE2__STATIC BIGHOLE2

#define STRIPEBALL__STATIC STRIPEBALL

#define QUEBALL__STATIC QUEBALL

#define POCKET__STATIC POCKET

#define WOODENHORSE__STATIC WOODENHORSE

#define TREE1__STATIC TREE1

#define TREE2__STATIC TREE2

#define CACTUS__STATIC CACTUS

#define MASKWALL2__STATIC MASKWALL2

#define MASKWALL3__STATIC MASKWALL3

#define MASKWALL4__STATIC MASKWALL4

#define FIREEXT__STATIC FIREEXT

#define TOILETWATER__STATIC TOILETWATER

#define NEON1__STATIC NEON1

#define NEON2__STATIC NEON2

#define CACTUSBROKE__STATIC CACTUSBROKE

#define BOUNCEMINE__STATIC BOUNCEMINE

#define BROKEFIREHYDRENT__STATIC BROKEFIREHYDRENT

#define BOX__STATIC BOX

#define BULLETHOLE__STATIC BULLETHOLE

#define BOTTLE1__STATIC BOTTLE1

#define BOTTLE2__STATIC BOTTLE2

#define BOTTLE3__STATIC BOTTLE3

#define BOTTLE4__STATIC BOTTLE4

#define FEMPIC5__STATIC FEMPIC5

#define FEMPIC6__STATIC FEMPIC6

#define FEMPIC7__STATIC FEMPIC7

#define HYDROPLANT__STATIC HYDROPLANT

#define OCEANSPRITE1__STATIC OCEANSPRITE1

#define OCEANSPRITE2__STATIC OCEANSPRITE2

#define OCEANSPRITE3__STATIC OCEANSPRITE3

#define OCEANSPRITE4__STATIC OCEANSPRITE4

#define OCEANSPRITE5__STATIC OCEANSPRITE5

#define GENERICPOLE__STATIC GENERICPOLE

#define CONE__STATIC CONE

#define HANGLIGHT__STATIC HANGLIGHT

#define HYDRENT__STATIC HYDRENT

#define MASKWALL14__STATIC MASKWALL14

#define TIRE__STATIC TIRE

#define PIPE5__STATIC PIPE5

#define PIPE6__STATIC PIPE6

#define PIPE4__STATIC PIPE4

#define PIPE4B__STATIC PIPE4B

#define BROKEHYDROPLANT__STATIC BROKEHYDROPLANT

#define PIPE5B__STATIC PIPE5B

#define NEON3__STATIC NEON3

#define NEON4__STATIC NEON4

#define NEON5__STATIC NEON5

#define BOTTLE5__STATIC BOTTLE5

#define BOTTLE6__STATIC BOTTLE6

#define BOTTLE8__STATIC BOTTLE8

#define SPOTLITE__STATIC SPOTLITE

#define HANGOOZ__STATIC HANGOOZ

#define MASKWALL15__STATIC MASKWALL15

#define BOTTLE7__STATIC BOTTLE7

#define HORSEONSIDE__STATIC HORSEONSIDE

#define GLASSPIECES__STATIC GLASSPIECES

#define HORSELITE__STATIC HORSELITE

#define DONUTS__STATIC DONUTS

#define NEON6__STATIC NEON6

#define MASKWALL6__STATIC MASKWALL6

#define CLOCK__STATIC CLOCK

#define RUBBERCAN__STATIC RUBBERCAN

#define BROKENCLOCK__STATIC BROKENCLOCK

#define PLUG__STATIC PLUG

#define OOZFILTER__STATIC OOZFILTER

#define FLOORPLASMA__STATIC FLOORPLASMA

#define REACTOR__STATIC REACTOR

#define REACTORSPARK__STATIC REACTORSPARK

#define REACTORBURNT__STATIC REACTORBURNT

#define DOORTILE15__STATIC DOORTILE15

#define HANDSWITCH__STATIC HANDSWITCH

#define CIRCLEPANNEL__STATIC CIRCLEPANNEL

#define CIRCLEPANNELBROKE__STATIC CIRCLEPANNELBROKE

#define PULLSWITCH__STATIC PULLSWITCH

#define MASKWALL8__STATIC MASKWALL8

#define BIGHOLE__STATIC BIGHOLE

#define ALIENSWITCH__STATIC ALIENSWITCH

#define DOORTILE21__STATIC DOORTILE21

#define HANDPRINTSWITCH__STATIC HANDPRINTSWITCH

#define BOTTLE10__STATIC BOTTLE10

#define BOTTLE11__STATIC BOTTLE11

#define BOTTLE12__STATIC BOTTLE12

#define BOTTLE13__STATIC BOTTLE13

#define BOTTLE14__STATIC BOTTLE14

#define BOTTLE15__STATIC BOTTLE15

#define BOTTLE16__STATIC BOTTLE16

#define BOTTLE17__STATIC BOTTLE17

#define BOTTLE18__STATIC BOTTLE18

#define BOTTLE19__STATIC BOTTLE19

#define DOORTILE17__STATIC DOORTILE17

#define MASKWALL7__STATIC MASKWALL7

#define JAILBARBREAK__STATIC JAILBARBREAK

#define DOORTILE11__STATIC DOORTILE11

#define DOORTILE12__STATIC DOORTILE12

#define VENDMACHINE__STATIC VENDMACHINE

#define VENDMACHINEBROKE__STATIC VENDMACHINEBROKE

#define COLAMACHINE__STATIC COLAMACHINE

#define COLAMACHINEBROKE__STATIC COLAMACHINEBROKE

#define CRANEPOLE__STATIC CRANEPOLE

#define CRANE__STATIC CRANE

#define BARBROKE__STATIC BARBROKE

#define BLOODPOOL__STATIC BLOODPOOL

#define NUKEBARREL__STATIC NUKEBARREL

#define NUKEBARRELDENTED__STATIC NUKEBARRELDENTED

#define NUKEBARRELLEAKED__STATIC NUKEBARRELLEAKED

#define CANWITHSOMETHING__STATIC CANWITHSOMETHING

#define MONEY__STATIC MONEY

#define BANNER__STATIC BANNER

#define EXPLODINGBARREL__STATIC EXPLODINGBARREL

#define EXPLODINGBARREL2__STATIC EXPLODINGBARREL2

#define FIREBARREL__STATIC FIREBARREL

#define SEENINE__STATIC SEENINE

#define SEENINEDEAD__STATIC SEENINEDEAD

#define STEAM__STATIC STEAM

#define CEILINGSTEAM__STATIC CEILINGSTEAM

#define PIPE6B__STATIC PIPE6B

#define TRANSPORTERBEAM__STATIC TRANSPORTERBEAM

#define RAT__STATIC RAT

#define TRASH__STATIC TRASH

#define FEMPIC1__STATIC FEMPIC1

#define FEMPIC2__STATIC FEMPIC2

#define BLANKSCREEN__STATIC BLANKSCREEN

#define PODFEM1__STATIC PODFEM1

#define FEMPIC3__STATIC FEMPIC3

#define FEMPIC4__STATIC FEMPIC4

#define FEM1__STATIC FEM1

#define FEM2__STATIC FEM2

#define FEM3__STATIC FEM3

#define FEM5__STATIC FEM5

#define BLOODYPOLE__STATIC BLOODYPOLE

#define FEM4__STATIC FEM4

#define FEM6__STATIC FEM6

#define FEM6PAD__STATIC FEM6PAD

#define FEM8__STATIC FEM8

#define HELECOPT__STATIC HELECOPT

#define FETUSJIB__STATIC FETUSJIB

#define HOLODUKE__STATIC HOLODUKE

#define SPACEMARINE__STATIC SPACEMARINE

#define INDY__STATIC INDY

#define FETUS__STATIC FETUS

#define FETUSBROKE__STATIC FETUSBROKE

#define MONK__STATIC MONK

#define LUKE__STATIC LUKE

#define COOLEXPLOSION1__STATIC COOLEXPLOSION1

#define WATERSPLASH2__STATIC WATERSPLASH2

#define FIREVASE__STATIC FIREVASE

#define SCRATCH__STATIC SCRATCH

#define FEM7__STATIC FEM7

#define APLAYERTOP__STATIC APLAYERTOP

#define APLAYER__STATIC APLAYER

#define PLAYERONWATER__STATIC PLAYERONWATER

#define DUKELYINGDEAD__STATIC DUKELYINGDEAD

#define DUKETORSO__STATIC DUKETORSO

#define DUKEGUN__STATIC DUKEGUN

#define DUKELEG__STATIC DUKELEG

#define SHARK__STATIC SHARK

#define BLOOD__STATIC BLOOD

#define FIRELASER__STATIC FIRELASER

#define TRANSPORTERSTAR__STATIC TRANSPORTERSTAR

#define SPIT__STATIC SPIT

#define LOOGIE__STATIC LOOGIE

#define FIST__STATIC FIST

#define CIRCLESAW__STATIC CIRCLESAW

#define TEATGUNBLAST__STATIC TEATGUNBLAST

#define TONGUE__STATIC TONGUE

#define MORTER__STATIC MORTER

#define ALIENARMGUNEXPLOSION__STATIC ALIENARMGUNEXPLOSION

#define RADIUSEXPLOSION__STATIC RADIUSEXPLOSION

#define FORCERIPPLE__STATIC FORCERIPPLE


/*
#define LIZMANHEAD1__STATIC LIZMANHEAD1

#define LIZMANARM1__STATIC LIZMANARM1

#define LIZMANLEG1__STATIC LIZMANLEG1

#define HEADJIB1__STATIC HEADJIB1

#define ARMJIB1__STATIC ARMJIB1

#define LEGJIB1__STATIC LEGJIB1
/*/
#define FBOATJIBA__STATIC FBOATJIBA
#define FBOATJIBB__STATIC FBOATJIBB
#define CHEERJIBA__STATIC CHEERJIBA
#define CHEERJIBB__STATIC CHEERJIBB
#define CHEERJIBC__STATIC CHEERJIBC
#define CHEERJIBD__STATIC CHEERJIBD
#define RABBITJIBA__STATIC RABBITJIBA
#define RABBITJIBB__STATIC RABBITJIBB
#define RABBITJIBC__STATIC RABBITJIBC
#define MINJIBA__STATIC MINJIBA
#define MINJIBB__STATIC MINJIBB
#define MINJIBC__STATIC MINJIBC
#define HULKJIBA__STATIC HULKJIBA
#define HULKJIBB__STATIC HULKJIBB
#define HULKJIBC__STATIC HULKJIBC
#define BILLYJIBA__STATIC BILLYJIBA
#define BILLYJIBB__STATIC BILLYJIBB
#define COOTJIBA__STATIC COOTJIBA
#define COOTJIBB__STATIC COOTJIBB
#define COOTJIBC__STATIC COOTJIBC
#define BIKEJIBA__STATIC BIKEJIBA
#define BIKEJIBB__STATIC BIKEJIBB
#define BIKEJIBC__STATIC BIKEJIBC
#define BIKERJIBA__STATIC BIKERJIBA
#define BIKERJIBB__STATIC BIKERJIBB
#define BIKERJIBC__STATIC BIKERJIBC
#define BIKERJIBD__STATIC BIKERJIBD
#define MAMAJIBA__STATIC MAMAJIBA
#define MAMAJIBB__STATIC MAMAJIBB
//*/



/*

#define BOSS1__STATIC BOSS1

#define BOSS1STAYPUT__STATIC BOSS1STAYPUT

#define BOSS1SHOOT__STATIC BOSS1SHOOT

#define BOSS1LOB__STATIC BOSS1LOB

#define BOSSTOP__STATIC BOSSTOP

#define BOSS2__STATIC BOSS2

#define BOSS3__STATIC BOSS3


#define LIZTROOP__STATIC LIZTROOP

#define LIZTROOPRUNNING__STATIC LIZTROOPRUNNING

#define LIZTROOPSTAYPUT__STATIC LIZTROOPSTAYPUT

#define LIZTOP__STATIC LIZTOP

#define LIZTROOPSHOOT__STATIC LIZTROOPSHOOT

#define LIZTROOPJETPACK__STATIC LIZTROOPJETPACK

#define LIZTROOPDSPRITE__STATIC LIZTROOPDSPRITE

#define LIZTROOPONTOILET__STATIC LIZTROOPONTOILET

#define LIZTROOPJUSTSIT__STATIC LIZTROOPJUSTSIT

#define LIZTROOPDUCKING__STATIC LIZTROOPDUCKING



#define OCTABRAIN__STATIC OCTABRAIN

#define OCTABRAINSTAYPUT__STATIC OCTABRAINSTAYPUT

#define OCTATOP__STATIC OCTATOP

#define OCTADEADSPRITE__STATIC OCTADEADSPRITE


#define DRONE__STATIC DRONE


#define COMMANDER__STATIC COMMANDER

#define COMMANDERSTAYPUT__STATIC COMMANDERSTAYPUT

#define RECON__STATIC RECON

#define TANK__STATIC TANK

#define PIGCOP__STATIC PIGCOP

#define PIGCOPSTAYPUT__STATIC PIGCOPSTAYPUT

#define PIGCOPDIVE__STATIC PIGCOPDIVE

#define PIGCOPDEADSPRITE__STATIC PIGCOPDEADSPRITE

#define PIGTOP__STATIC PIGTOP

#define LIZMAN__STATIC LIZMAN

#define LIZMANSTAYPUT__STATIC LIZMANSTAYPUT

#define LIZMANSPITTING__STATIC LIZMANSPITTING

#define LIZMANFEEDING__STATIC LIZMANFEEDING

#define LIZMANJUMP__STATIC LIZMANJUMP

#define LIZMANDEADSPRITE__STATIC LIZMANDEADSPRITE

#define FECES__STATIC FECES




/*/
#define COOT__STATIC COOT
#define COOTSTAYPUT__STATIC COOTSTAYPUT
#define COOTSHOOT__STATIC COOTSHOOT
#define COOTDIE__STATIC COOTDIE
#define COOTDUCK__STATIC COOTDUCK
#define COOTPAIN__STATIC COOTPAIN
#define COOTTRANS__STATIC COOTTRANS
#define COOTGETUP__STATIC COOTGETUP
#define ECLAIRHEALTH__STATIC ECLAIRHEALTH
#define BILLYWALK__STATIC BILLYWALK
#define BILLYDIE__STATIC BILLYDIE
#define BILLYCOCK__STATIC BILLYCOCK
#define BILLYRAY__STATIC BILLYRAY
#define BILLYSHOOT__STATIC BILLYSHOOT
#define BILLYRAYSTAYPUT__STATIC BILLYRAYSTAYPUT
#define BILLYBUT__STATIC BILLYBUT
#define BILLYSCRATCH__STATIC BILLYSCRATCH
#define BILLYSNIFF__STATIC BILLYSNIFF
#define BILLYWOUND__STATIC BILLYWOUND
#define BILLYGORE__STATIC BILLYGORE
#define DOGRUN__STATIC DOGRUN
#define DOGDIE__STATIC DOGDIE
#define DOGDEAD__STATIC DOGDEAD
#define DOGBARK__STATIC DOGBARK
#define DOGATTACK__STATIC DOGATTACK
#define LTH__STATIC LTH
#define LTHSTRAFE__STATIC LTHSTRAFE
#define LTHLOAD__STATIC LTHLOAD
#define LTHDIE__STATIC LTHDIE
#define BUBBASCRATCH__STATIC BUBBASCRATCH
#define BUBBANOSE__STATIC BUBBANOSE
#define BUBBAPISS__STATIC BUBBAPISS
#define BUBBASTAND__STATIC BUBBASTAND
#define BUBBAOUCH__STATIC BUBBAOUCH
#define BUBBADIE__STATIC BUBBADIE
#define BUBBADEAD__STATIC BUBBADEAD
#define HULK__STATIC HULK
#define HULKSTAYPUT__STATIC HULKSTAYPUT
#define HULKA__STATIC HULKA
#define HULKB__STATIC HULKB
#define HULKC__STATIC HULKC
#define SBSWIPE__STATIC SBSWIPE
#define SBPAIN__STATIC SBPAIN
#define SBDIE__STATIC SBDIE
#define HEN__STATIC HEN
#define HENSTAYPUT__STATIC HENSTAYPUT
#define HENSTAND__STATIC HENSTAND
#define MOSQUITO__STATIC MOSQUITO
#define PIG__STATIC PIG
#define PIGSTAYPUT__STATIC PIGSTAYPUT
#define PIGEAT__STATIC PIGEAT
#define SBMOVE__STATIC SBMOVE
#define SBSPIT__STATIC SBSPIT
#define SBDIP__STATIC SBDIP
#define MINION__STATIC MINION
#define MINIONSTAYPUT__STATIC MINIONSTAYPUT
#define UFO1__STATIC UFO1
#define UFO2__STATIC UFO2
#define UFO3__STATIC UFO3
#define UFO4__STATIC UFO4
#define UFO5__STATIC UFO5
#define COW__STATIC COW
#define VIXEN__STATIC VIXEN
#define VIXENPAIN__STATIC VIXENPAIN
#define VIXENDIE__STATIC VIXENDIE
#define VIXENSHOOT__STATIC VIXENSHOOT
#define VIXENWDN__STATIC VIXENWDN
#define VIXENWUP__STATIC VIXENWUP
#define VIXENKICK__STATIC VIXENKICK
#define VIXENTELE__STATIC VIXENTELE
#define VIXENTEAT__STATIC VIXENTEAT
#define MOTOHIT__STATIC MOTOHIT
#define BOATHIT__STATIC BOATHIT
#define EMPTYBIKE__STATIC EMPTYBIKE
#define EMPTYBOAT__STATIC EMPTYBOAT
#define RABBIT__STATIC RABBIT
#define MAKEOUT__STATIC MAKEOUT
#define DEADBIKE__STATIC DEADBIKE
#define CHEER__STATIC CHEER
#define CHEERSTAYPUT__STATIC CHEERSTAYPUT
#define CHEERB__STATIC CHEERB
#define CHEERBOMB__STATIC CHEERBOMB
#define CHEERBLADE__STATIC CHEERBLADE
#define MOTOGUN__STATIC MOTOGUN
#define MOTOAMMO__STATIC MOTOAMMO
#define BOATAMMO__STATIC BOATAMMO
#define WEED__STATIC WEED
#define BIKERB__STATIC BIKERB
#define BIKERBV2__STATIC BIKERBV2
#define BIKER__STATIC BIKER
#define MINIONBOAT__STATIC MINIONBOAT
#define HULKBOAT__STATIC HULKBOAT
#define CHEERBOAT__STATIC CHEERBOAT
#define MAMA__STATIC MAMA
#define MAMACLOUD__STATIC MAMACLOUD
#define COOTPLAY__STATIC COOTPLAY
#define BILLYPLAY__STATIC BILLYPLAY
//*/



#define INNERJAW__STATIC INNERJAW

#define EXPLOSION2__STATIC EXPLOSION2

#define CANNONBALL__STATIC CANNONBALL


#define EXPLOSION2BOT__STATIC EXPLOSION2BOT

#define USERWEAPON__STATIC USERWEAPON

#define HEADERBAR__STATIC HEADERBAR

#define JIBS1__STATIC JIBS1

#define JIBS2__STATIC JIBS2

#define JIBS3__STATIC JIBS3

#define JIBS4__STATIC JIBS4

#define JIBS5__STATIC JIBS5

#define BURNING__STATIC BURNING

#define FIRE__STATIC FIRE

#define JIBS6__STATIC JIBS6

#define BLOODSPLAT1__STATIC BLOODSPLAT1

#define BLOODSPLAT3__STATIC BLOODSPLAT3

#define BLOODSPLAT2__STATIC BLOODSPLAT2

#define BLOODSPLAT4__STATIC BLOODSPLAT4

#define OOZ__STATIC OOZ

#define OOZ2__STATIC OOZ2

#define WALLBLOOD1__STATIC WALLBLOOD1

#define WALLBLOOD2__STATIC WALLBLOOD2

#define WALLBLOOD3__STATIC WALLBLOOD3

#define WALLBLOOD4__STATIC WALLBLOOD4

#define WALLBLOOD5__STATIC WALLBLOOD5

#define WALLBLOOD6__STATIC WALLBLOOD6

#define WALLBLOOD7__STATIC WALLBLOOD7

#define WALLBLOOD8__STATIC WALLBLOOD8

#define BURNING2__STATIC BURNING2

#define FIRE2__STATIC FIRE2

#define CRACKKNUCKLES__STATIC CRACKKNUCKLES

#define SMALLSMOKE__STATIC SMALLSMOKE

#define SMALLSMOKEMAKER__STATIC SMALLSMOKEMAKER

#define FLOORFLAME__STATIC FLOORFLAME

#define ROTATEGUN__STATIC ROTATEGUN

#define GREENSLIME__STATIC GREENSLIME

#define WATERDRIPSPLASH__STATIC WATERDRIPSPLASH

#define SCRAP6__STATIC SCRAP6

#define SCRAP1__STATIC SCRAP1

#define SCRAP2__STATIC SCRAP2

#define SCRAP3__STATIC SCRAP3

#define SCRAP4__STATIC SCRAP4

#define SCRAP5__STATIC SCRAP5

#define ORGANTIC__STATIC ORGANTIC

#define BETAVERSION__STATIC BETAVERSION

#define PLAYERISHERE__STATIC PLAYERISHERE

#define PLAYERWASHERE__STATIC PLAYERWASHERE

#define SELECTDIR__STATIC SELECTDIR

#define F1HELP__STATIC F1HELP

#define NOTCHON__STATIC NOTCHON

#define NOTCHOFF__STATIC NOTCHOFF

#define GROWSPARK__STATIC GROWSPARK

#define DUKEICON__STATIC DUKEICON

#define BADGUYICON__STATIC BADGUYICON

#define FOODICON__STATIC FOODICON

#define GETICON__STATIC GETICON

#define MENUSCREEN__STATIC MENUSCREEN

#define MENUBAR__STATIC MENUBAR

#define KILLSICON__STATIC KILLSICON

#define FIRSTAID_ICON__STATIC FIRSTAID_ICON

#define HEAT_ICON__STATIC HEAT_ICON

#define BOTTOMSTATUSBAR__STATIC BOTTOMSTATUSBAR

#define BOOT_ICON__STATIC BOOT_ICON

#define FRAGBAR__STATIC FRAGBAR

#define JETPACK_ICON__STATIC JETPACK_ICON

#define AIRTANK_ICON__STATIC AIRTANK_ICON

#define STEROIDS_ICON__STATIC STEROIDS_ICON

#define HOLODUKE_ICON__STATIC HOLODUKE_ICON

#define ACCESS_ICON__STATIC ACCESS_ICON

#define DIGITALNUM__STATIC DIGITALNUM

#define DUKECAR__STATIC DUKECAR

#define CAMCORNER__STATIC CAMCORNER

#define CAMLIGHT__STATIC CAMLIGHT

#define LOGO__STATIC LOGO

#define TITLE__STATIC TITLE

#define NUKEWARNINGICON__STATIC NUKEWARNINGICON

#define MOUSECURSOR__STATIC MOUSECURSOR

#define SLIDEBAR__STATIC SLIDEBAR

#define DREALMS__STATIC DREALMS

#define BETASCREEN__STATIC BETASCREEN

#define WINDOWBORDER1__STATIC WINDOWBORDER1

#define TEXTBOX__STATIC TEXTBOX

#define WINDOWBORDER2__STATIC WINDOWBORDER2

#define DUKENUKEM__STATIC DUKENUKEM

#define THREEDEE__STATIC THREEDEE

#define INGAMEDUKETHREEDEE__STATIC INGAMEDUKETHREEDEE

#define TENSCREEN__STATIC TENSCREEN

#define PLUTOPAKSPRITE__STATIC PLUTOPAKSPRITE

#define TEATGUN__STATIC TEATGUN

#define KNEE__STATIC KNEE

#define CROSSHAIR__STATIC CROSSHAIR

#define FIRSTGUN__STATIC FIRSTGUN

#define FIRSTGUNRELOAD__STATIC FIRSTGUNRELOAD

#define FALLINGCLIP__STATIC FALLINGCLIP

#define CLIPINHAND__STATIC CLIPINHAND

#define HAND__STATIC HAND

#define SHELL__STATIC SHELL

#define SHOTGUNSHELL__STATIC SHOTGUNSHELL

#define CHAINGUN__STATIC CHAINGUN

#define RPGGUN__STATIC RPGGUN

#define RPGMUZZLEFLASH__STATIC RPGMUZZLEFLASH

#define BUZSAW__STATIC BUZSAW

#define CATLITE__STATIC CATLITE

#define ALIENARMGUN__STATIC ALIENARMGUN

#define HANDHOLDINGLASER__STATIC HANDHOLDINGLASER

#define TRIPBOMB__STATIC TRIPBOMB

#define LASERLINE__STATIC LASERLINE

#define HANDHOLDINGACCESS__STATIC HANDHOLDINGACCESS

#define HANDREMOTE__STATIC HANDREMOTE

#define HANDTHROW__STATIC HANDTHROW

#define TIP__STATIC TIP

#define GLAIR__STATIC GLAIR

#define SCUBAMASK__STATIC SCUBAMASK

#define SPACEMASK__STATIC SPACEMASK

#define FORCESPHERE__STATIC FORCESPHERE

#define SHOTSPARK1__STATIC SHOTSPARK1

#define RPG__STATIC RPG

#define LASERSITE__STATIC LASERSITE

#define SHOTGUN__STATIC SHOTGUN



#define SPINNINGNUKEICON__STATIC SPINNINGNUKEICON

#define BIGFNTCURSOR__STATIC BIGFNTCURSOR

#define SMALLFNTCURSOR__STATIC SMALLFNTCURSOR

#define STARTALPHANUM__STATIC STARTALPHANUM

#define ENDALPHANUM__STATIC ENDALPHANUM

#define BIGALPHANUM__STATIC BIGALPHANUM

#define BIGPERIOD__STATIC BIGPERIOD

#define BIGCOMMA__STATIC BIGCOMMA

#define BIGX__STATIC BIGX

#define BIGQ__STATIC BIGQ

#define BIGSEMI__STATIC BIGSEMI

#define BIGCOLIN__STATIC BIGCOLIN

#define THREEBYFIVE__STATIC THREEBYFIVE

#define BIGAPPOS__STATIC BIGAPPOS

#define BLANK__STATIC BLANK

#define MINIFONT__STATIC MINIFONT

#define BUTTON1__STATIC BUTTON1

#define GLASS3__STATIC GLASS3

#define RESPAWNMARKERRED__STATIC RESPAWNMARKERRED

#define RESPAWNMARKERYELLOW__STATIC RESPAWNMARKERYELLOW

#define RESPAWNMARKERGREEN__STATIC RESPAWNMARKERGREEN

#define BONUSSCREEN__STATIC BONUSSCREEN

#define VIEWBORDER__STATIC VIEWBORDER

#define VICTORY1__STATIC VICTORY1

#define ORDERING__STATIC ORDERING

#define TEXTSTORY__STATIC TEXTSTORY

#define LOADSCREEN__STATIC LOADSCREEN

#define BORNTOBEWILDSCREEN__STATIC BORNTOBEWILDSCREEN

#define BLIMP__STATIC BLIMP

#define FEM9__STATIC FEM9

#define FOOTPRINT__STATIC FOOTPRINT

#define FRAMEEFFECT1_13__STATIC FRAMEEFFECT1_13

#define POOP__STATIC POOP

#define FRAMEEFFECT1__STATIC FRAMEEFFECT1

#define PANNEL3__STATIC PANNEL3

#define SCREENBREAK14__STATIC SCREENBREAK14

#define SCREENBREAK15__STATIC SCREENBREAK15

#define SCREENBREAK19__STATIC SCREENBREAK19

#define SCREENBREAK16__STATIC SCREENBREAK16

#define SCREENBREAK17__STATIC SCREENBREAK17

#define SCREENBREAK18__STATIC SCREENBREAK18

#define W_TECHWALL11__STATIC W_TECHWALL11

#define W_TECHWALL12__STATIC W_TECHWALL12

#define W_TECHWALL13__STATIC W_TECHWALL13

#define W_TECHWALL14__STATIC W_TECHWALL14

#define W_TECHWALL5__STATIC W_TECHWALL5

#define W_TECHWALL6__STATIC W_TECHWALL6

#define W_TECHWALL7__STATIC W_TECHWALL7

#define W_TECHWALL8__STATIC W_TECHWALL8

#define W_TECHWALL9__STATIC W_TECHWALL9

#define BPANNEL3__STATIC BPANNEL3

#define W_HITTECHWALL16__STATIC W_HITTECHWALL16

#define W_HITTECHWALL10__STATIC W_HITTECHWALL10

#define W_HITTECHWALL15__STATIC W_HITTECHWALL15

#define W_MILKSHELF__STATIC W_MILKSHELF

#define W_MILKSHELFBROKE__STATIC W_MILKSHELFBROKE

#define PURPLELAVA__STATIC PURPLELAVA

#define LAVABUBBLE__STATIC LAVABUBBLE

#define DUKECUTOUT__STATIC DUKECUTOUT

#define TARGET__STATIC TARGET

#define GUNPOWDERBARREL__STATIC GUNPOWDERBARREL

#define DUCK__STATIC DUCK

#define HATRACK__STATIC HATRACK

#define DESKLAMP__STATIC DESKLAMP

#define COFFEEMACHINE__STATIC COFFEEMACHINE

#define CUPS__STATIC CUPS

#define GAVALS__STATIC GAVALS

#define GAVALS2__STATIC GAVALS2

#define POLICELIGHTPOLE__STATIC POLICELIGHTPOLE

#define FLOORBASKET__STATIC FLOORBASKET

#define PUKE__STATIC PUKE

#define DOORTILE23__STATIC DOORTILE23

#define TOPSECRET__STATIC TOPSECRET

#define SPEAKER__STATIC SPEAKER

#define TEDDYBEAR__STATIC TEDDYBEAR

#define ROBOTDOG__STATIC ROBOTDOG

#define ROBOTPIRATE__STATIC ROBOTPIRATE

#define ROBOTMOUSE__STATIC ROBOTMOUSE

#define MAIL__STATIC MAIL

#define MAILBAG__STATIC MAILBAG

#define HOTMEAT__STATIC HOTMEAT

#define COFFEEMUG__STATIC COFFEEMUG

#define DONUTS2__STATIC DONUTS2

#define TRIPODCAMERA__STATIC TRIPODCAMERA

#define METER__STATIC METER

#define DESKPHONE__STATIC DESKPHONE

#define GUMBALLMACHINE__STATIC GUMBALLMACHINE

#define GUMBALLMACHINEBROKE__STATIC GUMBALLMACHINEBROKE

#define PAPER__STATIC PAPER

#define MACE__STATIC MACE

#define GENERICPOLE2__STATIC GENERICPOLE2

#define XXXSTACY__STATIC XXXSTACY

#define WETFLOOR__STATIC WETFLOOR

#define BROOM__STATIC BROOM

#define MOP__STATIC MOP

#define LETTER__STATIC LETTER

#define PIRATE1A__STATIC PIRATE1A

#define PIRATE4A__STATIC PIRATE4A

#define PIRATE2A__STATIC PIRATE2A

#define PIRATE5A__STATIC PIRATE5A

#define PIRATE3A__STATIC PIRATE3A

#define PIRATE6A__STATIC PIRATE6A

#define PIRATEHALF__STATIC PIRATEHALF

#define CHESTOFGOLD__STATIC CHESTOFGOLD

#define SIDEBOLT1__STATIC SIDEBOLT1

#define FOODOBJECT1__STATIC FOODOBJECT1

#define FOODOBJECT2__STATIC FOODOBJECT2

#define FOODOBJECT3__STATIC FOODOBJECT3

#define FOODOBJECT4__STATIC FOODOBJECT4

#define FOODOBJECT5__STATIC FOODOBJECT5

#define FOODOBJECT6__STATIC FOODOBJECT6

#define FOODOBJECT7__STATIC FOODOBJECT7

#define FOODOBJECT8__STATIC FOODOBJECT8

#define FOODOBJECT9__STATIC FOODOBJECT9

#define FOODOBJECT10__STATIC FOODOBJECT10

#define FOODOBJECT11__STATIC FOODOBJECT11

#define FOODOBJECT12__STATIC FOODOBJECT12

#define FOODOBJECT13__STATIC FOODOBJECT13

#define FOODOBJECT14__STATIC FOODOBJECT14

#define FOODOBJECT15__STATIC FOODOBJECT15

#define FOODOBJECT16__STATIC FOODOBJECT16

#define FOODOBJECT17__STATIC FOODOBJECT17

#define FOODOBJECT18__STATIC FOODOBJECT18

#define FOODOBJECT19__STATIC FOODOBJECT19

#define FOODOBJECT20__STATIC FOODOBJECT20

#define HEADLAMP__STATIC HEADLAMP

#define TAMPON__STATIC TAMPON

#define SKINNEDCHICKEN__STATIC SKINNEDCHICKEN

#define FEATHEREDCHICKEN__STATIC FEATHEREDCHICKEN

#define ROBOTDOG2__STATIC ROBOTDOG2

#define JOLLYMEAL__STATIC JOLLYMEAL

#define DUKEBURGER__STATIC DUKEBURGER

#define SHOPPINGCART__STATIC SHOPPINGCART

#define CANWITHSOMETHING2__STATIC CANWITHSOMETHING2

#define CANWITHSOMETHING3__STATIC CANWITHSOMETHING3

#define CANWITHSOMETHING4__STATIC CANWITHSOMETHING4

#define SNAKEP__STATIC SNAKEP

#define DOLPHIN1__STATIC DOLPHIN1

#define DOLPHIN2__STATIC DOLPHIN2

#define NEWBEAST__STATIC NEWBEAST

#define NEWBEASTSTAYPUT__STATIC NEWBEASTSTAYPUT

#define NEWBEASTJUMP__STATIC NEWBEASTJUMP

#define NEWBEASTHANG__STATIC NEWBEASTHANG

#define NEWBEASTHANGDEAD__STATIC NEWBEASTHANGDEAD

#define BOSS4__STATIC BOSS4

#define BOSS4STAYPUT__STATIC BOSS4STAYPUT

#define FEM10__STATIC FEM10

#define TOUGHGAL__STATIC TOUGHGAL

#define MAN__STATIC MAN

#define MAN2__STATIC MAN2

#define WOMAN__STATIC WOMAN

#define PLEASEWAIT__STATIC PLEASEWAIT

#define NATURALLIGHTNING__STATIC NATURALLIGHTNING

#define WEATHERWARN__STATIC WEATHERWARN

#define DUKETAG__STATIC DUKETAG

#define SIGN1__STATIC SIGN1

#define SIGN2__STATIC SIGN2

#define JURYGUY__STATIC JURYGUY

#define RESERVEDSLOT1__STATIC RESERVEDSLOT1

#define RESERVEDSLOT2__STATIC RESERVEDSLOT2

#define RESERVEDSLOT3__STATIC RESERVEDSLOT3

#define RESERVEDSLOT4__STATIC RESERVEDSLOT4

#define RESERVEDSLOT5__STATIC RESERVEDSLOT5

#define RESERVEDSLOT6__STATIC RESERVEDSLOT6

#define RESERVEDSLOT7__STATIC RESERVEDSLOT7

#define RESERVEDSLOT8__STATIC RESERVEDSLOT8

#define RESERVEDSLOT9__STATIC RESERVEDSLOT9

#define RESERVEDSLOT10__STATIC RESERVEDSLOT10

#define RESERVEDSLOT11__STATIC RESERVEDSLOT11

#define RESERVEDSLOT12__STATIC RESERVEDSLOT12
extern int16_t DynamicTileMap[MAXTILES];
