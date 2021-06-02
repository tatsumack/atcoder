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

class BRGBMatching {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(2 * N);
        vector<char> c(2 * N);
        vector<int> R, G, B;
        map<char, int> cnt;
        REP(i, 2 * N) {
            cin >> a[i] >> c[i];
            cnt[c[i]]++;
            if (c[i] == 'R') R.push_back(a[i]);
            if (c[i] == 'G') G.push_back(a[i]);
            if (c[i] == 'B') B.push_back(a[i]);
        }
        sort(R.begin(), R.end());
        sort(G.begin(), G.end());
        sort(B.begin(), B.end());
        if (cnt['R'] % 2 == 0 && cnt['G'] % 2 == 0 && cnt['B'] % 2 == 0) {
            cout << 0 << endl;
            return;
        }
        if (cnt['G'] % 2 == 0) swap(R, G);
        if (cnt['B'] % 2 == 0) swap(R, B);

        int rg = INF;
        int rb = INF;
        int gb = INF;
        REP(i, G.size()) {
            auto itr = upper_bound(R.begin(), R.end(), G[i]);
            if (itr != R.end()) {
                rg = min(rg, *itr - G[i]);
            }
            if (itr != R.begin()) {
                itr--;
                rg = min(rg, G[i] - *itr);
            }
        }
        REP(i, B.size()) {
            auto itr = upper_bound(R.begin(), R.end(), B[i]);
            if (itr != R.end()) {
                rb = min(rb, *itr - B[i]);
            }
            if (itr != R.begin()) {
                itr--;
                rb = min(rb, B[i] - *itr);
            }
        }
        REP(i, B.size()) {
            auto itr = upper_bound(G.begin(), G.end(), B[i]);
            if (itr != G.end()) {
                gb = min(gb, *itr - B[i]);
            }
            if (itr != G.begin()) {
                itr--;
                gb = min(gb, B[i] - *itr);
            }
        }

        cout << min(rg + rb, gb) << endl;
    }
};
