#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    a += b;
    int num = atoi(a.c_str());
    for (int i = 2; i <= 100100; ++i)
    {
        if (i*i == num)
        {
            cout << "Yes" << endl;
            return 0;
        }

    }
    cout << "No" << endl;
    return 0;

    return 0;
}
