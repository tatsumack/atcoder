#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

double dp[101][60][40][30];
int N;
ll D;
int I, J, K;

int main()
{
    cin >> N >> D;

    while (D%2==0) ++I, D /= 2;
    while (D%3==0) ++J, D /= 3;
    while (D%5==0) ++K, D /= 5;
    if (D != 1)
    {
        printf("%.9f\n", 0.0);
        return 0;
    }

    dp[0][0][0][0] = 1;
    for (int n = 0; n < N; ++n)
    {
        for (int i = 0; i < 60; ++i)
        for (int j = 0; j < 40; ++j)
        for (int k = 0; k < 30; ++k)
        {
            if (dp[n][i][j][k] == 0) continue;
            dp[n+1][i][j][k] += dp[n][i][j][k]/6.0;
            dp[n+1][min(I,i+1)][j][k] += dp[n][i][j][k]/6.0;
            dp[n+1][i][min(J,j+1)][k] += dp[n][i][j][k]/6.0;
            dp[n+1][min(I,i+2)][j][k] += dp[n][i][j][k]/6.0;
            dp[n+1][i][j][min(K,k+1)] += dp[n][i][j][k]/6.0;
            dp[n+1][min(I,i+1)][min(J,j+1)][k] += dp[n][i][j][k]/6.0;
        }
    }
    printf("%.9f\n", dp[N][I][J][K]);

    return 0;
}
