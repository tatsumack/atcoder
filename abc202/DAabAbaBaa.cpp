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

class DAabAbaBaa {
public:
    int calc(int n, int r) {
        if (r == 0) return 1;
        int res = 1;
        REP(i, r) {
            res *= n - i;
            res /= i + 1;
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int A, B, K;
        cin >> A >> B >> K;

        string res;
        int N = A + B;
        REP(i, N) {
            if (A == 0) {
                res += 'b';
                continue;
            }
            if (B == 0) {
                res += 'a';
                continue;
            }
            int n = A - 1 + B;
            int r = min(B, n - B);
            int num = calc(n, r);

            if (num >= K) {
                res += 'a';
                A--;
            } else {
                res += 'b';
                B--;
                K -= num;
            }
        }
        cout << res << endl;
    }
};
