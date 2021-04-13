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

class AReachableTowns {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<tuple<int, int, int>> v(N);
        REP(i, N) {
            int x, y;
            cin >> x >> y;
            v[i] = {x, y, i};
        }
        sort(v.begin(), v.end());

        atcoder::dsu d(N);
        stack<pair<int, int>> st;
        REP(i, N) {
            int x, y, id;
            tie(x, y, id) = v[i];
            if (st.empty() || y < st.top().first) {
                st.push({y, id});
                continue;
            }
            auto front = st.top();
            while (!st.empty() && y > st.top().first) {
                int to = st.top().second;
                d.merge(id, to);
                st.pop();
            }
            st.push(front);
        }
        REP(i, N) {
            cout << d.size(i) << endl;
        }
    }
};
