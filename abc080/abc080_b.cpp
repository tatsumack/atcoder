#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

using namespace std;

string s;
signed main()
{
    cin >> s;

    int sum = 0;
    REP(i, s.size()) sum += s[i] - '0';

    int N = stoi(s);
    if (N % sum == 0)
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }

    return 0;
}
