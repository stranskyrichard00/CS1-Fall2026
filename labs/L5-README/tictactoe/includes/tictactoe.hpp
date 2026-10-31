#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

// These functions expect a 3-by-3 board.
void initTicTacToe(char board[][3], int row);
void printTicTacToe(char board[][3], int row);

// Returns 'X', 'O', or '-' when there is no winner.
char findWinner(char board[][3], int row);

bool isBoardFull(char board[][3], int row);

#endif