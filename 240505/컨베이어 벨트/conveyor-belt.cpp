#include <iostream>
using namespace std;

int main() {
    int n,t;
    cin >> n >> t;

    int twoN = 2*n;

    int* first = new int[twoN];

    for(int i=0; i<(2*n); i++){
        cin >> first[i];
    }
    
    for(int i=0; i<t; i++){
        int twoNo = (2*n)-1;
        int firstTemp = first[twoNo];
        
        for(int j=(2*n)-2; j>=0; j--){
            first[j+1] = first[j];
        }
        first[0] = firstTemp;
    }

    for(int i=0; i<n; i++){
        cout << first[i] << " ";
    }
    cout << "\n";
    for(int i=n; i<(2*n); i++){
        cout << first[i] << " ";
    }

    return 0;
}