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

class FModularness {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int k, q;
        cin >> k >> q;
        vector<int> d(k);
        REP(i, k) {
            cin >> d[i];
        }
        REP(i, q) {
            int n, x, m;
            cin >> n >> x >> m;
            int znum = 0;
            auto md = d;
            int sum = 0;
            REP(j, k) {
                md[j] %= m;
                sum += md[j];
                if (md[j] == 0) znum++;
            }

            int num = (n - 1) / k;
            int an = x + sum * num;
            int zero = znum * num;
            REP(j, (n - 1) % k) {
                an += md[j];
                if (md[j] == 0) zero++;
            }
            int p = an / m - x / m + zero;

            cout << n - 1 - p << endl;
        }
    }
};
