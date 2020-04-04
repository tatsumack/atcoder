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

class DLine {
public:
    map<int, int> cnt;
    vector<vector<int>> G;

    void solve(std::istream& cin, std::ostream& cout) {
        int N, X, Y;
        cin >> N >> X >> Y;
        X--, Y--;
        G.resize(N);
        REP(i, N - 1) {
            G[i].push_back(i + 1);
            G[i + 1].push_back(i);
        }
        G[X].push_back(Y);
        G[Y].push_back(X);
        REP(i, N) {
            queue<pair<int, int>> q;
            q.push({i, 0});
            set<int> used;
            while (!q.empty()) {
                auto kv = q.front();
                q.pop();
                int p = kv.first;
                int d = kv.second;
                if (used.count(p)) continue;
                used.insert(p);
                cnt[d]++;
                for (auto to : G[p]) {
                    if (used.count(to)) continue;
                    q.push({to, d + 1});
                }
            }
        }

        FOR(k, 1, N - 1) {
            cout << cnt[k] / 2 << endl;
        }
    }
};
