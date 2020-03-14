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

class CThREE {
public:
    vector<vector<int>> G;
    map<int, int> cnt, types;
    int one, two;

    void dfs(int v, int p, int n) {
        cnt[n]++;
        types[v] = n;
        n == 0 ? one++ : two++;
        for (auto to : G[v]) {
            if (to == p) continue;
            dfs(to, v, n ^ 1);
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        G.resize(N);
        REP(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        one = 0, two = 0;
        dfs(0, -1, 0);

        int oneNum = N / 3;
        if (N % 3 >= 1) oneNum++;
        int twoNum = N / 3;
        if (N % 3 >= 2) twoNum++;

        vector<int> res(N, 0);
        if (one < oneNum || two < twoNum) {
            int t = 0;
            if (two < one) t = 1;
            int cur = 1;
            set<int> used;
            REP(i, N) {
                if (types[i] == t) {
                    res[i] = cur * 3;
                    used.insert(res[i]);
                    cur++;
                }
            }
            int id = 1;
            REP(i, N) {
                if (res[i] == 0) {
                    res[i] = id;
                    id++;
                    if (used.count(id)) id++;
                }
            }
        } else {
            int c1 = 0;
            int c2 = 0;
            REP(i, N) {
                if (types[i] == 0 && c1 * 3 + 1 <= N) {
                    res[i] = c1 * 3 + 1;
                    c1++;
                } else if (types[i] == 1 && c2 * 3 + 2 <= N) {
                    res[i] = c2 * 3 + 2;
                    c2++;
                }
            }
            int c0 = 1;
            REP(i, N) {
                if (res[i] == 0) {
                    res[i] = c0 * 3;
                    c0++;
                }
            }
        }
        REP(i, N) {
            cout << res[i] << " ";
        }
    }
};
