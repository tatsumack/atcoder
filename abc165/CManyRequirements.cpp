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

class CManyRequirements {
public:
    int N, M, Q;
    vector<int> a, b, c, d;
    int res = 0;
    void dfs(vector<int>& cur) {
        if (cur.size() == N) {
            int tmp = 0;
            REP(i, Q) {
                if (cur[b[i]] - cur[a[i]] == c[i]) {
                    tmp += d[i];
                }
            }
            res = max(res, tmp);
            return;
        }
        int start = 1;
        if (!cur.empty()) {
            start = cur.back();
        }
        FOR(i, start, M) {
            cur.push_back(i);
            dfs(cur);
            cur.pop_back();
        }
    }
    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> Q;
        a.resize(Q);
        b.resize(Q);
        c.resize(Q);
        d.resize(Q);
        REP(i, Q) {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
            a[i]--, b[i]--;
        }
        vector<int> v;
        dfs(v);

        cout << res << endl;
    }
};
