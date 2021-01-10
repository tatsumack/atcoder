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

class C1SAT {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        set<string> s, t;
        REP(i, N) {
            string str;
            cin >> str;
            if (str[0] != '!') {
                s.insert(str);
            } else {
                t.insert(str);
            }
        }
        bool ok = true;
        string res;
        for (auto& target : s) {
            if (t.count('!' + target)) {
                ok = false;
                res = target;
            }
        }
        cout << (ok ? "satisfiable" : res) << endl;
    }
};
