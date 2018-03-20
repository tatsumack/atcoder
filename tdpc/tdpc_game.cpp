#include <iostream>

using namespace std;

typedef long long ll;

int dp[1001][1001]; // dp[i+1][j+1]: 左の山が i 個、右の山が j 個のこっている状態からスタートするときの先手の取るものの価値の和
int a[1001];
int b[1001];

int main()
{
    int A, B;
    cin >> A >> B;

    for (int i = 0; i < A; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < B; ++i)
    {
        cin >> b[i];
    }

    dp[0][0] = 0;
    for (int i = 0; i < A; ++i)
    {
        int turn = (A+B) - (i+1)+1;
        dp[i+1][0] = turn % 2 != 0 ? dp[i][0] + a[A-1-i] : dp[i][0];
    }
    for (int i = 0; i < B; ++i)
    {
        int turn = (A+B) - (i+1)+1;
        dp[0][i+1] = turn % 2 != 0 ? dp[0][i] + b[B-1-i] : dp[0][i];
    }

    for (int i = 0; i < A; ++i)
    {
        for (int j = 0; j < B; ++j)
        {
            int turn = (A+B) - ((i+1)+(j+1)) + 1;
            if (turn % 2)
            {
                dp[i+1][j+1] = max(dp[i][j+1] + a[(A-1) - i], dp[i+1][j] + b[(B-1) - j]);
            }
            else
            {
                dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    cout << dp[A][B] << endl;

    return 0;
}
