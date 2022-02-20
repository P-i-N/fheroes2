/***************************************************************************
 *   Free Heroes of Might and Magic II: https://github.com/ihhub/fheroes2  *
 *   Copyright (C) 2019 - 2022                                             *
 *                                                                         *
 *   Free Heroes2 Engine: http://sourceforge.net/projects/fheroes2         *
 *   Copyright (C) 2009 by Andrey Afletdinov <fheroes2@gmail.com>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef H2M82_H
#define H2M82_H

#include "mp2.h"
#include "types.h"
#include <cstddef>

#define LOOPXX_COUNT 28

namespace M82
{
    enum
    {
        AELMATTK,
        AELMKILL,
        AELMMOVE,
        AELMWNCE,
        ANTIMAGK,
        ARCHATTK,
        ARCHKILL,
        ARCHMOVE,
        ARCHSHOT,
        ARCHWNCE,
        ARMGEDN,
        BADLUCK,
        BADMRLE,
        BERZERK,
        BLESS,
        BLIND,
        BLOODLUS,
        BOARATTK,
        BOARKILL,
        BOARMOVE,
        BOARWNCE,
        BONEATTK,
        BONEKILL,
        BONEMOVE,
        BONEWNCE,
        BUILDTWN,
        CATSND00,
        CATSND02,
        CAVLATTK,
        CAVLKILL,
        CAVLMOVE,
        CAVLWNCE,
        CHAINLTE,
        CNTRATTK,
        CNTRKILL,
        CNTRMOVE,
        CNTRSHOT,
        CNTRWNCE,
        COLDRAY,
        COLDRING,
        CURE,
        CURSE,
        CYCLATTK,
        CYCLKILL,
        CYCLMOVE,
        CYCLWNCE,
        DIGSOUND,
        DIPMAGK,
        DISRUPTR,
        DRAWBRG,
        DRGNATTK,
        DRGNKILL,
        DRGNMOVE,
        DRGNSLAY,
        DRGNWNCE,
        DRUIATTK,
        DRUIKILL,
        DRUIMOVE,
        DRUISHOT,
        DRUIWNCE,
        DWRFATTK,
        DWRFKILL,
        DWRFMOVE,
        DWRFWNCE,
        EELMATTK,
        EELMKILL,
        EELMMOVE,
        EELMWNCE,
        ELF_ATTK,
        ELF_KILL,
        ELF_MOVE,
        ELF_SHOT,
        ELF_WNCE,
        ERTHQUAK,
        EXPERNCE,
        FELMATTK,
        FELMKILL,
        FELMMOVE,
        FELMWNCE,
        FIREBALL,
        GARGATTK,
        GARGKILL,
        GARGMOVE,
        GARGWNCE,
        GBLNATTK,
        GBLNKILL,
        GBLNMOVE,
        GBLNWNCE,
        GENIATTK,
        GENIKILL,
        GENIMOVE,
        GENIWNCE,
        GHSTATTK,
        GHSTKILL,
        GHSTMOVE,
        GHSTWNCE,
        GOLMATTK,
        GOLMKILL,
        GOLMMOVE,
        GOLMWNCE,
        GOODLUCK,
        GOODMRLE,
        GRIFATTK,
        GRIFKILL,
        GRIFMOVE,
        GRIFWNCE,
        H2MINE,
        HALFATTK,
        HALFKILL,
        HALFMOVE,
        HALFSHOT,
        HALFWNCE,
        HASTE,
        HYDRATTK,
        HYDRKILL,
        HYDRMOVE,
        HYDRWNCE,
        HYPNOTIZ,
        KEEPSHOT,
        KILLFADE,
        LICHATTK,
        LICHEXPL,
        LICHKILL,
        LICHMOVE,
        LICHSHOT,
        LICHWNCE,
        LIGHTBLT,
        LOOP0000,
        LOOP0001,
        LOOP0002,
        LOOP0003,
        LOOP0004,
        LOOP0005,
        LOOP0006,
        LOOP0007,
        LOOP0008,
        LOOP0009,
        LOOP0010,
        LOOP0011,
        LOOP0012,
        LOOP0013,
        LOOP0014,
        LOOP0015,
        LOOP0016,
        LOOP0017,
        LOOP0018,
        LOOP0019,
        LOOP0020,
        LOOP0021,
        LOOP0022,
        LOOP0023,
        LOOP0024,
        LOOP0025,
        LOOP0026,
        LOOP0027,
        MAGCAROW,
        MAGEATTK,
        MAGEKILL,
        MAGEMOVE,
        MAGESHOT,
        MAGEWNCE,
        MASSBLES,
        MASSCURE,
        MASSCURS,
        MASSHAST,
        MASSSHIE,
        MASSSLOW,
        MEDSATTK,
        MEDSKILL,
        MEDSMOVE,
        MEDSWNCE,
        METEOR,
        MINOATTK,
        MINOKILL,
        MINOMOVE,
        MINOWNCE,
        MIRRORIM,
        MNRDEATH,
        MUMYATTK,
        MUMYKILL,
        MUMYMOVE,
        MUMYWNCE,
        NMADATTK,
        NMADKILL,
        NMADMOVE,
        NMADWNCE,
        NWHEROLV,
        OGREATTK,
        OGREKILL,
        OGREMOVE,
        OGREWNCE,
        ORC_ATTK,
        ORC_KILL,
        ORC_MOVE,
        ORC_SHOT,
        ORC_WNCE,
        PARALIZE,
        PHOEATTK,
        PHOEKILL,
        PHOEMOVE,
        PHOEWNCE,
        PICKUP01,
        PICKUP02,
        PICKUP03,
        PICKUP04,
        PICKUP05,
        PICKUP06,
        PICKUP07,
        PIKEATTK,
        PIKEKILL,
        PIKEMOVE,
        PIKEWNCE,
        PLDNATTK,
        PLDNKILL,
        PLDNMOVE,
        PLDNWNCE,
        PREBATTL,
        PROTECT,
        PSNTATTK,
        PSNTKILL,
        PSNTMOVE,
        PSNTWNCE,
        RESURECT,
        RESURTRU,
        ROC_ATTK,
        ROC_KILL,
        ROC_MOVE,
        ROC_WNCE,
        ROGUATTK,
        ROGUKILL,
        ROGUMOVE,
        ROGUWNCE,
        RSBRYFZL,
        SHIELD,
        SKELATTK,
        SKELKILL,
        SKELMOVE,
        SKELWNCE,
        SLOW,
        SPRTATTK,
        SPRTKILL,
        SPRTMOVE,
        SPRTWNCE,
        STELSKIN,
        STONESKI,
        STONSKIN,
        STORM,
        SUMNELM,
        SWDMATTK,
        SWDMKILL,
        SWDMMOVE,
        SWDMWNCE,
        TELEIN,
        TELPTIN,
        TELPTOUT,
        TITNATTK,
        TITNKILL,
        TITNMOVE,
        TITNSHOT,
        TITNWNCE,
        TREASURE,
        TRLLATTK,
        TRLLKILL,
        TRLLMOVE,
        TRLLSHOT,
        TRLLWNCE,
        UNICATTK,
        UNICKILL,
        UNICMOVE,
        UNICWNCE,
        VAMPATTK,
        VAMPEXT1,
        VAMPEXT2,
        VAMPKILL,
        VAMPMOVE,
        VAMPWNCE,
        WELMATTK,
        WELMKILL,
        WELMMOVE,
        WELMWNCE,
        WOLFATTK,
        WOLFKILL,
        WOLFMOVE,
        WOLFWNCE,
        WSND00,
        WSND01,
        WSND02,
        WSND03,
        WSND04,
        WSND05,
        WSND06,
        WSND10,
        WSND11,
        WSND12,
        WSND13,
        WSND14,
        WSND15,
        WSND16,
        WSND20,
        WSND21,
        WSND22,
        WSND23,
        WSND24,
        WSND25,
        WSND26,
        ZOMBATTK,
        ZOMBKILL,
        ZOMBMOVE,
        ZOMBWNCE,

        UNKNOWN
    };

    const char * GetString( int );
    int FromSpell( int );
    u32 GetIndexLOOP00XXFromObject( const MP2::MapObjectType objectType );
    int GetLOOP00XX( const size_t index );
}

#endif
