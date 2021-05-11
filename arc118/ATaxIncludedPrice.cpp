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

class ATaxIncludedPrice {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t, N;
        cin >> t >> N;
        set<int> s;
        int loop;
        int num = 0;
        for (int i = 1;; i++) {
            int val = (100 + t) * i;
            if (s.count(val % 100)) {
                loop = i - 1;
                break;
            }
            if ((val % 100) >= 100 - t) num++;
            s.insert(val % 100);
        }
        int loopNum = N / num;
        if (N % num == 0) loopNum--;
        int res = loop * loopNum;
        N -= num * loopNum;
        while (N > 0) {
            int val = (100 + t) * res;
            if ((val % 100) >= 100 - t) N--;
            res++;
        }
        cout << res * (100 + t) / 100 - 1 << endl;
    }
};
