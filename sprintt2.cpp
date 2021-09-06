// This is game is fightmaster. It has a single player and multiplayer mode. The player can choose
// to start a new game, load a game or exit. When a game is started, the user is offered several 
// options: fight, display stats, save, exit or rest. The rest option allows a player to be rested
// but cannot be selected during a fight (only between fights). The fight option allows the user
// to select the attack method they want to launch an attack and then the defense method they'd like
// to block their opponents attack. A damage is inflicted on the defending player by finding the difference
// between the attack method's points and defense method's points and subtracting that from the defending player's
// health points. It is good to note that some attack or defense methods may become unavailable if a 
// player's attack or defense points fall under a certain threshold. When a player's health points
// reach zero or below that, the player is declared defeated and their data is restored to default
// to allow a new fight to be initiated.

#include <iostream>
#include <memory>
#include <string>
#include <cmath>
#include <fstream>
#include <sys/stat.h>
#include "character.h"
#include "singmulti.h"
#include "gamedata.h"

using namespace std; // change later to use std:: instead

int main() {
  
    mkdir("../fightmaster_savedgames", 0777); 

    // creates an integer to receive the returned data from the menu method of the gamedata class
    // which represents the user's game option selection
    int menu_choice;

    // creates object mygame of class gamedata
    gamedata mygame;

    // boolean to ensure loop is reran upon incorrect inputted option
    int correct_game_option = 0;

    // displays message to user
    cout << "Welcome to fightmaster! Are you ready to battle?" << endl;
    cout << " " << endl;

    // as long as correct_game_option boolean is equal to 0, the loop will rerun
    while (correct_game_option == 0) {

        //creates integer game_option to receive the user's inputted choice
        int game_option;

        // The player at this point is presented with several options (starting a new game, loading a saved
        // game or exiting the game)
        cout << "Please enter one of the following options: " << endl;
        cout << "1 to start the game" << endl;
        cout << "2 to load the game" << endl;
        cout << "3 to exit" << endl;
        cout << " " << endl;
        // sets a, the players choice from the above 3
        cin >> game_option;

        // If the player chooses to start a new game by typing 1, they are presented with several statements
        // before beginning.
        if (game_option == 1) {

            int single_multipl;
           
            // user can choose to play single or multiplayer
            singmulti(mygame.player1.get(), mygame.player2.get());

            // pl1 holds the name of player 1 returned by the method called
            string pl1 = mygame.player1 -> get_name();
            // pl2 hold the name of player 2 returned by the called method
            string pl2 = mygame.player2 -> get_name();

            cout << " " << endl;
            // displays the message below including player 1 and 2's names
            cout << "Hello " << pl1 << "! " << "Your opponent is " << pl2 << "!" << endl;
            cout << " " << endl;

            // displays the game days passed
            mygame.display_time();

            // sets boolean to 1 to end loop
            correct_game_option = 1;
        }

        // player chooses to load an older game
        else if (game_option == 2) {

            // calls loadgame method of mygame object of class gamedata
            mygame.loadgame();

            // pl1 holds the name of player 1 returned by the method called
            string pl1 = mygame.player1 -> get_name();
            // pl2 holds the name of player 2 returned by the method called
            string pl2 = mygame.player2 -> get_name();
            cout << " " << endl;
            // displays the message below including player 1 and 2's names
            cout << "Hello " << pl1 << "! " << "Your opponent is " << pl2 << "!" << endl;
            cout << " " << endl;

            // display game days passed
            mygame.display_time();

            // set boolean to 1 to end loop
            correct_game_option = 1;
        }

        // option selected is to exit game
        else if (game_option == 3) {

        // calls the exitgame function that first asks user if they want to save their progress before exiting
        mygame.exitgame();

        // sets boolean to 1 to exit loop
        correct_game_option = 1;
        }

        // if any other value (option) is typed in, an error message is returned and the loop is reran
        else {

            cout << " " << endl;
            // error message
            cout << "Enter a valid option" << endl;
            cout << " " << endl;
            // set boolean to zero to rerun loop
            correct_game_option = 0;
        }

    }

   // boolean that ensures the game loop is not exited unless the exit option is selected

   int no_exit_requested = 0;

   // displays some game instruction to the user before commencing
   cout << "Check the player stats to view your health points!" << endl;
   cout << "During the fight, players have the following attack options: arrow with 6 attack points, spear with 12 attack points and sword with 10 attack points!" << endl;
   cout << "Three defense Methods are available: shield, cloak and sword. The shield offers 2 defense points against the arrow, 5 against the sword and 4 against the spear.";
   cout << "The cloak provides 5 defense points agains the arrow, 6 against the spear and 2 against the sword. The sword provides 1 defense points against the arrow, 3 against the spear and 7 against the sword." << endl;
   cout << "The inflicted damage is the difference between the attack and defence points" << endl;
   cout << "If the player's attack or defense points fall below a certain threshold, some attack or defense methods";
   cout << "may become unavailable" << endl;
   cout << "Some attack and defense points are restored between rounds." << endl;
   cout << "Once a player's healthpoints reach zero, the player is declared defeated and a new fight can be ensued" << endl;
   cout << "Lets Go!" << endl;
   cout << " " << endl;

    // loop runs as long as boolean equal 0
    while (no_exit_requested == 0) {

        // receives the value of returned by the menu function, representing the user's choice
        menu_choice = mygame.menu();

        // choice is 1 means the user has decided to start a fight
        if (menu_choice == 1) {

            // asks for attack type/method user one would like to use
            int pl1_att = mygame.player1->attack_type(); 

            // displays the attack type chosen by the player
            mygame.player1->display_attack(pl1_att);

            // asks for defense type/method of player 2
            int pl2_def = mygame.player2->defense_type(pl1_att);

            // displays the defence type chosen by the player
            mygame.player2->display_defence(pl2_def);

            // calculates the damage inflicted on player 1's attack points
            int pl1_att_ram =  mygame.player1->attack_ramifications(pl1_att);

            // calculates the damage inflicted on player 2's health points and defence points
            mygame.player2->inflict_damage (pl1_att, pl2_def, pl1_att_ram);

            // asks for attack type pf player 2
            int pl2_att =  mygame.player2->attack_type();

            // displays the attack type chosen by player 2
            mygame.player2->display_attack(pl2_att);

            // asks for defense type of player 1
            int pl1_def = mygame.player1->defense_type(pl2_att);

            // displays the defence type chosen by player 1
            mygame.player1->display_defence(pl1_def);

            // calculates damage inflicted on player 2's attack points
            int pl2_att_ram =  mygame.player2->attack_ramifications(pl2_att);

            // calculates the damage inflicted on player 1's health points and defence points
            mygame.player1->inflict_damage (pl2_att, pl1_def, pl2_att_ram);

            // increases game days by 1
            mygame.inc_time();

            // increases player 1 attack points
            mygame.player1 -> inc_attack_p();

            // increases player 1 defense points
            mygame.player1 -> inc_defence_p();

            //increases player 2 attack points
            mygame.player2 -> inc_attack_p();

            // increases player 2 defense points
            mygame.player2 -> inc_defence_p();

            // displays game days passed
            mygame.display_time();

            // keeps boolean at zero to rerun loop
            no_exit_requested = 0;

            // sets change_menu_options to 1
            int change_menu_options = 1;

            // change_menu_options is sent as an argument of set_game_state method to change
            // the _game_state value to 1 and thus only allow the display of menu options not
            // relating to resting the player, since player can only rest when a fight is not
            // ongoing
            mygame.set_game_state(change_menu_options);
        }

        // if the user's choice is 2, player stats are displayed
        else if (menu_choice == 2) {

            mygame.display_time();

            // displays player 1 stats
            cout << mygame.player1->get_name() << "'s game stats: "<< endl; 
            mygame.player1->show_stats();
            //displays player 2 stats
            cout << mygame.player2->get_name() << "'s game stats: " << endl; 
            mygame.player2->show_stats();

            // boolean to zero to rerun the loop
            no_exit_requested = 0; 
        }

        // if user inputs 3, the savegame function is called
        else if (menu_choice == 3) {

            // allows user to choose a file name to save the game's data to
            mygame.savegame();

            // boolean still zero to rerun loop
            no_exit_requested = 0;
        }

        // user inputting 4 means they want to exit the game
        else if (menu_choice == 4) {

            // exitgame function allows user to save before exiting or not to and then exits the whole game
            mygame.exitgame();

            // boolean set to 1 to exit loop
            no_exit_requested = 1;

        }

        // if user selects 5, it means they want to rest their player/s
        else if (menu_choice == 5) {

            //displays message
            cout << " " << endl;
            cout << "Player is resting to allow health, attack and defence points to be restored. This requires one game day." << endl;
            cout << " " << endl;

            // rests player 1 (restores points)
            mygame.player1 -> rest_character();
            // rests player 2 (restores points)
            mygame.player2 -> rest_character();

            // increases time
            mygame.inc_time();

            //displays time
            mygame.display_time();

        }

        // when the user inputs an invalid menu option, an error message is displayed and the loop is reran
        else {

            cout << " " << endl;
            cout << "Enter a valid operation" << endl;
            cout << " " << endl;
            // boolean at zero to rerun loop
            no_exit_requested = 0;
        }

        // returns the status of player 1, if hp of player 1 is 0 or less, 0 is returned. Otherwise 1 is returned
        int return_status1 = mygame.player1 -> check_status();

        // returns the status of player 2, if hp of player 2 is 0 or less, 0 is returned. Otherwise 1 is returned
        int return_status2 = mygame.player2 -> check_status();

        // if any of the two players' status returns 0, a message is displayed from whithin the
        // check_status() function and that player's data is retored to default. The change_menu_options
        // is set to zero to allow 5 menu options including the resting option to be selected now.
        // This allows the winnig player to rest before starting a new fight.
        if (return_status1 == 0 || return_status2 == 0) {

            int change_menu_options = 0;

            mygame.set_game_state(change_menu_options);
        }

        // otherwise nothing happens and the loop reruns
        else {

        }

    }

}
