#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    int* arr = new int[3*n];

    for(int i=0; i<(3*n); i++){
        cin >> arr[i];
    }

    for(int i=0; i<t; i++){
        int temp = arr[(3*n)-1];
        for(int j = (3*n)-2 ; j>=0 ; j--){
            arr[j+1] = arr[j];
        }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    for(int i=n; i<(2*n); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    for(int i=(2*n); i<(3*n); i++){
        cout << arr[i] << " ";
    }

    return 0;
}