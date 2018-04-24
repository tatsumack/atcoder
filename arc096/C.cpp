#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int A, B, C, X, Y;

int solve(int x, int y)
{
    if (A+B >= 2*C)
    {
        if (X > Y)
        {
            int ans = Y*2*C;
            ans += (X-Y) * min(A, 2*C);
            return ans;
        }
        else
        {
            int ans = X*2*C;
            ans += (Y-X) * min(B, 2*C);
            return ans;
        }
    }

    return X*A + Y*B;
}

signed main()
{
    cin >> A >> B >> C >> X >> Y;

    int ans = solve(X, Y);
    cout << ans << endl;

    return 0;
}
