#include <iostream>

using namespace std;

typedef long long ll;

ll X, Y;

int main()
{
    cin >> X >> Y;

    int ans = 0;
    while (X <= Y)
    {
        ++ans;
        X *= 2;
    }
    cout << ans << endl;

    return 0;
}
