#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define BASE 8001
bool dpx[BASE][BASE*2];
bool dpy[BASE][BASE*2];

int main()
{
    string s;
    int x, y;
    cin >> s >> x >> y;

    bool isX = true;
    int cnt = 0;
    vector<int> vx, vy;
    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        switch (c)
        {
            case 'T':
                isX ? vx.push_back(cnt) : vy.push_back(cnt);
                cnt = 0;
                isX = !isX;
                break;
            case 'F':
                ++cnt;
                break;
        }
    }
    isX ? vx.push_back(cnt) : vy.push_back(cnt);

    dpx[1][BASE + vx[0]] = true;
    for (int i = 1; i < vx.size(); ++i)
    {
        for (int j = 0; j < 2*BASE; ++j)
        {
            if (!dpx[i][j]) continue;
            dpx[i+1][j-vx[i]] = true;
            dpx[i+1][j+vx[i]] = true;
        }
    }

    dpy[0][BASE] = true;
    for (int i = 0; i < vy.size(); ++i)
    {
        for (int j = 0; j < 2*BASE; ++j)
        {
            if (!dpy[i][j]) continue;
            dpy[i+1][j-vy[i]] = true;
            dpy[i+1][j+vy[i]] = true;
        }
    }

    if (dpx[vx.size()][x+BASE] && dpy[vy.size()][y+BASE])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }


    return 0;
}
