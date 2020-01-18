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

class CWelcomeToAtCoder {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> p(M);
        vector<string> S(M);
        REP(i, M) {
            cin >> p[i] >> S[i];
            p[i]--;
        }

        vector<int> AC(N), WA(N);
        REP(i, M) {
            int no = p[i];
            auto& res = S[i];

            if (res == "AC") {
                AC[no]++;
            }
            if (res == "WA") {
                if (AC[no] == 0) {
                    WA[no]++;
                }
            }
        }

        int ac, wa;
        ac = 0;
        wa = 0;
        REP(i, N) {
            if (AC[i] > 0) ac++;
            if (AC[i] > 0) wa += WA[i];
        }
        cout << ac << " " << wa << endl;
    }
};
