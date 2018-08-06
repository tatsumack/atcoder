
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N, M, K;
int sx, sy, gx, gy;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dist[1005][1005];
char S[1005][1005];
int e[4][200005];

typedef pair<int, pair<int, int>> PP;

void dijkstra() {
    priority_queue<PP, vector<PP>, greater<PP> > que;
    REP(i, N) REP(j, M) {
            dist[i][j] = INF;
        }
    dist[sx][sy] = 0;
    que.push(PP(0, {sx, sy}));

    while (!que.empty()) {
        PP p = que.top();
        que.pop();
        int x = p.second.first;
        int y = p.second.second;
        if (dist[x][y] < p.first)
            continue;
        REP(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (S[nx][ny] == '#') continue;

            int cost = e[i][p.first % K];
            if (cost < 0) continue;
            if (dist[nx][ny] > p.first + cost) {
                dist[nx][ny] = p.first + cost;
                que.push(PP(dist[nx][ny], {nx, ny}));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    string d;
    cin >> d;
    d += d;

    REP(i, N) REP(j, M) {
            cin >> S[i][j];
            if (S[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (S[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }

    REP(j, 4) e[j][d.size()] = -INF;
    REV(i, d.size() - 1, 0) {
        REP(j, 4) e[j][i] = e[j][i + 1] + 1;
        switch (d[i]) {
            case 'U':
                e[0][i] = 1;
                break;
            case 'D':
                e[1][i] = 1;
                break;
            case 'L':
                e[2][i] = 1;
                break;
            case 'R':
                e[3][i] = 1;
                break;
        }
    }

    dijkstra();

    int ans = dist[gx][gy] == INF ? -1 : dist[gx][gy];
    cout << ans << endl;

    return 0;
}
