#include "utils.hpp"
using namespace std;

string followCommand(const string& command) {
    if (command.find("Simon says ") == 0) {
        return command.substr(10);
    }

    return "";
}