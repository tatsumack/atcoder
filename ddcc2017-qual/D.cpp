
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W, A, B;
    cin >> H >> W >> A >> B;

    int id = 1;
    vector<vector<int>> m(H, vector<int>(W, 0));
    map<int, pair<int, int>> mmap;
    REP(i, H) {
        REP(j, W) {
            char c;
            cin >> c;
            if (c != 'S') continue;

            m[i][j] = id;
            mmap[id] = {i, j};
            id++;
        }
    }

    set<int> ew;
    set<int> ns;
    REP(i, H) {
        REP(j, W) {
            if (m[i][j] == 0) continue;
            if (m[H - 1 - i][j] == 0) ns.insert(m[i][j]);
            if (m[i][W - 1 - j] == 0) ew.insert(m[i][j]);
        }
    }

    int ans = 0;
    while (!ns.empty() || !ew.empty()) {
        if (A > B) {
            if (!ns.empty()) {
                int t = *(ns.begin());
                auto kv = mmap[t];
                m[kv.first][kv.second] = 0;
                ns.erase(t);
                ew.erase(t);

                if (m[kv.first][W - 1 - kv.second] > 0) {
                    ew.insert(m[kv.first][W - 1 - kv.second]);
                }
            } else {
                int t = *(ew.begin());
                auto kv = mmap[t];
                m[kv.first][kv.second] = 0;
                ns.erase(t);
                ew.erase(t);

                if (m[H - 1 - kv.first][kv.second] > 0) {
                    ns.insert(m[H - 1 - kv.first][kv.second]);
                }
            }
        }
        else {
            if (!ew.empty()) {
                int t = *(ew.begin());
                auto kv = mmap[t];
                m[kv.first][kv.second] = 0;
                ns.erase(t);
                ew.erase(t);

                if (m[H - 1 - kv.first][kv.second] > 0) {
                    ns.insert(m[H - 1 - kv.first][kv.second]);
                }
            } else {
                int t = *(ns.begin());
                auto kv = mmap[t];
                m[kv.first][kv.second] = 0;
                ns.erase(t);
                ew.erase(t);

                if (m[kv.first][W - 1 - kv.second] > 0) {
                    ew.insert(m[kv.first][W - 1 - kv.second]);
                }
            }
        }

        if (ns.empty()) ans += A;
        if (ew.empty()) ans += B;
    }
    cout << ans << endl;

    return 0;
}


