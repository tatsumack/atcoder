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

class D {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N;
    vector<int> s, d;
    vector<int> visit;

    bool dfs(int x, int bit = 0) {
        if (s[bit] > x) return false;
        if (bit & 1) return true;
        visit[bit] = true;

        REP(i, N) {
            // タスクを実行
            if ((bit >> i & 1) == 0 && (bit & d[i]) == d[i]) {
                int next = bit | (1 << i);
                if (visit[next]) continue;
                if (dfs(x, next)) return true;
            }

            // タスクを削除
            if (bit >> i & 1) {
                int next = bit ^ (1 << i);
                if (visit[next]) continue;
                if (dfs(x, next)) return true;
            }
        }
        return false;
    }

    bool check(int x, int bit = 0) {
        visit.clear();
        visit.resize(1 << N);
        return dfs(x);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        vector<int> x(N);
        d.resize(N);
        REP(i, N) cin >> x[i];
        REP(i, N - 1) {
            int a;
            cin >> a;
            a--;
            int t = i + 1;
            d[a] |= 1 << t;
        }

        s.resize(1 << N);
        REP(i, 1 << N) {
            REP(j, N) {
                if (i >> j & 1) s[i] += x[j];
            }
        }

        int l = 0;
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
