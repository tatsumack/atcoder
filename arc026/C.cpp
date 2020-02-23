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

// Range Minimum Query
struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1, INF);
        for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

class C {
public:
    int N, L;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> L;
        vector<pair<P, int>> v(N);
        REP(i, N) {
            int l, r, c;
            cin >> l >> r >> c;
            v[i] = {{l, r}, c};
        }
        sort(v.begin(), v.end());

        vector<int> init(L + 1, INF);
        SegmentTree seg(init);

        seg.update(0, 0);
        REP(i, N) {
            int l, r, c;
            tie(l, r) = v[i].first;
            c = v[i].second;
            int val = seg.getmin(l, r + 1);
            int rval = seg.getmin(r, r + 1);
            if (val + c >= rval) continue;
            seg.update(r, val + c);
        }
        cout << seg.getmin(L, L + 1) << endl;
    }
};
