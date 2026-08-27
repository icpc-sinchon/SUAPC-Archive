#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> pos(n + 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    /*
    pos[x] < pos[x+1]이면 x와 x+1은 같은 코드를 받아도 된다.

    따라서 1, 2, ..., n을
    pos[x] > pos[x+1]인 지점에서 자른다.
    */
    vector<int> w;

    int len = 1;

    for (int x = 1; x < n; ++x) {
        if (pos[x] < pos[x + 1]) {
            ++len;
        } else {
            w.push_back(len);
            len = 1;
        }
    }

    w.push_back(len);

    int m = (int)w.size();

    /*
    k번 시행으로 만들 수 있는 선택 여부 코드는 2^k개이다.
    각 증가 구간에는 서로 다른 코드가 필요하다.
    */
    int k = 0;

    while ((1 << k) < m) {
        ++k;
    }

    int codeCount = 1 << k;

    /*
    증가 구간 i에 코드 c를 부여하면
    그 구간의 모든 책은 popcount(c)번 이동한다.

    증가하는 서로 다른 코드 m개를 고르는 DP.
    */
    const long long INF = (1LL << 60);

    vector<long long> dp(m + 1, INF);
    dp[0] = 0;

    for (int code = 0; code < codeCount; ++code) {
        long long cost = __builtin_popcount((unsigned)code);

        for (int used = min(m, code + 1); used >= 1; --used) {
            dp[used] = min(
                dp[used],
                dp[used - 1] + cost * w[used - 1]
            );
        }
    }

    cout << k << ' ' << dp[m] << '\n';
}