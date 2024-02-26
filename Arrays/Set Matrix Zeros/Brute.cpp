#include <iostream>
#include <vector>
using namespace std;

void mark_row (int i, vector<vector<int>>& matrix){
    for (int j=0; j<matrix[i].size(); j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void mark_col (int j, vector<vector<int>>& matrix) {
    for (int i=0; i<matrix.size(); i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void set_matrix_zeros(vector<vector<int>>& matrix) {
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if (matrix[i][j] == 0) {
                mark_row(i, matrix); 
                mark_col(j, matrix);
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    set_matrix_zeros(matrix);
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[i].size(); j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
    }
}