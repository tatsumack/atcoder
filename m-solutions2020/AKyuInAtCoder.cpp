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

class AKyuInAtCoder {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int x;
        cin >> x;
        if (x < 600) {
            cout << 8 << endl;
        } else if (x < 800) {
            cout << 7 << endl;
        } else if (x < 1000) {
            cout << 6 << endl;
        } else if (x < 1200) {
            cout << 5 << endl;
        } else if (x < 1400) {
            cout << 4 << endl;
        } else if (x < 1600) {
            cout << 3 << endl;
        } else if (x < 1800) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }
};
