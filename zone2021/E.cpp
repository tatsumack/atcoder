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
        vector<vector<int>> B(R - 1, vector<int>(C));
        REP(i, R) REP(j, C - 1) cin >> A[i][j];
        REP(i, R - 1) REP(j, C) cin >> B[i][j];

        vector<int> dist(R * C * 2, INF);
        dist[0] = 0;
        priority_queue<P, vector<P>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int cost, v;
            tie(cost, v) = pq.top();
            pq.pop();
            //cout << v << ":" << cost << endl;
            int x = v % R;
            int y = v / R;
            if (v >= R * C) {
                if (x - 1 >= 0) {
                    int nv = R * y + x - 1;
                    if (cost + 1 < dist[nv]) {
                        dist[nv] = cost;
                        pq.push({cost + 1, nv});
                    }
                }
                int nv = v - R * C;
                if (cost < dist[nv]) {
                    dist[nv] = cost;
                    pq.push({cost, nv});
                }
            } else {
                int nv = v + R * C;
                if (cost + 1 < dist[nv]) {
                    dist[nv] = cost + 1;
                    pq.push({cost + 1, nv});
                }
                if (y + 1 <= C - 1) {
                    nv = R * (y + 1) + x;
                    if (cost + A[x][y] < dist[nv]) {
                        dist[nv] = cost + A[x][y];
                        pq.push({cost + A[x][y], nv});
                    }
                }
                if (y - 1 >= 0) {
                    nv = R * (y - 1) + x;
                    if (cost + A[x][y - 1] < dist[nv]) {
                        dist[nv] = cost + A[x][y - 1];
                        pq.push({cost + A[x][y - 1], nv});
                    }
                }
                if (x + 1 <= R - 1) {
                    nv = R * y + x + 1;
                    if (cost + B[x][y] < dist[nv]) {
                        dist[nv] = cost + B[x][y];
                        pq.push({cost + B[x][y], nv});
                    }
                }
            }
        }
        cout << dist[R * C - 1] << endl;
    }
};
