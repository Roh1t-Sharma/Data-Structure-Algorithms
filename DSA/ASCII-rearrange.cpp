#include <iostream>
#include <math.h>
using namespace std;

bool cmp (char ch, char chh) {return int(ch) <= int(chh);}

string sortstring (string S)
{
    sort(S.begin(), S.end(), cmp);
    return S;
}
int main ()
{
    //string S = "cat";
    //cout << sortstring(S);
    string S; 
    cout << "Enter an Array: " << endl;
    cin>>S;
    cout << sortstring(S);
    return 0;
} 