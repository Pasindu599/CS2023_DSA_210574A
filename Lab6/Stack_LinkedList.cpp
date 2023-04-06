#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
struct Stack{
    Node* head = NULL;
    Node* top = NULL;

    bool isEmpty(){
        if (top == NULL) {
            return true;
        }
        return false;
    }

    void push(int value)
    {   
        Node* newNode = (struct Node*) malloc(sizeof(newNode));
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()){
            head = newNode;
            top = newNode;
        }
        else{
            top->next = newNode;
            top = newNode;
        }
    
    }

    int pop(){
        if(isEmpty()) {
            throw "Stack Underflow";
        }
        else{
            int x = top->data;
            if(top == head){
                top = NULL;
                head = NULL;
            }
            else{
                Node* tmp = head;
                while(tmp->next != top){
                    tmp = tmp->next;
                }
                tmp->next = NULL;
                top = tmp;
            }
            return x;
        }
    }

    void display(){
        if(isEmpty()){
            throw "Stack Underflow";
        }
        else{
            Node* temp = head;
            // cout << temp->data;
            while(temp != NULL){
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    auto starting_of_stack = chrono::high_resolution_clock::now();
    int sz;
    cin >> sz;
    Stack* s;
    s = new Stack;
    try {
        
        
        for (int i = 0; i < (sz/3)*2; i++)
        {
            s->push(rand() % 100);
        }
        s->display();
        for (int i = 0; i < (sz/3); i++)
        {
            s->pop();
        }
        s->display();

    }
    catch(const char* msg){
        cerr << msg << endl;
        exit(1);
    }
    auto ending_of_stack = chrono::high_resolution_clock::now();
    auto duration_of_stack = chrono::duration_cast<chrono::microseconds>(ending_of_stack - starting_of_stack);

    auto time_taken_iterative = chrono::duration_cast<chrono::duration<double>>(ending_of_stack - starting_of_stack).count() ;
    // cout << "Time taken by stack : " << duration_of_stack.count() << " microseconds" << endl;
    cout << "time taken for iterative is : " << fixed << setprecision(20)<< time_taken_iterative << " microseconds"<<endl;





}