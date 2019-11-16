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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int H, W, T;
    vector<vector<char>> s;

    typedef pair<int, pair<int, int>> PP;
    P start, goal;

    bool check(int val) {
        priority_queue<PP, vector<PP>, greater<PP> > que;
        vector<vector<int>> dist(H, vector<int>(W, INF));
        dist[start.first][start.second] = 0;
        que.push(PP(0, start));

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
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

                int cost = s[nx][ny] == '#' ? val : 1;
                if (dist[nx][ny] > p.first + cost) {
                    dist[nx][ny] = p.first + cost;
                    que.push(PP(dist[nx][ny], {nx, ny}));
                }
            }
        }
        return dist[goal.first][goal.second] <= T;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W >> T;
        s = vector<vector<char>>(H, vector<char>(W));
        REP(i, H) {
            REP(j, W) {
                cin >> s[i][j];
                if (s[i][j] == 'S') start = {i, j};
                if (s[i][j] == 'G') goal = {i, j};
            }
        }

        int ok = 1;
        int ng = T + 1;
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (check(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok << endl;
    }
};
