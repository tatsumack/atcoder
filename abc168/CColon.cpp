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

static const double pi = 3.141592653589793;

class CColon {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        double A, B, H, M;
        cin >> A >> B >> H >> M;

        double a = (H * 60 + M) * 360 / (12 * 60);
        double b = 360.0f / 60 * M;
        double c = abs(a - b);

        double res = sqrt(A * A + B * B - 2 * A * B * cos(c * pi/ 180));
        fcout << res << endl;
    }
};
