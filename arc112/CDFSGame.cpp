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

class CDFSGame {
public:
    vector<vector<int>> G;
    vector<int> num, memo;

    int dfs1(int v, int p) {
        int n = 0;
        for (auto to : G[v]) {
            if (to == p) continue;
            n += dfs1(to, v);
        }
        return num[v] = n + 1;
    }

    int dfs2(int v, int p) {
        if (memo[v] != -1) return memo[v];
        int res = 1;
        int evenp = 0;
        vector<int> odd;
        for (auto to : G[v]) {
            if (to == p) continue;
            int d = dfs2(to, v);
            if (num[to] % 2 == 1) {
                odd.push_back(d);
            } else {
                if (d < 0) {
                    res += d;
                } else {
                    evenp += d;
                }
            }
        }
        sort(odd.begin(), odd.end());
        odd.push_back(evenp);
        for (int i = 0; i < odd.size(); i++) {
            int d = odd[i];
            if (i % 2 == 0) {
                res += d;
            } else {
                res += -d;
            }
        }
        return memo[v] = res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> P(N);
        G.resize(N);
        num.resize(N);
        memo = vector<int>(N, -1);
        FOR(i, 1, N - 1) {
            int p;
            cin >> p;
            p--;
            P[i] = p;
            G[p].push_back(i);
        }
        dfs1(0, -1);

        int d = dfs2(0, -1);
        cout << (N + d) / 2 << endl;
    }
};
