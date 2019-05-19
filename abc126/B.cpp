
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
vector <T> make_v(size_t a) { return vector<T>(a); }

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

bool isYY (string s) {
    int n = stoi(s);
    return 0 <= n;
}
bool isMM (string s) {
    int n = stoi(s);
    return 1 <= n && n <= 12;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int b1 = 0;
    if (isYY(s.substr(0, 2))) b1 += 1;
    if (isMM(s.substr(0, 2))) b1 += 2;

    int b2 = 0;
    if (isYY(s.substr(2, 2))) b2 += 1;
    if (isMM(s.substr(2, 2))) b2 += 2;

    if (b1 == 3 && b2 == 3) {
        cout << "AMBIGUOUS" << endl;
    }
    else if ((b1 & 1) == 1 && (b2 & 2) == 2) {
        cout << "YYMM" << endl;
    }
    else if ((b1 & 2) == 2 && (b2 & 1) == 1) {
        cout << "MMYY" << endl;
    }
    else {
        cout << "NA" << endl;
    }

    return 0;
}
