#include<iostream>
using namespace std;
int main(){

    //creating dynamic array
    int row;
    cout<<"Enter number of rows:";
    cin>>row;
    int **arr = new int*[row];
    //saving column size
    int Colsize[row];
    for(int i=0;i<row;i++){
        int col;
        cout<<"Enter "<<i+1<<" column size:";
        cin>>col;
        Colsize[i]=col;
        arr[i]=new int [col];
    }


    //taking input
    cout<<endl<<"Enter element:"<<endl;
    for(int i=0;i<row;i++){
        cout<<"Enter "<<Colsize[i]<<" element:"<<endl;
        for(int j=0;j<Colsize[i];j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    //Printing array
    cout<<endl<<"The dynamic array is:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<Colsize[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //releasing memory
    for(int i=0;i<row;i++){
        delete []arr[i];
    }
    delete [] arr;
}
