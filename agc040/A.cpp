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

class A {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;

        int N = s.size() + 1;

        vector<int> A(N);
        vector<int> pos;
        if (s.front() == '<') pos.push_back(0);
        if (s.back() == '>') pos.push_back(N - 1);

        REP(i, s.size() - 1) {
            if (s[i] == '>' && s[i + 1] == '<') {
                pos.push_back(i + 1);
            }
        }

        for (auto i : pos) {
            A[i] = 0;
            int l = i;
            while (l - 1 >= 0 && s[l - 1] == '>') {
                l--;
                A[l] = max(A[l], A[l + 1] + 1);
            }
            int r = i;
            while (r + 1 <= N - 1 && s[r] == '<') {
                r++;
                A[r] = max(A[r], A[r - 1] + 1);
            }
        }

        int res = 0;
        REP(i, N) res += A[i];
        cout << res << endl;
    }
};
