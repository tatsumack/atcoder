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

class EFriendships {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;

        if (N == 2) {
            if (K != 0) {
                cout << -1 << endl;
            } else {
                cout << 1 << endl;
                cout << 1 << " " << 2 << endl;
            }
            return;
        }

        int c = N - 2;
        int max = c + c * (c - 1) / 2;
        if (K > max) {
            cout << -1 << endl;
            return;
        }

        vector<P> v;
        v.emplace_back(1, 2);
        REP(i, c) {
            v.emplace_back(2, i + 3);
        }

        int diff = max - K;
        FOR(i, 3, N) {
            FOR(j, i + 1, N) {
                if (diff == 0) break;
                v.emplace_back(i, j);
                diff--;
            }
        }
        if (diff > 0) {
            FOR(i, 3, N) {
                if (diff == 0) break;
                v.emplace_back(1, i);
                diff--;
            }
        }
        cout << v.size() << endl;
        REP(i, v.size()) {
            cout << v[i].first << " " << v[i].second << endl;
        }

    }
};
