#include "../includes/tictactoe.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void initTicTacToe(char board[][3], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printTicTacToe(char board[][3], int row) {
    cout << setfill('-') << setw(13) << "" << endl;

    for (int i = 0; i < row; i++) {
        cout << "| ";

        for (int j = 0; j < 3; j++) {
            // #FIXED#: Use the board passed to the function.
            cout << board[i][j] << " | ";
        }

        cout << endl;
        cout << setfill('-') << setw(13) << "" << endl;
    }
}

char findWinner(char board[][3], int row) {
    char winner;
    bool won;

    // Check rows.
    for (int i = 0; i < row; i++) {
        winner = board[i][0];

        // #FIXED#: Empty spaces cannot win.
        if (winner != 'X' && winner != 'O') {
            continue;
        }

        won = true;

        for (int j = 1; j < 3; j++) {
            if (winner != board[i][j]) {
                won = false;
                break;
            }
        }

        if (won) {
            return winner;
        }
    }

    // Check columns.
    for (int j = 0; j < 3; j++) {
        winner = board[0][j];

        if (winner != 'X' && winner != 'O') {
            continue;
        }

        won = true;

        for (int i = 1; i < row; i++) {
            if (winner != board[i][j]) {
                won = false;
                break;
            }
        }

        if (won) {
            return winner;
        }
    }

    // Check the top-left to bottom-right diagonal.
    winner = board[0][0];

    if ((winner == 'X' || winner == 'O') &&
        winner == board[1][1] &&
        winner == board[2][2]) {
        return winner;
    }

    // #FIXED#: Check the top-right to bottom-left diagonal.
    winner = board[0][2];

    if ((winner == 'X' || winner == 'O') &&
        winner == board[1][1] &&
        winner == board[2][0]) {
        return winner;
    }

    return '-';
}

bool isBoardFull(char board[][3], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}