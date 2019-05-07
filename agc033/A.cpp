
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
#include <queue>

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

// 多重配列
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
    for(auto &e:t) fill_v(e,v);
}

typedef pair<int, int> P;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;
    auto memo = make_v<int>(H, W);
    fill_v(memo, -1);

    queue<P> q;
    REP(i, H) REP(j, W) {
        char a;
        cin >> a;
        if (a != '#') continue;
        memo[i][j] = 0;
        q.push({i, j});
    }

    int res = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        REP(i, 4) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (memo[nx][ny] >= 0) continue;
            memo[nx][ny] = memo[p.first][p.second] + 1;
            res = max(memo[nx][ny], res);
            q.push({nx, ny});
        }
    }
    cout << res << endl;

    return 0;
}
