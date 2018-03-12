#include<iostream>

using namespace std;

typedef long long ll;

int main()
{
    int c[4][4];
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            cin >> c[i][j];
        }
    }

    for (int a1 = 0; a1 <= 100; ++a1)
    {
        int b1 = c[1][1] - a1;
        int b2 = c[1][2] - a1;
        int b3 = c[1][3] - a1;
        if ((c[2][1] - b1 == c[2][2] - b2) && (c[2][2] - b2 == c[2][3] - b3))
        {
            if ((c[3][1] - b1 == c[3][2] - b2) && (c[3][2] - b2 == c[3][3] - b3))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
