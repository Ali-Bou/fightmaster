// character is a header file that hold the class character with all its fields and methods. It manages and 
// manipulates all the data directly related to an object of this class. Hence of the players created with 
// their names, health points, etc...
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <string>

using namespace std;

class character {

    private:
    // fields of this class

    //name of player
    string _name;
    //attack points
    int _attack_p;
    //defense points
    int _defense_p;
    // health points
    int _hp;
    // maximum healthpoints
    int _max_hp;
    // type of the player (computer or human to allow multiplayer or singleplayer options)
    string _type;

    public:

    //constructor
    character ();


    // method to set the name of the player
    void set_name(string name);
    
    // method to set the type of the player
    void set_type(string type);

    // method to get the name of the player
    string get_name();

    // method to get the type of the player
    string get_type();

    // gets the attack points of the player
    int get_attack_p();

    // returns the defense points of the player
    int get_defense_p();

    // returns the health points of the player
    int get_hp();

    // returns the maximum healthpoints possible
    int get_max_hp();

    // displays the player's stats (fields of this class)
    void show_stats();

    // allows the player to rest between fights to restore strength
    void rest_character();

    // returns the type of attack selected by a player
    int attack_type();

    void display_attack(int att_launched);

    // returns the type of defense selected by a player
    int defense_type(int attk_type);

    void display_defence(int def_launched);

    int attack_ramifications(int attack_launched);

    // calculates the inflicted damage based on the players' attack and defense types 
    // subtracts the damage from the defending player's health points
    int inflict_damage(int def, int att, int att_inflicted);

    // increases attack points by a certain number after every round as a form of restoration 
    // to maintain the player's ability to complete a game
    void inc_attack_p();

    // increases attack points by a certain number after every round to maintain the player's 
    // ability to complete a game
    void inc_defence_p();

    // checks the player's healthpoints to determine if a game is over
    int check_status();

    //serialises the data to be saved as a string in a file
    string serialize();

    // deserialises data loaded from a saved file and sets the data to their corresponding class fields
    int deserialize(string serialdata); /*returns 0 on success*/
};


#endif