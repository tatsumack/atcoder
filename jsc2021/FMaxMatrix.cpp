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

class FMaxMatrix {
public:
    map<int, int> id;
    int res;

    void sub(int val, BIT& bit1, BIT& bit2) {
        res -= bit1.sum(id[val]) * val;
        res -= bit2.sum(id.size()) - bit2.sum(id[val]);
    }

    void add(int val, BIT& bit1, BIT& bit2) {
        res += bit1.sum(id[val]) * val;
        res += bit2.sum(id.size()) - bit2.sum(id[val]);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, Q;
        cin >> N >> M >> Q;
        vector<int> T(Q), X(Q), Y(Q), A(N + 1), B(M + 1);
        set<int> s;
        REP(i, Q) {
            cin >> T[i] >> X[i] >> Y[i];
            s.insert(Y[i]);
        }
        id[0] = 1;
        for (auto n : s) {
            id[n] = id.size() + 1;
        }
        BIT a1(id.size()), a2(id.size()), b1(id.size()), b2(id.size());
        a1.add(id[0], N);
        b1.add(id[0], M);
        res = 0;
        REP(i, Q) {
            if (T[i] == 1) {
                sub(A[X[i]], b1, b2);
                add(Y[i], b1, b2);
                int old = A[X[i]];
                A[X[i]] = Y[i];
                a1.add(id[old], -1);
                a1.add(id[Y[i]], 1);
                a2.add(id[old], -old);
                a2.add(id[Y[i]], Y[i]);
            } else {
                sub(B[X[i]], a1, a2);
                add(Y[i], a1, a2);
                int old = B[X[i]];
                B[X[i]] = Y[i];
                b1.add(id[old], -1);
                b1.add(id[Y[i]], 1);
                b2.add(id[old], -old);
                b2.add(id[Y[i]], Y[i]);
            }
            cout << res << endl;
        }
    }
};
