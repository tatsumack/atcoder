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

class BZL {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int id(char c) {
        if (is_num(c)) {
            return c - '0';
        }
        return c - 'A' + 10;
    }

    bool is_num(char c) {
        return '0' <= c && c <= '9';
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        UnionFind uf(100);

        REP(i, n) {
            char c1 = s1[i];
            char c2 = s2[i];
            uf.unite(id(c1), id(c2));
        }

        int res = 1;
        set<int> checked;
        REP(i, n) {
            char c = s1[i];
            int par = uf.par[id(c)];
            if (checked.count(par)) continue;
            if (is_num(c)) continue;

            bool found = false;
            REP(j, 10) {
                if (uf.same(id(c), j)) {
                    found = true;
                    break;
                }
            }
            if (found) continue;

            if (i == 0) {
                res *= 9;
            } else {
                res *= 10;
            }

            checked.insert(par);
        }

        cout << res << endl;
    }
};
