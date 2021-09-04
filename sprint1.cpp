//This is FightMaster Sprint 1, a simple preliminary version of the final FightMaster game.
//FightMaster is an RPG fight adventure game. In sprint 1, after the player starts the game, they receive
//3 options: start, load or exit the game. Once the game is started, whether a new game or a previously
//saved now loaded game, the player can choose to either fight, view their stats, save or exit the game.
//Each player has a name and healthpoints (hp). The initial hp at the beginning of every new game is always
//100. When a fight starts, the player can choose to enter a number between 1 and 99. The number the player
//chooses is then subtracted from the players current health points (hp). If the players hp reaches 0,
//the game is over.
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;
//HP represents the health points of a player and is always 100 when a new game is started.
int HP = 100;
// CN stands for character name
string CN;
//oper stands for operation and represents what the player is requesting to happen in the game(Fight,
//show stats, save game, exit game)
string oper;
//gametime is a function that dictates what happens when a player selects a certain option in the game.
int gametime(int r)
{
    //r is equal to 1, the player is prompted to choose a number between 1 and 99, for that number
    //to be reduced from their current HP
    if (r == 1)
    {
        //define integer a
        int a;
        cout << "choose a number between 1 and 99" << endl;
        //represents the user's inputted number in the code
        cin >> a;
        //subtracts the player's chosen number from the current HP and sets the new HP
        HP = HP - a;
        //if HP is greater than 0, a statement is displayed to the player along with their current HP
        if (HP > 0)
        {
            cout << "Lets fight! "
                 << "Your HP is " << HP << endl;
        }
        //if HP is less than zero, game over is displayed and RETURN_QUIT is returned to trigger the end
        //of the game by stopping the while loop below.
        else if (HP <= 0)
        {
            cout << "Game Over. "
                 << "To play again, restart the game." << endl;
            exit(0);
        }
    }
    // If r is equal to 2. THe game displays the player's stats (Name, HP).
    else if (r == 2)
    {
        cout << "Name: " << CN << endl;
        cout << "Health Points: " << HP << endl;
    }
    // If r is equal to 3, the player received a message to enter a name.txt for the file he wants to save
    // his progress to.
    else if (r == 3)
    {
        //filetosave is the string representing the name of the file the player enters in the game
        string filetosave;
        cout << "Enter the name of the file you want to save." << endl;
        //sets filetosave
        cin >> filetosave;
        ofstream outfile;
        outfile.open(filetosave);
        //registers the character name to the first line of the txt file.
        outfile << CN << endl;
        //registers the current HP to the second line of the txt file.
        outfile << HP << endl;
        //closes the outfile.
        outfile.close();
        return 0;
    }
    // If r is equal to 4, the player has chosen to exit the game, a message appears asking them whether
    // they would like to save their progress before exiting or not.
    else if (r == 4)
    {
        // boolean b3 equal to zero
        int b3=0;
        //SDS (savedontsave) is the representation of the players decision in the code
        string SDS;
        //message to player
        cout << "Are you sure you don't want to save the game? To save, type N. To exit without saving, type Y." << endl;
        while (b3 == 0)
        {
            // sets the player's choice to SDS
            cin >> SDS;
            // If SDS is Y, this implies yes. Hence the player has decided to exit without saving.
            if (SDS == "Y")
            {
                // Sets boolean 3 to one
                b3=1;
                // Ends execution of the function
                return 0;
            }
            // If the SDS is N, this implies No. Hence the player has decided to save before exiting. This sends
            // the code to the function gametime at "r" equal to 3 to allow the player to enter a name for the file
            // they want to save and to save it.
            else if (SDS == "N")
            {
                gametime(3);
                // Sets boolean 3 to one
                b3=1;
                // Ends execution of the function
                return 0;
            }
            else{
                cout<<"Enter a valid option"<<endl;
                // Sets boolean 3 to zero
                b3=0;
            }
        }
    }
    // Ends the function
    return 0;
}
int main()
{
    // a is an integer local to the function main and it's contituents. a represents the players choice
    // to start, load ot exit the game in the code
    int a;
    int b1 = 0;
    while (b1 == 0)
    {
        // The player at this point is presented with several options (starting a new game, loading a saved
        // game or exiting the game)
        cout << "Please enter one of the following options: " << endl;
        cout << "1 to start the game" << endl;
        cout << "2 to load the game" << endl;
        cout << "3 to exit" << endl;
        // sets a, the players choice from the above 3
        cin >> a;
        // If the player chooses to start a new game by typing 1, they are presented with several statements
        // before beginning.
        if (a == 1)
        {
            // The player is prompted to choose a name for their character
            cout << "Enter your character's name" << endl;
            // Sets the character name to code
            cin >> CN;
            // The player is presented with their stats (character name and HP)
            cout << "Welcome to the game " << CN << " You are in full health with HP = " << HP << endl;
            // The player is presented with the operations of the game's menu (F to start the fight, ST to
            // view the stats, SV to save their progress and E to exit the game)
            cout << "The operations of the game's menu are: " << endl;
            cout << "F to start fighting" << endl;
            cout << "ST to show " << CN << "'s stats" << endl;
            cout << "SV to save the game" << endl;
            cout << "E to exit" << endl;
            //set boolean b1 to 1;
            b1 = 1;
        }
        // If the player types in 2 to load the game setting a to 2, the player is prompted to choose the
        // file they would like to load.
        else if (a == 2)
        {
            // filetoload is the representation of the player's chosen file name in the code
            string filetoload;
            // Prompts the player to choose a name for their file.txt
            cout << "Enter the name of the txt file you would like to load eg. filename.txt" << endl;
            // Sets the name to filetoload
            cin >> filetoload;
            ifstream infile;
            // Opens the chosen file with the saved progress stats
            infile.open(filetoload);
            //check for error in the chosen file name
            if (infile.fail())
            {
                //returns an error statement to the player
                cerr << "Error opening file" << endl;
                exit(1);
            }
            // If no error occurs the first line the files standing for the character's name is set to CN
            // (Character Name) and the second line representing the healthpoints is set to HP (healthpoints).
            // These are then the current player stats in the game started.
            infile >> CN >> HP;
            // The player is presented with the operations of the game's menu (F to start the fight, ST to
            // view the stats, SV to save their progress and E to exit the game)
            cout << "The operations of the game's menu are: " << endl;
            cout << "F to start fighting" << endl;
            cout << "ST to show " << CN << "'s stats" << endl;
            cout << "SV to save the game" << endl;
            cout << "E to exit" << endl;
            //set boolean b1 to 1
            b1 = 1;
        }
        // If the player types 3 setting a to 3, they have chosen to exit the game. This sends the code to the
        // function gametime where the value of "r" is 3. At that point, the player is asked whether they want
        // to exit without saving or not before they can finally exit the game.
        else if (a == 3)
        {
            gametime(4);
            return 0;
            //set boolean b1 to 1
            b1 = 1;
        }
        else
        {
            cout << "Enter a valid option" << endl;
            // set boolean b1 to zero
            b1 = 0;
        }
    }

    int b2 = 0;
    // While loop for the game, which reruns again and again as long as the conditions are being met.
    // Condtion is that boolean b2 remians equal to zero
    while (b2 == 0)
    {
        // Sets the chosen operation (fight F, show stats (ST), save progress (SV), exit (E)) to oper
        cin >> oper;
        // If operation is fight (F), the code is sent to gametime at "r" equals 1 to allow the player
        // play
        if (oper == "F")
        {
            gametime(1);
            //set boolean b2 to zero
            b2 = 0;
        }
        // If the operation is show stats (ST), the code is sent to gametime at "r" equals 2 to display
        // the player's current stats
        else if (oper == "ST")
        {
            gametime(2);
            // Set boolean b2 to zero
            b2 = 0;
        }
        // If the operation is save (SV), the code is sent to gametime at "r" equals 3, where the player
        // is prompted to choose a file name to save the progress
        else if (oper == "SV")
        {
            gametime(3);
            //set boolean b2 to zero
            b2 = 0;
        }
        // If the operation chosen is exit (E), the code is sent to gametime function at "r" equals 4, where
        // the player is asked whether they want to save their progress before exiting the game
        else if (oper == "E")
        {
            gametime(4);
            //set boolean b2 to one to end the loop
            b2 = 1;
            return 0;
        }
        // This statement allows the program to fully stop after displaying game over because of the player's
        // HP reaching 0 or below. It is called from the function gametime at "r" equals 1.
        else
        {
            cout << "Enter a valid operation" << endl;
            //set boolean b2 to zero
            b2 = 0;
        }
    }

    return 0;
}
