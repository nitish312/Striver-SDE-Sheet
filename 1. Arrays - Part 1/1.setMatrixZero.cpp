#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix){

	int m = matrix.size(), n = matrix[0].size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

// // 1. brute ? O(N*M) + O(N*M) -> O(N*M) : O(N*M)
// void setMatrixZero(vector<vector<int>>& matrix){

// 	int m = matrix.size(), n = matrix[0].size();
	
// 	vector<pair<int,int>> store;
// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++){
// 			if(matrix[i][j] == 0){
// 				store.push_back({i, j});
// 			}
// 		}
// 	}

// 	for(int i = 0; i < m; i++){
// 		for(int j = 0; j < n; j++){
// 			for(auto p: store){
// 				matrix[p.first][j] = 0;
// 				matrix[i][p.second] = 0;
// 			}
// 		}
// 	}
// }



// 2. optimal ? O(N*M) + O(N*M) -> O(N*M) : O(1)
void setMatrixZero(vector<vector<int>>& matrix){

	int n = matrix.size(), m = matrix[0].size();
    
    bool firstRow = false, firstCol = false;
    
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < m; j++){    
			if(matrix[i][j] == 0){ 
                if(i == 0) firstRow = true;
                if(j == 0) firstCol = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    
    if(firstRow){
        for(int i=0; i<m; i++) 
            matrix[0][i] = 0;
    }
    
    if(firstCol){
        for(int i=0; i<n; i++) 
            matrix[i][0] = 0;
    }
}

int main(){

	vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

	printMatrix(matrix);

	setMatrixZero(matrix);

	printMatrix(matrix);

	return 0;
}