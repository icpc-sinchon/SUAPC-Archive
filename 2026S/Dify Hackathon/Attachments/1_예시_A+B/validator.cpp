// 예시 문제 "A+B" 의 테스트케이스 검증기.
// 채점기는 이런 검증기로 여러분이 만든 케이스의 형식을 확인한다.
// 하나라도 통과하지 못하면 그 문제는 0점이다.
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 100000, "T");
    inf.readEoln();

    for (int i = 1; i <= t; i++) {
        inf.readLong(-1000000000LL, 1000000000LL, format("A[%d]", i));
        inf.readSpace();
        inf.readLong(-1000000000LL, 1000000000LL, format("B[%d]", i));
        inf.readEoln();
    }

    inf.readEof();
}
