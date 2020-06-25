#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class FPondSkater {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, K;
        cin >> H >> W >> K;
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        sx--, sy--, gx--, gy--;

        vector<vector<char>> c(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> c[i][j];

        vector<vector<int>> dist(H, vector<int>(W, INT_MAX));
        dist[sx][sy] = 0;

        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, 0, -1});
        while (!q.empty()) {
            int x, y, d, prev;
            tie(x, y, d, prev) = q.front();
            q.pop();
            if (dist[x][y] < d) continue;
            dist[x][y] = d;

            REP(k, 4) {
                if (prev == 0 && k == 1) continue;
                if (prev == 1 && k == 0) continue;
                if (prev == 2 && k == 3) continue;
                if (prev == 3 && k == 2) continue;
                int nx = x + dx[k];
                int ny = y + dy[k];
                while (0 <= nx && nx < H && 0 <= ny && ny < W) {
                    if (dist[nx][ny] <= d) break;
                    if (abs(nx - x) > K || abs(ny - y) > K) break;
                    if (c[nx][ny] == '@') break;
                    q.push({nx, ny, d + 1, k});
                    dist[nx][ny] = min(dist[nx][ny], d + 1);
                    nx += dx[k];
                    ny += dy[k];
                }
            }
        }
        if (dist[gx][gy] == INT_MAX) {
            cout << -1 << endl;
            return;
        }
        cout << dist[gx][gy] << endl;

    }
};
