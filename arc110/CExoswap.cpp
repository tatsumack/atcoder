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

class CExoswap {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> P(N), pos(N);
        REP(i, N) {
            int p;
            cin >> p;
            p--;
            P[i] = p;
            pos[p] = i;
        }

        int cur = 0;
        vector<int> res;
        REP(i, N) {
            if (i < cur) continue;
            int prev = cur;
            cur = pos[i];
            int p = cur;
            while (p - 1 >= prev) {
                res.push_back(p - 1);
                swap(P[p - 1], P[p]);
                p--;
            }
            FOR(i, prev, cur - 1) {
                if (P[i] != i) {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        REP(i, res.size()) cout << res[i] + 1 << endl;
    }
};
