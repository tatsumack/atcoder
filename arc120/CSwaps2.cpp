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

class CSwaps2 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);

        int suma = 0;
        REP(i, N) {
            cin >> A[i];
            suma += A[i];
        }
        int sumb = 0;
        REP(i, N) {
            cin >> B[i];
            sumb += B[i];
        }
        if (suma != sumb) {
            cout << -1 << endl;
            return;
        }

        map<int, vector<int>> ma, mb;
        REP(i, N) {
            ma[i + A[i]].push_back(i);
        }
        REP(i, N) {
            mb[i + B[i]].push_back(i);
        }


        vector<int> pos(N);
        for (auto kv : ma) {
            int n = kv.second.size();
            if (n != mb[kv.first].size()) {
                cout << -1 << endl;
                return;
            }
            REP(i, n) {
                pos[kv.second[i]] = mb[kv.first][i];
            }
        }
        int res = 0;
        BIT bit(N + 1);
        REP(i, N) {
            res += i - bit.sum(pos[i] + 1);
            bit.add(pos[i] + 1, 1);
        }

        cout << res << endl;
    }
};
