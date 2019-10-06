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

class AConnectionAndDisconnection {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int calc(string s) {
        char prev = '-';
        int num = 0;
        int res = 0;
        REP(i, s.size()) {
            if (s[i] != prev) {
                res += num / 2;
                num = 1;
            } else {
                num++;
            }
            prev = s[i];
        }
        res += num / 2;
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        int K;
        cin >> K;

        if (K == 1 || s[0] != s[s.size() - 1]) {
            int n = calc(s);
            cout << n * K << endl;
            return;
        }

        string tmp = s + s;
        int pos = -1;
        FOR(i, 1, s.size() - 1) {
            if (s[i] != s[i - 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << s.size() * K / 2 << endl;
            return;
        }
        auto ns = tmp.substr(pos, s.size());
        int n = calc(ns);
        int res = n * (K - 1);
        res += pos / 2;
        res += calc(s.substr(pos));
        cout << res << endl;
    }
};
