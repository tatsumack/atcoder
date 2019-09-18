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

class EFrequency {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        map<int, int> m, pos;
        REP(i, N) {
            int a;
            cin >> a;
            m[a]++;
            if (pos.count(a) == 0) pos[a] = i;
        }

        priority_queue<pair<int, int>> q;
        for (auto kv : m) {
            q.push({kv.first, kv.second});
        }

        vector<int> res(N);
        int cur = 0;
        int minPos = INF;
        while (!q.empty()) {
            auto kv = q.top();
            q.pop();
            cur += kv.second;
            minPos = min(minPos, pos[kv.first]);
            if (q.empty()) {
                res[minPos] += kv.first * cur;
                break;
            }
            auto nkv = q.top();
            res[minPos] += (kv.first - nkv.first) * cur;
        }
        REP(i, N) cout << res[i] << endl;
    }
};
