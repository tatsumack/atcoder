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

class BDoNotDuplicate {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        map<int, vector<int>> idx;
        REP(i, N) {
            cin >> A[i];
            idx[A[i]].push_back(i);
        }

        vector<int> next(N);
        for (auto kv: idx) {
            auto& b = kv.second;
            int m = b.size();
            b.push_back(kv.second[0] + N);
            REP(i, m) {
                next[b[i]] = b[i + 1] - b[i] + 1;
            }
        }

        int L = 60;
        vector<vector<int>> dnext(L + 1, vector<int>(N));
        dnext[0] = next;
        REP(l, L) {
            REP(i, N) {
                dnext[l + 1][i] = min(INF, dnext[l][i] + dnext[l][(i + dnext[l][i]) % N]);
            }
        }

        int k = N * K;
        int cur = 0;
        REV(l, 60, 0) {
            if (cur + dnext[l][cur % N] <= k) {
                cur += dnext[l][cur % N];
            }
        }
        if (cur == k) {
            cout << "" << endl;
            return;
        }

        vector<int> ans;
        set<int> s;
        FOR(i, cur % N, N - 1) {
            if (s.count(A[i])) {
                while (true) {
                    int v = ans.back();
                    ans.pop_back();
                    s.erase(v);
                    if (v == A[i]) break;
                }
            } else {
                ans.push_back(A[i]);
                s.insert(A[i]);
            }
        }

        REP(i, ans.size()) cout << ans[i] << " ";


    }
};
