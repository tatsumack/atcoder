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

class BMany110 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        string T;
        cin >> N >> T;
        int num = 10000000000;
        if (N == 1) {
            if (T == "1") {
                cout << 2 * num << endl;
            } else {
                cout << num << endl;
            }
            return;
        }
        string S = "110";
        if (T[0] == '1' && T[1] == '1') {
            bool ok = true;
            int cnt = 0;
            REP(i, T.size()) {
                if (T[i] != S[i % 3]) {
                    ok = false;
                    break;
                }
                if (i % 3 == 0) {
                    cnt++;
                }
            }
            if (!ok) {
                cout << 0 << endl;
                return;
            }
            cout << num - (cnt - 1) << endl;
        } else if (T[0] == '1' && T[1] == '0') {
            bool ok = true;
            int cnt = 1;
            REP(i, T.size()) {
                if (T[i] != S[(i + 1) % 3]) {
                    ok = false;
                    break;
                }
                if (i % 3 == 2) {
                    cnt++;
                }
            }
            if (!ok) {
                cout << 0 << endl;
                return;
            }
            cout << num - (cnt - 1) << endl;
        } else {
            bool ok = true;
            int cnt = 1;
            REP(i, T.size()) {
                if (T[i] != S[(i + 2) % 3]) {
                    ok = false;
                    break;
                }
                if (i % 3 == 1) {
                    cnt++;
                }
            }
            if (!ok) {
                cout << 0 << endl;
                return;
            }
            cout << num - (cnt - 1) << endl;
        }
    }
};
