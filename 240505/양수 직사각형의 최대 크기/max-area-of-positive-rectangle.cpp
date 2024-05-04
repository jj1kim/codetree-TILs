#include <iostream>
using namespace std;

int main() {
    
    int n,m;

    cin >> n >> m;

    int** arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int max = -1;

    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            for(int row=1; row<=n; row++){
                for(int col=1; col<=m; col++){
                    if((x>=0 && (x+row)<=n) && (y>=0 && (y+col)<=m)){
                        int inner = 1;
                        for(int i = 0; i<row; i++){
                            for(int j=0; j<col; j++){
                                if(arr[x+i][y+j] <= 0){
                                    inner = 0;
                                }
                            }
                        }
                        if(inner != 0){
                            int size = row*col;
                            if(size > max) max = size;
                        }
                    }
                    else continue;
                }
            }
        }
    }

    cout << max;


    return 0;
}