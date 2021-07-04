#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

constexpr long double EPS = 1E-11;

using namespace std;

class DCongruencePoints {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N), b(N), c(N), d(N);
        REP(i, N) cin >> a[i] >> b[i];
        REP(i, N) cin >> c[i] >> d[i];
        int x = 0;
        int y = 0;
        REP(i, N) {
            x += a[i];
            y += b[i];
            a[i] *= N;
            b[i] *= N;
        }
        REP(i, N) {
            a[i] -= x;
            b[i] -= y;
        }
        x = 0;
        y = 0;
        REP(i, N) {
            x += c[i];
            y += d[i];
            c[i] *= N;
            d[i] *= N;
        }
        REP(i, N) {
            c[i] -= x;
            d[i] -= y;
        }
        REP(i, N) {
            REP(j, N) {
                double ang = atan2(d[j], c[j]) - atan2(b[i], a[i]);
                bool ok = true;
                REP(m, N) {
                    bool ok2 = false;
                    double X = a[m] * cos(ang) - b[m] * sin(ang);
                    double Y = a[m] * sin(ang) + b[m] * cos(ang);
                    REP(n, N) {
                        if (abs(X - c[n]) <= EPS && abs(Y - d[n]) <= EPS) {
                            ok2 = true;
                            break;
                        }
                    }
                    if (!ok2) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    //fcout << ang << endl;
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
        cout << "No" << endl;
    }
};
