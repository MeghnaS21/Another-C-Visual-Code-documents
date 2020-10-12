#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str, strnew;
        cin >> str;
        int n = str.length();
        if (n <=10)
        {
            cout << str << endl;
        }
        else
        {
            for (int i = 1; i < n - 1; i++)
                strnew = strnew + str.at(i);
            cout << str.at(0) << strnew.length() << str.at(n - 1) << endl;
        }

    }
     return 0;
}