#include "character.h"
#include "gamedata.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std; //change to using std::

// sets the initial values of the class fields.
character :: character() : _name("player"), _type("human"), _hp(100), _max_hp(100), _attack_p(100), _defense_p(100)  {
    
}

// sets the name of the player _name to the inputted string argument's value
void character :: set_name(string name) {
    
    _name = name;

}

// sets the name of the player _type to the inputted string argument's value
void character :: set_type(string type) {

    _type = type;

}

// returns the player's name
string character :: get_name() {

     return _name;
}

// returns the player's type
string character :: get_type() {

    return _type;
}

// returns the player's attack points
int character :: get_attack_p() {

    return _attack_p;
}

// returns the player's defense points
int character :: get_defense_p() {

    return _defense_p;
}

// returns the player's health points
int character :: get_hp() {

    return _hp;
}

// returns the player's maximum health points
int character :: get_max_hp() {

    return _max_hp;
}

// method to display the player's stats
void character :: show_stats() {
   
   cout << " " << endl;
   cout << "Character's Name: " << _name << ", Health Points: " << _hp
   << ", Attack Points: " << _attack_p << ", Defense Points: " << _defense_p 
   << ", Max Health Points: " << _max_hp << ", Character Type: " << _type << endl;
   cout << " " << endl;

}

// methods to rest player: restores player health points, attack and defense points, while taking one game day
// to do so (this is performed displayed in the main function)
void character :: rest_character() {

    _hp = _max_hp;
    _attack_p = 100;
    _defense_p = 100;

}

// method that allows the player to select the type of attack they want to launch
// The player can only select a certain attack if they have enough attack points
// Function also checks for the players input validity
int character :: attack_type() {

    // creates an integer referencing the type of attack to be chosen
    int att_type;

    // if the type of the player's character is human, a message will be displayed to choose an attack type
    if (_type == "human") {

        // boolean to check selection validity and rerun the options using a loop if an incorrect selection is made
        int check_selection_validity = 0;

        while (check_selection_validity == 0) { 

            // if player's attack points are more than 12, they can choose from all three attack options
            if (_attack_p >= 12) {
               
                cout << " " << endl;
                cout << _name << "! Choose one of the following attack methods: 1 for arrow, 2 for sword, 3 for spear." << endl;
                cout << " " << endl;
                cin >> att_type;
                
                //selection correct returns the attack type selected 
                if (att_type == 1 || att_type == 2 || att_type == 3) {

                    // sets boolean to 1 to end loop
                    check_selection_validity = 1;
                    return att_type;
                }

                // incorrect selection keeps boolean value at zero and the loop is reran
                else {

                    check_selection_validity = 0;
                }
            }

            // if player's attack points are more or equal to 10 but less than 12, only 2 attack options
            // can be chosen
            if (_attack_p < 12 && _attack_p >= 10) {
               
                cout << " " << endl;
                cout << _name << "! Your attack points are less than 12. You can only choose one of the following attack methods: 1 for arrow, 2 for sword." << endl;
                cout << " " << endl;
                cin >> att_type;

                // if correct selection, set boolean to 1 to end loop and return the attack type selected
                if (att_type == 1 || att_type == 2) {

                    check_selection_validity = 1;
                    return att_type;
                }

                // if incorrect selection keep boolean at zero and rerun the loop
                else {

                    check_selection_validity = 0;
                }
            }

            // if the attack points are less than 10 and greater than or equal to 6, only one attack option
            // can be selected
            if (_attack_p < 10 && _attack_p >= 6) {
                
                cout << " " << endl;
                cout << _name << "! Your attack points are less than 10. You can only choose one of the following attack methods: 1 for arrow." << endl;
                cout << " " << endl;
                cin >> att_type;
                
                // if selection correct, set boolean to 1 ending the loop and return attack value
                if (att_type == 1) {

                    check_selection_validity = 1;
                    return att_type;
                }

                // if selection is incorrect, keep boolean at zero and rerun the loop
                else {

                    check_selection_validity = 0;
                }
            }

            // if attack points are less than 6, no attack option can be selected
            if (_attack_p < 6) {
                
                cout << " " << endl;
                cout << _name << "! You don't have enough point to attack in this round. Wait until you restore some attack points." << endl;
                cout << " " << endl;

                att_type = 0;

                check_selection_validity = 1;
                
                return att_type;
            }
        }
     
    }

    // if the type of the player is a computer, the same rules of minimum attack points required for 
    // each method still apply, but the type selection is done randomly by the computer
    else {

        // seed 
        srand(time(0));

        // minimum attack points required for options
        if (_attack_p >= 12) {
               
                // random function to choose 1 our of 3 available attack types
                att_type = rand()%(3 - 1 + 1) + 1;

                return att_type;
        }

        // condition for choosing attack type based on attack points
        if (_attack_p < 12 && _attack_p >= 10) {
               
                // random function for choosing attack type
                att_type = rand()%(2 - 1 + 1) + 1;

                return att_type;
        }

        // condition that determines which attack types can be chosen based on attack points
        if (_attack_p < 10 && _attack_p >= 6) {
                
        // sets attack type to 1 as only option for attack
        att_type = 1;

        return att_type;
        }

        // condition determines that no attack can be made
        if (_attack_p < 6) {

        // sets attack type to zero
        att_type = 0;

        return att_type;
        }
    }    

    return att_type;
}

// a function that displays the player's chosen attack based on the attack type selected
// the attack type is taken by functions argument as an integer value
void character :: display_attack(int att_launched) {

    // based on the attack type chosen, a message is displayed to the user/s

    if(att_launched == 1) {

        cout << " " << endl;
        cout << _name << " is using an arrow to attack" << endl;
        cout << " " << endl;
    }

    else if(att_launched == 2) {

        cout << " " << endl;
        cout << _name << " is using a sword to attack" << endl;
        cout << " " << endl;
    }

    else if(att_launched == 3) {

        cout << " " << endl;
        cout << _name << " is using a spear to attack" << endl;
        cout << " " << endl;
    }

    else if(att_launched == 0) {

        cout << " " << endl;
        cout << _name << " is not attacking in this round" << endl;
        cout << " " << endl;
        
    }
}


// method to allow players to select their defence type against the  selected attack type 
// returns the selected defense type
int character :: defense_type(int attk_type){

    // creates an integer to receive the user's choice for the defence type
    int def_type;

    // if type of the character type of the player is human
    if (_type == "human") {
        
        // if the attack type chosen is 1 then the following applies to the available defense options
        if (attk_type == 1) {

            int check_selection_validity = 0;
            
            while (check_selection_validity == 0) { 

                // if player's defence points are more than or equal to 5, they can choose from all 
                // three defence options
                if (_defense_p >= 5) {
               
                    cout << " " << endl;
                    cout << _name << "! Choose one of the following defence methods: 1 for shield, 2 for cloak, 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                
                    //selection correct returns the defence type selected 
                    if (def_type == 1 || def_type == 2 || def_type == 3) {

                        // sets boolean to 1 to end loop
                        check_selection_validity = 1;

                        return def_type;
                    }

                    // incorrect selection keeps boolean value at zero and the loop is reran
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if player's defence points are more or equal to 2 but less than 5, only 2 defence options
                // can be chosen
                if (_defense_p < 5 && _defense_p >= 2) {
               
                    cout << " " << endl;
                    cout << _name << "! Your defence points are less than 5. You can only choose one of the following defence methods: 1 for shield, 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                    // if correct selection, set boolean to 1 to end loop and return the defence type selected
                    if (def_type == 1 || def_type == 3) {

                        check_selection_validity = 1;

                        return def_type;
                    }

                    // if incorrect selection keep boolean at zero and rerun the loop
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if the defebce points are less than 2 and greater than or equal to 1, only one defence option
                // can be selected
                if (_defense_p < 2 && _defense_p >= 1) {
                
                    cout << " " << endl;
                    cout << _name << "! Your defence points are less than 2. You can only choose one of the following defence methods: 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                
                    // if selection correct, set boolean to 1 ending the loop and return defence value
                    if (def_type == 3) {

                        check_selection_validity = 1;
                        
                        return def_type;
                    }

                    // if selection is incorrect, keep boolean at zero and rerun the loop
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if defence points are less than 1, no defence option can be selected
                if (_defense_p < 1) {
                
                    cout << " " << endl;
                    cout << _name << "! You don't have enough points to defend in this round. Wait until you restore some defence points." << endl;
                    cout << " " << endl;

                    def_type = 0;

                    check_selection_validity = 1;

                    return def_type;
                }
            }
     
                
            
        }

        // if the attack type chosen has the value of 2 
        else if (attk_type == 2) {

            int check_selection_validity = 0;
            
            while (check_selection_validity == 0) { 

                // if player's defence points are more than or equal to 7, they can choose from all 
                // three defence options
                if (_defense_p >= 7) {
               
                    cout << " " << endl;
                    cout << _name << "! Choose one of the following defence methods: 1 for shield, 2 for cloak, 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                
                    //selection correct returns the defence type selected 
                    if (def_type == 1 || def_type == 2 || def_type == 3) {

                        // sets boolean to 1 to end loop
                        check_selection_validity = 1;

                        return def_type;
                    }

                    // incorrect selection keeps boolean value at zero and the loop is reran
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if player's defence points are more or equal to 5 but less than 7, only 2 defence options
                // can be chosen
                if (_defense_p < 7 && _defense_p >= 5) {
               
                    cout << " " << endl;
                    cout << _name << "! Your defence points are less than 7. You can only choose one of the following defence methods: 1 for shield, 2 for cloak." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                    // if correct selection, set boolean to 1 to end loop and return the defence type selected
                    if (def_type == 1 || def_type == 2) {

                        check_selection_validity = 1;

                        return def_type;
                    }

                    // if incorrect selection keep boolean at zero and rerun the loop
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if the defence points are less than 5 and greater than or equal to 2, only one defence option
                // can be selected
                if (_defense_p < 5 && _defense_p >= 2) {
                
                    cout << " " << endl;
                    cout << _name << "! Your defence points are less than 5. You can only choose one of the following defence methods: 2 for cloak." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                
                    // if selection correct, set boolean to 1 ending the loop and return defence value
                    if (def_type == 2) {

                        check_selection_validity = 1;

                        return def_type;
                    }

                    // if selection is incorrect, keep boolean at zero and rerun the loop
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if defence points are less than 2, no defence option can be selected
                if (_defense_p < 2) {
                
                    cout << " " << endl;
                    cout << _name << "! You don't have enough points to defend in this round. Wait until you restore some defence points." << endl;
                    cout << " " << endl;

                    def_type = 0;

                    check_selection_validity = 1;

                    return def_type;
                }
            }
     
                
            
        }

        // if the chosen attack type, represented by the value 3 is selected
        else if (attk_type == 3) {

            int check_selection_validity = 0;
            
            while (check_selection_validity == 0) { 

                // if player's defence points are more than or equal to 6, they can choose from all 
                // three defence options
                if (_defense_p >= 6) {
               
                    cout << " " << endl;
                    cout << _name << "! Choose one of the following defence methods: 1 for shield, 2 for cloak, 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                
                    //selection correct returns the defence type selected 
                    if (def_type == 1 || def_type == 2 || def_type == 3) {

                        // sets boolean to 1 to end loop
                        check_selection_validity = 1;

                        return def_type;
                    }

                    // incorrect selection keeps boolean value at zero and the loop is reran
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if player's defence points are more or equal to 4 but less than 6, only 2 defence options
                // can be chosen
                if (_defense_p < 6 && _defense_p >= 4) {
               
                    cout << " " << endl;
                    cout << _name << "! Your defence points are less than 6. You can only choose one of the following defence methods: 1 for shield, 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                    // if correct selection, set boolean to 1 to end loop and return the attack type selected
                    if (def_type == 1 || def_type == 3) {

                        check_selection_validity = 1;

                        return def_type;
                    }

                    // if incorrect selection keep boolean at zero and rerun the loop
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if the defence points are less than 4 and greater than or equal to 3, only one defence option
                // can be selected
                if (_defense_p < 4 && _defense_p >= 3) {
                
                    cout << " " << endl;
                    cout << _name << "! Your defence points are less than 4. You can only choose one of the following defence methods: 3 for sword." << endl;
                    cout << " " << endl;
                    cin >> def_type;
                
                    // if selection correct, set boolean to 1 ending the loop and return attack value
                    if (def_type == 3) {

                        check_selection_validity = 1;

                        return def_type;
                    }

                    // if selection is incorrect, keep boolean at zero and rerun the loop
                    else {

                        check_selection_validity = 0;
                    }
                }

                // if defence points are less than 3, no defence option can be selected
                if (_defense_p < 3) {
                
                    cout << " " << endl;
                    cout << _name << "! You don't have enough points to defend in this round. Wait until you restore some defence points." << endl;
                    cout << " " << endl;

                    def_type = 0;

                    check_selection_validity = 1;

                    return def_type;
                }
            }
       
        }

    }

    // if the player is of type computer, the same procedure applies, but the random function is used to allow
    // the computer to choose its defense type.
    // In some cases, the random function output value is rewritten to match the allowed defense type
    // based on the defense points of the player.
    else {

        //seed
        srand(time(0));

        // if attack type represented by value 1 is chosen
        if (attk_type == 1) {

            // checks for minimum defence points
            if (_defense_p >= 5) {
               
                // selects one defence type from the options available in this case
                def_type = rand()%(3 - 1 + 1) + 1;

                // returns defence type
                return def_type;
            }

            // checks for minimum defence points
            if (_defense_p < 5 && _defense_p >= 2) {
               
                // selects one defence type from the options available in this case
                def_type = rand()%(2 - 1 + 1) + 1;

                // rewrites def_type to 3 if def_type is equal to 2, since in this case of available
                // defence points, only defence types 1 and 3 can be used.
                if (def_type == 2) {

                    def_type = 3;

                    return def_type;
                }

                // if random function returns 1, this number is then returned as the defence type
                else {

                    return def_type;
                }

            }

            // checks for minimum defence points
            if (_defense_p < 2 && _defense_p >= 1) {
                
               // sets defence type to 3 as the only defence option
               def_type = 3;

               // returns defence type
               return def_type;
            }

            // checks defence points available
            if (_defense_p < 1) {

                // sets defence type to zero implying that non of the defence options can be used
                def_type = 0;

                // returns defence type
                return def_type;
            }
        }

        // if attack type represented by value 2 is chosen
        if (attk_type == 2) {

            // same procedure applies as above for selecting defence type
            if (_defense_p >= 7) {
               
                def_type = rand()%(3 - 1 + 1) + 1;

                return def_type;
            }

            if (_defense_p < 7 && _defense_p >= 5) {
               
                def_type = rand()%(2 - 1 + 1) + 1;

                return def_type;

            }

            if (_defense_p < 5 && _defense_p >= 2) {
                
               def_type = 2;

               return def_type;
            }

            if (_defense_p < 1) {

                def_type = 0;

                return def_type;
            }
        }
        
        // if attack type represented by value 3 is selected
        if (attk_type == 3) {

            // same procedure for selecting defence type as above is applied
            if (_defense_p >= 6) {
               
                def_type = rand()%(3 - 1 + 1) + 1;

                return def_type;
            }

            if (_defense_p < 6 && _defense_p >= 4) {
               
                def_type = rand()%(2 - 1 + 1) + 1;

                if (def_type == 2) {

                    def_type = 3;

                    return def_type;
                }

                else {

                    return def_type;
                }

            }

            if (_defense_p < 4 && _defense_p >= 3) {
                
               def_type = 3;

               return def_type;
            }

            if (_defense_p < 1) {

                def_type = 0;

                return def_type;
            }
        }

        else if (attk_type == 0) {

            def_type = 0;

            return def_type;
        }

    }

    return def_type;
}

// function to display the player's chosen defence type
void character :: display_defence(int def_launched) {

    // based on the value representing the defence type chosen by a player, a message is displayed 
    // telling the user what kind of defence type was chosen
    if(def_launched == 1) {

        cout << " " << endl;
        cout << _name << " is using a shield as a defence" << endl;
        cout << " " << endl; 
    }

    else if(def_launched == 2) {

        cout << " " << endl;
        cout << _name << " is using a cloak as a defence" << endl;
        cout << " " << endl; 
    }

    else if(def_launched == 3) {

        cout << " " << endl;
        cout << _name << " is using a sword as a defence" << endl;
        cout << " " << endl; 
    }

    else if(def_launched == 0)  {

        cout << " " << endl;
        cout << _name << " cannot defend under these circumstances" << endl;
        cout << " " << endl;
    }
}

// attack ramifications is a function that deduces the strength of the attack type chosen by a player 
// represented by the number of attack points that the attack type uses.
// The function also automatically reduces the attack points used from the existing
// attack points of the player.
// function takes the type of attack chosen as an argument
int character :: attack_ramifications(int attack_launched) {

    // variable representing the attack strength of the attack type chosen by the player
    int inflicted_attack;

    // based on the attack type chosen, a certain number of attack points are used to inflict a damage
    // This number is determined below and returned by the function
    // this same number is then subtratced from the player's existing attack points
    if (attack_launched == 1) {

        inflicted_attack = 6;
        _attack_p = _attack_p - inflicted_attack;
        return inflicted_attack;
    }

    else if (attack_launched == 2) {

        inflicted_attack = 10;
        _attack_p = _attack_p - inflicted_attack;
        return inflicted_attack;
    }

    else if (attack_launched == 3) {

        inflicted_attack = 12;
        _attack_p = _attack_p - inflicted_attack;
        return inflicted_attack;
    }

    else if (attack_launched == 0) {
        
        inflicted_attack = 0;
        _attack_p = _attack_p;
        return inflicted_attack;
    }

    return inflicted_attack;   
}

// method to calculate the incflicted damage on the defending player equal to the difference between
// the attack and defence points of the methods chosen subtracted from the player's health points
// THe ability of the defence type in defending the player varies based on the attack being made
int character :: inflict_damage (int def, int att, int att_inflicted) {

    int def_power;

   // if attack method chosen is 1 then attack inflicted is 6 points 
   if (att == 1) {

        // if the attack method chosen is 1, then the defense power varies based on the chosen defence method 
        // if defence method chosen is 1, the defence power is 2
        if (def == 1) {

            // displays the defence power represented by the amount of defence points that the chosen
            // defence type can generate to block the damage of the attack type chpsen
            def_power = 2;

            // subtracts the damage caused from the health points of the defending player
            _hp = _hp - (att_inflicted - def_power);
            // subtracts the defence points used to block the attack from the player's existing defence points
            _defense_p = _defense_p - def_power;
        }

        else if (def == 2) {

            def_power = 5;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 3) {

            def_power = 1;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;

        }

        else if (def == 0) {

            _hp = _hp - att_inflicted;
            _defense_p = _defense_p;
        }
    }

    else if (att == 2) {

            if (def == 1) {

            def_power = 5;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 2) {

            def_power = 2;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 3) {

            def_power = 7;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 0) {

            _hp = _hp - att_inflicted;
            _defense_p = _defense_p;
        }
    }

    else if (att == 3) {

        if (def == 1) {

            def_power = 4;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 2) {

            def_power = 6;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 3) {

            def_power = 3;

            _hp = _hp - (att_inflicted - def_power);
            _defense_p = _defense_p - def_power;
        }

        else if (def == 0) {

            _hp = _hp - att_inflicted;
            _defense_p = _defense_p;
        }
    }

    else if (att == 0) {

        _hp = _hp;
        _defense_p = _defense_p;
    }

return 0;

}

// method to increase attack points by 4 after each round
void character :: inc_attack_p() {

    _attack_p = _attack_p + 4;

    // ensures attack points does not go over 100
    if (_attack_p>100) {

        _attack_p = 100;
    }

    else {
        // do nothing
    }
}

// method to increase attack points by 3 after each round
void character :: inc_defence_p() {

    _defense_p = _defense_p +2;

    // ensures attack points does not go over 100
    if (_defense_p>100) {

    _defense_p = 100;
    }

    else {
    // do nothing
    }
}

// checks the status of the player
int character :: check_status() {

    // if player's health points are less than or equal to zero, the players data will be restored to their 
    // original values and a message will be displayed stating that this player lost and that a new fight 
    // can begin now
    if(_hp<=0){

        _hp = _max_hp;
        _attack_p = 100;
        _defense_p = 100;

        cout <<" "<< endl; 
        cout << _name << " defeated. " << "Defeated player will be resurrected and a new fight can be initiated" << endl;
        cout <<" "<< endl;

        return 0;
    
    }

    else {

        return 1;

    }

}

// serailises the class fields' values 
string character::serialize() {
    //use a string stream to write the vairables into a string
    std::ostringstream stringStream;
    
    stringStream <<
    //"CHARACTER" << " " <<
    _name << "," << 
    _attack_p << "," <<
    _defense_p << "," <<
    _hp << "," <<
    _max_hp << "," <<
    _type;
    return stringStream.str(); /*return a string object*/
}

// deserialises the data coming from the loaded file
int character::deserialize(string serialdata) {
    //use a string stream to write the vairables into a string
    std::istringstream stringStream;

    stringStream.str(serialdata);
    
    // string s;
    // stringStream << s;
    // //CHARACTER name 100 100 500 2000 0
    // if (s == "CHARACTER") {
    //     read in priv memebers
    // }
    // else return -1

    string s;

    std::getline(stringStream, _name, ','); /*string can be directly read*/
    std::getline(stringStream, s, ','); _attack_p = stoi(s); /*use std::stoi to convert string to int*/
    std::getline(stringStream, s, ','); _defense_p = stoi(s); /*use stoi to convert string to int*/
    std::getline(stringStream, s, ','); _hp = stoi(s); /*use stoi to convert string to int*/
    std::getline(stringStream, s, ','); _max_hp = stoi(s); /*use stoi to convert string to int*/

    std::getline(stringStream, _type, ',');

    return 0; /*error checking not implemented ...*/
}