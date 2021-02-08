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

class CDigitalGraffiti {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> S(H, vector<char>(W));
        REP(i, H) REP(j, W) cin >> S[i][j];

        int res = 0;
        REP(i, H) {
            REP(j, W) {
                if (S[i][j] == '.') continue;
                // 左上
                if (S[i][j - 1] == '.' && S[i - 1][j] == '.') res++;
                if (S[i][j - 1] == '#' && S[i - 1][j] == '#' && S[i - 1][j - 1] == '.') res++;
                // 右上
                if (S[i][j + 1] == '.' && S[i - 1][j] == '.') res++;
                if (S[i][j + 1] == '#' && S[i - 1][j] == '#' && S[i - 1][j + 1] == '.') res++;
                // 左下
                if (S[i][j - 1] == '.' && S[i + 1][j] == '.') res++;
                if (S[i][j - 1] == '#' && S[i + 1][j] == '#' && S[i + 1][j - 1] == '.') res++;
                // 右下
                if (S[i][j + 1] == '.' && S[i + 1][j] == '.') res++;
                if (S[i][j + 1] == '#' && S[i + 1][j] == '#' && S[i + 1][j + 1] == '.') res++;
            }
        }
        cout << res << endl;
    }
};
