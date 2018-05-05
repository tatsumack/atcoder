#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

int N;
int A[200005];
int sum[200005];

signed main()
{
    cin >> N;
    REPS(i, N) cin >> A[i];
    REPS(i, N) sum[i] = A[i] + sum[i-1];

    int ans = INF;
    REPS(i, N-1)
    {
        ans = min(ans, abs(sum[i] - (sum[N] - sum[i])));
    }
    cout << ans << endl;

    return 0;
}
