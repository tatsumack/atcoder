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

class BElectricBoard {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string S, T;
        cin >> S >> T;

        vector<int> s(2), t(2);
        for (auto c: S) s[c - '0']++;
        for (auto c: T) t[c - '0']++;

        if (s[0] != t[0] || s[1] != t[1]) {
            cout << -1 << endl;
            return;
        }

        vector<int> spos(s[0]), tpos(t[0]);
        int id = 0;
        REP(i, S.size()) {
            if (S[i] == '0') {
                spos[id++] = i;
            }
        }
        id = 0;
        REP(i, T.size()) {
            if (T[i] == '0') {
                tpos[id++] = i;
            }
        }

        int res = s[0];
        REP(i, s[0]) {
            if (spos[i] == tpos[i]) res--;
        }
        cout << res << endl;
    }
};
