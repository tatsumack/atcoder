
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
#define fcout cout << fixed << setprecision(10)

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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;


    int a = 0;
    int b = 0;
    int ba = 0;
    int res = 0;
    REP(i, N) {
        string s;
        cin >> s;

        REP(j, s.size() - 1) {
            if (s.substr(j, 2) == "AB") res++;
        }
        if (s[0] == 'B' && s[s.size() - 1] == 'A') {
            ba++;
        }
        else if (s[0] == 'B') {
            b++;
        }
        else if (s[s.size() - 1] == 'A') {
            a++;
        }
    }

    if (ba > 1) {
        res += ba - 1;
        ba = 1;
    }
    if (ba > 0 && a > 0 && b > 0) {
        ba--;
        a--;
        b--;
        res += 2;
    }

    int n = min(a, b);
    res += n;

    if (a - n > 0 || b - n > 0) {
        res += ba;
    }


    cout << res << endl;

    return 0;
}
