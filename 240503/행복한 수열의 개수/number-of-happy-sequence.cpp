#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
            cin >> arr[i][j];
        }
    }

    int total = 0;

    for(int i=0; i<n; i++){
        int target = 0;
        int repeatNum = 0;
        for(int j=0; j<n; j++){
            if(arr[i][j] != target){
                target = arr[i][j];
                repeatNum = 1;
            }
            else repeatNum += 1;
        }
        if(repeatNum >= m) total +=1;
    }

    for(int i=0; i<n; i++){
        int target = 0;
        int repeatNum = 0;
        for(int j=0; j<n; j++){
            if(arr[j][i] != target){
                target = arr[j][i];
                repeatNum = 1;
            }
            else repeatNum += 1;
        }
        if(repeatNum >= m) total +=1;
    }

    cout << total;

    return 0;
}