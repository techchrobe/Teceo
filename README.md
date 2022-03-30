# Teceo
Teceo Engine and GameOver game

by Christina Obereigner

## How to build:
Simply run the GenerateProjects.bat file.

## Base Engine
Setup, Logging, Event System and Window were done according to the "The Cherno" videos.

## Own additional Implementations
Own additional Implementations can be found in Teceo\src\Teceo in the GameObjects and States folder.

### Component based Game Objects
Components can be added and removed from Game Objects. Additionally it can be searched for specific Game Objects.
The Game Objects are handled by a Game Object Manager (Singleton). It adds, removes and updates the Game Obejcts.
A test Game Object with a test Component is created when starting the game.

### States
States were added together with a simple Game Loop with deltaTime (see Application.cpp). Each State has it's own function for init, update and exit.
States act like separate "Scenes" each state contains their own Game Object Manager.
Game Objects are created during Init and updated in Update.
A test State that initializes the test Game Object is created when starting the game.
