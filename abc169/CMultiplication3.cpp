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

class CMultiplication3 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A;
        string B;
        cin >> A >> B;

        int b = 0;
        bool hasP = false;
        int num = 0;
        for (auto c : B) {
            if (c == '.') {
                hasP = true;
            } else {
                if (hasP) num++;
                b = 10 * b + (c - '0');
            }
        }

        int points = 1;
        REP(i, num) points *= 10;
        cout << A * b / points << endl;

    }
};
