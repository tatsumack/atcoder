
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N, M;
vector<int> G[100005];
bool used[100005];

int dfs(int s, deque<int> &q) {
    used[s] = true;
    q.push_back(s);
    REP(i, G[s].size()) {
        if (used[G[s][i]]) continue;
        return dfs(G[s][i], q);
    }
    return s;
}

bool judge(deque<int> &q) {
    int front = q.front();
    REP(i, G[front].size()) {
        if (used[G[front][i]]) continue;
        q.push_front(G[front][i]);
        used[q.front()] = true;
        return false;
    }
    int back = q.back();
    REP(i, G[back].size()) {
        if (used[G[back][i]]) continue;
        q.push_back(G[back][i]);
        used[q.back()] = true;
        return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    deque<int> q;
    int a = dfs(1, q);
    while (!judge(q)) {}

    cout << q.size() << endl;
    REP(i, q.size()) {
        if (i != 0) cout << " ";
        cout << q[i];
    }
    cout << endl;

    return 0;
}
