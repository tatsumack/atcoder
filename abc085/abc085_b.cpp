#include <iostream>
#include <unordered_set>


using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    unordered_set<int> set;
    for (int i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        set.insert(n);
    }
    cout << set.size() << endl;

    return 0;
}
