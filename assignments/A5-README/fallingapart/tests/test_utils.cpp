#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/main.h"

using namespace std;

TEST_CASE("Sample 1: odd number of pieces") {
    int pieces[] = {3, 1, 2};

    sortPieces(pieces, 3);

    CHECK(pieces[0] == 3);
    CHECK(pieces[1] == 2);
    CHECK(pieces[2] == 1);

    CHECK(calculateScore(pieces, 3, 0) == 4);
    CHECK(calculateScore(pieces, 3, 1) == 2);
}

TEST_CASE("Sample 2: duplicate values") {
    int pieces[] = {1, 2, 2, 1};

    sortPieces(pieces, 4);

    CHECK(pieces[0] == 2);
    CHECK(pieces[1] == 2);
    CHECK(pieces[2] == 1);
    CHECK(pieces[3] == 1);

    CHECK(calculateScore(pieces, 4, 0) == 3);
    CHECK(calculateScore(pieces, 4, 1) == 3);
}

TEST_CASE("One piece goes to Alice") {
    int pieces[] = {100};

    sortPieces(pieces, 1);

    CHECK(pieces[0] == 100);
    CHECK(calculateScore(pieces, 1, 0) == 100);
    CHECK(calculateScore(pieces, 1, 1) == 0);
}

TEST_CASE("Equal pieces give equal totals with even size") {
    int pieces[] = {7, 7, 7, 7, 7, 7};

    sortPieces(pieces, 6);

    CHECK(calculateScore(pieces, 6, 0) == 21);
    CHECK(calculateScore(pieces, 6, 1) == 21);
}

TEST_CASE("Maximum count and maximum piece values") {
    int pieces[15];

    for (int i = 0; i < 15; i++) {
        pieces[i] = 100;
    }

    sortPieces(pieces, 15);

    CHECK(calculateScore(pieces, 15, 0) == 800);
    CHECK(calculateScore(pieces, 15, 1) == 700);
}

TEST_CASE("Unsorted pieces stored in a dynamic array") {
    int* pieces = new int[5];

    pieces[0] = 1;
    pieces[1] = 10;
    pieces[2] = 3;
    pieces[3] = 8;
    pieces[4] = 5;

    sortPieces(pieces, 5);

    CHECK(pieces[0] == 10);
    CHECK(pieces[1] == 8);
    CHECK(pieces[2] == 5);
    CHECK(pieces[3] == 3);
    CHECK(pieces[4] == 1);

    CHECK(calculateScore(pieces, 5, 0) == 16);
    CHECK(calculateScore(pieces, 5, 1) == 11);

    delete[] pieces;
    pieces = nullptr;
}