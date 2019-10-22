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

class ELISDL {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, A, B;
        cin >> N >> A >> B;

        if (A + B - 1 > N) {
            cout << -1 << endl;
            return;
        }
        if (A * B < N) {
            cout << -1 << endl;
            return;
        }

        vector<int> res;
        int remain = N - A;
        int cur = N;
        REP(i, A) {
            int num = min(remain, B - 1);
            REP(j, num + 1) {
                res.push_back(cur - num + j);
            }
            remain -= num;
            cur -= (num + 1);
        }
        reverse(res.begin(), res.end());

        REP(i, N) cout << res[i] << " ";
    }
};
