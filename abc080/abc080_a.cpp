#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

using namespace std;
int N, A, B;

signed main()
{
    cin >> N >> A >> B;

    int ans = min(A*N, B);
    cout << ans << endl;

    return 0;
}
