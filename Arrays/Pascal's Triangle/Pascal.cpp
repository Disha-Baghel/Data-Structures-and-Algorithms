#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate (int numRows) {
    if (numRows == 0) {
        return {};
    }
    if (numRows == 1) {
        return {{1}};
    }

    vector<vector<int>> prevRows = generate(numRows - 1);
    vector<int> newRow(numRows, 1);

    for (int i = 0; i < numRows - 1; i++) {
        newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
    }
    prevRows.push_back(newRow);
    return prevRows;
}

int main() {
    int numRows = 5;
    vector<vector<int>> pascal = generate(numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < pascal[i].size(); j++){
            cout<<pascal[i][j]<<" ";
        }
        cout<<endl;
    }

}