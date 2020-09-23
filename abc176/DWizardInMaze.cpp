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

class DWizardInMaze {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    int H, W, si, sj, gi, gj;

    int id(int x, int y) {
        return x * W + y;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W;
        cin >> si >> sj >> gi >> gj;
        si--, sj--, gi--, gj--;
        vector<vector<char>> S(H, vector<char>(W));
        vector<vector<bool>> visit(H, vector<bool>(W));
        REP(i, H) REP(j, W) cin >> S[i][j];

        UnionFind uf(H * W);

        REP(i, H) {
            REP(j, W) {
                if (S[i][j] == '#') continue;
                if (visit[i][j]) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i][j] = true;
                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    REP(k, 4) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                        if (S[nx][ny] == '#') continue;
                        if (visit[nx][ny]) continue;
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                        uf.unite(x * W + y, nx * W + ny);
                    }
                }
            }
        }
        map<int, set<int>> G;
        REP(i, H) {
            REP(j, W) {
                if (S[i][j] == '#') continue;
                for (int di = -2; di <= 2; di++) {
                    for (int dj = -2; dj <= 2; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni < 0 || nj < 0 || ni >= H || nj >= W) continue;
                        if (S[ni][nj] == '#') continue;
                        if (uf.same(i * W + j, ni * W + nj)) continue;
                        G[uf.find(id(i, j))].insert(uf.find(id(ni, nj)));
                        G[uf.find(id(ni, nj))].insert(uf.find(id(i, j)));
                    }
                }
            }
        }

        if (uf.same(id(si, sj), id(gi, gj))) {
            cout << 0 << endl;
            return;
        }

        queue<pair<int, int>> q;
        q.push({uf.find(id(si, sj)), 0});
        set<int> s;
        s.insert(uf.find(id(si, sj)));
        while (!q.empty()) {
            int x, d;
            tie(x, d) = q.front();
            q.pop();
            if (x == uf.find(id(gi, gj))) {
                cout << d << endl;
                return;
            }
            for (auto to : G[x]) {
                if (s.count(to)) continue;
                s.insert(to);
                q.push({to, d + 1});
            }
        }
        cout << -1 << endl;
    }

};
