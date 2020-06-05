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

class DDoubleDots {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> G(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> res(N, -1);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto to : G[x]) {
                if (res[to] != -1) continue;
                res[to] = x;
                q.push(to);
            }
        }

        for (int i = 1; i < N; i++) {
            if (res[i] == -1) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        for (int i = 1; i < N; i++) cout << res[i] + 1 << endl;
    }
};
