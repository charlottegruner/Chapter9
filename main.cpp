#include <iostream>
using namespace std;

void printArray(double*, int);
double* fillArray(int&);  

int main()
{
    /* start here*/
    int size;
    cout << "How many spaces do you want to allocate in the array? ";
    cin >> size;

    //double values[size]; // size is not set at compile time, 
    // not allowed technically -- stack memory 

    // dynamically allocated memory -- heap memory 
    // bigger chunks of memory than stack memory
    // don't need to know at compile time how big

    // dynamically allocated memory uses pointers

    double* arrPtr = nullptr;  
    arrPtr = new double[size];  //allocating heap memory
    // double* arrPtr = new double[size];  

    // write some code to prompt the user for numbers to fill
    // the array.  Challenge: don't use indexing notation.  
    for (int indx = 0; indx < size; indx++)
    {
        double val;
        cout << "Enter the value for index " << indx << " :";
        cin >> val;
        *(arrPtr + indx) = val;
        //arrPtr[indx] = val;
    }
     /* to here go inside fill array */
    
    double* arrPtr = fillArray(size);
    printArray(arrPtr, size);
    // one more key step here for dynmically allocated memory
    delete [] arrPtr;  
    // if you forget this, then "memory leak" 


    return 0;  

}

void printArray(double* arr, int size)
{
    for (int ind = 0; ind < size; ind++)
    {
        cout << arr[ind] << " ";
    }
    cout << endl;
}