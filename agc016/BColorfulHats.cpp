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

class BColorfulHats {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N);
        map<int, int> cnt;
        REP(i, N) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());

        if (a.back() > N - 1) {
            cout << "No" << endl;
            return;
        }

        if (a.front() + 1 < a.back()) {
            cout << "No" << endl;
            return;
        }
        if (a.front() == a.back()) {
            cout << (N >= 2 * a.front() || a.front() + 1 == N ? "Yes" : "No") << endl;
            return;
        }

        int anum = cnt[a.front()];
        int bnum = cnt[a.back()];
        if (anum > a.front()) {
            cout << "No" << endl;
            return;
        }
        if (N >= (a.back() - anum) * 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
};
