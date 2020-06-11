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

map<int, int> getPrimeFactors(int a) {
    map<int, int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        while (a % i == 0) {
            s[i]++;
            a /= i;
        }
    }
    if (a > 1) s[a]++;
    return s;
}

class DDivGame {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<int> sum(101,  0);
        FOR(i, 1, 100) sum[i] = sum[i-1] + i;

        auto m = getPrimeFactors(N);

        int res = 0;
        for (auto kv : m) {
            int num = kv.second;
            res += upper_bound(sum.begin(), sum.end(), num) - sum.begin() - 1;
        }
        cout << res << endl;

    }
};
