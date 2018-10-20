
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

int b[1005][1005], c[1005][1005];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    REP(ii, N) {
    }

    REP(ii, N) {
        int i = ii;
        int j = (3 * i) % 5;
        while (j < N) {
            b[i][j] = 1;
            j += 5;
        }
    }
    REP(i, N) {
        REP(j, N) {
            if (b[i][j] == 0) continue;
            c[i][j] = 1;
            REP(k, 4) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                c[nx][ny] = 1;
            }
        }
    }
    REP(i, N) {
        REP(j, N) {
            if (c[i][j] == 0) {
                b[i][j] = 1;
            }
        }
    }

    REP(i, N) {
        REP(j, N) {
            switch (b[i][j]) {
                case 0:
                    cout << ".";
                    break;
                case 1:
                    cout << "X";
                    break;
            }
        }
        cout << endl;
    }

    return 0;
}
