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

class EBomber {
public:
    int H, W, M;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> H >> W >> M;
        vector<int> row(H), col(W);
        set<pair<int, int>> s;

        int maxR = 0;
        int maxC = 0;
        REP(i, M) {
            int h, w;
            cin >> h >> w;
            h--, w--;
            s.insert({h, w});
            row[h]++;
            col[w]++;
            maxR = max(maxR, row[h]);
            maxC = max(maxC, col[w]);
        }
        vector<int> maxh, maxc;
        REP(i, H) {
            if (row[i] == maxR) {
                maxh.push_back(i);
            }
        }
        REP(i, W) {
            if (col[i] == maxC) {
                maxc.push_back(i);
            }
        }
        int res = maxR + maxC;
        for (auto h : maxh) {
            for (auto c : maxc) {
                if (s.count({h, c}) == 0) {
                    cout << res << endl;
                    return;
                }
            }
        }
        cout << res - 1 << endl;
    }
};
