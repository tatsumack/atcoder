#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N, K;
int x[51];
int y[51];
bool used[51];

signed main()
{
    cin >> N >> K;
    REP(i, N) cin >> x[i] >> y[i];

    int ans = -1;
    REP (i, N)
    for (int j = i+1; j < N; ++j)
    REP (m, N)
    for (int n = m+1; n < N; ++n)
    {
        int x1 = min(x[i], x[j]);
        int x2 = max(x[i], x[j]);
        int y1 = min(y[m], y[n]);
        int y2 = max(y[m], y[n]);

        int num = 0;
        REP(k, N)
        {
            if (x1 <= x[k] && x[k] <= x2 && y1 <= y[k] && y[k] <= y2) ++num;
        }

        int s = abs(x2 - x1) * abs(y2 - y1);
        if (num >= K)
        {
            ans = ans == -1 ? s : min(ans, s);
        }
    }
    cout << ans << endl;

    return 0;
}
