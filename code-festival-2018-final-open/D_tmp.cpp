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

typedef pair<int, int> P;

int toNum(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A';
    } else {
        return c - 'a' + 26;
    }
}

char toChar(int n) {
    if (n < 26) {
        return n + 'A';
    } else {
        return n + 'a' - 26;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<string> A(N);
    REP(i, N) cin >> A[i];

    map<string, int> cnt;
    REP(i, N) {
        auto sub = A[i];
        if (sub.size() >= 52) {
            vector<vector<int>> L(sub.size() + 1, vector<int>(53, 0));
            vector<vector<int>> R(sub.size() + 1, vector<int>(53, 0));
            REP(j, sub.size()) {
                REP(k, 52) {
                    L[j + 1][k] = L[j][k];
                    if (toNum(sub[j]) == k) {
                        L[j + 1][k]++;;
                    }
                }
            }
            REV(j, sub.size() - 1, 0) {
                REP(k, 52) {
                    R[j][k] = R[j + 1][k];
                    if (toNum(sub[j]) == k) {
                        R[j][k]++;;
                    }
                }
            }

            set<string> set;
            REP(k, sub.size()) {
                char m = sub[k];
                REP(l, 52) {
                    REP(r, 52) {
                        if (L[k][l] == 0 || R[k + 1][r] == 0) continue;

                        string t{toChar(l), m, toChar(r)};
                        if (set.count(t) > 0) continue;
                        set.insert(t);
                        cnt[t]++;
                    }
                }
            }
        } else {
            set<string> set;
            REP(i, sub.size()) {
                FOR(j, i + 1, sub.size() - 1) {
                    FOR(k, j + 1, sub.size() - 1) {
                        if (i == j || j == k || k == i) continue;
                        string t{sub[i], sub[j], sub[k]};
                        if (set.count(t) > 0) continue;
                        set.insert(t);
                        cnt[t]++;
                    }
                }

            }

        }
    }

    string ans;
    int maxc = -1;
    REP(i, 52) {
        REP(j, 52) {
            REP(k, 52) {
                string tmp{toChar(i), toChar(j), toChar(k)};
                if (cnt[tmp] > maxc) {
                    ans = tmp;
                    maxc = cnt[tmp];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
