#include "testlib.h"
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int tc = inf.readInt(1, 20, "tc");
    inf.readEoln();
    while(tc--){
        long long N = inf.readLong(1, 1'000'000'000'000'000'000ll, "N");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}