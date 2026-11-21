#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/util.hpp"

using namespace std;

TEST_CASE("Remove known animal sounds") {
    vector<string> recording{"woof", "ring", "meow", "ding"};
    vector<string> known{"woof", "meow"};
    vector<string> expected{"ring", "ding"};

    CHECK(foxSounds(recording, known) == expected);
}

TEST_CASE("Preserve repeated fox sounds") {
    vector<string> recording{"pa", "woof", "pa", "pa"};
    vector<string> known{"woof"};
    vector<string> expected{"pa", "pa", "pa"};

    CHECK(foxSounds(recording, known) == expected);
}

TEST_CASE("No known sounds") {
    vector<string> recording{"ring", "ding"};

    CHECK(foxSounds(recording, {}) == recording);
}

TEST_CASE("Known sounds absent from recording") {
    vector<string> recording{"wa", "pow"};

    CHECK(foxSounds(recording, {"moo", "quack"}) == recording);
}

TEST_CASE("Official sample") {
    vector<string> recording{
        "toot", "woof", "wa", "ow", "ow", "ow", "pa",
        "blub", "blub", "pa", "toot", "pa", "blub",
        "pa", "pa", "ow", "pow", "toot"
    };

    vector<string> known{"woof", "blub", "toot", "ow"};
    vector<string> expected{"wa", "pa", "pa", "pa", "pa", "pa", "pow"};

    CHECK(foxSounds(recording, known) == expected);
}