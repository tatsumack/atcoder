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

class abc141_f {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void Gauss(vector<long long> &A) {
        int rank = 0;
        for (int d = 60; d >= 0; --d) {
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

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];

        int s1 = 0;
        REP(i, n) {
            s1 ^= a[i];
        }

        REV(j, 60, 0) {
            int ok = 0;
            REP(i, n) {
                if (a[i] >> j & 1) {
                    ok ^= 1;
                }
            }
            if (ok) {
                REP(i, n) {
                    if (a[i] >> j & 1) {
                        a[i] ^= (1LL << j);
                    }
                }
            }
        }

        Gauss(a);

        int s2 = 0;
        REP(i, n) s2 ^= a[i];
        cout << s1 + 2 * s2 << endl;
    }
};
