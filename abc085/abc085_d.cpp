#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int B[100001] = {};

int main()
{
    int N, H;
    cin >> N >> H;

    int maxA = 0;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        maxA = max(a, maxA);
        B[i] = b;
    }

    sort(B, B+N, greater<int>());

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (B[i] < maxA) break;
        H -= B[i];
        ++ans;

        if (H <= 0)
        {
            cout << ans << endl;
            return 0;
        }
    }
    ans += H / maxA;
    if (H % maxA != 0) ++ans;
    cout << ans << endl;


    return 0;
}
