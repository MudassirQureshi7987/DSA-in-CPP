/*

 * Problem 1.7 Rotate a matrix by 90' clockwise ( or anticlockwise).
 * Solution : I have done it two ways.
 * Approach 1: Take transpose of matrix and then reverse the rows for clockwise 90' rotation.
 * 			   Obviously if we reverse the columns we will get anticlockwise 90' rotation.
 * Approach 2: As mentioned in the book, rotating invididual elements layer by layer.
 * 			   I have solved it perform anticlockwise 90' rotation, it can be done similarly for clockwise rotatation.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat){
	int n = mat.size();

	for(int i = 0;i < n-1;i++)
	{
		for(int j = i+1;j < n;j++)
		{
			swap(mat[i][j],mat[j][i]);
		}
	}

	for(int i = 0;i < n;i++)
	{
		reverse(mat[i].begin(),mat[i].end());
	}
	
}