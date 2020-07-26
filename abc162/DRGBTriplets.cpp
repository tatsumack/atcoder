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

class DRGBTriplets {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        vector<vector<int>> left(N, vector<int>(3));
        vector<vector<int>> right(N, vector<int>(3));
        map<char, int> m;
        m['R'] = 0;
        m['G'] = 1;
        m['B'] = 2;
        FOR(i, 1, s.size() - 1) {
            char c = s[i - 1];
            REP(j, 3) {
                left[i][j] = left[i-1][j];
            }
            left[i][m[c]]++;
        }
        REV(i, s.size() - 2, 0) {
            char c = s[i + 1];
            REP(j, 3) {
                right[i][j] = right[i+1][j];
            }
            right[i][m[c]]++;
        }

        int res = 0;
        REP(i, s.size()) {

        }

    }
};
