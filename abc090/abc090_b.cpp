#include<iostream>
#include <unordered_set>

using namespace std;

bool IsKaibun(int n)
{
    string s = to_string(n);
    int i = 0;
    int j = s.size() - 1;
    while (i != j)
    {
        if (s[i] != s[j]) return false;
        ++i;
        --j;
    }
    return true;
}

int main()
{

    int A, B;
    cin >> A >> B;

    int result = 0;
    for (int n = A; n <= B; ++n)
    {
        if (IsKaibun(n)) ++result;
    }

    cout << result << endl;

    return 0;
}
