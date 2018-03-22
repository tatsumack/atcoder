#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A+B > C+D) puts("Left");
    if (A+B < C+D) puts("Right");
    if (A+B == C+D) puts("Balanced");

    return 0;
}
