#include <iostream>
using namespace std;
int main()
{
    int tot_questions, a, b, c, sum = 0, count = 0;
    cin >> tot_questions;
    while (tot_questions--)
    {
        cin>>a>>b>>c;
        int sum = a + b + c;
        if (sum >= 2)
          count+=1;
    }
     cout << count;

    return 0;
}
