#include "game_modifiers.h"

#include "artifact.h"
#include "skill.h"
#include "spell.h"

namespace
{
    Game::Modifiers gameModifiers;
}

const Game::Modifiers & Game::GetModifiers()
{
    return gameModifiers;
}

void Game::SetModifiers( const Game::Modifiers & modifiers )
{
    gameModifiers = modifiers;
}

void Game::SetDefaultModifiers()
{
    Game::Modifiers mods;
    mods.blacklistedSecondarySkills = { Skill::Secondary::EAGLE_EYE }; // Enough with this useless s#!t!
    mods.allowWarlockNecromancy = false;
    mods.freeBoatEmbarkation = true;
    mods.allowArtifactDismiss = true;
    mods.allowFriendlyCapture = true;
    mods.treasureChestArtLevel = Artifact::ART_LEVEL_MAJOR;
    mods.movementScaling = 500;

    int blacklistedRandomArtifacts[] = {
        Artifact::ICE_CLOAK,        Artifact::FIRE_CLOAK,        Artifact::ENCHANTED_HOURGLASS,
        Artifact::HOLY_PENDANT,     Artifact::PENDANT_FREE_WILL, Artifact::PENDANT_LIFE,
        Artifact::SERENITY_PENDANT, Artifact::KINETIC_PENDANT,   Artifact::PENDANT_DEATH,
        Artifact::GOLDEN_BOW,       Artifact::TELESCOPE,         Artifact::STATESMAN_QUILL,
        Artifact::EVIL_EYE,         Artifact::GOLD_WATCH,        Artifact::SKULLCAP,
        Artifact::AMMO_CART,        Artifact::BALLISTA,          Artifact::WAND_NEGATION,
        Artifact::WIZARD_HAT,
        //
    };

    mods.blacklistedRandomArtifacts.clear();
    for ( int artifactID : blacklistedRandomArtifacts )
        mods.blacklistedRandomArtifacts.push_back( artifactID );

    fheroes2::ArtifactBonusType extraCumulativeBonuses[] = {
        fheroes2::ArtifactBonusType::MORALE,
        fheroes2::ArtifactBonusType::LUCK,
        fheroes2::ArtifactBonusType::SEA_BATTLE_MORALE_BOOST,
        fheroes2::ArtifactBonusType::SEA_BATTLE_LUCK_BOOST,
        fheroes2::ArtifactBonusType::LAND_MOBILITY,
        fheroes2::ArtifactBonusType::SEA_MOBILITY,
        fheroes2::ArtifactBonusType::SPELL_POINTS_DAILY_GENERATION,
        fheroes2::ArtifactBonusType::EVERY_COMBAT_SPELL_DURATION,
        fheroes2::ArtifactBonusType::EXTRA_CATAPULT_SHOTS,
        fheroes2::ArtifactBonusType::AREA_REVEAL_DISTANCE,
        fheroes2::ArtifactBonusType::NECROMANCY_SKILL,
    };

    mods.extraCumulativeBonuses.clear();
    for ( auto bonus : extraCumulativeBonuses )
        mods.extraCumulativeBonuses.push_back( static_cast<int32_t>( bonus ) );

    int blacklistedSpells[] = {
        Spell::BLOODLUST, Spell::CURSE,    Spell::VIEWMINES, Spell::VIEWRESOURCES, Spell::DISRUPTINGRAY, Spell::DRAGONSLAYER, Spell::HAUNT,    Spell::VIEWARTIFACTS,
        Spell::VISIONS,   Spell::COLDRING, Spell::MASSCURSE, Spell::IDENTIFYHERO,  Spell::VIEWHEROES,    Spell::VIEWTOWNS,    Spell::BERSERKER
        //
    };

    mods.blacklistedSpells.clear();
    for ( int spellID : blacklistedSpells )
        mods.blacklistedSpells.push_back( spellID );

    SetModifiers( mods );
}
