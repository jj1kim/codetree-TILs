#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int rightMaxMove = n-1-j;
            int upMaxMove = i;
            
            int maxFirstMove = min(rightMaxMove, upMaxMove);

            for(int firstMove = 1; firstMove <= maxFirstMove; firstMove++){
                for(int secondMove = 1; secondMove <= (upMaxMove - firstMove); secondMove++){
                    if((i-secondMove >= 0) && (j-secondMove >= 0)){
                        if(((i-secondMove-firstMove) >=0) && ((j-secondMove+firstMove) >=0) && (j-secondMove+firstMove <= n)){
                            int tempSum = 0;
                            for(int temp = 0; temp <= firstMove; temp++){
                                tempSum += arr[i-temp][j+temp];
                            }
                            for(int temp = 1; temp <= secondMove; temp++){
                                tempSum += arr[i-firstMove-temp][j+firstMove-temp];
                            }
                            for(int temp = 1; temp <= secondMove; temp++){
                                tempSum += arr[i-temp][j-temp];
                            }
                            for(int temp = 1; temp <= firstMove-1; temp++){
                                tempSum += arr[i-secondMove-temp][j-secondMove+temp];
                            }
                            if(tempSum > answer){
                                answer = tempSum;
                            }
                            
                        }
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}