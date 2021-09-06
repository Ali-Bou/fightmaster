#include <iostream>
#include <string>
#include "character.h"
using namespace std; // change to using std::

//has pointers of type character in argument to receive the address of the player unique pointers created
void singmulti(character* p1, character* p2) {

    // boolean to ensure the loop the reran if the user's selection doesn't match the available options
    int check_valid_selection = 0;

    // creates an integer called single_multipl to receive users desired option
    int single_multipl;

    while (check_valid_selection == 0) {

         // displays message to user
         cout << " " << endl;
         cout << "Please select 1 for single player and 2 for multiplayer" << endl;
         cout << " " << endl;
         // receives user's selected input value 
         cin >> single_multipl;


        // if input value is 1, then single player mode is selected
        if (single_multipl == 1) {

                // string to represent user's desired player name
                string player1_name;

                // user asked to input their desired player name
                cout << " " << endl;
                cout << "Choose your player's name." << endl;
                cout << " " << endl;
                // receives player name chosen by user
                cin >> player1_name;
                cout << " " << endl;

                // names the second player, which is the computer, Knight.
                string player2_name = "Knight";

                // type of player 1 is human
                string type1 = "human";
                // type of player 2 is computer
                string type2 = "computer";

                // sets the name of player1 unique pointer to object of class character
                p1 -> set_name(player1_name);
                // sets the type of player1 unique pointer to object of class character as human
                p1 -> set_type(type1);

                // sets the name of player2 unique pointer to object of class character
                p2 -> set_name(player2_name);
                // sets the type of player2 unique pointer to object of class character as computer
                p2 -> set_type(type2);

                // sets boolean to 1 to end loop
                check_valid_selection = 1;

            }

           // if 2 is selected then multiplayer mode is started
            else if (single_multipl== 2) {

                // string for desired name of player1
                string player1_name;
                // string for desired name of player 2
                string player2_name;

                // message displayed to user
                cout << " " << endl;
                cout << "Choose your first player's name." << endl;
                cout << " " << endl;
                // input of first user's name for player 1
                cin >> player1_name;

                cout << " " << endl;
                cout << "Choose your second player's name." << endl;
                cout << " " << endl;
                // input of second user's name for player 2
                cin >> player2_name; 
                cout << " " << endl; 

                // type of player 1
                string type1 = "human";
                // type of player 2
                string type2 = "human"; 

                // sets the name of player1 unique pointer to object of class character 
                p1 -> set_name(player1_name);
                // sets the type of player1 unique pointer to object of class character as human
                p1 -> set_type(type1);

                // sets the name of player2 unique pointer to object of class character 
                p2 -> set_name(player2_name);
                // sets the type of player2 unique pointer to object of class character as human
                p2 -> set_type(type2);

                // sets boolean to 1 to end loop
                check_valid_selection = 1;


            }

            // if an invalid inputted option is made, the loop is reran to display the available 
            // options again
            else {

                check_valid_selection = 0;
            }  
    }
}