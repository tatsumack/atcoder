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

class AHitachiString {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        if (s.size() % 2 == 1) {
            cout << "No" << endl;
            return;
        }

        bool ok = true;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != 'h' || s[i+1] != 'i') {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;

    }
};
