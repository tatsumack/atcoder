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

class CCountOrder {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> P(N), Q(N);
        REP(i, N) cin >> P[i];
        REP(i, N) cin >> Q[i];

        vector<int> v;
        REP(i, N) v.push_back(i + 1);

        int a = 0;
        int b = 0;
        int cnt = 0;
        do {
            bool ok = true;
            REP(i, N) {
                if (v[i] != P[i]) ok = false;
            }
            if (ok) {
                a = cnt;
            }
            ok = true;
            REP(i, N) {
                if (v[i] != Q[i]) ok = false;
            }
            if (ok) {
                b = cnt;
            }
            cnt++;
        } while (next_permutation(v.begin(), v.end()));

        cout << abs(a - b) << endl;
    }
};
