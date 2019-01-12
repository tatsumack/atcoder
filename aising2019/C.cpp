
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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

char s[500][500];
bool visit[500][500];
int num[500][500];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int H, W;

int bfs(int i, int j) {
    char c = s[i][j];
    if (c == '.') return 0;
    if (num[i][j] != -1) return num[i][j];

    CLR(visit, false);

    queue<pair<int, int>> q;
    REP(k, 4) {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
            continue;
        }
        if (s[nx][ny] == '#') continue;
        q.push({nx, ny});
    }


    vector<pair<int, int>> cand;
    int ans = 0;
    visit[i][j] = true;
    while (!q.empty()) {
        auto kv = q.front();
        q.pop();
        int kx = kv.first;
        int ky = kv.second;
        if (visit[kx][ky]) continue;
        visit[kx][ky] = true;

        if (s[kx][ky] == '.') {
            ans++;
            REP(k, 4) {
                int nx = dx[k] + kx;
                int ny = dy[k] + ky;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    continue;
                }
                if (s[nx][ny] == '.') continue;
                if (visit[nx][ny]) continue;
                q.push({nx, ny});
            }
        }
        else {
            cand.push_back({kx, ky});
            REP(k, 4) {
                int nx = dx[k] + kx;
                int ny = dy[k] + ky;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                    continue;
                }
                if (s[nx][ny] == '#') continue;
                if (visit[nx][ny]) continue;
                q.push({nx, ny});
            }
        }
    }

    for (auto kv : cand) {
        num[kv.first][kv.second] = ans;
    }
    return num[i][j] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> s[i][j];
            num[i][j] = -1;
        }
    }

    int ans = 0;
    REP(i, H) {
        REP(j, W) {
            ans += bfs(i, j);
        }
    }
    cout << ans << endl;

    return 0;
}
