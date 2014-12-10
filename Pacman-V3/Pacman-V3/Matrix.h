#include "stdafx.h"
#include <iostream>
using namespace std;

class Matrix
{
public:
	//Constructors
	Matrix(int sizeR, int sizeC, double* in_data)
	{
		M = sizeR;
		N = sizeC;
		data = new double[M*N];

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//Deep copy required
				data[i*N + j] = in_data[i*N + j];
			}
		}
	}
	Matrix(int sizeR, int sizeC)
	{
		M = sizeR;
		N = sizeC;
		data = new double[M*N];
		for (int i = 0; i < M*N; i++)
		{
			*(data + i) = 0;
		}
	}

	// ======== Methods ========

	//Get Value at location (I,J)
	double Get(int i, int j)
	{
		int k = ((i * N) + j);
		return *(data + k);
	}
	double* GetArray()
	{
		return data;
	}
	double& GetWrite(int i, int j)
	{
		int k = ((i * N) + j);
		return *(data + k);
	}
	//Get Number of Rows
	int GetR() const
	{
		return M;
	}
	//Get Number of Columns
	int GetC() const
	{
		return N;
	}
	//Set Value at location (I,J)
	void Set(int i, int j, double val)
	{
		int k = ((i*N) + j);
		*(data + k) = val;
	}
	double*  GetData()
	{
		return data;
	}
	//Square all values in the matrix
	Matrix SquareMatrix()
	{
		double* outputArray = new double[M * N];
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				*(outputArray + i*N + j) = (*(data + i*N + j)) * (*(data + i*N + j));
			}
		}
		Matrix C(M, N, outputArray);
		return C;
		delete[] outputArray;
	}
	//Find Difference of values in the matrix A and B
	Matrix Difference(Matrix A, Matrix B)
	{
		M = A.GetR();
		N = A.GetC();
		double* outputArray = new double[M * N];
		Matrix C(M, N, outputArray);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				C.Set(i, j, (A.Get(i, j) - B.Get(i, j)));
			}
		}
		return C;
		delete[] outputArray;
	}
	//Add all values in the Matrix
	double SumOfElements()
	{
		double tempSum = 0;
		for (int i = 0; i < M*N; i++)
		{
			tempSum = tempSum + *(data + i);
		}
		return tempSum;
	}
	//Return Sub-Matrix 
	Matrix GetBlock(int stRow, int stCol, int endRow, int endCol)
	{
		int rows = endRow - stRow;
		int columns = endCol - stCol;
		Matrix subMatrix(rows, columns);

		for (int i = 0; i < subMatrix.GetR(); i++)
		{
			for (int j = 0; j < subMatrix.GetC(); j++)
			{
				subMatrix.GetWrite(i, j) = Get(i + stRow, j + stCol);
			}
		}
		return subMatrix;
	}

	//Print All Elements in Array
	void Print()
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << *(data + i) << " ";
			}
			cout << "\n";
		}
	}


private:
	int M;
	int N;
	double* data;
};