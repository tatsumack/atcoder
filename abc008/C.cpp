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

class C {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> C(N);
        REP(i, N) cin >> C[i];
        sort(C.begin(), C.end());

        vector<int> v(N);
        REP(i, N) {
            REP(j, N) {
                if (i == j) continue;
                if (C[i] % C[j] == 0) {
                    v[i]++;
                }
            }
        }

        double res = 0;
        REP(i, N) {
            int num = v[i];
            if (num & 1) {
                res += ((num + 1) / 2) / (double) (num + 1);
            } else {
                res += (num / 2 + 1) / (double) (num + 1);
            }
        }
        fcout << res << endl;
    }
};
