#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../includes/tictactoe.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("Initialize the board") {
    char board[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };

    initTicTacToe(board, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CHECK(board[i][j] == ' ');
        }
    }
}

TEST_CASE("Find a winner in each row") {
    for (int row = 0; row < 3; row++) {
        char board[3][3];
        initTicTacToe(board, 3);

        for (int column = 0; column < 3; column++) {
            board[row][column] = 'X';
        }

        CHECK(findWinner(board, 3) == 'X');
    }
}

TEST_CASE("Find a winner in each column") {
    for (int column = 0; column < 3; column++) {
        char board[3][3];
        initTicTacToe(board, 3);

        for (int row = 0; row < 3; row++) {
            board[row][column] = 'O';
        }

        CHECK(findWinner(board, 3) == 'O');
    }
}

TEST_CASE("Find a winner on the main diagonal") {
    char board[3][3];
    initTicTacToe(board, 3);

    board[0][0] = 'X';
    board[1][1] = 'X';
    board[2][2] = 'X';

    CHECK(findWinner(board, 3) == 'X');
}

TEST_CASE("Find a winner on the other diagonal") {
    char board[3][3];
    initTicTacToe(board, 3);

    board[0][2] = 'O';
    board[1][1] = 'O';
    board[2][0] = 'O';

    CHECK(findWinner(board, 3) == 'O');
}

TEST_CASE("Empty spaces do not count as a winner") {
    char board[3][3];
    initTicTacToe(board, 3);

    CHECK(findWinner(board, 3) == '-');
    CHECK_FALSE(isBoardFull(board, 3));
}

TEST_CASE("An unfinished game has no winner") {
    char board[3][3] = {
        {'X', 'O', ' '},
        {' ', 'X', ' '},
        {'O', ' ', ' '}
    };

    CHECK(findWinner(board, 3) == '-');
    CHECK_FALSE(isBoardFull(board, 3));
}

TEST_CASE("A full board can be a tie") {
    char board[3][3] = {
        {'X', 'O', 'X'},
        {'X', 'O', 'O'},
        {'O', 'X', 'X'}
    };

    CHECK(findWinner(board, 3) == '-');
    CHECK(isBoardFull(board, 3));
}

TEST_CASE("A full board can have a winner") {
    char board[3][3] = {
        {'X', 'O', 'O'},
        {'O', 'X', 'X'},
        {'O', 'X', 'X'}
    };

    CHECK(findWinner(board, 3) == 'X');
    CHECK(isBoardFull(board, 3));
}

TEST_CASE("Print the supplied board") {
    char board[3][3] = {
        {'X', ' ', 'O'},
        {'O', 'X', ' '},
        {'O', ' ', 'X'}
    };

    ostringstream output;

    // Temporarily capture cout.
    streambuf* originalBuffer = cout.rdbuf(output.rdbuf());
    char originalFill = cout.fill();

    printTicTacToe(board, 3);

    // Restore cout before checking the result.
    cout.rdbuf(originalBuffer);
    cout.fill(originalFill);

    string expected =
        "-------------\n"
        "| X |   | O | \n"
        "-------------\n"
        "| O | X |   | \n"
        "-------------\n"
        "| O |   | X | \n"
        "-------------\n";

    CHECK(output.str() == expected);
}