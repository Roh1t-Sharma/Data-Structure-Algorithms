#include <iostream>
using namespace std;

int main()
{
     char arrF[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 48};
     int size = sizeof(arrF)/sizeof(arrF[0]); //obtaining the size of the array
     char arrR[size];

     for(int i=0,j=size-1; j>=0; i++,j--) 
    {
       arrR[i] = arrF[j];
    }

     for(int i=0; i<size; i++) 
    {
       cout<< arrR[i] << ' ';
    }
       cout<< endl;
     return 0; 
}