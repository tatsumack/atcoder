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

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> m(H, vector<char>(W));

        int sx, sy, gx, gy;
        REP(i, H) REP(j, W) {
                cin >> m[i][j];
                if (m[i][j] == 's') {
                    sx = i, sy = j;
                }
                if (m[i][j] == 'g') {
                    gx = i, gy = j;
                }
            }

        priority_queue<P, vector<P>, greater<>> pq;
        pq.push({0, W * sx + sy});
        vector<int> dist(H * W, INF);
        dist[W * sx + sy] = 0;
        while (!pq.empty()) {
            int cost, pos;
            tie(cost, pos) = pq.top();
            pq.pop();
            if (cost > dist[pos]) continue;
            int x = pos / W;
            int y = pos % W;
            REP(i, 4) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
                int ncost = cost;
                if (m[nx][ny] == '#') ncost++;
                int npos = nx * W + ny;
                if (ncost < dist[npos]) {
                    dist[npos] = ncost;
                    pq.push({ncost, npos});
                }
            }
        }
        cout << (dist[gx * W + gy] <= 2 ? "YES" : "NO") << endl;
    }
};
