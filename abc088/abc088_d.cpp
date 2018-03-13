#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

struct Square {
    int i,j;
    Square(){}
    Square(int i, int j) : i(i), j(j){}
};

int main()
{
    int H, W;
    char s[51][51];
    int memo[51][51] = {};

    cin >> H >> W;

    int blackNum = 0;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            cin >> s[i][j];
            if (s[i][j] == '#') ++blackNum;
        }
    }

    queue<struct Square> q;
    q.push(Square(1,1));
    memo[1][1] = 1;

    int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
    while (!q.empty())
    {
        struct Square cur = q.front();
        q.pop();

        int x = cur.i;
        int y = cur.j;

        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > H || yy > W) continue;
            if (memo[xx][yy] == 0 && s[xx][yy] == '.')
            {
                memo[xx][yy] = memo[x][y] + 1;
                q.push(Square(xx,yy));
            }

        }
    }

    if (memo[H][W] == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << H*W - memo[H][W] - blackNum << endl;

    return 0;
}
