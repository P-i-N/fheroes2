/***************************************************************************
 *   fheroes2: https://github.com/ihhub/fheroes2                           *
 *   Copyright (C) 2019 - 2024                                             *
 *                                                                         *
 *   Free Heroes2 Engine: http://sourceforge.net/projects/fheroes2         *
 *   Copyright (C) 2011 by Andrey Afletdinov <fheroes2@gmail.com>          *
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

#pragma once

#include <vector>

namespace Game
{
    struct Modifiers
    {
        std::vector<int> blacklistedSecondarySkills;
        bool allowWarlockNecromancy = true;
        bool freeBoatEmbarkation = false; // Allow to embark/disembark on a boat without loss of movement points
        bool allowArtifactDismiss = false;
        bool allowFriendlyCapture = false; // Allow recapturing of ally objects
        int treasureChestArtLevel = 0x01; // Flags of allowed artifact types in treasure chests
        int movementScaling = 100; // Movement scaling factor (100% = no scaling)
        std::vector<int> blacklistedRandomArtifacts;
        std::vector<int32_t> extraCumulativeBonuses;
        std::vector<int> blacklistedSpells;
    };

    // Get the current modifiers
    const Modifiers & GetModifiers();

    // Set new game modifiers. You might want to call this function before loading
    // a map or starting a new game. Otherwise, not all modifiers will be applied.
    void SetModifiers( const Modifiers & modifiers );

    // Set default modifiers
    void SetDefaultModifiers();

} // namespace Game
