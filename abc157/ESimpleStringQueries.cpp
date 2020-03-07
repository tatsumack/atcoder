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

class ESimpleStringQueries {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        int q;
        cin >> q;

        vector<BIT> v;
        REP(i, 26) {
            v.emplace_back(N + 1);
        }
        REP(i, N) {
            int idx = s[i] - 'a';
            v[idx].add(i + 1, 1);
        }

        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int i;
                char c;
                cin >> i >> c;
                int idx = s[i - 1] - 'a';
                v[idx].add(i, -1);
                s[i - 1] = c;
                v[c - 'a'].add(i, 1);
            } else {
                int l, r;
                cin >> l >> r;
                int res = 0;
                REP(i, 26) {
                    int num = v[i].sum(r) - v[i].sum(l - 1);
                    if (num > 0) res++;
                }
                cout << res << endl;
            }
        }
    }
};
