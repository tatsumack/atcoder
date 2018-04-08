#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (1e9)

using namespace std;

int A[3];

signed main()
{
    REP(i, 3) cin >> A[i];
    sort(A, A+3);
    int ans = 0;
    ans += A[2] - A[1];

    A[0] = A[0] + ans;
    if ((A[2]- A[0]) % 2 != 0) ++ans, ++A[2];
    ans += (A[2] - A[0]) / 2;

    cout << ans << endl;

    return 0;
}
