#include <iostream>

using namespace std;

void selection (int Array[], int n)
{
    int i, j, minimum;
    for (i=0; i<n-1; i++)
    {
        minimum = i;
        for (j=i+1; j<n; j++)
        
        if (Array[j] < Array[minimum])
           minimum = j;

    int temp = Array[minimum];
    Array[minimum] = Array[i];
            
    Array[i] = temp;

    }
}

void printArray (int Array1[], int n)
{
    int i;
    for (i=0; i<n; i++)
    
    cout << Array1[i] << " ";
}

int main ()
{
    //int Array1[] = {4022, 2011, 4324, 50, 424234, 9093144, 13413411, 803480139};
    int Array1[] = {35, 30, 25, 20 ,15, 10, 5, 0};
    int n = sizeof(Array1) / sizeof(Array1[0]);

    cout << "Entered Array: \n";  
    printArray(Array1, n);  
    selection(Array1, n);  
    cout << "\nSorted Array: \n";    
    printArray(Array1, n);
   return 0;
}