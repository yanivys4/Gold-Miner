# Gold-Miner

Gold Miner Project
********************************************************************************************

Yaniv Shoham  ;  Dvir Datner 

********************************************************************************************
run on x86

#Description of the program:
The program runs the classic game Gold Miner.
The board of the game is a big mine including different kind of objects: regular rocks,
golden rocks, diamond rocks, tnt barrels and surprise bags.
On the top of the mine there are two miners(players) which have a hook that keeps moving left
and right and waiting to be sent and mine, each player has it's score and number of dynamites.
The player can decide to send the hook or to send a dynamite after an object is already grabbed 
and explod it and therefore to ignore that object and keep playing.
The game includes 3 different levels with different times and objects,Each level ends when 
the time is over or when the board is left empty.
The purpose of the game is to achieve as much coins possible and to beat the other player 
in the conclusion of the whole game.
There are two modes of play:
Single player - play against the Computer.
Multi player - 2 human players playing against each other. 

There are 3 different sizes on the board: small, regular and big.
Each of the rocks has two main attributes: weight and value. the weight and value naturally
derives from the size of the rock. as much the rock is bigger it is heavier and more worty.
All of the golden rocks are more worthy than all of the regular rocks (the smallest golden
rock worth more than the biggest regular rock).
The diamond rock worth more than all the other rocks and it's size is constant small.
The tnt barrel has no value and its purpose is to explode when touched and explode other objects 
surrounded.
The surprise bag includes 3 different features:
Freeze: this surprise freeze the player for certain amount of time and prevent him to keep
play.
extra coins: gives the player a reward of 500 coins.
extra dynamite


********************************************************************************************
#There are in total 48 classes:

main - runs the program using controller object.
Controller - controls the program sessions of games.
GameController - runs a single game session, contains 2 players.
LevelController - runs a single level. contains: board, toolbar, pauseMenu, and holds
2 pointers for the 2 players.
Board - holds the board of play(the mine) which it is a vector of BoardObject and respponsible
of it.
ToolBar - holds the visual objects that are showed in each level which are the scores,
the dynamite indicators and the clock. in addition holds the pause button.

Button - an abstract class of button.

==========================================================================================
Derive from Button:
ExitButton - activates exit from game.
HomeButton - placed in PauseMenu and ressponsibble to close the pause menu and go back to 
home menu.
PauseButton - activates pause game and afterwards makes the program to open the PauseMenu.
ContinueButton - placed in SummaryMenu and respponsible to finish the summary menu 
and start play the level.
ResumeButton - placed in PauseMenu and ressponsible to close the pause menu and resume 
the paused level.
MuteButton - activates mute/unmute music in game.
SinglePlayerButton - activates the single player option of playing against a ComputerPlayer.
MultiPlayerButton - activates the multi player option.
==========================================================================================

Menu - abstract class for menu holds background and vector of buttons.

==========================================================================================
derive from Menu:
HomeMenu - contains MuteButton
PauseMenu - a menu that activates during the play of level. contains ExitButton,
ResumeButton, MuteButton, and HomeMenu.
SummaryMenu - a menu that appears between levels and shows the present points of the two 
players. contains ContinueButton.
GameOverMenu - a menu that appears at the end of the game. contains two buttons: ExitBUtton and 
HomeButton. 
==========================================================================================

Factory - a class that create BoardObjects in a factory design pattern.
Animation - a class that play animation to the objects that holds it.
Textures - a singelton class that contains all of the program textures.
Sounds -  a singelton class that contains all of the program sounds and music.

Object - an abstract class of object that has rectangleShape member.

==========================================================================================
Derive from Object:
BoardObject - an abstract class that represents an object that is found on the board.

==========================================================================================
Derive from BoardObject:
Rock - an abstract class of general Rock.
==========================================================================================
Derive from Rock:
GoldenRock - derives from Rock.
RegularRock - derives from Rock.
DiamondRock - derives from Rock.
each of the classes that derives from Rock has it's own texture, value and etc.
==========================================================================================
SurpriseBag - a class that represents the surprise bag holds the kind of feature that hidden
inside. the feature is chosen randommly when creating the object.
==========================================================================================
Barrel - a class that represents the barrel board object.
==========================================================================================

Dynamite - an object that thrown by the player.
VisualObject - an abstract class of visual object used only for interface. holds font and
text members.

==========================================================================================
Derive from VisualObject:
DynamiteIndicator - shows the number of dynamites a player has.
Score - shows the score of a player (number of coins).
Clock - shows the time remains in a certain level.
LevelIndicator - shows the number of the current played level.
==========================================================================================

Hook - an object that is holded by each player and controlled by the player.
the hook is respponsible to be sent by the player to the mine board and intersect with the
BoardObjects grab them and to be a link factor between the grabbed object to the player.
the hook rotates right and left as long as the player hasn't send it.
===========================================================================================

Player - an abstract class of player. contains mine and throw dynamite animations, rectangle
shape, hook, rewardSound, Dynamite.

===========================================================================================
Derive from Player:
HumanPlayer : represents a human player controlled by the input of the keyboard.
has spacific play method, and use it's textures and animations.
ComputerPlayer : represents a computer player controlled by unique algorithm. use it's own
textures and animations.

===========================================================================================

BoardSettings : static class holds the settings and  const data of Board.
AnimationSettings : static class holds the settings and const data of Animation.
ButtonSettings : static class holds the settings and const data of Button.
HookSettings: static class holds the settings and const data of Hook.
PlayerSettings : static class holds the settings and const data of Player.
VisualObjectSettings : static class holds settings and the const data of VisualObject.
TexturesSettings: header file holds const data of Textures.
SoundsSettings : header file holds const data of Sounds.

********************************************************************************************

Algorithems worth mention:

findBestAngle function used in play method of ComputerPlayer. 
The function fakes play of hook in all the possible angles and choose the angle that the
computer player should send the hook so it will get the best reward. 

play function of the ComputerPlayer decides whether to use the findBestAngle algorithm randomly.
the chance to choose the smart algorithm is getting higher as the level is more progressive. 


********************************************************************************************
Data Structures used:
std::vector, std::map, std::pair

********************************************************************************************
