#pragma once
#include <string>
using namespace std;

namespace repeated {
    enum class Count { Three = 3 };

    string repeatWord(const string& word, Count count);
}
