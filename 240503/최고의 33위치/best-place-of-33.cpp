#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int** arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        fill_n(arr[i], n, 0);
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int max = 0;

    for(int i=0; i<n-2; i++){
        for (int j=0; j<n-2; j++){
            int sum = 0;
            sum = sum + arr[i][j] + arr[i+1][j]+ arr[i+2][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i][j+2] + arr[i+1][j+2] + arr[i+2][j+2];
            if (sum > max) max = sum;
        }
    }

    cout << max;

    return 0;
}