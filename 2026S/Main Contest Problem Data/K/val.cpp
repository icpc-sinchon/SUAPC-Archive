#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 2'000'000, "N");
    inf.readEoln();
    inf.readEof();

    return 0;
}