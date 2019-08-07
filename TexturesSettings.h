#pragma once

#include <experimental/vector>
#include <experimental/string>

const size_t NUM_OF_TEXTURES = 32;

const enum texturesNames {
	COMP_MINING_TN, COMP_THROW_TN, DIAMOND_ROCK_TN, EXIT_BUTTON_TN
	, GOLDEN_ROCK_TN, HOME_BUTTON_TN, HOME_MENU_TN, LEVEL_BACKGROUND_TN,
	MUTE_BUTTON_TN, CONTINUE_BUTTON_TN, PLAYER_MINING_TN, PLAYER_THROW_TN, REGULAR_ROCK_TN,
	RESUME_BUTTON_TN, SURPRISE_BAG_TN, UNMUTE_BUTTON_TN,
	PAUSE_MENU_TN, SUMMARY_MENU_TN, HOOK_TN, PAUSE_BUTTON_TN, DYNAMITE_TN, CLOCK_TN, LEVEL_INDICATOR_TN,
	COIN_TN, HALF_HOOK_TN, EXPLOSION_TN, FROZEN_PLAYER_TN, FROZEN_COMP_TN, BARREL_TN, SINGLE_PLAYER_TN, MULTI_PLAYER_TN,
	GAME_OVER_BACK_TN
};

const std::vector<std::string> texturesImages = { "Images/CompMining.png",
												 "Images/CompThrow.png",
												 "Images/DiamondRock.png",
												 "Images/ExitButton.png",
												 "Images/GoldenRock.png",
												 "Images/HomeButton.png",
												 "Images/HomeMenu.png",
												 "Images/LevelBackground.png",
												 "Images/MuteButton.png",
												 "Images/ContinueButton.png",
												 "Images/PlayerMining.png",
												 "Images/PlayerThrow.png",
												 "Images/RegularRock.png",
												 "Images/ResumeButton.png",
												 "Images/SurpriseBag.png",
												 "Images/UnmuteButton.png",
												 "Images/PauseMenu.png",
												 "Images/SummaryMenu.png",
												 "Images/Hook.png",
												 "Images/PauseButton.png",
												 "Images/Dynamite.png" ,
												 "Images/Clock.png" ,
												 "Images/LevelIndicator.png",
												 "Images/Coin.png",
												 "Images/HalfHook.png",
												 "Images/Explosion.png",
												 "Images/FrozenPlayer.png", 
												 "Images/FrozenComp.png", 
												 "Images/Barrel.png",
												 "Images/SinglePlayer.png" , 
												 "Images/MultiPlayer.png",
												 "Images/GameOverBack.png" };