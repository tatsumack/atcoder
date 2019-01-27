
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;

vector<int> G[100005];
int dist[100005];
int par[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> in(N);
    REP(i, N - 1 + M) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;

        G[from].push_back(to);
        in[to]++;
    }

    int root = -1;
    REP(i, N) {
        if (in[i] == 0) {
            root = i;
            break;
        }
    }

    // トポロジカルソート O(N+M)
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int t = st.top();
        st.pop();

        for (auto k : G[t]) {
            in[k]--;
            if (in[k] == 0) {
                st.push(k);
                par[k] = t + 1;
            }
        }
    }

    REP(i, N) {
        cout << par[i] << endl;
    }

    return 0;
}
