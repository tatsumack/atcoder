/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author tatsumack
 */

#include <iostream>
#include <fstream>

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

void Gauss(vector<long long> &A) {
    int rank = 0;
    for (int d = 0; d < 60; ++d) {
        int pivot = -1;
        for (int i = rank; i < (int)A.size(); ++i) {
            if (A[i] & (1LL<<d)) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[rank], A[pivot]);
        for (int j = 0; j < (int)A.size(); ++j) {
            if (j == rank) continue;
            if (!(A[j] & (1LL<<d))) continue;
            A[j] ^= A[rank];
        }
        ++rank;
    }
}

class DXOR {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];

        Gauss(A);
        Gauss(B);

        bool ok = true;
        REP(i, N) {
            if (A[i] != B[i]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::istream& in(std::cin);
    std::ostream& out(std::cout);

    DXOR solver;
    solver.solve(in, out);
    return 0;
}
