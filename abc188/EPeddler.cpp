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

class EPeddler {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), sell(N, INF), in(N);
        REP(i,N) cin >> A[i];
        vector<vector<int>> G(N);
        REP(i, M) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            G[x].push_back(y);
            in[y]++;
        }

        queue<int> q;
        REP(i, N) {
            if (in[i] == 0) q.push(i);
        }

        int res = -INF;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (sell[i] != INF) {
                res  = max(res, A[i] - sell[i]);
            }
            for (int to : G[i]) {
                in[to]--;
                sell[to] = min({sell[to], sell[i], A[i]});
                if (in[to] == 0) {
                    q.push(to);
                }
            }
        }
        cout << res << endl;
    }
};
