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

class BTakingTheMiddle {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> v(2 * N);

        int sum = 0;
        REP(i, 2 * N) {
            cin >> v[i];
            sum += v[i];
        }

        priority_queue<int, vector<int>, greater<>> pq;
        int aoki = 0;
        REP(i, N) {
            pq.push(v[N - 1 - i]);
            pq.push(v[N + i]);

            aoki += pq.top();
            pq.pop();
        }
        cout << sum - aoki << endl;
    }
};
