#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

signed main()
{
    int N, M;
    cin >> N >> M;

    int ans = (1900 * M + 100 * (N - M)) * pow(2, M);
    cout << ans << endl;

    return 0;
}
