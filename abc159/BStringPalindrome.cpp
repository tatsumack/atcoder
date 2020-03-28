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

class BStringPalindrome {
public:
    bool ok(string s) {
        int l = 0;
        int r = s.size() -1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        if (!ok(s)) {
            cout << "No" << endl;
            return;
        }
        if (!ok(s.substr(0, s.size() / 2))) {
            cout << "No" << endl;
            return;
        }
        if (!ok(s.substr( s.size() / 2 + 1))) {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
    }
};
