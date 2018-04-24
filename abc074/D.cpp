#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N;

int A[301][301];

signed main()
{
    cin >> N;
    REP(i, N) REP(j, N) cin >> A[i][j];

    int ans = 0;
    REP(i, N)
    for (int j = i+1; j < N; ++j)
    {
        int e = INF;
        REP(k, N)
        {
            if (k == i || k == j) continue;
            e = min(e, A[i][k] + A[k][j]);
        }
        if (A[i][j] < e)
        {
            ans += A[i][j];
        }
        else if (A[i][j] > e)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    return 0;
}
