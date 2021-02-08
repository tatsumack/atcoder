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

class DCircleLatticePoints {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        double dX, dY, dR;
        cin >> dX >> dY >> dR;
        int X = round(dX * 10000);
        int Y = round(dY * 10000);
        int R = round(dR * 10000);

        int res = 0;
        for (int x = -200000 * 10000; x <= 200000 * 10000; x += 10000) {
            if (x < X - R || X + R < x) continue;
            int maxY = Y + sqrt(R * R - (X - x) * (X - x)) + 5;
            while ((maxY - Y) * (maxY - Y) + (X - x) * (X - x) > R * R) maxY--;
            int minY = Y - sqrt(R * R - (X - x) * (X - x)) - 5;
            while ((minY - Y) * (minY - Y) + (X - x) * (X - x) > R * R) minY++;
            if (maxY >= 0 || maxY % 10000 == 0) {
                maxY /= 10000;
            } else {
                maxY = maxY / 10000 - 1;
            }
            if (minY <= 0 || minY % 10000 == 0) {
                minY /= 10000;
            } else {
                minY = minY / 10000 + 1;
            }
            if (minY > maxY) continue;
            res += maxY - minY + 1;
        }

        cout << res << endl;
    }
};
