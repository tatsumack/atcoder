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

class ADividingAString {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        int last = s.size()-1;
        REV(i, s.size()- 1, 1) {
            if (s[i] != s[i-1]) {
                break;
            }
            last--;
        }

        int res = 1;
        int i = 0;
        char prev = s[0];
        for (i = 1; i < s.size(); i++) {
            if (i >= last) break;
            if (s[i] == prev) {
                i++;
                prev = '0';
            }
            res++;
        }
        int len = s.size() - 1 - i;
        int k = len / 3 * 2;
        if (k % 3 != 0) k++;
        res += k;
        cout << res << endl;

    }
};
