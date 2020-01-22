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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a * (b / gcd(a, b)); }

class DSemiCommonMultiple {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N);
        REP(i, N) {
            cin >> a[i];
            a[i] /= 2;
        }

        int num = 0;
        int c = a[0];
        while (c % 2 == 0) {
            c /= 2;
            num++;
        }
        REP(i, N) {
            int tmp = 0;
            int c = a[i];
            while (c % 2 == 0) {
                c /= 2;
                tmp++;
            }
            if (num != tmp) {
                cout << 0 << endl;
                return;
            }
        }

        int l = a[0];
        REP(i, N) {
            l = lcm(l, a[i]);
            if (l > M) {
                cout << 0 << endl;
                return;
            }
        }

        cout << (M + l) / (2 * l) << endl;
    }
};
