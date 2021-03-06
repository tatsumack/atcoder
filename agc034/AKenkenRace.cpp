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

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

typedef pair<int, int> P;

class AKenkenRace {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;
        A--, B--, C--, D--;

        string s;
        cin >> s;

        // 2連続
        bool ok = true;
        bool prev = false;
        int num = 0;
        int maxnum = 0;
        REP(i, s.size()) {
            if (i > C && i > D) break;
            if (i < A && i < B) continue;

            if (prev && s[i] == '#') {
                ok = false;
                break;
            }

            if (s[i] == '#') {
                prev = true;
                num = 0;
            } else {
                prev = false;
                if (i == B) {
                    num = 1;
                } else {
                    num++;
                }
            }
            if (i <= D) {
                maxnum = max(maxnum, num);
            }
        }

        if (!ok) {
            cout << "No" << endl;
            return;
        }
        if (C > D && maxnum <= 2) {
            // 追い越せない
            if (s[D - 1] == '.' && s[D + 1] == '.') {
                // ok
            }
            else if (s[B - 1] == '.' && s[B + 1] == '.') {
                // ok
            }
            else {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
};
