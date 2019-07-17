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

class BSportsFestival {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> A;
    int open[301];
    int N, M;

    P calc() {
        map<int, int> cnt;
        REP(i, N) {
            REP(j, M) {
                if (open[A[i][j]]) {
                    cnt[A[i][j]]++;
                    break;
                }
            }
        }

        int num = 0;
        int sports = -1;
        for (auto kv : cnt) {
            if (kv.second > num) {
                sports = kv.first;
                num = kv.second;
            }
        }

        return {sports, num};
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> M;
        A = vector<vector<int>>(N, vector<int>(M));
        REP(i, N) REP(j, M) {
            cin >> A[i][j];
            A[i][j]--;
        }

        REP(i, M) open[i] = 1;

        int cur = INF;
        REP(i, M) {
            int num, sports;
            tie(sports, num) = calc();
            if (num < cur) {
                cur = num;
            }
            open[sports] = 0;
        }
        cout << cur << endl;
    }
};
