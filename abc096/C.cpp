#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define FOR(i,a,b) for(int i=(a), i##_len=(b);i< i##_len; ++i)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int H, W;
char s[5000][5000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

signed main()
{
    cin >> H >> W;
    REP(i, H) REP(j, W) cin >> s[i][j];

    REP(i, H) REP(j, W)
    {
        char c = s[i][j];
        if (c == '.') continue;
        bool cond = false;
        for (int k = 0; k < 4; ++k)
        {
            int x = dx[k];
            int y = dy[k];
            if (i+x < 0 || i+x > H-1 || j+y < 0 || j+y > W-1) continue;
            char t = s[i+x][j+y];
            if (t == '#') cond = true;

        }
        if (!cond)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
