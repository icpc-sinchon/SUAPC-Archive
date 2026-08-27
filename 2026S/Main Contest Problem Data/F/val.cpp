#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 1'000'000, "N");
    inf.readEoln();

    for (int i = 1; i <= n; i++) {
        if (i > 1) inf.readSpace();
        inf.readInt(1, n, "A_i");
    }
    inf.readEoln();

    inf.readEof();
}
