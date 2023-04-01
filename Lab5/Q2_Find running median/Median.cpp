#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

vector<int>  optimizedBubbleSort(vector<int> arr, int n) {
    int i, j, temp;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }

    return arr;
}




int main(){
    
    int array[] = {7,2,5,2,3};
    int length = sizeof(array)/sizeof(array[0]);
    vector<int> newArray;

    for(int n : array){
        newArray.push_back(n);
        double median = 0;
        vector<int> sortedArray = optimizedBubbleSort(newArray,newArray.size());
        
        
        cout << endl;
        if(sortedArray.size() % 2 == 1){
            median = sortedArray[sortedArray.size() / 2] ;  
        }
        else{
            int mid1 = sortedArray[sortedArray.size()/2];
            int mid2 = sortedArray[(sortedArray.size()/2)-1];
            median = (mid1 + mid2) / 2.0 ;
        }

        
        cout << "[ ";
        for (int n : sortedArray){
            cout << n <<  "  ";
        }
        cout << "]";
        cout <<"  "<<std::fixed << std::setprecision(1)<< median << endl;
        cout << endl;



    }



}


