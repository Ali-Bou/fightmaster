// Header file of gamedata that includes all the fields of this class and its methods
// gamedata is a class that deals with general data of the game and the management of that data.
// The current important game data used are _time, which returns the game days passed and _game_state
// which defines what options the user is allowed to select during the game (based on the game's state)
// The methods allow for the manipulation of the gamedata fields and the management of the data of a certain
// game being ran including data from the class character.
#ifndef _GAMEDATA_H
#define _GAMEDATA_H

#include "character.h"
#include <string>
#include <memory>

using namespace std; // remove later to use std::

class gamedata {
    private:
    // private fields of class gamedata
    int _time;
    int _game_state;

    public:
    //constructor
    gamedata();
    //creates a unique pointer of type character
    unique_ptr<character> player1;
    //creates a unique pointer of type character
    unique_ptr<character> player2;
    // method to serialise data of the gamedata class
    string serialize_gamedata();
    // method to deserialise data of the gamedata class
    int deserialize_gamedata(string serialdata);
    // method to load a saved file along with all the saved data including the data from the character class
    void loadgame();
    // method to save the game's data to a file including  all the data along with the data from the character class
    void savegame();
    // method to exit game
    void exitgame ();
    // method that sets a new value to the class field _game_state
    void set_game_state(int game_state);
    // get the value of _game_state 
    int get_name_state();
    // method that displays the game's menu options to the player.
    int menu();
    // method to increase the game days passed
    void inc_time();
    // method to display the game days passed
    void display_time();
};

#endif