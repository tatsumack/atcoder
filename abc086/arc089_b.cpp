#include <iostream>

using namespace std;

typedef long long ll;

int sum[2010][2010] = {};
int dot[2010][2010] = {};

int findDot(int x1, int y1, int x2, int y2)
{
    if (x2 < x1 || y2 < y1) return 0;
    return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
}

int main()
{
    int N, K;
    cin >> N >> K;

    int x, y;
    char c;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y >> c;

        if (c == 'W') y += K;

        dot[x % (2*K) + 1][y % (2*K) + 1] += 1;
    }

    for (int i = 0; i < 2*K + 2; ++i)
    {
        for (int j = 0; j < 2*K + 2; ++j)
        {
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + dot[i+1][j+1];
        }
    }

    int ans = 0;
    int tmp = 0;
    for (int x = 1; x <= K; ++x)
    {
        for (int y = 1; y <= K; ++y)
        {
            tmp = findDot(x, y, x+K-1, y+K-1)
                + findDot(x+K, y+K, 2*K, 2*K)
                + findDot(1, 1, x-1, y-1)
                + findDot(1, y+K, x-1, 2*K)
                + findDot(x+K, 1, 2*K, y-1);
            ans = max(ans, max(tmp, N-tmp));
        }
    }
    cout << ans << endl;

    return 0;
}
