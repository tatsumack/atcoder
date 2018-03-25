#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int N, C;
int s[100001];
int t[100001];
int c[100001];

int tt[100001];
int sm[100001];

signed main()
{
    cin >> N >> C;
    REP(i, N) cin >> s[i] >> t[i] >> c[i];

    REPS(i, C)
    {
        REP(j, 100001) tt[j] = 0;
        REP(j, N) if (i == c[j]) tt[s[j]-1]++, tt[t[j]]--;
        REPS(j, 100000) tt[j] += tt[j-1];
        REP(j, 100001) if (tt[j] > 0) sm[j]++;
    }

    int ans = 0;
    REP(i, 100000) ans = max(ans, sm[i]);
    cout << ans << endl;

    return 0;
}
