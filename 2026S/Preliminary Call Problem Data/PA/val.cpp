#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int S1 = inf.readInt(1, 1000, "S1");
    inf.readSpace();
    int E1 = inf.readInt(S1, 1000, "E1");
    inf.readEoln();

    int S2 = inf.readInt(1, 1000, "S2");
    inf.readSpace();
    int E2 = inf.readInt(S2, 1000, "E2");
    inf.readEoln();

    inf.readEof();
}