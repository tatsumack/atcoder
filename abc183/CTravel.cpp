#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class CTravel {
public:
    map<int, int> visited;
    int N, K;
    vector<vector<int>> G;
    int res;
    void dfs(int v, int num, int cur) {
        if (num == N) {
            if (cur + G[v][0] == K) {
                res++;
            }
            return;
        }

        REP(i, N) {
            if (visited[i]) continue;
            visited[i] = 1;
            dfs(i, num+1, cur + G[v][i]);
            visited[i] = 0;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> K;
        G = vector<vector<int>>(N, vector<int>(N));
        REP(i, N) {
            REP(j, N) {
                cin >> G[i][j];
            }
        }
        res = 0;
        visited[0] = 1;
        dfs(0, 1, 0);

        cout << res << endl;
    }
};
