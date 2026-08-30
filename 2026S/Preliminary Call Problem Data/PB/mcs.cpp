#include <bits/stdc++.h>
using namespace std;

int T, pass[8];
string pw;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    if(T == 1){
        cin >> pw;
        for (int i = 0; i < 8; ++i){
            pass[i] = (pw[i] - '0' + 1) % 10;
            cout << pass[i];
        }
        cout << endl;
    }
    else{
        cin >> pw;
        for (int i = 0; i < 8; ++i){
            pass[i] = (pw[i] - '0' + 9) % 10;
            cout << pass[i];
        }
        cout << endl;
    }

    return 0;
}