#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M, K;
vector<string> fview;
vector<string> uview;
vector<string> rview;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    for(int i = 0; i < K; ++i){
        cin >> s;
        fview.push_back(s);
    }
    for(int i = 0; i < M; ++i){
        cin >> s;
        uview.push_back(s);
    }
    for(int i = 0; i < K; ++i){
        cin >> s;
        rview.push_back(s);
    }

    vector<vector<int>> recFr(K, vector<int>(N, 0));
    vector<vector<int>> recUp(M, vector<int>(N, 0));
    vector<vector<int>> recRi(K, vector<int>(M, 0));
    for (int z = 0; z < K; ++z){
        for (int y = 0; y < M; ++y){
            for (int x = 0; x < N; ++x){
                if (fview[z][x] == '1' && uview[y][x] == '1' && rview[z][y] == '1') {
                    recFr[z][x]++;
                    recUp[y][x]++;
                    recRi[z][y]++;
                }
            }
        }
    }

    bool avail = true;
    for (int z = 0; z < K; ++z) {
        for (int x = 0; x < N; ++x) {
            if (recFr[z][x] == 0 && fview[z][x] == '1') {
                avail = false;
            }
        }
    }

    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            if (recUp[y][x] == 0 && uview[y][x] == '1') {
                avail = false;
            }
        }
    }

    for (int z = 0; z < K; ++z) {
        for (int y = 0; y < M; ++y) {
            if (recRi[z][y] == 0 && rview[z][y] == '1') {
                avail = false;
            }
        }
    }

    if (avail){
        for (int z = 0; z < K; ++z){
            for (int y = 0; y < M; ++y){
                for (int x = 0; x < N; ++x) {
                    if (recFr[z][x] > 1 && recUp[y][x] > 1 && recRi[z][y] > 1) cout << 1;
                    else if (recFr[z][x] && recUp[y][x] && recRi[z][y]) cout << 2;
                    else cout << 0;
                }
                cout << '\n';
            }
        }
    }
    else {
        cout << "Wrong design";
    }
    return 0;
}