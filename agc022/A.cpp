#include <iostream>
#include <algorithm>
#include <map>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

string s;

string MAX_STRING = "zyxwvutsrqponmlkjihgfedcba";

signed main()
{
    cin >> s;

    if (s == MAX_STRING)
    {
        cout << -1 << endl;
        return 0;
    }

    map<char, int> smap;
    REP(i, s.size()) smap[s[i]] = i;

    if (s.size() < 26)
    {
        char c;
        for (c = 'a'; c <= 'z'; ++c)
        {
            if (smap.find(c) == smap.end()) break;
        }
        s += c;
        cout << s << endl;

        return 0;
    }

    for (int i = s.size()-2; i > 0; --i)
    {
        char nc = s[i] + 1;
        while (nc <= 'z')
        {
            auto find = smap.find(nc);
            if (i < find->second)
            {
                string ans = s.substr(0, i);
                ans += nc;
                cout << ans << endl;
                return 0;
            }
            ++nc;
        }
    }

    int zidx = smap['z'];
    char nc = s[zidx - 1] + 1;
    while (nc < 'z')
    {
        auto find = smap.find(nc);
        if (find == smap.end()) break;
        if (zidx - 1 < find->second) break;
        ++nc;
    }
    string ans = s.substr(0, zidx-1);
    ans += nc;
    cout << ans << endl;

    return 0;
}
