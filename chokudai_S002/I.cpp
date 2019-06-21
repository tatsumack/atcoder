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

class I {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> A, B;

    int fight(int i, int j) {
        int inum = (A[i] + B[j] - 1) / B[j];
        int jnum = (A[j] + B[i] - 1) / B[i];
        if (inum > jnum) {
            return i;
        } else if (inum < jnum) {
            return j;
        }
        return -1;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        A.resize(N);
        B.resize(N);
        REP(i, N) cin >> A[i] >> B[i];

        int cur = 0;
        FOR(i, 1, N - 1) {
            int res = fight(cur, i);
            if (res == -1) {
                continue;
            }
            cur = res;
        }

        bool ok = true;
        REP(i, N) {
            if (i == cur) continue;
            if (fight(cur, i) != cur) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << cur + 1 << endl;
        }
        else {
            cout << -1 << endl;
        }

    }
};
