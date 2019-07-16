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

class CSkolemXORTree {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        if ((N & -N) == N) {
            cout << "No" << endl;
            return;
        }

        cout << "Yes" << endl;

        vector<P> ans;
        ans.emplace_back(N + 1, 2);

        for (int i = 2; i + 1 <= N; i += 2) {
            ans.emplace_back(i, i + 1);
            ans.emplace_back(i + 1, 1);
            ans.emplace_back(1, N + i);
            ans.emplace_back(N + i, N + i + 1);
        }

        if (N % 2 == 0) {
            int i = N & -N;
            int t = N ^ 1 ^ i;
            if (i % 2 == 0) i += N;
            if (t % 2 == 0) t += N;
            ans.emplace_back(N, i);
            ans.emplace_back(2 * N, t);
        }

        REP(i, ans.size()) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
};
