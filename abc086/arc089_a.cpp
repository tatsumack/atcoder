#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    int px = 0;
    int py = 0;
    int pt = 0;
    while (N--)
    {
        int t, x, y;
        cin >> t >> x >>y;

        int times = abs(x - px) + abs(y - py) + pt;
        if (times > t || (t - times) % 2 != 0)
        {
            puts("No");
            return 0;
        }

    }
    puts("Yes");

    return 0;
}
