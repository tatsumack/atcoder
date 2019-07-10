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

class B {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N, M, K;
    vector<int> A, B;

    bool check(int x) {

        int cur = 0;
        int num = 0;
        REP(i, A.size()) {
            while (cur < B.size() && B[cur] < A[i] - x) {
                cur++;
            }
            if (cur >= B.size()) return false;
            if (B[cur] > A[i] + x) continue;

            num++;
            cur++;
            if (num == K) return true;
        }
        return false;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M >> K;
        A = vector<int>(N);
        REP(i, N) cin >> A[i];
        B = vector<int>(M);
        REP(i, M) cin >> B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int l = -1;
        int r = INF;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << r << endl;
    }
};
