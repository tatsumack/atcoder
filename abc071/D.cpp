
#include <iostream>
#include <algorithm>
 
#define int long long
 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
 
#define INF (3e9)
 
using namespace std;
 
int N;
char S1[60];
char S2[60];
 
int mod = 1000000007;
 
signed main()
{
    cin >> N;
    REP(i,N) cin >> S1[i];
    REP(i,N) cin >> S2[i];
 
    int ans = 0;
    REP(i,N)
    {
        if (S1[i] == S2[i])
        {
            // たて
            if (i == 0)
            {
                ans = 3;
            }
            else
            {
                ans = S1[i-1] == S2[i-1] ? ans*2 % mod : ans;
            }
        }
        else
        {
            // よこ
            if (i == 0)
            {
                ans = 6;
            }
            else
            {
                ans = S1[i-1] == S2[i-1] ? ans*2 % mod : ans*3 % mod;
            }
            ++i;
        }
    }
    cout << ans << endl;
 
 
    return 0;
}
