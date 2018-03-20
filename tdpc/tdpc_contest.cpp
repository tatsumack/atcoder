#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

#define MAX 10000

bool dp[101][MAX+1]; // dp[i+1][j]: i番目までの整数まででjが作れるか
int p[101];


int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> p[i];
    }

    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= MAX; ++j)
        {
            dp[i+1][j] |= dp[i][j];
            if (j >= p[i]) dp[i+1][j] |= dp[i][j-p[i]];
        }
    }

    int ans = 0;
    for (int j = 0; j <= MAX; ++j)
    {
        if (dp[N][j]) ++ans;
    }
    cout << ans << endl;

    return 0;
}
