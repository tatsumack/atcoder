#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[200001];
ll b[200001];
ll c[200001];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> b[i];
    }

    int ans = 0;
    for (int k = 0; k < 29; ++k)
    {
        int T = 1 << k;
        for (int i = 0; i < N; ++i) c[i] = b[i] % (T*2);
        sort(c, c+N);

        int tmp = 0;
        for (int i = 0; i < N; ++i)
        {
            int aa = a[i] % (T*2);
            int t  = lower_bound(c, c+N, T - aa) - c;
            int t2 = lower_bound(c, c+N, 2*T - aa) - c;
            int t3 = lower_bound(c, c+N, 3*T - aa) - c;
            tmp += (t2 - t) + (N - t3);
        }
        if (tmp % 2 != 0) ans += T;
    }
    cout << ans << endl;

    return 0;
}
