#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
using namespace std;
const int PRECISION = 9;
using pi2 = pair<int, int>;

char str[2][500020];

int ptr[2][500020]; vector<int> adj[2][500020];
void init(int p, int st, int ed){
	if (st > ed){ return; }
	int l = st; while (l <= ed){
		int r = ptr[p][l]; adj[p][st-1].push_back(l);
		init(p, l+1, r-1); adj[p][l].push_back(st-1); l = r+1;
	}
}
inline bool f(char c){ return (c=='(' || c=='{' || c=='['); }
void init(int p, int n){
	stack<int> stk; for (int i = 1; i <= n; i++){
		if (f(str[p][i])){ stk.push(i); }
		else{ int j = stk.top(); stk.pop(); ptr[p][j] = i; }
	} init(p, 1, n);
}

bool chk[2][500020]; int siz[2][500020];
void sizf(int i, int v, int p){
	siz[i][v] = 1; for (int w : adj[i][v]){
		if (w == p){ continue; }
		sizf(i, w, v); siz[i][v] += siz[i][w];
	}
}
pi2 cent = {-1, -1}; void centroid(int i, int v, int p, int n){
	bool flg = 1; for (int w : adj[i][v]){
		if (w == p){ continue; }
		centroid(i, w, v, n); if (siz[i][w]*2 > n){ flg = 0; }
	} if (flg && (n-siz[i][v])*2 <= n){ (cent.fr==-1 ? cent.fr : cent.sc) = v; }
} inline pi2 centroid(int i, int v){
	cent = {-1, -1}; sizf(i, v, v); centroid(i, v, v, siz[i][v]); return cent;
}

char chr[2][500020];
char shift(int i, int v, int p, int t){
	char tmp = chr[i][v];
	if (v == t){ chr[i][v] = ' '; return tmp; }
	for (int w : adj[i][v]){
		if (w == p){ continue; }
		char res = shift(i, w, v, t);
		if (res != 0){ chr[i][v] = res; return tmp; }
	} return 0;
}
char res[2][1000020]; int len[2];
inline char g(char c){ return (c=='(' ? ')' : c=='{' ? '}' : ']'); }
void dfs(int i, int v, int p){
	if (v != p){ res[i][len[i]++] = chr[i][v]; }
	int l = adj[i][v].size();
	int j = 0; for (int k = 0; k < l; k++){
		if (adj[i][v][k] == p){ j = k; }
	}
	for (int d = 0; d < l; d++){
		int w = adj[i][v][(j+d)%l]; if (w == p){ continue; }
		dfs(i, w, v);
	}
	if (v != p){ res[i][len[i]++] = g(chr[i][v]); }
}
int jmp[500020]; int prf[1000020];
bool solve(int n, int c0, int c1){
	if (c0 == -1 || c1 == -1){ return 0; }
	memcpy(chr, str, sizeof(str)); shift(0, 0, 0, c0); shift(1, 0, 0, c1);
	len[0] = len[1] = 0; dfs(0, c0, c0); dfs(1, c1, c1);
	int l0 = len[0], l1 = len[1];
	for (int i = 0; i < l0; i++){ res[0][i+l0] = res[0][i]; } l0 += l0;
	for (int i = 0; i < l0; i++){
		prf[i] = (i==0 ? 0 : prf[i-1]) + (f(res[0][i]) ? +1 : -1);
	}
	int j = 0; jmp[0] = 0; for (int i = 1; i < l1; i++){
		while (j != 0){
			if (res[1][i] == res[1][j]){ break; } else{ j = jmp[j-1]; }
		} if (res[1][i] == res[1][j]){ j += 1; } jmp[i] = j;
	}
	j = 0; for (int i = 0; i < l0; i++){
		while (j != 0){
			if (res[0][i] == res[1][j]){ break; } else{ j = jmp[j-1]; }
		} if (res[0][i] == res[1][j]){
			if (j+1 == l1){
				int p = i-l1+1; if (p == 0 || prf[p-1] == 0){ return 1; }
				j = jmp[j];
			} else{ j += 1; }
		}
	} return 0;
}

void Main(){
	int n = -1; for (int p = 0; p < 2; p++){
		string s; cin >> s; int sl = s.size();
		if (p == 1 && n != sl){ cout << "NO"; return; } n = sl;
		str[p][0] = ' '; for (int i = 1; i <= sl; i++){ str[p][i] = s[i-1]; }
	} init(0, n); init(1, n);
	pi2 c0 = centroid(0, 0), c1 = centroid(1, 0);
	if (solve(n, c0.fr, c1.fr)){ cout << "YES"; return; }
	if (solve(n, c0.fr, c1.sc)){ cout << "YES"; return; }
	cout << "NO";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION); Main();
}