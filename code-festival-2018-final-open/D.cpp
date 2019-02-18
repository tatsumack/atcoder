
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

int L[52];
int R[52];

int cnt[52][52][52];
int last[52][52][52];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    CLR(last, -1);

    REP(n, N) {
        string sub;
        cin >> sub;
        if (sub.size() >= 52) {
            CLR(L, 0);
            CLR(R, 0);
            REP(i, sub.size()) {
                R[toNum(sub[i])] += 1;
            }
            REP(k, sub.size()) {
                int m = toNum(sub[k]);
                R[m]--;
                REP(l, 52) {
                    REP(r, 52) {
                        if (L[l] == 0 || R[r] == 0) continue;
                        if (n <= last[l][m][r]) continue;
                        cnt[l][m][r]++;
                        last[l][m][r] = n;
                    }
                }
                L[m]--;
            }
        } else {
            REP(i, sub.size()) {
                FOR(j, i + 1, sub.size() - 1) {
                    FOR(k, j + 1, sub.size() - 1) {
                        if (i == j || j == k || k == i) continue;
                        int l = toNum(sub[i]);
                        int m = toNum(sub[j]);
                        int r = toNum(sub[k]);
                        if (n <= last[l][m][r]) continue;
                        cnt[l][m][r]++;
                        last[l][m][r] = n;
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
                if (cnt[i][j][k] > maxc) {
                    ans = string{toChar(i), toChar(j), toChar(k)};
                    maxc = cnt[i][j][k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
