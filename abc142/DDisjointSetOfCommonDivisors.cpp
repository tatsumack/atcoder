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

class DDisjointSetOfCommonDivisors {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

// 素因数
    set<int> getPrimeFactors(int a) {
        set<int> s;
        for (int i = 2; i * i <= a; i++) {
            if (a % i != 0) continue;
            s.insert(i);
            while (a % i == 0) a /= i;
        }
        if (a > 1) s.insert(a);
        return s;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int A, B;
        cin >> A >> B;

        auto a = getPrimeFactors(A);
        auto b = getPrimeFactors(B);
        vector<int> v;
        v.push_back(1);
        for(auto i: b) {
            if (a.count(i) > 0) v.push_back(i);
        }
        cout << v.size() << endl;
        return;
    }
};
