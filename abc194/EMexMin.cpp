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

class EMexMin {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), cnt(N + 5);
        REP(i, N) {
            cin >> A[i];
            A[i]++;
        }

        BIT bit(N + 5);
        REP(i, M - 1) {
            cnt[A[i]]++;
            if (cnt[A[i]] == 1) {
                bit.add(A[i], 1);
            }
        }
        int res = INF;
        FOR(i, M - 1, N - 1) {
            cnt[A[i]]++;
            if (cnt[1] == 0) {
                res = 1;
                break;
            }
            if (cnt[A[i]] == 1) {
                bit.add(A[i], 1);
            }
            int l = 1;
            int r = N + 2;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                int num = bit.sum(mid);
                if (num == mid) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            res = min(res, r);

            int val = A[i - (M - 1)];
            cnt[val]--;
            if (cnt[val] == 0) {
                bit.add(val, -1);
            }
        }
        cout << res - 1 << endl;
    }
};
