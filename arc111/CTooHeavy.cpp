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

class CTooHeavy {
public:
    vector<int> G;
    vector<int> A, B, P;
    vector<bool> visit;
    int N;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        A.resize(N);
        B.resize(N);
        G.resize(N);
        P.resize(N);
        visit.resize(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];
        REP(i, N) {
            int p;
            cin >> p;
            p--;
            G[p] = i;
            P[i] = p;
        }

        bool ok = true;
        REP(i, N) {
            if (i != P[i] && B[P[i]] >= A[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }
        vector<pair<int,int>> res;
        REP(i, N) {
            if (visit[i]) continue;
            if (i == G[i]) continue;
            int v = i;
            int minA = INF;
            int minB = INF;
            int pos = -1;
            while (!visit[v]) {
                visit[v] = true;
                minA = min(minA, A[v]);
                if (B[P[v]] < minB) {
                    minB = B[P[v]];
                    pos = v;
                }
                v = G[v];
            }
            if (minA <= minB) {
                ok = false;
                break;
            }
            int start = pos;
            while (G[pos] != start) {
                int next = G[pos];
                res.emplace_back(pos, next);
                pos = next;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }
        cout << res.size() << endl;
        REP(i, res.size()) {
            cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
        }
    }
};
