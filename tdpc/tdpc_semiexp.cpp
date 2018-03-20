#include <iostream>

using namespace std;

typedef long long ll;

ll mod = 1000000007;

int dp[1000003]; // dp[i] is the way which does not stop i-th station
int sum[1000003];

int N, K;

int main()
{
    cin >> N >> K;
    dp[0] = 1;
    sum[0] = 1;
    for (int i = 1; i <= N+1; ++i)
    {
        int minsum = i-1-K < 0 ? 0 : sum[i-1-K];
        if (i != 1 && i != N) dp[i] = (sum[i-1] - minsum) % mod;
        sum[i] += (sum[i-1] + dp[i]) % mod;
    }

    cout << dp[N+1] << endl;
    return 0;
}
