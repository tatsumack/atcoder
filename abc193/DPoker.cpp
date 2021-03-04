#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(16)

using namespace std;

class DPoker {
public:
    int K;
    string S, T;

    int calc(map<int, int>& cnt) {
        int res = 0;
        FOR(i, 1, 9) {
            int n = cnt[i];
            int mul = 1;
            while (n--) {
                mul *= 10;
            }
            res += i * mul;
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> K >> S >> T;

        int total = 9 * K - 8;
        map<int, int> taka, aoki;
        for (auto c : S) {
            taka[c - '0']++;
        }
        for (auto c : T) {
            aoki[c - '0']++;
        }
        int num = 0;
        FOR(i, 1, 9) {
            FOR(j, 1, 9) {
                auto t = taka;
                auto a = aoki;
                t[i]++;
                a[j]++;
                bool ok = true;
                FOR(k, 1, 9) {
                    if (t[k] + a[k] > K) {
                        ok = false;
                    }
                }
                if (!ok) continue;
                if (calc(t) > calc(a)) {
                    if (i == j) {
                        int tmp = K - (taka[i] + aoki[i]);
                        num += tmp * (tmp - 1);
                    } else {
                        num += (K - (taka[i] + aoki[i])) * (K - (taka[j] + aoki[j]));
                    }
                }
            }
        }
        fcout << (double) num / (double) (total * (total - 1)) << endl;
    }
};
