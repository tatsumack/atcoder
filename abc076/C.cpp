#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

signed main()
{
    string s;
    string t;
    cin >> s >> t;

    int mIdx = -1;
    REP(i, s.size() - t.size()+1)
    {
        bool match = true;
        REP(j, t.size())
        {
            if (s[i+j] == t[j] || s[i+j] == '?') continue;
            match = false;
            break;
        }
        if (match) mIdx = max(mIdx, i);
    }
    if (mIdx == -1)
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    REP(i, s.size())
    {
        if (i == mIdx)
        {
            REP(j, t.size())
            {
                s[i+j] = t[j];
            }
            i += t.size()-1;
        }
        if (s[i] == '?') s[i] = 'a';
    }

    cout << s << endl;

    return 0;
}
