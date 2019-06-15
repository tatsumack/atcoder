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
int lcm(int a, int b) { return a * b * gcd(a, b); }

class DSquirrelMerchant {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int g[2], s[2], b[2];

    vector<int> convert(int n, const vector<int>& order, int x) {
        vector<int> num(4);
        REP(i, order.size()) {
            if (n == 0) break;
            int type = order[i];

            if (type == 0) {
                num[0] = n;
                n = 0;
            }
            if (type == 1) {
                num[1] = n / g[x];
                n -= num[1] * g[x];

            }
            if (type == 2) {
                num[2] = n / s[x];
                n -= num[2] * s[x];
            }
            if (type == 3) {
                num[3] = n / b[x];
                n -= num[3] * b[x];
            }
        }
        return num;
    }

    int change(const vector<int>& num, int x) {
        int res = num[0];
        res += num[1] * g[x];
        res += num[2] * s[x];
        res += num[3] * b[x];
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        REP(i, 2) cin >> g[i] >> s[i] >> b[i];

        vector<int> order({0, 1, 2, 3});
        int res = N;
        do {
            // A -> B
            auto num = convert(N, order, 0);
            int tmp = change(num, 1);
            res = max(res, tmp);
            //DUMP(tmp)
            //REP(i, order.size()) cout << order[i] << " ";
            //cout << endl;
            //REP(i, num.size()) cout << num[i] << " ";
            //cout << endl;
        } while (next_permutation(order.begin(), order.end()));

        N = res;
        do {
            // B -> A
            auto num = convert(N, order, 1);
            int tmp = change(num, 0);
            res = max(res, tmp);
            //DUMP(tmp)
            //REP(i, order.size()) cout << order[i] << " ";
            //cout << endl;
            //REP(i, num.size()) cout << num[i] << " ";
            //cout << endl;
        } while (next_permutation(order.begin(), order.end()));

        cout << res << endl;
    }
};
