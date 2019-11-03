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
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        deque<char> deq;
        REP(i, N) {
            char c = S[i];
            if (deq.empty()) {
                deq.push_back(c);
                continue;
            }
            char l = deq.front();
            if (c == l) {
                deq.pop_front();
                continue;
            }
            char r = deq.back();
            if (c == r) {
                deq.pop_back();
                continue;
            }

            if (i + 1 <= N - 1) {
                char n = S[i + 1];
                if (n == r) {
                    deq.push_front(c);
                } else {
                    deq.push_back(c);
                }
            } else {
                deq.push_back(c);
            }
        }
        cout << deq.size() << endl;
    }
};
