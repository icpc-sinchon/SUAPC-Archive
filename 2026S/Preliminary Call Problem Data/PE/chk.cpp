#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 좌표를 관리하기 위한 구조체
struct Farm {
    int x, y, z;
    bool operator<(const Farm& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    auto start_time = high_resolution_clock::now();
    int tc = inf.readInt();
    
    for (int ii = 0; ii < tc; ii++) {
        unsigned long long n = inf.readLong();
        int a = ouf.readInt(0, 5000);
        
        vector<Farm> farms(a);
        for (int i = 0; i < a; i++) {
            int x = ouf.readInt(-1'000'000'000, 1'000'000'000);
            int y = ouf.readInt(-1'000'000'000, 1'000'000'000);
            int z = ouf.readInt(0, 1);
            farms[i] = {x, y, z};
        }
        
        // 정렬을 통해 좌표 탐색 최적화
        sort(farms.begin(), farms.end());
        
        // 중복 농지 체크 (정렬되어 있으므로 인접한 원소만 비교하면 됨)
        for (int i = 1; i < a; i++) {
            if (farms[i].x == farms[i-1].x && farms[i].y == farms[i-1].y) {
                quitf(_wa, "duplicate farm on tc %d input %llu", ii + 1, n);
            }
        }
        
        int t = ouf.readInt(0, 500);
        int ax = ouf.readInt(-1'000'000'000, 1'000'000'000);
        int ay = ouf.readInt(-1'000'000'000, 1'000'000'000);
        
        // 정답 위치 확인 (이분 탐색)
        Farm target_dummy{ax, ay, 0};
        auto target_it = lower_bound(farms.begin(), farms.end(), target_dummy);
        if (target_it == farms.end() || target_it->x != ax || target_it->y != ay) {
            quitf(_wa, "answer location not a farm on tc %d input %llu", ii + 1, n);
        }
        int target_id = distance(farms.begin(), target_it);
        
        // 인접 리스트 생성 최적화 (가변 vector 대신 고정 array 사용)
        vector<array<int, 4>> adj(a);
        vector<int> deg(a, 0);
        
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = farms[i].x + dx[j];
                int ny = farms[i].y + dy[j];
                
                Farm dummy{nx, ny, 0};
                auto it = lower_bound(farms.begin(), farms.end(), dummy);
                
                if (it != farms.end() && it->x == nx && it->y == ny) {
                    adj[i][deg[i]++] = distance(farms.begin(), it);
                }
            }
        }
        
        // 시뮬레이션 최적화 (루프 내 메모리 할당 제거)
        vector<unsigned long long> dp[2];
        dp[0].assign(a, 0);
        dp[1].assign(a, 0);
        
        for (int i = 0; i < a; i++) {
            dp[0][i] = farms[i].z;
        }
        
        int cur = 0;
        for (int day = 1; day <= t; day++) {
            int nxt = cur ^ 1; // 0과 1을 번갈아가며 사용 (토글링)
            for (int i = 0; i < a; i++) {
                unsigned long long ans = 0;
                // deg 배열을 이용해 존재하는 이웃만 빠르게 순회
                for (int j = 0; j < deg[i]; j++) {
                    ans += dp[cur][adj[i][j]];
                }
                dp[nxt][i] = min(ans, 1'000'000'000'000'000'000ull);
            }
            cur = nxt;
        }
        
        if (dp[cur][target_id] != n) {
            quitf(_wa, "amount of ssal wrong on tc %d input %llu", ii + 1, n);
        }
    }
    
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    quitf(_ok, "successful (Checker time: %lld ms)", (long long)duration.count());
}