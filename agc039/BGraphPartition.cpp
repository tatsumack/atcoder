#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;

    UnionFind(int size) : par(size), rank(size), vsize(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        vsize[x] += vsize[y];
        vsize[y] = vsize[x];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return vsize[find(x)]; }
};

class BGraphPartition {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        // 二部グラフ判定
        vector<vector<int>> G(N, vector<int>(N, 0));
        REP(i, N) REP(j, N) {
                char c;
                cin >> c;
                G[i][j] = c - '0';
            }

        UnionFind uf(N * 2);
        REP(i, N) {
            REP(j, N) {
                if (G[i][j] == 1) {
                    uf.unite(i, j + N);
                    uf.unite(i + N, j);
                }
            }
        }
        REP(i, N) {
            if (uf.same(i, i + N)) {
                cout << -1 << endl;
                return;
            }
        }

        int res = 0;
        REP(s, N) {
            set<int> v;
            vector<bool> used(N);
            v.insert(s);
            used[s] = true;
            int tmp = 0;
            while (!v.empty()) {
                tmp++;
                set<int> next;
                for (auto i : v) {
                    REP(j, N) {
                        if (G[i][j] == 1 && !used[j]) {
                            next.insert(j);
                            used[j] = true;
                        }
                    }
                }
                v = next;
            }
            res = max(res, tmp);
        }
        cout << res << endl;
    }
};
