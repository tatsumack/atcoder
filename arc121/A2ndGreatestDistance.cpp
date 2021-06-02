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

class A2ndGreatestDistance {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> x(N), y(N);
        vector<pair<int, int>> vx(N), vy(N);
        REP(i, N) {
            cin >> x[i] >> y[i];
            vx[i] = {x[i], i};
            vy[i] = {y[i], i};
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        vector<int> cand;
        cand.push_back(vx[0].second);
        cand.push_back(vx[1].second);
        cand.push_back(vx[N - 1].second);
        cand.push_back(vx[N - 2].second);
        cand.push_back(vy[0].second);
        cand.push_back(vy[1].second);
        cand.push_back(vy[N - 1].second);
        cand.push_back(vy[N - 2].second);
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        vector<int> res;
        REP(ci, cand.size()) {
            int i = cand[ci];
            FOR(cj, ci + 1, cand.size() - 1) {
                int j = cand[cj];
                res.push_back(max(abs(x[i] - x[j]), abs(y[i] - y[j])));
            }
        }
        sort(res.rbegin(), res.rend());
        cout << res[1] << endl;
    }
};
