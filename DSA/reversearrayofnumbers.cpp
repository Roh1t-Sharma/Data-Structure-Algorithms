#include <iostream>  
using namespace std;  
  
void disp(int arr1[], int num)  
{  
    int i;  
    for ( i = 0; i < num; i++)  
    {  
        cout << arr1[i] << " ";  
    }  
}  
void reverse(int arr1[], int num)  
{  
    reverse(arr1, arr1 + num);   
}  
  
int main ()  
{  
    int = arr1[];  
    int num = sizeof(arr1)/sizeof(arr1[0]);  
    cout << "Enter an array: " << endl;
    cin >> arr1;
    reverse(arr1, num);  
    disp(arr1, num); 
      
    return 0;   
}   