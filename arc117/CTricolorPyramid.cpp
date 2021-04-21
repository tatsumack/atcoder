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

struct Comb {
    vector<vector<long long>> com;
    long long p;

    Comb(long long _p) : p(_p) {
        init(p);
    }

    void init(long long p) {  // 動的計画法で前処理
        com.assign(p, vector<long long>(p));
        com[0][0] = 1;
        for (int i = 1; i < p; i++) {
            com[i][0] = 1;
            for (int j = i; j > 0; j--) {
                com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]) % p;
            }
        }
    }

    long long nCk(long long n, long long k) {
        long long ret = 1;
        while (n > 0) {  // 下から一桁ずつ計算する
            int ni = n % p;
            int ki = k % p;
            ret *= com[ni][ki];
            ret %= p;
            n /= p;
            k /= p;
        }
        return ret;
    }
};

class CTricolorPyramid {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> C(N);
        REP(i, N) {
            char c;
            cin >> c;
            if (c == 'B') C[i] = 0;
            if (c == 'W') C[i] = 1;
            if (c == 'R') C[i] = 2;
        }

        Comb cb(3);

        int res = 0;
        REP(i, N) {
            res += cb.nCk(N - 1, i) * C[i];
            res %= 3;
        }
        if ((N - 1) % 2 == 1) {
            res *= -1;
        }
        res %= 3;
        if (res < 0) res += 3;
        char ans;
        switch (res) {
            case 0:
                ans = 'B';
                break;
            case 1:
                ans = 'W';
                break;
            case 2:
                ans = 'R';
                break;
        }
        cout << ans << endl;
    }
};
