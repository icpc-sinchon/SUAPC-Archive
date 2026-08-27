#include "testlib.h"

int main(int argc, char **argv) {
    registerValidation(argc, argv);

    inf.readInt(1, 1000000000, "seed");
    inf.readEoln();

    int T = inf.readInt(1, 1000, "T");
    inf.readEoln();

    for (int i = 0; i < T; i++) {
        inf.readInt(1, 1000000000, "X");
        inf.readEoln();
    }

    inf.readEof();
}
