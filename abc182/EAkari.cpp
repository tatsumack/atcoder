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

class EAkari {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, N, M;
        cin >> H >> W >> N >> M;
        vector<int> A(N), B(N), C(M), D(M);
        vector<vector<int>> block(H, vector<int>(W));
        REP(i, N) {
            cin >> A[i] >> B[i];
            A[i]--, B[i]--;
        }
        REP(i, M) {
            cin >> C[i] >> D[i];
            C[i]--, D[i]--;
            block[C[i]][D[i]] = 1;
        }

        vector<set<pair<int, int>>> sh(W), sw(H);
        REP(i, N) {
            sh[B[i]].insert({A[i], 1});
            sw[A[i]].insert({B[i], 1});
        }
        REP(i, M) {
            sh[D[i]].insert({C[i], 2});
            sw[C[i]].insert({D[i], 2});
        }

        int res = 0;
        REP(i, H) {
            REP(j, W) {
                if (block[i][j]) continue;
                {
                    auto itr = sh[j].upper_bound({i, 0});
                    if (itr != sh[j].end()) {
                        if (itr->second == 1) {
                            res++;
                            continue;
                        }
                    }
                    if (itr != sh[j].begin()) {
                        itr--;
                        if (itr->second == 1) {
                            res++;
                            continue;
                        }
                    }
                }
                {
                    auto itr = sw[i].upper_bound({j, 0});
                    if (itr != sw[i].end()) {
                        if (itr->second == 1) {
                            res++;
                            continue;
                        }
                    }
                    if (itr != sw[i].begin()) {
                        itr--;
                        if (itr->second == 1) {
                            res++;
                            continue;
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
};
