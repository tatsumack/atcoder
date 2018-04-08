#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (1e9)

using namespace std;

int a, b, c;

signed main()
{
    string s;
    cin >> s;
    REP(i, 3)
    {
        char ch = s.at(i);
        switch (ch)
        {
            case 'a':
                ++a;
                break;
            case 'b':
                ++b;
                break;
            case 'c':
                ++c;
                break;
        }

    }

    if (a == 1 && b == 1 && c == 1)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }

    return 0;
}
