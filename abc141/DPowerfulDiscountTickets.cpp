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

class DPowerfulDiscountTickets {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        priority_queue<P> v;
        REP(i, N) {
            int a = 1;
            while (A[i] > (1LL << a)) a++;
            v.push({a, A[i]});
        }

        int cnt = 0;
        while (cnt < M) {
            auto kv = v.top();
            v.pop();
            if (kv.first == 0) break;
            v.push({kv.first - 1, kv.second / 2});
            cnt++;
        }

        int res = 0;
        while (!v.empty()) {
            auto kv = v.top();
            v.pop();
            res += kv.second;
        }
        cout << res << endl;
    }
};
