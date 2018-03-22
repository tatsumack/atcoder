#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<char> sv, tv;

int main()
{
    string s,t;
    cin >> s >> t;

    for (int i = 0; i < s.size(); ++i) sv.push_back(s[i]);
    for (int i = 0; i < t.size(); ++i) tv.push_back(t[i]);
    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end(), greater<char>());

    bool bIsLexOrder = true;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i >= t.size()
            || sv[i] > tv[i]
            || (sv.size() == tv.size() && sv[i] == tv[i]))
        {
            bIsLexOrder = false;
            break;
        }
        if (sv[i] < tv[i]) break;
    }

    string ans = bIsLexOrder ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
