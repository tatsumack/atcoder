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

class DBannedK {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        map<int, int> cnt;
        REP(i, N) {
            cnt[a[i]]++;
        }

        int res = 0;
        for (auto kv : cnt) {
            int num = kv.second;
            if (num < 2) continue;
            res += num * (num - 1) / 2;
        }

        REP(i, N) {
            int n = a[i];
            int tmp = res;
            int num = cnt[n];
            tmp -= num * (num - 1) / 2;
            tmp += (num - 1) * (num - 2) / 2;
            cout << tmp << endl;
        }
    }
};
