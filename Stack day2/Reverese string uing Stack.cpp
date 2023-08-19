#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cout<<"Enter String:";
    cin>>s;
    cout<<endl;

    cout<<"Reverse of string using stack is:";

    stack<char> st;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        st.push(ch);
    }

    for(int i = 0;i<s.size();i++){
        s[i] = st.top();
        st.pop();
    }
    cout<<s;
}
