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

class DAnythingGoesToZero {
public:

    int bitcount(int n) {
        int cnt = 0;
        REP(i, 20) {
            if (n >> i & 1) cnt++;
        }
        return cnt;
    }

    int calc(int x) {
        int res = 0;
        while (x > 0) {
            int num = bitcount(x);
            x = x % num;
            res++;
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string X;
        cin >> X;

        int num = 0;
        REP(i, N) if (X[i] == '1') num++;
        vector<int> A(N + 1), B(N + 1);
        A[0] = B[0] = 1;
        REP(i, N) {
            A[i + 1] = (A[i] * 2) % (num + 1);
            if (num > 1) B[i + 1] = (B[i] * 2) % (num - 1);
        }

        int a, b;
        a = b = 0;
        REP(i, N) {
            a *= 2;
            b *= 2;
            if (X[i] == '1') {
                a++;
                b++;
            }
            a %= num + 1;
            if (num > 1) b %= num - 1;
        }

        REP(i, N) {
            if (X[i] == '0') {
                int x = a + A[N - 1 - i];
                x %= num + 1;
                cout << calc(x) + 1 << endl;
            } else {
                if (num == 1) {
                    cout << 0 << endl;
                    continue;
                }
                int x = b - B[N - 1 - i];
                x %= num - 1;
                if (x < 0) x += num - 1;
                cout << calc(x) + 1 << endl;
            }
        }
    }
};
