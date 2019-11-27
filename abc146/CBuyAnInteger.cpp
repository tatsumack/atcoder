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

class CBuyAnInteger {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int A, B, X;

    bool check(int n) {
        int d = 0;
        int nn = n;
        while (nn > 0) {
            nn /= 10;
            d++;
        }
        return A * n + B * d <= X;
    }


    void solve(std::istream& cin, std::ostream& cout) {
        cin >> A >> B >> X;

        int ok = 0;
        int ng = 1000000001;
        while (ng - ok > 1) {
            int mid = (ng + ok) / 2;
            if (check(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok << endl;
    }
};
