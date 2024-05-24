#include <iostream>
#include <cstdlib>
using namespace std;

class TICTACTOE {
private: 
  char** Grid;
  int turn;
  char* symbols;

public: 
    // Default Constructor
    TICTACTOE() : turn(0) {
        // Dynamically allocating a 3*3 Tic Tac Toe Grid
        Grid = new char*[3];
        for (int i = 0; i < 3; i++) {
            Grid[i] = new char[3]{' '};
        }

        Grid[0][0] = '1'; Grid[0][1] = '2'; Grid[0][2] = '3';
        Grid[1][0] = '4'; Grid[1][1] = '5'; Grid[1][2] = '6';
        Grid[2][0] = '7'; Grid[2][1] = '8'; Grid[2][2] = '9';

        // Dynamically allocating symbols for both players
        symbols = new char[2];
        symbols[0] = 'O';
        symbols[1] = 'X';
    }

    // Function for displaying the board
    void DisplayBoard() {
        cout << "BOARD:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "| " << Grid[i][j] << " ";
            }
            cout << "|" << endl;
        }
    }

    // Function to check victory for a specific player
    bool VictoryCheck(char symbol) {
    for(int i = 0; i < 3; i++) {
        if (Grid[i][0] == symbol && Grid[i][1] == symbol && Grid[i][2] == symbol) {
            return true;
        }
    }
    for(int j = 0; j < 3; j++) {
        if (Grid[0][j] == symbol && Grid[1][j] == symbol && Grid[2][j] == symbol) {
            return true;
        }
    }
    if(Grid[0][0] == symbol && Grid[1][1] == symbol && Grid[2][2] == symbol) {
        return true;
    }
    if(Grid[0][2] == symbol && Grid[1][1] == symbol && Grid[2][0] == symbol) {
        return true;
    }
    return false;
  }

    // Function for handling the gameplay environment
    void Gameplay() {
    bool gameOver = false;
    int checkdone[9] = {0};

    while (!gameOver && turn != 9) {
        DisplayBoard();
        char currentSymbol = symbols[turn % 2];
        int position;
        cout << "PLAYER " << currentSymbol << " TURN: ";
        cout << "ENTER POSITION (1-9) TO PLAY: ";
        cin >> position;
        while (position < 1 || position > 9 || checkdone[position - 1]) {
            cout << "INVALID MOVE! TRY AGAIN" << endl;
            cout << "ENTER POSITION (1-9) TO PLAY: ";
            cin >> position;
        }
        checkdone[position - 1] = true;
        Grid[(position - 1) / 3][(position - 1) % 3] = currentSymbol;
        gameOver = VictoryCheck(currentSymbol);
        turn++;
    }
    if (VictoryCheck('O')) {
        DisplayBoard();
        cout << "PLAYER O WINS!" << endl;
    }else if(VictoryCheck('X')) {
        DisplayBoard();
        cout << "PLAYER X WINS!" << endl;
    }else{
        DisplayBoard();
        cout << "ITS A DRAW!" << endl;
    }
    int again;
    cout << "DO YOU WANT TO PLAY AGAIN?\n1-YES\n~-NO\nENTER CHOICE: "; cin >> again;
    if(again == 1){
        Grid[0][0] = '1';Grid[0][1] = '2';Grid[0][2] = '3';
        Grid[1][0] = '4';Grid[1][1] = '5';Grid[1][2] = '6';
        Grid[2][0] = '7';Grid[2][1] = '8';Grid[2][2] = '9';
        turn       = 0;
        Gameplay();
    }else{
        cout << "THANKS FOR PLAYING!";
        exit(0);
    }
  }

    // Destructor
    ~TICTACTOE() {
        delete[] Grid;
        delete[] symbols;
    }
};

int main() {
  TICTACTOE game;
  game.Gameplay();
  return 0;
}
