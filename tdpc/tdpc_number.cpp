#include <iostream>

using namespace std;

typedef long long ll;

string s;
int D;
ll dp[10001][101][2];
ll mod = 1000000007;

int main()
{
    cin >> D >> s;
    int N = s.size();

    dp[0][0][0] = 1;

    for (int i = 0; i < N; ++i)
    for (int j = 0; j < D; ++j)
    for (int k = 0; k < 2; ++k)
    {
        int end = k ? 9 : s[i] - '0';
        for (int l = 0; l <= end; ++l)
        {
            dp[i+1][(l+j)%D][k || l < end] += dp[i][j][k] % mod;
        }
    }
    cout << (dp[N][0][0]+dp[N][0][1]-1) % mod << endl;

    return 0;
}
