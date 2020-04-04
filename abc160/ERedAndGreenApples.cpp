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

class ERedAndGreenApples {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int X, Y, A, B, C;
        cin >> X >> Y >> A >> B >> C;
        vector<int> p(A), q(B), r(C);
        REP(i, A) cin >> p[i];
        REP(i, B) cin >> q[i];
        REP(i, C) cin >> r[i];
        priority_queue<int, vector<int>, greater<>> pq, qq;
        REP(i, A) {
            pq.push(p[i]);
            if (pq.size() > X) {
                pq.pop();
            }
        }
        REP(i, B) {
            qq.push(q[i]);
            if (qq.size() > Y) {
                qq.pop();
            }
        }

        priority_queue<int> rq;
        REP(i, C) {
            rq.push(r[i]);
        }
        while (!rq.empty()) {
            if (rq.top() <= pq.top() && rq.top() <= qq.top()) break;

            if (pq.top() < qq.top()) {
                pq.pop();
                pq.push(rq.top());
            } else {
                qq.pop();
                qq.push(rq.top());
            }
            rq.pop();
        }

        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        while (!qq.empty()) {
            res += qq.top();
            qq.pop();
        }
        cout << res << endl;
    }
};
