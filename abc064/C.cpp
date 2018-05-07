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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
int A[103];

int RATING[9] = {1, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};

signed main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    set<int> rset;
    int maxr = 0;
    REP(i, N) {
        int a = A[i];
        REV(k, 8) {
            int r = RATING[k];
            if (a >= r) {
                if (r == 3200)
                    ++maxr;
                else
                    rset.insert(r);
                break;
                DUMP(r)
            }
        }
    }

    int minans = rset.size();
    if (maxr > 0 && rset.size() == 0) minans += 1;
    int maxans = rset.size() + maxr;
    cout << minans << " " << maxans << endl;

    return 0;
}
