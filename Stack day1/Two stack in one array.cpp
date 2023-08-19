#include <bits/stdc++.h> 
using namespace std;
class TwoStack {
    int *arr;
    int top1;
    int top2 ;
    int size;

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if((top2 - top1) > 1){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if((top2 - top1) > 1){
            top2--;
            arr[top2] = num;
        }

    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1 >= 0){
            int val = arr[top1];
            top1--;
            return val;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2 < size){
            int val = arr[top2];
            top2++;
            return val;
        }
        else{
            return -1;
        }
    }

    int peek1(){
        if(top1 >= 0){
            return arr[top1];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    int peek2(){
        if(top2 >= 0){
            return arr[top2];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
};

int main(){
    TwoStack st(5);
    st.push1(12);
    st.push1(21);

    cout<<st.peek1()<<endl;

    st.push2(122);
    st.push2(221);

    cout<<st.peek2()<<endl;
}
