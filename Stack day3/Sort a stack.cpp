#include <bits/stdc++.h> 
using namespace std;
void insertInSorted(stack<int> &st,int num){
	if((st.empty()) || (st.top()<num)){
		st.push(num);
		return ;
	}

	int num1 = st.top();

	st.pop();
	insertInSorted(st,num);
	st.push(num1);
}
void sortStack(stack<int> &st)
{
	// Write your code here
	if(st.empty()){
		return ;
	}

	int num = st.top();
	st.pop();

	sortStack(st);
	insertInSorted(st,num);
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

    sortStack(s);
    cout<<"Printing sorted stack:";
    for(int i=0;i<n;i++){
        cout<<s.top()<<" ";
        s.pop();
    }



}
