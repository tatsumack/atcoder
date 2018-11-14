
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

    int K;
    cin >> K;

    int n1 = 200 / K;
    pair<int, int> o1 = {100, 100};
    int ans1 = 0;
    REP(i, n1) {
        REP(j, n1) {
            vector<pair<int, int>> v = {
                    {i * K,     j * K},
                    {i * K,     j * K + K},
                    {i * K + K, j * K},
                    {i * K + K, j * K + K},
            };

            bool ok = true;
            REP(k, v.size()) {
                auto p = v[k];
                int d = (o1.first - p.first) * (o1.first - p.first) +
                        (o1.second - p.second) * (o1.second - p.second);
                if (d > 100 * 100) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans1++;
        }
    }

    int n2 = 300 / K;
    pair<int, int> o2 = {150, 150};
    int ans2 = 0;
    REP(i, n2) {
        REP(j, n2) {
            vector<pair<int, int>> v = {
                    {i * K,     j * K},
                    {i * K,     j * K + K},
                    {i * K + K, j * K},
                    {i * K + K, j * K + K},
            };

            bool ok = true;
            REP(k, v.size()) {
                auto p = v[k];
                int d = (o2.first - p.first) * (o2.first - p.first) +
                        (o2.second - p.second) * (o2.second - p.second);
                if (d > 150 * 150) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans2++;
        }
    }
    cout << ans1 << " " << ans2 << endl;

    return 0;
}
