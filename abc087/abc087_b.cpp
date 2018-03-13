#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int result = 0;
    for (int i = 0; i <= A; ++i)
    {
        for (int j = 0; j <= B; ++j)
        {
            for (int k = 0; k <= C; ++k)
            {
                if (500 * i + 100 * j + 50 * k == X) ++result;
            }
        }
    }

    cout << result << endl;

    return 0;
}
