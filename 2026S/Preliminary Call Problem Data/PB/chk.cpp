#include "testlib.h"
#include <string>
using namespace std;

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);

    inf.readInt(1, 1, "T");
    inf.readEoln();

    string password = inf.readToken("[0-9]{8}", "password");

    string answer = ouf.readToken("[0-9]{8}", "answer");

    if (answer != password) {
        quitf(_wa, "Wrong password");
    }

    quitf(_ok, "Correct");
}