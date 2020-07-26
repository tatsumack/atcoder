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

class EMsSolution {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> v(N);
        REP(i, N) {
            int x, y, p;
            cin >> x >> y >> p;
            v[i] = {x, y, p};
        }

        map<int, vector<vector<int>>> mx, my;
        map<int, vector<int>> minx, miny;
        vector<int, int> minvalx(N+1, INF), minvaly(N+1, INF);
        REP(i, 1 << N) {
            int cnt = 0;
            REP(j, N) if (i >> j & 1) cnt++;
            vector<int> X, Y;
            REP(j, N) {
                int x, y, p;
                tie(x, y, p) = v[j];
                if (i >> j & 1) {
                    X.push_back(x);
                }
                if (i >> j & 1) {
                    Y.push_back(y);
                }
            }
            int tmp = 0;
            REP(i, N) {
                int x, y, p;
                tie(x, y, p) = v[i];
                int val = p * min(abs(x), abs(y));
                for (auto valx : X) val = min(val, p * abs(x - valx));
                for (auto valy : Y) val = min(val, p * abs(y - valy));
                tmp += val;
            }
            mx[cnt].push_back(X);
            my[cnt].push_back(Y);
        }

        FOR(k, 0, N) {
            int res = INF;
            FOR(kx, 0, k) {
                int ky = k - kx;
                auto vx = mx[kx];
                auto vy = my[ky];
                if (vx.empty()) vx.push_back({0});
                if (vy.empty()) vy.push_back({0});
                for (auto vvx : vx) {
                    for (auto vvy : vy) {
                        int tmp = 0;
                        REP(i, N) {
                            int x, y, p;
                            tie(x, y, p) = v[i];
                            int val = p * min(abs(x), abs(y));
                            for (auto valx : vvx) val = min(val, p * abs(x - valx));
                            for (auto valy : vvy) val = min(val, p * abs(y - valy));
                            tmp += val;
                        }
                        res = min(res, tmp);
                    }
                }
            }
            cout << res << endl;
        }

    }
};
