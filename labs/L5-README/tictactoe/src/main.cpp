#include "../includes/tictactoe.hpp"
#include <iostream>

using namespace std;

int main() {
    char tic_tac_toe[3][3];

    initTicTacToe(tic_tac_toe, 3);

    cout << "Empty board:" << endl;
    printTicTacToe(tic_tac_toe, 3);

    // Example moves.
    tic_tac_toe[0][0] = 'X';
    tic_tac_toe[0][2] = 'O';
    tic_tac_toe[1][0] = 'O';
    tic_tac_toe[1][1] = 'X';
    tic_tac_toe[2][0] = 'O';
    tic_tac_toe[2][2] = 'X';

    cout << "\nBoard after moves:" << endl;
    printTicTacToe(tic_tac_toe, 3);

    char winner = findWinner(tic_tac_toe, 3);

    if (winner != '-') {
        cout << "Congrats " << winner << "! You win!" << endl;
    }
    else if (isBoardFull(tic_tac_toe, 3)) {
        cout << "The game is a tie." << endl;
    }
    else {
        cout << "The game is still in progress." << endl;
    }

    return 0;
}