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

class CLargeRPSTournament {
public:

    int n, k;
    char calc(string& s, int l, int r) {
        if (r - l <= 1) {
            return s[l % n];
        }
        int m = (l + r) / 2;
        char cl = calc(s, l, m);
        char cr = calc(s, m, r);
        if (cl == cr) return cl;
        if (cl == 'R' && cr == 'S') return 'R';
        if (cl == 'R' && cr == 'P') return 'P';
        if (cl == 'S' && cr == 'R') return 'R';
        if (cl == 'S' && cr == 'P') return 'S';
        if (cl == 'P' && cr == 'R') return 'P';
        if (cl == 'P' && cr == 'S') return 'S';
        return '#';
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> n >> k;
        string s;
        cin >> s;

        if (k <= 10) {
            cout << calc(s, 0, pow(2, k)) << endl;
            return;
        }
        cout << calc(s, 0, 128) << endl;
    }
};
