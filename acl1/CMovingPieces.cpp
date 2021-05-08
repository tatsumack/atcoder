#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

class CMovingPieces {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<vector<char>> S(N, vector<char>(M));
        vector<pair<int, int>> cand;
        REP(i, N) {
            REP(j, M) {
                cin >> S[i][j];
                if (S[i][j] == 'o')cand.emplace_back(i, j);
            }
        }

        int OFFSET = 100000;
        vector<vector<int>> dp(cand.size());
        REP(i, cand.size()) {
            int x, y;
            tie(x, y) = cand[i];
            vector<int> dist(N * M, INF);
            dist[x * M + y] = 0;
            queue<pair<int, int>> q;
            q.push({x * M + y, 0});
            while (!q.empty()) {
                int cost, v;
                tie(v, cost) = q.front();
                q.pop();
                int cx = v / M;
                int cy = v % M;
                REP(j, 2) {
                    int nx = cx + dx[j];
                    int ny = cy + dy[j];
                    if (nx >= N || ny >= M) continue;
                    if (S[nx][ny] == '#') continue;
                    if (cost + 1 < dist[nx * M + ny]) {
                        dist[nx * M + ny] = cost + 1;
                        q.push({nx * M + ny, dist[nx * M + ny]});
                    }
                }
            }
            dp[i] = dist;
        }

        atcoder::mcf_graph<int, int> graph(cand.size() + N * M + 2);
        int s = N * M + cand.size();
        int t = s + 1;
        REP(i, cand.size()) {
            graph.add_edge(s, N * M + i, 1, 0);
        }
        REP(i, N * M) {
            graph.add_edge(i, t, 1, 0);
        }
        REP(i, cand.size()) {
            REP(j, N * M) {
                if (dp[i][j] < INF) {
                    graph.add_edge(N * M + i, j, 1, OFFSET - dp[i][j]);
                }
            }
        }
        int res = graph.flow(s, t).second;
        res -= cand.size() * OFFSET;
        cout << -res << endl;
    }
};
