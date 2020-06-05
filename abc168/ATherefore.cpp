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

class ATherefore {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int d = N % 10;
        switch (d) {
            case 2:
            case 4:
            case 5:
            case 7:
            case 9:
                cout << "hon" << endl;
                break;
            case 0:
            case 1:
            case 6:
            case 8:
                cout << "pon" << endl;
                break;
            case 3:
                cout << "bon" << endl;
                break;
        }

    }
};
