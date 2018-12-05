
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> p(N, -1);
    vector<vector<int>> c(N);
    int root = -1;
    REP(i, N) {
        int pp;
        cin >> pp;
        if (pp == 0) {
            root = i;
            continue;
        }
        pp--;
        p[i] = pp;
        c[p[i]].push_back(i);
    }

    // bfs
    vector<int> d(N);
    int depth = 1;
    d[root] = depth;
    queue<pair<int, int>> q;
    q.push({root, depth});
    while (!q.empty()) {
        auto kv = q.front();
        q.pop();
        REP(i, c[kv.first].size()) {
            int cc = c[kv.first][i];
            d[cc] = kv.second + 1;
            q.push({cc, kv.second + 1});
        }
    }

    vector<int> ans;
    vector<bool> used(N);
    int k = K;
    FOR(m, 1, M) {
        REP(x, N) {
            if (used[x]) continue;
            queue<int> q;
            q.push(x);
            vector<bool> tmp = used;
            tmp[x] = true;
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                REP(i, c[t].size()) {
                    int cc = c[t][i];
                    if (tmp[cc]) continue;
                    tmp[cc] = true;
                    q.push(cc);
                }
            }

            int remain = 0;
            vector<int> dd;
            REP(i, N) {
                if (tmp[i]) continue;
                dd.push_back(d[i]);
                remain++;
            }
            if (remain < M - m) continue;

            int a = 0, b = 0;
            sort(dd.begin(), dd.end());
            REP(i, dd.size()) {
                if (i == M - m) break;
                a += dd[i];
            }
            sort(dd.begin(), dd.end(), greater<int>());
            REP(i, dd.size()) {
                if (i == M - m) break;
                b += dd[i];
            }
            if (k - d[x] < a || b < k - d[x]) continue;

            k -= d[x];
            ans.push_back(x);
            used = tmp;
            break;
        }
    }

    if (ans.size() != M) {
        cout << -1 << endl;
    } else {
        REP(i, ans.size()) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
