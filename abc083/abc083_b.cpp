#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        string s = to_string(i);
        int sum = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            sum += s[j] - '0';
        }
        if (sum >= A && sum <= B) ans += i;
    }
    cout << ans << endl;


    return 0;
}
