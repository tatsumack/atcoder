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

class B123Triangle {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        vector<int> a(N);
        REP(i, N) {
            a[i] = s[i] - '0';
            a[i]--;
        }

        int cur = 0;
        REP(i, N) {
            if (a[i] % 2 == 1) {
                if (((N - 1) & i) == i) cur ^= 1;
            }
        }
        if (cur == 1) {
            cout << 1 << endl;
            return;
        }
        REP(i, N) {
            if (a[i] == 1) {
                cout << 0 << endl;
                return;
            }
        }
        cur = 0;
        REP(i, N) {
            if (a[i] == 2) {
                if (((N - 1) & i) == i) cur ^= 1;
            }
        }
        if (cur == 1) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
};
