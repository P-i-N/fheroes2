

fheroes2::GameMode Game::SelectScenarioEx( const uint8_t humanPlayerCount )
{
    assert( humanPlayerCount >= 1 && humanPlayerCount <= 6 );

    AudioManager::PlayMusicAsync( MUS::MAINMENU, Music::PlaybackMode::RESUME_AND_PLAY_INFINITE );

    const MapsFileInfoList maps = Maps::getAllMapFileInfos( false, humanPlayerCount );
    if ( maps.empty() ) {
        fheroes2::showStandardTextMessage( _( "Warning" ), _( "No maps available!" ), Dialog::OK );
        return fheroes2::GameMode::MAIN_MENU;
    }

    // We must release UI resources for this window before loading a new map. That's why all UI logic is in a separate function.
    const fheroes2::GameMode result = ChooseNewMap( maps, humanPlayerCount );
    if ( result != fheroes2::GameMode::START_GAME ) {
        return result;
    }

    return LoadNewMap();
}
