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

class DMovingPiece {
public:
    map<int, int> par, point, size;
    vector<int> P, C;
    int sum = 0;
    int sz = 0;

    void dfs(int v, int p) {
        if (par.count(v)) return;
        par[v] = p;
        sum += C[v];
        sz++;
        dfs(P[v], p);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        P.resize(N);
        C.resize(N);
        REP(i, N) {
            cin >> P[i];
            P[i]--;
        }
        REP(i, N) cin >> C[i];

        REP(i, N) {
            if (par.count(i)) continue;
            sum = 0;
            sz = 0;
            dfs(i, i);
            point[i] = sum;
            size[i] = sz;
        }

        int res = -INF;
        REP(i, N) {
            int p = par[i];
            int cur = i;
            int tmp = 0;
            if (K <= N) {
                REP(j, K) {
                    tmp += C[P[cur]];
                    cur = P[cur];
                    res = max(res, tmp);
                }
                continue;
            }
            if (point[p] > 0) {
                int num = K / size[p];
                num = max(num - 1, 0LL);
                tmp = num * point[p];
                int rem = K - num * size[p];
                if (num > 0) res = max(res, tmp);
                REP(j, rem) {
                    tmp += C[P[cur]];
                    cur = P[cur];
                    res = max(res, tmp);
                }
            } else {
                REP(j, min(size[p], K)) {
                    tmp += C[P[cur]];
                    cur = P[cur];
                    res = max(res, tmp);
                }
            }
        }
        cout << res << endl;
    }
};
