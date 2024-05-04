#include <iostream>
using namespace std;

int n,m;

bool isPossibleRec(int x, int y, int row, int col){
    if((x>=0 && (x+row)<=n) && (y>=0 && (y+col)<=m)) return true;
    else return false;
}

bool isPossibleTotal(int firstX, int firstY, int firstRow, int firstCol, int secondX, int secondY, int secondRow, int secondCol){
    if(isPossibleRec(firstX, firstY, firstRow, firstCol) && isPossibleRec(secondX, secondY, secondRow, secondCol)){
        if((firstY+firstCol-1)<(secondY)) return true;
        if((firstX+firstRow-1)<(secondX)) return true;
        return false;
    }
    else return false;
}

int main() {
    cin >> n >> m;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }   
    }

    int answer = -25000;

    for(int firstX=0; firstX<n; firstX++){
        for(int firstY=0; firstY<m; firstY++){
            for(int firstRow=1; firstRow<=n; firstRow++){
                for(int firstCol=1; firstCol<=m; firstCol++){
                    if(!isPossibleRec(firstX, firstY, firstRow, firstCol)) continue;
                    for(int secondX=0; secondX<n; secondX++){
                        for(int secondY=0; secondY<m; secondY++){
                            for(int secondRow=1; secondRow<=n; secondRow++){
                                for(int secondCol=1; secondCol<=m; secondCol++){
                                    if(isPossibleTotal(firstX, firstY, firstRow, firstCol, secondX, secondY, secondRow, secondCol)){
                                        int temp = 0;
                                        for(int i=0; i<firstRow; i++){
                                            for(int j=0; j<firstCol; j++){
                                                temp += arr[firstX+i][firstY+j];
                                            }
                                        }

                                        for(int i=0; i<secondRow; i++){
                                            for(int j=0; j<secondCol; j++){
                                                temp += arr[secondX+i][secondY+j];
                                            }
                                        }
                                        if(temp > answer) answer = temp;
                                    }
                                    else continue;
                                }
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