#include <bits/stdc++.h> 
using namespace std;
class NStack
{
    int *arr;
    int *next;
    int *top;

    int n,s;
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //initilize top as -1
        for(int i = 0;i<n;i++){
            top[i] = -1;
        }

        //initilize next array free spot
        for(int i = 1;i<s;i++){
            next[i-1] = i;
        }
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freespot == -1)
            return 0;

        //finding index
        int index = freespot;

        //inserting element at that index
        arr[index] = x;

        //updateing freespot
        freespot = next[index];

        //updating next to top of the stack
        next[index] = top[m-1];

        //updating top to that index of next
        top[m-1] = index;

        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};
