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

class CIPFL {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N;
        string S;
        cin >> S;
        cin >> Q;
        int num = 0;
        while (Q--) {
            int t, a, b;
            cin >> t >> a >> b;
            a--, b--;
            if (t == 2) {
                num++;
                continue;
            }
            if (num % 2 == 1) {
                a += N;
                a %= 2 * N;
                b += N;
                b %= 2 * N;
            }
            swap(S[a], S[b]);
        }
        if (num % 2 == 0) {
            cout << S << endl;
            return;
        }
        FOR(i, N, 2 * N - 1) cout << S[i];
        REP(i, N) cout << S[i];
        cout << endl;
    }
};
