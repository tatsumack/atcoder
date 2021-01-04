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

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

class FRookOnGrid {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, M;
        cin >> H >> W >> M;
        vector<vector<int>> row(H), col(W);
        REP(i, M) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            row[x].push_back(y);
            col[y].push_back(x);
        }
        REP(i, H) {
            sort(row[i].begin(), row[i].end());
            row[i].push_back(W);
        }
        REP(i, W) {
            sort(col[i].begin(), col[i].end());
            col[i].push_back(H);
        }

        int res = 0;
        REP(j, row[0].front()) {
            res += col[j].front();
        }
        //cout << res << endl;

        vector<bool> found(W);
        BIT bit(W + 1);
        for (int c = row[0].front(); c < W; c++) {
            if (!found[c]) {
                found[c] = true;
                bit.add(c + 1, 1);
            }
        }
        FOR(i, 1, col[0].front() - 1) {
            int first = row[i].front();
            res += bit.sum(first);
            //cout << first << ":b" << bit.sum(first) << ":" << res << endl;
            for (int c : row[i]) {
                if (!found[c]) {
                    found[c] = true;
                    bit.add(c + 1, 1);
                }
            }
        }
        cout << res << endl;
    }
};
