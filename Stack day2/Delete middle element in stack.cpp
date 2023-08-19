#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>&inputStack,int cnt,int size){
   //base case
   if(cnt == size/2){
      inputStack.pop();
      return ;
   }

   int num = inputStack.top();
   inputStack.pop();
   
   solve(inputStack,cnt+1,size);
   
   inputStack.push(num);
   
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int cnt = 0;
   solve(inputStack,cnt,N);
   
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(13);
    st.push(12);
    st.push(1);
    st.push(12);
    deleteMiddle(st,4);

    for(int i=0;i<=4;i++){
        cout<<st.top()<<" ";
        st.pop();
    }
}
