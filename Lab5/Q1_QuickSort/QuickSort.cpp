

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
        i++;
        swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}

void quickSortRecursive(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSortRecursive(A, p, q - 1);
        quickSortRecursive(A, q + 1, r);
    }
}

void quickSortNonRecursive(int arr[], int start, int end)
{
    // Create an auxiliary stack
    int stack[end - start + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of start and end to stack
    stack[++top] = start;
    stack[++top] = end;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop end and start
        end = stack[top--];
        start = stack[top--];
  
        // Set pivot element at its correct position
        int p = partition(arr, start, end);
  
        
        // push left side to stack
        if (p - 1 > start) {
            stack[++top] = start;
            stack[++top] = p - 1;
        }
  
        
        // push right side to stack
        if (p + 1 < end) {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
}
  
int main()
{   srand(time(NULL));


        cout << "Total elements in array: ";
        int length ;
        cin >> length;
      // choose a random length between 3 and 20
        int arr[length];
        for (int j = 0; j < length; ++j) {
            arr[j] = rand() % 1001;  // generate random integers between 0 and 100
        }
       
        // Record the start time
        auto start_time1 = chrono::high_resolution_clock::now();

        // Sort the array
        quickSortRecursive(arr,0,length-1);

        // Record the end time
        auto end_time1 = chrono::high_resolution_clock::now();
        
        

        // Compute the elapsed time in microseconds
        double time_taken1 = chrono::duration_cast<chrono::duration<double>>(end_time1 - start_time1).count() ;

        // Print the sorted array and the time taken in microseconds
        cout << "Recursive Quick Sort time taken is " << fixed << setprecision(10)<< time_taken1 << " microseconds"<< endl;
      cout << endl;
      auto start_time2 = chrono::high_resolution_clock::now();

        // Sort the array
        quickSortNonRecursive(arr,0,length-1);

        // Record the end time
        auto end_time2 = chrono::high_resolution_clock::now();
        
        

        // Compute the elapsed time in microseconds
        double time_taken2 = chrono::duration_cast<chrono::duration<double>>(end_time2 - start_time2).count() ;

        // Print the sorted array and the time taken in microseconds
        cout << "Non Recursive Quick Sort time taken is " << fixed << setprecision(10)<< time_taken2 << " microseconds"<< endl;
    
}