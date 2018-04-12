#include <iostream>
#include <iomanip>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N;
int T[103];
int tt[103];
int V[103];

signed main()
{
    cin >> N;

    int sum = 0;
    REPS(i, N) cin >> T[i];
    REPS(i, N) cin >> V[i];
    REPS(i, N+1)
    {
        sum += T[i];
        tt[i] += tt[i-1] + T[i];
    }

    int v = 0;
    float ans = 0.0;
    for (float time = 0; time <= sum; time += 0.5)
    {
        float minv = INF;
        for (int i = 0; i <= N + 1; ++i)
        {
            float tmpv = INF;
            if (i > 0 && time < tt[i-1])
            {
                tmpv = V[i] + tt[i-1] - time;
            }
            else if (i > 0 && tt[i-1] <= time && time < tt[i])
            {
                tmpv = V[i];
            }
            else if (tt[i] <= time)
            {
                tmpv = V[i] + time - tt[i];
            }
            minv = min(minv, tmpv);
        }
        //printf("time:%f, v:%f\n", time, minv);
        ans += minv * 0.5;
    }
    cout << fixed;
    cout << setprecision(5) << ans << endl;

    return 0;
}
