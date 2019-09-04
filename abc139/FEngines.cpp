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
#define fcout cout << fixed << setprecision(50)

using namespace std;

typedef pair<int, int> P;

class FEngines {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    double calc(vector<pair<int, int>>& v) {
        int x = 0;
        int y = 0;
        REP(i, v.size()) {
            x += v[i].first;
            y += v[i].second;
        }
        return sqrt(x * x + y * y);
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<pair<int , int>> RU, LU, RB, LB;
        REP(i, N) {
            int x, y;
            cin >> x >> y;
            pair<int, int> p = {x, y};
            if (x > 0 && y > 0) {
                RU.push_back(p);
            } else if (x < 0 && y > 0) {
                LU.push_back(p);
            } else if (x > 0 && y < 0) {
                RB.push_back(p);
            } else if (x < 0 && y < 0) {
                LB.push_back(p);
            } else if (x == 0) {
                if (y > 0) {
                    RU.push_back(p);
                    LU.push_back(p);
                } else {
                    RB.push_back(p);
                    LB.push_back(p);
                }
            } else if (y == 0) {
                if (x > 0) {
                    RU.push_back(p);
                    RB.push_back(p);
                } else {
                    LU.push_back(p);
                    LB.push_back(p);
                }
            }
        }

        double res = 0;
        res = max(res, calc(RU));
        res = max(res, calc(LU));
        res = max(res, calc(RB));
        res = max(res, calc(LB));
        fcout << res << endl;
    }
};
