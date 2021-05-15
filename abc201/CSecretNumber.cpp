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

class CSecretNumber {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        int num = 0;
        REP(i, 10000) {
            int val = i;
            set<int> v;
            REP(j, 4) {
                v.insert(val % 10);
                val /= 10;
            }
            bool ok = true;
            REP(j, 10) {
                char c = s[j];
                if (c == 'o') {
                    if (v.count(j) == 0) {
                        ok = false;
                    }
                }
                if (c == 'x') {
                    if (v.count(j) > 0) {
                        ok = false;
                    }
                }
            }
            if (ok) num++;
        }
        cout << num << endl;
    }
};
