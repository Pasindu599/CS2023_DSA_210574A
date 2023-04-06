#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>

using namespace std;
  
// int top = -1 , size = 4;
class StackArr
{
private:
    int top;
    int size;
    int s[];
    

public:
    StackArr(int arrSize)
    {
        s[arrSize];
        top = -1;
        size = arrSize;
    }


    bool isEmpty(){
        if (top == -1){
            return true;
        }
        return false;
    }

    void push( int x){
        top += 1;
        if (top > size-1 ){
            throw "Stack overflow";
        }
        else{
            s[top] = x;
        }

    }

    int pop(){
        if (isEmpty()){
            throw "Stack Underflow";
        }
        else{
            top = top - 1;
            return s[top+1];
        }

    }

    void display(){
        if(top == -1){
            throw "Stack Underflow";
        }
        else{
            for(int i = top ; i  >= 0 ; i --){
                cout << s[i] << "  " ;
            }
            cout << endl;
        }
    }

    bool isFull(){
        if(top == size -1){
            return true;
        }
        return false;
    }
};
int main(){
    auto starting_of_stack = chrono::high_resolution_clock::now();
    int sz;
    cin >> sz;

    StackArr stack(sz);
    try {
    for (int i = 0; i < (sz/3)*2; i++)
        {
            stack.push(rand() % 100);
        }
    stack.display();

    for (int i = 0; i < (sz/3); i++)
        {
            stack.pop();
        }
    
    
    stack.display();
    }

    catch(const char* msg){
        cerr << msg << endl;
        exit(1);

    }

    auto ending_of_stack = chrono::high_resolution_clock::now();
    auto duration_of_stack = chrono::duration_cast<chrono::microseconds>(ending_of_stack - starting_of_stack);

    auto time_taken_iterative = chrono::duration_cast<chrono::duration<double>>(ending_of_stack - starting_of_stack).count() ;
    cout << "Time taken by stack : " << duration_of_stack.count() << " microseconds" << endl;
    cout << "time taken for iterative is : " << fixed << setprecision(20)<< time_taken_iterative << " microseconds"<<endl;




    

}





