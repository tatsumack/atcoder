#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

double dp[2000][20];
int r[2000];

int main()
{
    int K;
    cin >> K;

    for (int i = 0; i < pow(2,K); ++i)
    {
        cin >> r[i];
        dp[i][0] = 1;
    }

    for (int j = 1; j <= K; ++j)
    {
        for (int i = 0; i < pow(2,K); ++i)
        {
            int head = i / static_cast<int>(pow(2,j)) * pow(2,j);
            int mid  = head + pow(2,j-1);
            int last = head + pow(2,j);

            //printf("i:%d, h:%d, m%d, l:%d\n", i, head, mid, last);

            int start = i >= mid ? head : mid;
            int end   = i >= mid ? mid  : last;

            //printf("i:%d, s:%d, e%d\n", i, start, end);

            dp[i][j] = 0;
            for (int m = start; m < end; ++m)
            {
                dp[i][j] += dp[m][j-1] * (1/(1+pow(10, (r[m] - r[i]) / 400.0)));
            }
            dp[i][j] *= dp[i][j-1];
        }
    }

    for (int i = 0; i < pow(2,K); ++i)
    {
        printf("%.9f\n", dp[i][K]);
    }

    return 0;
}
