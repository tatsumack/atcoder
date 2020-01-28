#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class C {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<vector<int>> V;
        vector<vector<vector<int>>> v(N);
        REP(i, N) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            V.push_back(vector<int>{X, Y, Z});

            int m;
            cin >> m;
            REP(j, m) {
                int x, y, z;
                cin >> x >> y >> z;
                v[i].push_back(vector<int>{x, y, z});
            }
        }

        vector<int> nim;
        REP(i, N) {
            REP(j, 3) {
                int l = INF;
                int r = 0;
                REP(k, v[i].size()) {
                    l = min(l, v[i][k][j]);
                    r = max(r, v[i][k][j]);
                }
                nim.push_back(l);
                nim.push_back(V[i][j] - 1 - r);
            }
        }

        int res = 0;
        for (auto j : nim) res ^= j;
        cout << (res > 0 ? "WIN" : "LOSE") << endl;
    }
};
