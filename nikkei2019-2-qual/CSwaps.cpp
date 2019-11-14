#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
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

class CSwaps {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) {
            cin >> A[i];
        }
        REP(i, N) {
            cin >> B[i];
        }

        vector<P> v(N);
        REP(i, N) v[i] = {B[i], A[i]};
        sort(v.begin(), v.end());

        vector<int> a, b;
        for (auto kv : v) {
            b.push_back(kv.first);
            a.push_back(kv.second);
        }

        vector<int> sa = a;
        sort(sa.begin(), sa.end());

        bool ok = false;
        REP(i, N) {
            if (sa[i] > b[i]) {
                cout << "No" << endl;
                return;
            }
            if (a[i] == sa[i]) {
                ok = true;
            }
        }

        if (ok) {
            cout << "Yes" << endl;
            return;
        }

        vector<int> vv(N);
        REP(i, N - 1) {
            if (sa[i + 1] <= b[i]) {
                vv[i] = 1;
            }
        }

        bool ok2 = false;
        REP(i, N - 1) {
            if (sa[i + 1] <= b[i]) {
                ok2 = true;
            }
        }
        if (!ok2) {
            cout << "No" << endl;
            return;
        }
        cout << "No" << endl;
    }
};
