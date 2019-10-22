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

class CTreeRestoring {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<int> a(N);
        REP(i, N) cin >> a[i];

        vector<int> d(101, 0);
        int len = 0;
        REP(i, N) {
            d[a[i]]++;
            len = max(a[i], len);
        }

        int pivot = len / 2;
        if (len & 1) pivot++;

        REP(i, pivot) {
            if (d[i] > 0) {
                cout << "Impossible" << endl;
                return;
            }
        }

        if (len % 2 == 0) {
            if (d[pivot] != 1) {
                cout << "Impossible" << endl;
                return;
            }
        } else {
            if (d[pivot] != 2) {
                cout << "Impossible" << endl;
                return;
            }
        }

        FOR(i, pivot + 1, len) {
            if (d[i] < 2) {
                cout << "Impossible" << endl;
                return;
            }
        }

        cout << "Possible" << endl;
        return;
    }
};
