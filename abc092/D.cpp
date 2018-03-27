#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int A, B;
int G[101][101]; // Black:0, White:1

signed main()
{
    cin >> A >> B;

    int h = 100;
    int w = 100;

    int bnum = 1;
    int wnum = 1;
    REPS(i, h) REPS(j, w)
    {
        if (j <= 50)
        {
            if (i%2 == 0 && j%2 != 0 && bnum < B)
            {
                ++bnum;
                G[i][j] = 0;
            }
            else
            {
                G[i][j] = 1;
            }
        }
        else
        {
            if (i%2 == 0 && j%2 == 0 && wnum < A)
            {
                ++wnum;
                G[i][j] = 1;
            }
            else
            {
                G[i][j] = 0;
            }
        }
    }

    printf("%lld %lld\n", h, w);
    REPS(i, h)
    {
        REPS(j, w)
        {
            char c = G[i][j] == 0 ? '#' : '.';
            printf("%c", c);
        }
        printf("\n");
    }

    return 0;
}
