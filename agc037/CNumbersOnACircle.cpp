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

class CNumbersOnACircle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int calc(vector<int>& A) {
        priority_queue<pair<int, int>> pq;
        int sz = A.size();
        REP(i, sz) {
            pq.push({A[i], i});
        }
        int res = 0;
        while (!pq.empty()) {
            int val, idx;
            tie(val, idx) = pq.top();
            pq.pop();

            int l = idx > 0 ? idx - 1 : sz - 1;
            int r = idx < sz - 1 ? idx + 1 : 0;

            int bc = A[l] + A[r];
            if (A[idx] <= bc) continue;

            res += (A[idx] - 1) / bc;
            A[idx] %= bc;
            if (A[idx] == 0) A[idx] = bc;

            pq.push({A[idx], idx});
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];

        int a = calc(A);
        int b = calc(B);
        if (A == B && b >= a) {
            cout << b - a << endl;
        } else {
            cout << -1 << endl;
        }
    }
};
