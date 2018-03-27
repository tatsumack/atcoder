#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int N;
int A[100010];
int cost[100010];
int sc[100010];

signed main()
{
    cin >> N;
    REPS(i, N) cin >> A[i];
    A[N+1] = 0;

    REPS(i, N+1) cost[i] = abs(A[i]-A[i-1]);
    REPS(i, N+1) sc[i] = sc[i-1] + cost[i];

    REPS(i, N)
    {
        int start = 0;
        int mid = i;
        int end = N+1;

        int ans = (sc[mid-1] - sc[start]) + abs(A[mid-1] - A[mid+1]) + (sc[N+1] - sc[mid+1]);
        printf("%lld\n", ans);
    }

    return 0;
}
