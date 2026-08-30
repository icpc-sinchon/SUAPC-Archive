#include "testlib.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    registerValidation(argc, argv);

    int T = inf.readInt(1, 1, "T");
    inf.readEoln();

    string password = inf.readToken("[0-9]{8}", "password");

    inf.seekEof();
    inf.readEof();
}