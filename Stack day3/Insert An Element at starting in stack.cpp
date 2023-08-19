#include <bits/stdc++.h> 
using namespace std;
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }
    else{
        int num = myStack.top();
        myStack.pop();
        pushAtBottom(myStack,x);
        myStack.push(num);
        return myStack;
    }
}
int main(){
    stack<int> s1;
    cout<<"Enter size of the stack:";
    int n;
    cin>>n;
    cout<<"Enter element:";
    for(int i=0;i<n;i++){
        int n1;
        cin>>n1;
        s1.push(n1);
    }
    cout<<"Enter element you wana to insert at starting:";
    int x;
    cin>>x;

    pushAtBottom(s1,x);
    cout<<endl<<"printing stack first one is top of the stack.";
    for(int i=0;i<n+1;i++){
        cout<<s1.top()<<" ";
        s1.pop();
    }

    
}

