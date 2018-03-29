#include <iostream>
#include <algorithm>
#include <string>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

string s;

signed main()
{
    cin >> s;
    int s0 = s[0] - '0';
    int s1 = s[1] - '0';
    int s2 = s[2] - '0';
    int s3 = s[3] - '0';
    REP(i, 2) REP(j, 2) REP(k, 2)
    {
        int ans = 0;
        ans = i == 0 ? s0 + s1 : s0 - s1;
        ans = j == 0 ? ans + s2 : ans - s2;
        ans = k == 0 ? ans + s3 : ans - s3;
        if (ans == 7)
        {
            string str = "";
            str += s[0];
            str += i == 0 ? "+" : "-";
            str += s[1];
            str += j == 0 ? "+" : "-";
            str += s[2];
            str += k == 0 ? "+" : "-";
            str += s[3];
            str += "=7";
            cout << str << endl;
            return 0;
        }
    }

    return 0;
}
