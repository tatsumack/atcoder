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

class CDifferBy1Bit {
public:
    int N, A, B;

    int bitcount(int n) {
        int cnt = 0;
        REP(i, N) {
            if (n >> i & 1) cnt++;
        }
        return cnt;
    }

    int erase(int n, int i) {
        int up = n;
        up = up >> (i + 1);
        up = up << i;
        int low = n & ((1 << i) - 1);
        return up | low;
    }

    int push(int n, int v, int i) {
        int up = n;
        up = up >> i;
        up = up << (i + 1);
        int low = n & ((1 << i) - 1);
        return up | low | (v << i);
    }

    vector<int> f(int a, int b, int d) {
        if (d == 1) return vector<int>{a, b};

        int x, va, vb;
        REP(i, d) {
            if (((a >> i) & 1) != ((b >> i) & 1)) {
                x = i;
                va = (a >> i) & 1;
                vb = (b >> i) & 1;
                break;
            }
        }
        int na = erase(a, x);
        int nb = erase(b, x);
        int c = na ^ 1;

        auto l = f(na, c, d - 1);
        auto r = f(c, nb, d - 1);
        for (auto &n : l) {
            n = push(n, va, x);
        }
        for (auto &n : r) {
            n = push(n, vb, x);
        }

        vector<int> res;
        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), r.begin(), r.end());
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> A >> B;

        int a = bitcount(A);
        int b = bitcount(B);
        if (a % 2 == b % 2) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;

        vector<int> res = f(A, B, N);
        REP(i, res.size()) cout << res[i] << " ";
        cout << endl;
    }
};
