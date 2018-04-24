#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int e[201][201];

int N, M, R;

signed main()
{
    cin >> N >> M >> R;

    vector<int> r;
    REP(i, R)
    {
        int a;
        cin >> a;
        r.push_back(a);
    }

    REPS(i,N) REPS(j,N) e[i][j] = i==j ? 0 : INF;
    REP(i, M)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        e[from][to] = cost;
        e[to][from] = cost;
    }

    REPS(k, N) REPS(i, N) REPS(j, N)
        e[i][j] = min(e[i][j], e[i][k] + e[k][j]);

    sort(r.begin(), r.end());
    int ans = INF;
    do
    {
        int tmp = 0;
        for (int i = 0; i < R-1; ++i)
        {
            tmp += e[r[i]][r[i+1]];
        }
        ans = min(ans, tmp);
    }
    while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;

    return 0;
}
