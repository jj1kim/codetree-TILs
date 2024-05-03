#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    int** arr = new int*[n];  
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            arr[i][j] = 0;
            cin >> arr[i][j];
        }
    }

    //일자모양 블록의 가로형
    int one_row = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m-2; j++){
            int sum = 0;
            sum += arr[i][j] + arr[i][j+1] + arr[i][j+2];
            if(sum > one_row) one_row = sum;
        }
    }

    //일자모양 블록의 세로형
    int one_col = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n-2; j++){
            int sum = 0;
            sum += arr[j][i] + arr[j][i+1] + arr[j][i+2];
            if(sum > one_col) one_col = sum;
        }
    }

    //ㄴ모양 블록의 전체 처리
    int neun = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            int temp[4];
            temp[0] = arr[i][j] + arr[i+1][j] + arr[i][j+1];
            temp[1] = arr[i][j] + arr[i+1][j] + arr[i+1][j+1];
            temp[2] = arr[i][j] + arr[i][j+1] + arr[i+1][j+1];
            temp[3] = arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];
            int tempMax = max({temp[0], temp[1], temp[2], temp[3]});
            if(tempMax > neun) neun = tempMax;
        }
    }

    int answer = max({neun, one_col, one_row});

    cout << answer;

    return 0;
}