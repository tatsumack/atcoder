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

int num = 7;
string name[] = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
int pos[] = {0, 2, 4, 5, 7, 9, 11};

class C {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;

        string key = "WBWBWWBWBWBW";

        REP(i, num) {
            int p = pos[i];
            bool ok = true;
            REP(j, s.size()) {
                if (key[(p + j) % key.size()] != s[j]) {
                    ok = false;
                }
            }
            if (ok) {
                cout << name[i] << endl;
                return;
            }
        }
    }
};
