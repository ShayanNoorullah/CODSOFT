#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

class NumberGuessingGameplay{
    private:
    int choice;
    int NumToGuess;
    int turns;

    public:

    NumberGuessingGameplay(){
        this->choice = -1;
        this->NumToGuess = 0;
        this->turns = 0;
    }    
    //Function to generate Random Number to guess for the number guessing game...
    int RandomNumberGenerator(){
        srand(time(0));
        if(choice == 1){
            //EASY MODE
            return rand() % 10;
        }else if(choice == 2){
            //MEDIUM MODE
            return rand() % 100;
        }else if(choice == 3){
            //HARD MODE
            return rand() % 1000;
        }
        return 0;
    }

    //Function for providing Number Guessing Game Environment:
    void NumberGuessingGame(){
        NumToGuess = RandomNumberGenerator();
        int UserGuess;
        cout << "LETS BEGIN THE GAME: " << endl;
        cout << "GUESS A NUMBER" << endl;
        while(1){
            cin >> UserGuess;
            turns++;
            if(UserGuess == NumToGuess){
                cout << "YOU GUESSED IT CORRECT!" << endl << "NUMBER OF TURNS: " << turns << endl;\
                cout << "THANKS FOR PLAYING";
                exit(0);
            }else if(UserGuess > NumToGuess){
                cout << "YOUR GUESS IS HIGHER..." << endl;
                cout << "TRY AGAIN!  " << endl;
            }else{
                cout << "YOUR GUESS IS LOWER..." << endl;
                cout << "TRY AGAIN!  " << endl;
            }
        }
    }

    //Function for Displaying the Menu of the Game:
    void displayMenu(){
        int x;
        cout << "NUMBER GUESSING GAME" << endl;
        cout << "DIFFICULTY LEVELS:" << endl << "1-EASY\n2-MEDIUM\n3-HARD\n0-EXIT" << endl;
        cin >> x;
        this->choice = x;
        if(choice == 0){
            cout << "THANKS FOR PLAYING";
            exit(0);
        }
        while(choice != 1 && choice != 2 && choice != 3){
            cout << "INVALID CHOICE... ENTER AGAIN: "; cin >> choice;
        }
        NumberGuessingGame();
    }
};




int main(){
    NumberGuessingGameplay Game;
    Game.displayMenu();

}