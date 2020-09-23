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

class FIHateShortestPathProblem {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<int> A(H), B(H);
        REP(i, H) {
            cin >> A[i] >> B[i];
            A[i]--, B[i]--;
        }
        set<tuple<int, int, int>> s;
        s.insert({0, W - 1, 0});
        vector<int> res(H, INF);
        REP(i, H) {
            vector<pair<int, int>> v;
            if (A[i] > 0) {
                v.push_back({0, A[i] - 1});
            }
            if (B[i] < W - 1) {
                v.push_back({B[i] + 1, W - 1});
            }
            for (auto kv : v) {
                int a, b;
                tie(a, b) = kv;
                for (auto t : s) {
                    int l, r, d;
                    tie(l, r, d) = t;
                    if (b < l) continue;
                    s.erase(t);
                    if (r < a) {
                        int val = d + a - r + 1;
                        s.insert({a, a, val});
                        res[i] = min(res[i], val);
                    } else {
                        int val = d + 1;
                        s.insert({max(l, a), min(r, b), val});
                        res[i] = min(res[i], val);
                    }
                }
            }
        }
        REP(i, H) {
            if (res[i] == INF) res[i] = -1;
            cout << res[i] << endl;
        }
    }
};
