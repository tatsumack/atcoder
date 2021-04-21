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

class APayToWin {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        vector<int> v = {2, 3, 5};
        while (T--) {
            int N, A, B, C, D;
            cin >> N >> A >> B >> C >> D;
            vector<int> c = {A, B, C};
            priority_queue<P, vector<P>, greater<>> q;
            int res = INF;
            q.push({0, N});
            map<int, int> memo;
            while (!q.empty()) {
                int cur, cost;
                tie(cost, cur) = q.top();
                q.pop();
                //cout << cur << ": " << cost << endl;
                if (cost >= res) break;
                if (cur <= 2e18 / D) res = min(res, cost + cur * D);

                REP(i, v.size()) {
                    int r = cur % v[i];
                    int next = cur / v[i];
                    int nextc = cost + r * D + c[i];
                    if (nextc < res && (!memo.count(next) || nextc < memo[next])) {
                        q.push({nextc, next});
                        memo[next] = nextc;
                    }
                    next = cur / v[i] + 1;
                    nextc = cost + (v[i] - r) * D + c[i];
                    if (nextc < res && (!memo.count(next) || nextc < memo[next])) {
                        q.push({nextc, next});
                        memo[next] = nextc;
                    }
                }
            }
            cout << res << endl;
        }
    }
};
