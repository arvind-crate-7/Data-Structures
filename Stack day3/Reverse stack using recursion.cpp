#include<bits/stdc++.h>
using namespace std;
void insertatbuttom(stack<int> &st,int num){
    if(st.empty()){
        st.push(num);
        return ;
    }
    int num1 = st.top();
    st.pop();
    insertatbuttom(st,num);
    st.push(num1);
}
void reverseStack(stack<int> &st) {
    // Write your code here
    if(st.empty()){
        return ;
    }
    int num = st.top();
    st.pop();
    
    reverseStack(st);
    insertatbuttom(st,num);
}

int main(){
    stack<int> s;
    cout<<"Enter size of the stack:";
    int n;
    cin>>n;

    cout<<"Enter element:";
    for(int i=0;i< n;i++){
        int x;
        cin>>x;
        s.push(x);
    }

    reverseStack(s);
    cout<<"printing stack it is in reverse order:";
    for(int i=0;i<n;i++){
        cout<<s.top()<<" ";
        s.pop();
    }


}
