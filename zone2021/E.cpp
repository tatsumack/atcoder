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

class E {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> A(R, vector<int>(C - 1));
        vector<vector<int>> B(R, vector<int>(C - 1));
        REP(i, R) REP(j, C - 1) cin >> A[i][j];
        REP(i, R) REP(j, C - 1) cin >> B[i][j];

        vector<int> dist(R * C);
        dist[0] = 0;
        priority_queue<P, vector<P>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
        }
    }
};
