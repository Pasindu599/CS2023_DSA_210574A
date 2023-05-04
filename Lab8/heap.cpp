#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largestElement = root; // assume the largest elememt is the parent node
   int left = 2 * root + 1; // get the left child node of root 
   int right = 2 * root + 2 ; // get the right child node of root
   if(left < n  && arr[left] > arr[largestElement]){
      largestElement = left; // change the largestElement
   }
   if(right < n && arr[right] > arr[largestElement]){
      largestElement = right; // change the largest element
   }
   if(largestElement != root){
      // // swap two elements 
      int temp = arr[root]; // get temp as the parent node value
      arr[root] = arr[largestElement];
      arr[largestElement] = temp;
      
      
      heapify(arr, n , largestElement); // bulid max heap with largestElement as the root
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i = n/2 -1 ; i >= 0 ; i--){
      heapify(arr, n , i);
   }
   
  
   // extracting elements from heap one by one
   for(int i = n-1 ; i > 0 ; i--){
      // swap two elements 
      int temp = arr[0]; // get temp as the parent node value
      arr[0] = arr[i];
      arr[i] = temp;
      
      
      heapify(arr, i , 0);

   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{  
   // get the size of the array
   int sizeArray;
   cout<<"Enter the size of array::";
   cin>>sizeArray;
   int heap_arr[sizeArray];
   for (int i = 0; i < sizeArray; i++) {
      // Reading User Input value Based on index
      cout << "Enter Value for Position " << i << " : ";
      cin >> heap_arr[i];
   }
   
   // int heap_arr[] = {4,17,3,12,9,6};
   
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}