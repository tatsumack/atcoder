#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int N, K;
map<int, int> bmap;

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        bmap[a] = bmap.find(a) != bmap.end() ? bmap[a] + 1 : 1;
    }

    if (bmap.size() <= K)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v;
    for (auto kv : bmap) v.push_back(kv.second);
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < v.size() - K; ++i)
    {
        ans += v[i];
    }
    cout << ans << endl;

    return 0;
}
