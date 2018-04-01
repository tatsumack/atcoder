#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

signed main()
{
    string s;
    cin >> s;

    vector<char> vc;
    REP(i, s.size()) vc.push_back(s[i]);

    next_permutation(vc.begin(), vc.end());
    REP(i, vc.size()) cout << vc[i];
    cout << endl;


    return 0;
}
