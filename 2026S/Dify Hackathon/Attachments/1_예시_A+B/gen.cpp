// 예시 테스트케이스 생성기 (1번 방식).
// 한 번 실행하면 1.in 부터 차례로 파일을 남긴다. 파일은 30개를 넘으면 안 된다.
//
// 무작위 케이스만 찍어 내면 경계에서 무너지는 오답을 놓친다.
// 자료형 한계, 부호가 섞인 값, 최소 크기, 최대 크기를 함께 넣는 것이 요령이다.
#include "testlib.h"
#include <cstdio>
#include <string>
#include <vector>

const long long LIM = 1000000000LL;

void dump(int idx, const std::vector<std::pair<long long, long long>>& cs) {
    FILE* f = fopen((std::to_string(idx) + ".in").c_str(), "w");
    fprintf(f, "%d\n", (int)cs.size());
    for (auto& c : cs) fprintf(f, "%lld %lld\n", c.first, c.second);
    fclose(f);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int idx = 0;

    // 1. 가장 작은 입력
    dump(++idx, {{0, 0}});

    // 2. 합이 int 범위를 넘는다. int 로 받은 오답이 여기서 죽는다.
    dump(++idx, {{LIM, LIM}, {-LIM, -LIM}});

    // 3. 부호가 섞여 있다. 절댓값만 더하는 오답을 잡는다.
    dump(++idx, {{LIM, -LIM}, {-LIM, LIM}, {-1, 1}});

    // 4. 경계값만 모아 둔다
    dump(++idx, {{LIM, 0}, {0, -LIM}, {1, -1}, {-1, -1}});

    // 5. 케이스 수가 많다. 입출력이 느린 오답이 시간 초과로 죽는다.
    {
        std::vector<std::pair<long long, long long>> cs;
        for (int i = 0; i < 100000; i++)
            cs.push_back({rnd.next(-LIM, LIM), rnd.next(-LIM, LIM)});
        dump(++idx, cs);
    }

    return 0;
}
