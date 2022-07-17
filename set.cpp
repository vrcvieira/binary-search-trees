#include <iostream>
#include <set>

using namespace std;

int main()
{

    set<int> s = {61, 7, 4, 160, 13, 58, 35, 77, 142, 212, 101, 89, 81, 24, 64, 84, 26, 7, 356, 1};

    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    s.erase(81);
    s.erase(101);
    s.erase(7);

    for (auto x : s)
    {
        cout << x << " ";
    }

    return 0;
}