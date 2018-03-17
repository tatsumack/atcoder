#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int A, B;
    cin >> A >> B;

    string s;
    cin >> s;
    for (int i = 0; i < A+B+1; ++i)
    {
        if (i == A)
        {
            if (s[i] != '-')
            {
                puts("No");
                return 0;
            }
        }
        else
        {
            if (s[i] == '-')
            {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");

    return 0;
}
