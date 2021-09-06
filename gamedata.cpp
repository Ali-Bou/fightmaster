#include <iostream>
#include "character.h"
#include "gamedata.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std; // change to using std:: later

// Constructor of gamedata() that sets the initial values of the class's memebers
gamedata :: gamedata() {
    _game_state = 0;
    _time = 0;
    player1 = make_unique<character>();
    player2 = make_unique<character>();
}

// Methods that take an integer as an argument and sets the _game_state field to be equal to that
// value
void gamedata :: set_game_state(int game_state) {

    _game_state = game_state;

}

// method that returns the value of _game_state
int gamedata :: get_name_state() { 

    return _game_state;
}

// Method to serialise the fields of class gamedata corresponding to an object of gamedata
string gamedata::serialize_gamedata() 
{
    // Use string stream to write the variables into a string
    std::ostringstream stringStream;
    
    // Set data to stringstream, separated by a comma
    stringStream << _time << "," << _game_state << endl; 

    return stringStream.str(); /*return a string object*/
}


// Method to deserialise the fields of the class gamedata corresponding to an object of gamedata
// deserialise_gamedata takes a string argument serialdata.
int gamedata::deserialize_gamedata(string serialdata) {
    //use a string stream to write the vairables into a string
    std::istringstream stringStream;

    stringStream.str(serialdata);

    // Created a string s to be able to received the string values from the loaded file before using 
    // stoi to covert the strings to the desired integer values.
    string s;

    // Use getline to allow for the use of comma as delimiter
    std::getline(stringStream, s, ','); _time = stoi(s);
    std::getline(stringStream, s, ','); _game_state = stoi(s);

    return 0; /*error checking not implemented ...*/
}

// methods to save game data
void gamedata :: savegame() 
{
    //filetosave is the string representing the name of the file the player enters in the game
    string filetosave;
    cout << " " << endl;
    cout << "Enter the name of the .txt file you want to save eg. file.txt ." << endl;
    cout << " " << endl;

    //sets filetosave
    cin >> filetosave;
    ofstream outfile("../fightmaster_savedgames"+filetosave); //check...........!!!!!!
    outfile.open(filetosave);
    
    // sends the serialised data of the gamedata object of the class gamedata to the file.
    outfile << this->serialize_gamedata() << endl;

    // sends the serialised data of player 1 of class character to the file
    outfile << player1->serialize() << endl;

    // sends the serialised data of player 2 of the class character to the file.
    outfile << player2->serialize() << endl;

    //closes the outfile.
    outfile.close();

}

// method to load a saved file to the game to continue playing
void gamedata::loadgame() 
{
    // filetoload is the representation of the player's chosen file name in the code
    string filetoload;
    // Prompts the player to choose a name for their file.txt
    cout << " " << endl;
    cout << "Enter the name of the txt file you would like to load eg. filename.txt" << endl;
    cout << " " << endl;
    // Sets the name to filetoload
    cin >> filetoload;
    ifstream infile ("../fightmaster_savedgames"+filetoload);
    // Opens the chosen file with the saved progress stats
    infile.open(filetoload);
    //check for error in the chosen file name
    if (infile.fail())
    {
        //returns an error statement to the player
        cerr << "Error opening file" << endl;
        exit(1);
    }

    // Creates 3 strings: game_serial for the gamedata values (_time and _game_state),
    // p1_serial for the data of player one represented by the fields of class character
    // p2_ serial for the data of player two represented by the fields of class character
    string game_serial;
    string p1_serial;
    string p2_serial;

    // Sets the 3 lines (1 for game data, 2 for player 1 data, 3 for player 2 data) 
    // of type string to the 3 created strings.
    infile >> game_serial >> p1_serial >> p2_serial;

    // This uses the deserialize_gamedata function to assing the received values to their corresponding
    // variables in mygame (a created object of class gamedata)
    this->deserialize_gamedata(game_serial); 
    // Deserialises the player 1's data received from the file and assigns them to their corresponding
    // variables of class character
    player1->deserialize(p1_serial);
    // Deserialises player 2's data received from the loaded file.
    player2->deserialize(p2_serial);

}

// method to exit the game
void gamedata :: exitgame () {

     int correct_selection = 0;

        // saved_or_not is the representation of the players decision in the code
        string save_or_not;

        //message to player
        cout << " " << endl;
        cout << "would you like to save before exiting the game? To save, type Y. To exit without saving, type N." << endl;
        cout << " " << endl;
        
        while (correct_selection == 0)
        {
            // sets the player's choice to save_or_not
            cin >> save_or_not;
            // If save_or_not is N, this implies No. Hence the player has decided to exit without saving.
            if (save_or_not == "N")
            {
                // Sets the boolean correct_selection to one to exit while loop
                correct_selection = 1;
                exit(0); // Ends execution of the function
                
            }
            // If the SDS is Y, this implies Yes. Hence the player has decided to save before exiting. This sends
            // the code to the function savegame to allow the player to enter a name for the file to save.
            else if (save_or_not == "Y")
            {
                savegame();
                // Sets cross_selection to one to exit while loop
                correct_selection = 1;
                exit(0); // Ends execution of the function
                
            }
            else{
                // displays enter a valid option for the user to know that their inputted value does not
                // match the available options
                cout << " " << endl;
                cout<<"Enter a valid option"<<endl;
                cout << " " << endl;
                // Sets the boolean correct_selection to zero to ensure the loop is ran again
                correct_selection = 0;
            }
        }

}

// a method of the class gamedata that deals with displaying the menu of available options 
// once a game has started.
int gamedata :: menu() {

    // oper holds the user's inputted value
    int oper;

    // _game_state is field of the class gamedata that defines weather there is an ongoing fight or not.
    // This is to prevent the player from resting midway through a fight. The player can only rest between fights.
    // When _game_state is equal to zero, the menu displays the resting option.
    if (_game_state == 0) {

        // Displays the available options the player can choose from while the game runs
        cout << " " << endl;
        cout << "The operations of the game's menu are: " << endl;
        cout << "1 to start fighting" << endl;
        cout << "2 to show player stats" << endl;
        cout << "3 to save the game" << endl;
        cout << "4 to exit" << endl;
        cout << "5 to rest your player and return to maximum hp" << endl;
        cout << " " << endl;

        //receives player's input
        cin >> oper;
        
        // Rerturns the chosen options to send the choice value to the main function to run the program
        //accordingly.
        return oper;
    }

    // When _game_state is equal to 1, the resting option is not displayed anymore.
    else if (_game_state == 1) {

        // Boolean to run while loop and ensure 5 (resting option) cannot be used by the player
        // The main function returns an error in selection messsage when any number other than the 
        // 5 (1,2,3,4,5) options is chosen. Therefore, this additonal while loop is required in the menu()
        // method to additionally ensure 5 cannot be chosen when a fight is running.
        int correct_selection = 0;

        while (correct_selection == 0) {

            // Displays the available options now that a fight is running
            cout << " " << endl;
            cout << "The operations of the game's menu are: " << endl;
            cout << "1 to start fighting" << endl;
            cout << "2 to show player stats" << endl;
            cout << "3 to save the game" << endl;
            cout << "4 to exit" << endl;
            cout << " " << endl;

            // Receives player's input
            cin >> oper;

            // If the player tries to select 5 for resting during a fight, a message is returned and 
            // the loop runs again
            if (oper == 5)
            {

                // Error message
                cout << " " << endl;
                cout << "Please enter a valid operation." << endl;
                cout << " " << endl;
                // Keeps boolean equal to 1 to rerun loop
                correct_selection  = 0;
            }

            // Otherwise selection is okay. If the player selects a number other than 5 that does not
            // match the 4 available options, the main function will deal with that and will ask the 
            // player to enter a valid option after which the menu() method will be called again.
            else 
            {
                // Sets boolean to 1 to end loop
                correct_selection  = 1;

                // Returns the player's inputted value to use it in running the command in the main
                // function.
                return oper;
            }

        }
    } 

    return oper;   
}

// Method to increas the in-game days, where the class field _time is incremented by a factor of 1 day.
void gamedata :: inc_time() {

    _time = _time + 1;
}

// A method of class gamedata that displays the game days passed when called.
void gamedata :: display_time() {

    cout << " " << endl;
    cout << "Game days passed: " << _time <<  endl;
    cout << " " << endl;

}