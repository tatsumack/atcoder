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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class CCollinearity {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> x(N), y(N);
        REP(i, N) cin >> x[i] >> y[i];
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    int dx1 = x[j] - x[i];
                    int dy1 = y[j] - y[i];
                    int g1 = gcd(dx1, dy1);
                    dx1 /= g1;
                    dy1 /= g1;
                    if (dx1 < 0) {
                        dx1 *= -1;
                        dy1 *= -1;
                    }

                    int dx2 = x[k] - x[i];
                    int dy2 = y[k] - y[i];
                    int g2 = gcd(dx2, dy2);
                    dx2 /= g2;
                    dy2 /= g2;
                    if (dx2 < 0) {
                        dx2 *= -1;
                        dy2 *= -1;
                    }
                    if (dx1 == dx2 && dy1 == dy2) {
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
        }
        cout << "No" << endl;
    }
};
