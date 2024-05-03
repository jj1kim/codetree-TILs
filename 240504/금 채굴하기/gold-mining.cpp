#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int totalSize = n*n;

    int xlist[totalSize];
    int ylist[totalSize];
    int totalMoneyNum = 0;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                xlist[totalMoneyNum] = i;
                ylist[totalMoneyNum] = j;
                totalMoneyNum += 1;
            }
        }
    }

    int MaxMoneyNum = 0;

    for(int k=0; k<(2*n)-1; k++){
        int KsMaxMoneyNum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int moneyNum = 0;
                //점 하나씩 중심으로부터의 거리를 측정해서 들어오는지 체크
                for(int t = 0; t < totalMoneyNum; t++){
                    int distance = abs(i - xlist[t]) + abs(j - ylist[t]);
                    if(distance <= k) moneyNum += 1;
                }
                if(moneyNum > KsMaxMoneyNum) KsMaxMoneyNum = moneyNum;
            }
        }
        if((KsMaxMoneyNum * m) >= floor(pow((2*k)+1, 2) / 2)){
            if(KsMaxMoneyNum > MaxMoneyNum) MaxMoneyNum = KsMaxMoneyNum;
        }

    }

    cout << MaxMoneyNum;

    return 0;
}