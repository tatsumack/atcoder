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

class CTests {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N, X;
    int b[100005];
    int l[100005];
    int u[100005];
    int aoki = 0;
    vector<P> v;

    bool check(int p) {
        int k = p / X;
        int d = p % X;

        int sum = 0;
        REP(i, k) {
            sum += v[i].first;
        }

        if (d == 0) {
            return sum >= aoki;
        }

        REP(t, N) {
            int tmp = sum;
            int i = v[t].second;
            if (t < k) tmp += v[k].first - v[t].first;
            if (d > b[i]) {
                tmp += u[i] * (d - b[i]) + l[i] * b[i];
            } else {
                tmp += l[i] * d;
            }
            if (tmp >= aoki) {
                return true;
            }
        }

        return false;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> X;

        REP(i, N) {
            cin >> b[i] >> l[i] >> u[i];
            aoki += l[i] * b[i];
        }
        v.resize(N);
        REP(i, N) {
            v[i] = {u[i] * (X - b[i]) + l[i] * b[i], i};
        }
        sort(v.begin(), v.end(), greater<P>());

        int low = -1;
        int high = N * X;
        while (high - low > 1) {
            int mid = (high + low) / 2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << endl;
    }
};
