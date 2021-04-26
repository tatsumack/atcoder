#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;
typedef atcoder::modint998244353 mint;

struct S {
    mint val, unit;
};


S op(S l, S r) { return S{l.val + r.val, l.unit + r.unit}; }

S e() { return S{0, 0}; }

S mapping(int l, S r) { return l == 0 ? r : S{l * r.unit, r.unit}; }

int composition(int l, int r) { return l == 0 ? r : l; }

int id() { return 0; }

class EReplaceDigits {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N >> Q;

        vector<S> v(N);
        mint unit = 1;
        REP(i, N) {
            v[i] = S{1 * unit, unit};
            unit *= 10;
        }
        reverse(v.begin(), v.end());

        atcoder::lazy_segtree<S, op, e, int, mapping, composition, id> seg(v);
        REP(i, Q) {
            int l, r, d;
            cin >> l >> r >> d;
            l--, r--;
            seg.apply(l, r + 1, d);
            cout << seg.prod(0, N).val.val() << endl;
        }
    }
};
