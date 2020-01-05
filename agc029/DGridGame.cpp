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

class DGridGame {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W, N;
        cin >> H >> W >> N;
        vector<int> X(N), Y(N);
        REP(i, N) {
            cin >> X[i] >> Y[i];
            X[i]--, Y[i]--;
        }

        vector<set<int>> v(W);
        REP(i, N) {
            v[Y[i]].insert(X[i]);
        }

        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(H);
        if (!v[0].empty()) {
            pq.push(*v[0].begin());
        }
        int cur = 0;
        for (int i = 1; i < H; i++) {
            if (cur == W - 1) break;
            if (v[cur + 1].empty()) {
                cur++;
                continue;
            }
            auto itr = v[cur + 1].lower_bound(i);
            if (itr == v[cur + 1].end()) {
                cur++;
            } else if (*itr == i) {
                // nop
            } else {
                pq.push(*itr);
                cur++;
            }
        }
        cout << pq.top() << endl;
    }
};
