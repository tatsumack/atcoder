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

class EGolf {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int K, X, Y;

    bool ok(int y) {
        int d = abs(Y - y);

        int res = 0;
        res += d / K;

        int r = d - (d / K) * K;
        return r % 2 == 0;
    }

    vector<P> calc(int y) {
        vector<P> v;
        int cur = X < 0 ? -K : K;
        while (abs(cur) < abs(X)) {
            v.emplace_back(cur, 0);
            if (X < 0) {
                cur -= K;
            } else {
                cur += K;
            }
        }
        v.emplace_back(X, y);

        while (abs(Y - y) > K) {
            if (Y - y > 0) {
                y += K;
            } else {
                y -= K;
            }
            v.emplace_back(X, y);
        }

        int ny = abs(Y - y) / 2;
        if (ny > 0) {
            if (v.size() == 1) {
                if (Y - y > 0) {
                    y += ny;
                } else {
                    y -= ny;
                }
                v.emplace_back(X + K - abs(ny), y);
            }
            else {
                int sz = v.size();
                v[sz - 1].second = Y
            }
        }
        v.emplace_back(X, Y);

        return v;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> K >> X >> Y;

        int y = K - abs(X) % K;
        if (!ok(-y) && !ok(y)){
            cout << "-1" << endl;
            return;
        }

        vector<P> v;
        if (ok(-y)) {
            v = calc(-y);
        }
        if (ok(y)) {
            auto tmp = calc(y);
            if (v.empty() || tmp.size() < v.size()) {
                v = tmp;
            }
        }

        cout << v.size() << endl;
        REP(i, v.size()) {
            cout << v[i].first << " " << v[i].second << endl;
        }

    }
};
