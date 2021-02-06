#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

// 約数列挙
vector<int> get(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

class DStaircaseSequences {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        auto v = get(2 * N);
        int res = 0;
        for (auto n : v) {
            int a = 2 * N / n - n + 1;
            if (a % 2 == 0) res++;
        }
        cout << res << endl;
    }
};
