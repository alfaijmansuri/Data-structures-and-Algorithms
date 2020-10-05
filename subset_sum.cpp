/*
	THIS SOLUTION IS THE SOLUTION TO FIND OUT WHETHER OT NOT A PARTICULAR SUM 
	IS A PART OF THE SUMMATION OF SOME OR ALL ELEMENTS OF THE GIVEN ARRAY USING
	EACH ELEMENT ONLY ONCE.
*/
#include <bits/stdc++.h>

using namespace std;
int mat[1000][1000];
int ss(int arr[], int sum, int n) {
	if(sum == 0) {
		return mat[sum][n] = 1;
	}
	else if(n == 0) {
		return mat[sum][n] = 0;
	}
	else if(mat[sum][n] != -1) {
		return mat[sum][n];
	}
	else if(arr[n] <= sum) {
		return mat[sum][n] = max( ss(arr, sum - arr[n], n-1), ss(arr, sum, n-1) );
	}
	else {
		return mat[sum][n] = ss(arr, sum, n-1);
	}
}

int main() {
	int i, j, n, sum;
	
	cout << "\nEnter the size of the array : ";
	cin >> n;
	
	int arr[n+1];
	
	cout << "\nEnter the array : ";
	for(i=1; i<=n; ++i) {
		cin >> arr[i];
	}
	
	cout << "\nEnter the sum to search for : ";
	cin >> sum;
	
	for(i=0; i<=sum; ++i) {
		for(j=0; j<=n; ++j) {
			mat[i][j] = -1;
		}
	}
	
	string s = (ss(arr,sum,n)==1) ? "YES\n" : "NO\n";
	
	cout << "\nThe answer is " << s;
	/*
	for(i=0; i<=sum; ++i) {
		for(j=0; j<=n; ++j)
			cout << mat[i][j] << ' ';
		cout << '\n';
	}
	*/	
	return 0;
}
