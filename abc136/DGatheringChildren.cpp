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

class DGatheringChildren {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> L(n + 1), R(n + 1);
        REP(i, n) {
            R[i + 1] = R[i];
            if (s[i] == 'R') {
                R[i + 1]++;
            } else {
                R[i + 1] = 0;
            }
        }
        REV(i, n, 1) {
            L[i - 1] = L[i];
            if (s[i] == 'L') {
                L[i - 1]++;
            } else {
                L[i - 1] = 0;
            }
        }

        vector<int> res(n);
        REP(i, n - 1) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                int r = R[i];
                int l = L[i + 1];
                int k = (r + l + 2) / 2;
                if (r == l || (r % 2 == l % 2)) {
                    res[i] = k;
                    res[i + 1] = k;
                } else if (r % 2 == 1) {
                    res[i] = k;
                    res[i + 1] = k + 1;
                } else {
                    res[i] = k + 1;
                    res[i + 1] = k;
                }
                i++;
            }
        }
        REP(i, n) {
            cout << res[i] << " ";
        }
        cout << endl;

    }
};
