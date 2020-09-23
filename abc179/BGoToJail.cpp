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

class BGoToJail {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<pair<int, int>> D(N);
        REP(i, N) {
            int a, b;
            cin >> a >> b;
            D[i] = {a, b};
        }
        int cnt = 0;
        REP(i, N) {
            if (D[i].first == D[i].second) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == 3) {
                cout << "Yes" << endl;
                return;
            }
        }
        cout << "No" << endl;
    }
};
