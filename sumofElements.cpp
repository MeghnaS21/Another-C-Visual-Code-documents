//FUNCTIONAL PROGRAMMING -- TO FIND THE SUM OF ELEMENTS OF ARRAY
#include<iostream>
//#include<ostream>
using namespace std;

int sum(int arr[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int arr[10];    
    int n;
    cerr<<"Enter the number of elements\n";
    cin>>n;
    cerr<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<sum(arr,n);
    
    return 0;
}
/* As you can clearly see that, in line 17 we have initialised the size of array as 10. So the size of aray was fixed 10 in the stack.
   And when we 
 */