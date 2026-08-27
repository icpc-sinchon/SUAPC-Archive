// 예시 문제 "A+B" 의 정해.
// 채점기가 여러분의 앱에 넘겨 주는 main.cpp 가 이런 모습이다.
#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a + b);
    }
    return 0;
}
