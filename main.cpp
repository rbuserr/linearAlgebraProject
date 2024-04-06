//Group 1 , Rolando,Yaya,Jasnoor 4/2024
//Write a program on your favorite method to solve a linear system 
// and implement it on an example. ( Remember we are dealing with
//unique solution only)

//using the LU decomposition / LU factorization method. This method 
//decomposes the coefficient matrix A into a product of lower triangular (L) and upper triangular (U) matrices, 
//which can then be used to solve the linear system efficiently.

#include <iostream>
#include <Eigen/Dense> //For the project we used the Eigen library which gives us already made formulas & commands to write in the code.

using namespace Eigen;
using namespace std;

int main() {
	//We ask the user to enter the size of the quare matrix
	//(n x n)
	int n;
	cout << "Enter the size of the square matrix (n x n): ";
	cin >> n;
	//We then define the coefficient matrix A and the constant vector b based on
	//user input.
	MatrixXd A(n, n); //Constant vector of size n
	VectorXd B(n); //Constant vector of size n
	//Asking the user to enter the numbers of Matrix A
	cout << "Enter the numbers of the coefficient matrix A, row by row: \n";
	for (int i = 0; i < n; ++i) {
		cout << "Row" << (i + 1) << ": ";
		for (int j = 0; j < n; ++j){
			cin >> A(i, j);
		}
	}
	//Asking the user to enter the numbers of Vector B
	cout << "Enter the numbers of the constant vector B:\n";
	for (int i = 0; i < n; ++i) {
		cout << "b[" << (i + 1) << "]: ";
		cin >> B(i);
	}
	//Now we can perform the LU decomposition of matrix A
	PartialPivLU<MatrixXd> lU(A);
	//Now we solve the linear system Ax=b using LU decomposition
	VectorXd x = lU.solve(B);

	//Outputting the solution vector x 
	cout << "The solution vector x is : \n" << x << endl;
	return 0;

}