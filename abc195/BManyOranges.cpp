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

class BManyOranges {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B, W;
        cin >> A >> B >> W;
        W *= 1000;
        int num = 1;
        int mina = INF;
        int maxa = -INF;
        while (num * A <= W) {
            if (W <= num * B) {
                mina = min(num, mina);
                maxa = max(num, maxa);
            }
            num++;
        }
        if (mina == INF) {
            cout << "UNSATISFIABLE" << endl;
            return;
        }
        cout << mina << " " << maxa << endl;
    }
};
