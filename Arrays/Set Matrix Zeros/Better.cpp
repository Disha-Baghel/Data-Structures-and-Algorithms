#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void set_matrix_zeros(vector<vector<int>>& matrix, int n, int m) {
    int *col = new int(m);
    int *row = new int(n);
    memset(col, 0, m*sizeof(int));
    memset(row, 0, n*sizeof(int));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    
    
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            int m = matrix[i].size();
            int n = matrix.size();
            set_matrix_zeros(matrix, n, m) ;
        }
    }
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}