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

class EMaxGCD {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);

        int sum = 0;
        REP(i, N) {
            cin >> A[i];
            sum += A[i];
        }

        vector<int> cand;
        for (int i = 1; i * i <= sum; i++) {
            cand.push_back(i);
            cand.push_back(sum / i);
        }
        sort(cand.begin(), cand.end());

        int res = 1;
        for (int n: cand) {
            if (sum % n != 0) continue;
            vector<int> r;
            REP(i, N) {
                r.push_back(A[i] % n);
            }
            sort(r.begin(), r.end());
            int s = 0;
            REP(i, r.size()) s += n - r[i];
            int x = 0;
            bool ok = true;
            REP(i, r.size()) {
                x += r[i];
                s -= n - r[i];
                if (x == s) {
                    if (x > K) {
                        ok = false;
                    }
                    break;
                }
            }
            if (ok) {
                res = n;
            }
        }
        cout << res << endl;
    }
};
