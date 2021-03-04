#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class FZebraness {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<vector<char>> c(N, vector<char>(N));
        map<pair<int, int>, int> id;
        int cur = 0;
        REP(i, N) {
            REP(j, N) {
                cin >> c[i][j];
                id[{i, j}] = cur++;
                if ((i + j) % 2 == 1) {
                    if (c[i][j] == 'B') {
                        c[i][j] = 'W';
                    } else if (c[i][j] == 'W') {
                        c[i][j] = 'B';
                    }
                }
            }
        }
        int s = N * N;
        int t = s + 1;

        atcoder::mf_graph<int> g(N * N + 2);
        REP(i, N) {
            REP(j, N) {
                if (i - 1 >= 0) g.add_edge(id[{i, j}], id[{i - 1, j}], 1);
                if (i + 1 < N) g.add_edge(id[{i, j}], id[{i + 1, j}], 1);
                if (j - 1 >= 0) g.add_edge(id[{i, j}], id[{i, j - 1}], 1);
                if (j + 1 < N) g.add_edge(id[{i, j}], id[{i, j + 1}], 1);
                if (c[i][j] == 'B') {
                    g.add_edge(s, id[{i, j}], 0);
                    g.add_edge(id[{i, j}], t, INF);
                }
                if (c[i][j] == 'W') {
                    g.add_edge(s, id[{i, j}], INF);
                    g.add_edge(id[{i, j}], t, 0);
                }
                if (c[i][j] == '?') {
                    g.add_edge(s, id[{i, j}], 0);
                    g.add_edge(id[{i, j}], t, 0);
                }
            }
        }
        cout << 2 * N * (N - 1) - g.flow(s, t) << endl;
    }
};
