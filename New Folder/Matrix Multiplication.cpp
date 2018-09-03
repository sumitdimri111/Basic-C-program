#include<iostream>
using namespace std;

int main()
{
	long long int row1, col1, row2, col2, mat1[10][10], mat2[10][10];
	
	row1=2, row2=2, col1=2, col2=2;

	cout << "Enter size of row and column :\n";
	cin >> row1 >> col1;
	
	cout << "Enter first matrix :\n";
	for(int row=0; row<row1; row++)
	for(int col=0; col<col1; col++)
		cin >> mat1[row][col];
		
//	cout << "Enter size of row and column :\n";	
//	cin >> row2 >> col2;
	cout << "Enter scecond matrix :\n";
	for(int row=0; row<row2; row++)
	for(int col=0; col<col2; col++)
		cin >> mat2[row][col];
		
	long long int mat3[row1][col2], row3=row1, col3=col2;
	if(col1 == row2)
	{
		for(int row=0; row<row3; row++) 
		{
			for(int col=0; col<col3; col++)
			{
				mat3[row][col] = 0;
				for(int c=0; c<row3; c++)
					mat3[row][col] += mat1[row][c] * mat2[c][col];
			}
		}
	}
	else
		cout << "Not square matrix :\n";
		
	
	cout << "Result :\n";
	for(int row=0; row<row3; row++) {
		for(int col=0; col<col3; col++)
			cout << mat3[row][col] << " ";
		cout << endl;
	}

 return 0;
}

