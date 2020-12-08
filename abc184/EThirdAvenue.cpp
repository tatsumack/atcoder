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

class EThirdAvenue {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> G(H, vector<char>(W));
        REP(i, H) {
            REP(j, W) {
                cin >> G[i][j];
            }
        }
        deque<tuple<int, int, int>> deq;
        vector<vector<pair<int, int>>> p(26);
        REP(i, H) {
            REP(j, W) {
                char c = G[i][j];
                if ('a' <= c && c <= 'z') {
                    p[c - 'a'].push_back({i, j});
                }
                if (c == 'S') {
                    deq.emplace_back(i, j, 0);
                }
            }
        }

        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};

        set<char> visitC;
        vector<vector<bool>> visited(H, vector<bool>(W));
        while (!deq.empty()) {
            int i, j, val;
            tie(i, j, val) = deq.front();
            deq.pop_front();
            if (i == H) {
                for (auto to : p[j]) {
                    if (visited[to.first][to.second]) continue;
                    visited[to.first][to.second] = true;
                    deq.push_back({to.first, to.second, val + 1});
                }
                continue;
            }
            visited[i][j] = true;
            char c = G[i][j];
            if (c == 'G') {
                cout << val << endl;
                return;
            }
            REP(k, 4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || nj < 0 || ni >= H || nj >= W) continue;
                if (G[ni][nj] == '#') continue;
                if (visited[ni][nj]) continue;
                visited[ni][nj] = true;
                deq.push_back({ni, nj, val + 1});
            }
            if ('a' <= c && c <= 'z' && visitC.count(c) == 0) {
                deq.push_front({H, c - 'a', val});
                visitC.insert(c);
            }
        }
        cout << -1 << endl;
    }
};
