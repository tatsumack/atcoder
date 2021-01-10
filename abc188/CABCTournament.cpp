#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class CABCTournament {
public:
    vector<int> A;

    int dfs(int l, int r) {
        if (r - l == 1) return l;
        int half = (l + r) / 2;

        int left = dfs(l, half);
        int right = dfs(half, r);
        int res = A[left] > A[right] ? left : right;
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        A.resize(1LL << N);
        REP(i, 1LL << N) cin >> A[i];
        int num = 1LL << N;
        int left = dfs(0, num / 2);
        int right = dfs(num / 2, num);
        cout << (A[left] < A[right] ? left+1 : right+1) << endl;
    }
};
