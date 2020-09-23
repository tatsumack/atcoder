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

#define ll long long
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

class CWalkingTakahashi {
public:
    static constexpr unsigned int kStressIterations = 100000;

    static void generateTest(std::ostream& test) {
        int X = rand() % 1000;
        int K = rand() % 1000;
        int D = rand() % 1000;
        test << -X << " " << K + 1 << " " << D + 1;
    }

    void validate(std::istream& cin, std::ostream& cout) {
        ll X, K, D;
        cin >> X >> K >> D;
        X = abs(X);
        ll num = X / D;
        if (num > K) {
            cout << X - K * D << endl;
            return;
        }

        K -= num;
        ll res = X - D * num;
        if (K % 2 == 0) {
            cout << res << endl;
        } else {
            cout << abs(D - res) << endl;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        ll X, K, D;
        cin >> X >> K >> D;
        X = abs(X);
        ll num = X / D;
        if (X > K * D) {
            cout << X - K * D << endl;
            return;
        }

        K -= num;
        ll res = X - D * num;
        if (K % 2 == 0) {
            cout << res << endl;
        } else {
            cout << abs(D - res) << endl;
        }
    }
};
