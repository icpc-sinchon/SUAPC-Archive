#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    ensuref(argc == 5, "usage: gen S1 E1 S2 E2");

    int S1 = atoi(argv[1]);
    int E1 = atoi(argv[2]);
    int S2 = atoi(argv[3]);
    int E2 = atoi(argv[4]);

    ensuref(1 <= S1 && S1 <= E1 && E1 <= 1000, "invalid first interval");
    ensuref(1 <= S2 && S2 <= E2 && E2 <= 1000, "invalid second interval");

    println(S1, E1);
    println(S2, E2);
}