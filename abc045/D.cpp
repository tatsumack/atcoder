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
#define INF (3e15)

using namespace std;

int H, W, N;
typedef pair<int, int> P;
P points[100005];
map<P, int> mp;

int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W >> N;
    REP(i, N) {
        int x, y;
        cin >> y >> x;
        REP(j, 9) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx <= 1 || ny <= 1 || nx >= W || ny >= H) continue;
            mp[{nx, ny}]++;
        }
    }

    map<int, int> cnt;
    for (auto kv : mp) {
        cnt[kv.second]++;
    }

    cout << (H - 2) * (W - 2) - mp.size() << endl;
    REPS(i, 9) { cout << cnt[i] << endl; }

    return 0;
}
