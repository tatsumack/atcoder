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

int mod = 998244353;

struct mint {
    unsigned x;

    mint() : x(0) {}

    mint(signed sig) { x = sig < 0 ? sig % mod + mod : sig % mod; }

    mint(signed long long sig) { x = sig < 0 ? sig % mod + mod : sig % mod; }

    int get() const { return (int) x; }

    mint& operator+=(mint that) {
        if ((x += that.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator-=(mint that) {
        if ((x += mod - that.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator*=(mint that) {
        x = (unsigned long long) x * that.x % mod;
        return *this;
    }

    mint& operator/=(mint that) { return *this *= that.inverse(); }

    mint operator+(mint that) const { return mint(*this) += that; }

    mint operator-(mint that) const { return mint(*this) -= that; }

    mint operator*(mint that) const { return mint(*this) *= that; }

    mint operator/(mint that) const { return mint(*this) /= that; }

    mint inverse() const {
        long long a = x, b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            std::swap(a, b);
            u -= t * v;
            std::swap(u, v);
        }
        return mint(u);
    }

    bool operator==(mint that) const { return x == that.x; }

    bool operator!=(mint that) const { return x != that.x; }

    mint operator-() const {
        mint t;
        t.x = x == 0 ? 0 : mod - x;
        return t;
    }
};


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

class FEnclosedPoints {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<P> v(N);
        vector<int> Y(N);
        REP(i, N) {
            int x, y;
            cin >> x >> y;
            v[i] = {x, y};
            Y[i] = y;
        }
        sort(v.begin(), v.end());

        BIT left(N), right(N);

        map<int, int> id;
        sort(Y.begin(), Y.end());
        REP(i, N) {
            id[Y[i]] = i + 1;
            right.add(i + 1, 1);
        }

        vector<mint> two(N+1);
        two[0] = 1;
        REP(i, N) two[i+1] = two[i] * 2;

        mint res = 0;
        REP(i, N) {
            int x, y;
            tie(x, y) = v[i];

            right.add(id[y], -1);

            // a | c
            // ------
            // b | d
            int a = left.sum(N) - left.sum(id[y]);
            int b = left.sum(id[y]);
            int c = right.sum(N) - right.sum(id[y]);
            int d = right.sum(id[y]);

            // 点iが含まれないとき
            res += (two[a] - 1) * two[b] * two[c] * (two[d] - 1);
            res += (two[b] - 1) * two[a] * two[d] * (two[c] - 1);
            res -= (two[a] - 1) * (two[b] - 1) * (two[c] - 1) * (two[d] - 1);

            // 点iが含まれるとき
            res += two[a] * two[b] * two[c] * two[d];
            
            left.add(id[y], 1);
        }
        cout << res.get() << endl;
    }
};
