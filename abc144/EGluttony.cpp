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

class EGluttony {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> A, F;
    int N, K;

    bool check(int x) {
        int cur = K;
        REP(i, N) {
            int v = x / F[i];
            v = max(0LL, A[i] - v);
            if (cur < v) {
                return false;
            }
            cur -= v;
        }
        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> K;
        A.resize(N);
        F.resize(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> F[i];
        sort(A.begin(), A.end());
        sort(F.rbegin(), F.rend());

        int l = -1;
        int r = INF;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << r << endl;
    }
};
