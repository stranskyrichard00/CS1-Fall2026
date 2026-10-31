#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/main.h"

using namespace std;

TEST_CASE("Sample case 1: three twos") {
    CHECK(makeNice("222") == "2222");
}

TEST_CASE("Sample case 2: already nice") {
    CHECK(makeNice("8224") == "8224");
}

TEST_CASE("Sample case 3: insert multiple numbers") {
    CHECK(makeNice("42424") == "422422448");
}

TEST_CASE("Single numbers remain unchanged") {
    CHECK(makeNice("2") == "2");
    CHECK(makeNice("4") == "4");
    CHECK(makeNice("8") == "8");
}

TEST_CASE("Equal pairs remain unchanged") {
    CHECK(makeNice("22") == "22");
    CHECK(makeNice("44") == "44");
    CHECK(makeNice("88") == "88");
}

TEST_CASE("Complete groups of equal numbers") {
    CHECK(makeNice("2222") == "2222");
    CHECK(makeNice("4444") == "4444");
    CHECK(makeNice("8888") == "8888");
}

TEST_CASE("Odd groups need an additional number") {
    CHECK(makeNice("444") == "4444");
    CHECK(makeNice("888") == "8888");
}

TEST_CASE("Insert twos and fours") {
    CHECK(makeNice("24") == "224");
    CHECK(makeNice("42") == "422");
    CHECK(makeNice("28") == "2248");
}

TEST_CASE("Choose the lexicographically smallest result") {
    // Both 224 and 422 contain 2 followed by 4 only in 224.
    CHECK(makeNice("24") == "224");

    // Both 448 and 844 contain 4 followed by 8.
    // 448 is lexicographically smaller.
    CHECK(makeNice("48") == "448");

    CHECK(makeNice("84") == "844");
}