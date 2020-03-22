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
#include <random>

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

class B123Triangle {
public:
    static constexpr int kStressIterations = 5;
    static void generateTest(std::ostream& test) {
        std::random_device rnd;
        std::mt19937 mt(rnd());
        std::uniform_int_distribution<int> rand13(1, 3);
        string tes;
        REP(i, 1000000)  {
            char c = rand13(mt) + '0';
            tes += c;
        }
        test << 1000000 << endl;
        test << tes << endl;
    }

    void validate(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        while (s.size() > 1) {
            nextstr(s);
        }
        cout << s[0] << endl;
    }

    map<string, int> memo;

    void nextstr(string& s) {
        REP(i, s.size() - 1) {
            s[i] = abs(s[i] - s[i + 1]) + '0';
        }
        s.pop_back();
    }
    int calc(string v) {
        while (v.size() > 1) {
            nextstr(v);
        }
        return v[0] - '0';
    }
    void build(string v) {
        if (v.size() == 10) {
            memo[v] = calc(v);
            return;
        }

        FOR(i, 0, 2) {
            v += (i + '0');
            build(v);
            v.pop_back();
        }
    }
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;

        build("");

        nextstr(s);
        while (s.size() > 10) {
            string next;
            for (int i = 0; i + 10 <= s.size(); i++) {
                auto tmp = s.substr(i, 10);
                next += (memo[tmp] + '0');
            }
            s = next;
        }
        while (s.size() > 1) {
            nextstr(s);
        }
        cout << s << endl;
    }
};
