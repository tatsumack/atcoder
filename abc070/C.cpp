#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N;
int T[103];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

signed main()
{
    cin >> N;
    REP(i,N) cin >> T[i];

    int ans = T[0];
    for (int i = 1; i < N; ++i)
    {
        ans = ans / gcd(ans, T[i]) * T[i];
    }
    cout << ans << endl;

    return 0;
}
