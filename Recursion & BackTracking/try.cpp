#include<iostream>

    using namespace std;

    int n = 2;
    void change(int (*arr)[n]) {

        //arr[0][0] = 0;

    }

    int main() {

        int arr[][n] = {{1,1} , {2,2}};

        cout<<arr[0][0]<<endl;
        //change(arr);
        cout<<arr[0][0]<<endl;
        return 0;
    }