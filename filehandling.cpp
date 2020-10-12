#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    char arr[100];
    cout<<"Enter your name and age\n";
    cin.getline(arr,100);
    ofstream myfile("firstFileCode.txt");
    myfile<<arr;
    myfile.close();
    cout<<"File open and write opearations perfomed successfully\n";
    return 0;
}
