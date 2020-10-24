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

class BVariousDistances {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<double> x(N);
        REP(i, N) cin >> x[i];
        int a = 0;
        REP(i, N) a += abs(x[i]);
        double b = 0;
        REP(i, N) b += x[i] * x[i];
        int c = abs(x[0]);
        REP(i, N) c = max(c, (int) abs(x[i]));

        cout << a << endl;
        fcout << sqrt(b) << endl;
        cout << c << endl;
    }
};
