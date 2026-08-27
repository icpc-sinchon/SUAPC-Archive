#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int N = inf.readInt(1, 100, "N");
    inf.readSpace();
    int M = inf.readInt(1, 100, "M");
    inf.readSpace();
    int K = inf.readInt(1, 100, "K");
    inf.readEoln();

    for(int i = 0; i < K; ++i){
        std::string s = inf.readToken("[01]{" + std::to_string(N) + "}", "front view");
        inf.readEoln();
    }
    for(int i = 0; i < M; ++i){
        std::string s = inf.readToken("[01]{" + std::to_string(N) + "}", "upper view");
        inf.readEoln();
    }
    for(int i = 0; i < K; ++i){
        std::string s = inf.readToken("[01]{" + std::to_string(M) + "}", "right view");
        inf.readEoln();
    }
    inf.readEof();
 
    return 0;
}