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

class FAbsoluteMinima {
public:
    int min = -1000000000;
    int max = 1000000000;
    void solve(std::istream& cin, std::ostream& cout) {
        int Q;
        cin >> Q;
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int>> big;

        int bsum = 0;
        int ssum = 0;

        int B = 0;
        while (Q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int a, b;
                cin >> a >> b;
                B += b;

                if (small.size() == big.size()) {
                    if (!big.empty() && a > big.top()) {
                        big.push(a);
                        bsum += (a - min);

                        int n = big.top();
                        big.pop();
                        bsum -= (n - min);
                        small.push(n);
                        ssum += (max - n);
                    }
                    else {
                        small.push(a);
                        ssum += (max - a);
                    }
                }
                else {
                    if (a < small.top()) {
                        small.push(a);
                        ssum += (max - a);
                        int n = small.top();
                        small.pop();
                        ssum -= (max - n);
                        big.push(n);
                        bsum += (n - min);
                    }
                    else {
                        big.push(a);
                        bsum += (a - min);
                    }
                }
            }
            else {
                int n = small.top();
                int res = ssum - (max - n) * small.size() + bsum - (n - min) * big.size() + B;
                cout << n << " " << res << endl;
            }
        }

    }
};
