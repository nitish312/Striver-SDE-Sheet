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

// // 1. brute ? O(N*M) : O(N^2)
// vector<vector<int>> generate(int n){

// 	vector<vector<int>> ans;

// 	for(int i = 0; i < n; i++){

// 		vector<int> vec(i + 1, 1);

// 		for(int j = 1; j < i; j++){
// 			vec[j] = ans[i - 1][j - 1] + ans[i - 1][j];
// 		}

// 		ans.push_back(vec);
// 	}

// 	return ans;
// }



// 2. by resize() ? O(N*M) : O(N^2)
vector<vector<int>> generate(int numRows) {
        
    vector<vector<int>> vec(numRows);
        
    for(int i = 0; i < numRows; i++){
		vec[i].resize(i + 1); 
		vec[i][0] = vec[i][i] = 1;

		for(int j = 1; j < i; j++){ 
		                
			vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j]; 
		}
	}
        
	return vec;
}

int main(){

	int n = 5;

	vector<vector<int>> ans = generate(n);
	
	printMatrix(ans);

	return 0;
}