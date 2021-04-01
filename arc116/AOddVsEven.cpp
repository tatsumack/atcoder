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

vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        while (a % i == 0) {
            s.push_back(i);
            a /= i;
        }
    }
    if (a > 1) s.push_back(a);
    return s;
}

class AOddVsEven {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            if (n % 2 != 0) {
                cout << "Odd" << endl;
            } else if ((n / 2) % 2 != 0) {
                cout << "Same" << endl;
            } else {
                cout << "Even" << endl;
            }
        }
    }
};
