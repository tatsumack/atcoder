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

class A106 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int a = 1;
        int cur = 3;
        int b;
        bool ok = false;
        while (cur <= N) {
            int rem = N - cur;
            b = 0;
            while (rem > 0 && rem % 5 == 0) {
                rem /= 5;
                b++;
            }
            if (rem == 1 && b > 0) {
                ok = true;
                break;
            }
            cur *= 3;
            a++;
        }
        if (ok) {
            cout << a << " " << b << endl;
        } else {
            cout << -1 << endl;
        }
    }
};
