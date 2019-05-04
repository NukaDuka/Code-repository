#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <ios>
#include <iterator>
#include <inttypes.h>
#include <stack>
#include <cstdio>
#include <map>
#include <climits>
#include <cctype>
#include <sstream>
#include <queue>
#include <list>
#include <chrono>
#define EPS		0.0005
#define MODULO	1000000007
#define ll 		long long
#define ull		unsigned long long
using namespace std;
using namespace std::chrono;

// Insert functions
template<class T>
class Matrix
{
	private:
	int **mat;
	size_t sizer;
	size_t sizec;
	public:
	Matrix()
	{
		sizer = 2;
		sizec = 2;
		mat = (T **) malloc(sizeof(T *) * 2);
		for (size_t i = 0; i < 2; i++)
		{
			mat[i] = (T *) malloc(sizeof(T) * 2);
		}
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < 2; j++) mat[i][j] = 0;
		}
	}

	Matrix(int sz)
	{
		sizer = sz;
		sizec = sz;
		mat = (T **) malloc(sizeof(T *) * sz);
		for (size_t i = 0; i < sz; i++)
		{
			mat[i] = (T *) malloc(sizeof(T) * sz);
		}
		for (size_t i = 0; i < sz; i++)
		{
			for (size_t j = 0; j < sz; j++) mat[i][j] = 0;
		}
	}

	Matrix(int row, int col)
	{
		sizer = row;
		sizec = col;
		mat = (T **) malloc(sizeof(T *) * row);
		for (size_t i = 0; i < row; i++)
		{
			mat[i] = (T *) malloc(sizeof(T) * col);
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++) mat[i][j] = 0;
		}
	}

	Matrix(const Matrix<T> &inp)
	{
		sizer = inp.getrows();
		sizec = inp.getcols();
		mat = (T **) malloc(sizeof(T) * sizec);
		for (size_t i = 0; i < sizer; i++)
		{
			mat[i] = (T *) malloc(sizeof(T) * sizec);
		}
		for (size_t i = 0; i < sizer; i++)
		{
			for (size_t j = 0; j < sizec; j++) mat[i][j] = inp[i][j];
		}
	}
	
	~Matrix()
	{
		for (int i = 0; i < sizer; i++) free(mat[i]);
		free(mat);
	}

	static Matrix<T> identity(size_t dim) 
	{
		Matrix<T> res(dim);
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				if (i == j) res[i][j] = 1;
			}
		}
		return res;
	}

	void print()
	{
		for (size_t i = 0; i < sizer; i++)
		{
			for (size_t j = 0; j < sizec; j++)
			{
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}
	}

	size_t getrows() const
	{ 
		return sizer;
	}

	size_t getcols() const
	{
		return sizec;
	}

	int *&operator[] (const int &inp)  const
	{
		return mat[inp];
	}

	Matrix<T> &operator= (const Matrix &inp)
	{
		if (inp.getrows() == this->sizer && inp.getcols() == this->sizec)
		{
			for (size_t i = 0; i < this->sizer; i++)
			{
				for(size_t j = 0; j < this->sizec; j++)
				{
					this->mat[i][j] = inp[i][j];
				}
			}
		}
		else throw "Matrices must be of the same size to perform this operation.";
		return *this;
	}
	Matrix<T> &operator+= (const Matrix &inp)
	{
		if (this->sizer == inp.getrows() && this->sizec == inp.getcols())
		{
			for (size_t i = 0; i < this->sizer; i++)
			{
				for (size_t j = 0; j < this->sizec; j++) this->mat[i][j] += inp[i][j];
			}
		}
		else throw "Matrices must be of same size for this operation.";
		return *this;
	}

	Matrix<T> &operator-= (const Matrix &inp)
	{
		if (this->sizer == inp.getrows() && this->sizec == inp.getcols())
		{
			for (size_t i = 0; i < this->sizer; i++)
			{
				for (size_t j = 0; j < this->sizec; j++) this->mat[i][j] -= inp[i][j];
			}
		}
		else throw "Matrices must be of same size for this operation.";
		return *this;
	}

	Matrix<T> operator+ (const Matrix<T> &inp)
	{
		Matrix<T> res(this->sizer, this->sizec);
		if (this->sizer == inp.getrows() && this->sizec == inp.getcols())
		{
			for (size_t i = 0; i < this->sizer; i++)
			{
				for (size_t j = 0; j < this->sizec; j++)
				{
					res[i][j] = this->mat[i][j] + inp[i][j];
				}
			}
		}
		else throw "Matrices must be of same size for this operation.";
		return res;
	}

	Matrix<T> operator- (const Matrix<T> &inp)
	{
		Matrix<T> res(this->sizer, this->sizec);
		if (this->sizer == inp.getrows() && this->sizec == inp.getcols())
		{
			for (size_t i = 0; i < this->sizer; i++)
			{
				for (size_t j = 0; j < this->sizec; j++)
				{
					res[i][j] = this->mat[i][j] - inp[i][j];
				}
			}
		}
		else throw "Matrices must be of same size for this operation.";
		return res;
	}

	Matrix<T> operator* (const Matrix<T> &inp)
	{
		size_t m = this->sizer;
		size_t k = this->sizec;
		size_t k_ = inp.getrows();
		size_t n = inp.getcols();
		Matrix<T> res(m, n);
		if (k == k_)
		{
			for (size_t i = 0; i < m; i++)
			{
				for (size_t j = 0; j < n; j++)
				{
					T elem = 0;
					for (size_t d = 0; d < k; d++)
					{
						elem += (this->mat[i][d] * inp[d][j]);
					}
					res[i][j] = elem;
				}
			}
		}
		else throw "Matrices must be of compatible sizes for this operation.";
		return res;
	}

	Matrix<T> operator^ (const size_t expt)
	{
		Matrix<T> t(*this);
		Matrix<T> res = Matrix<T>::identity(this->sizer);
		size_t temp = expt;
		if (this->sizer == this->sizec)
		{
			while (temp > 0)
			{
				if (temp%2 == 1) res = res * t;

				t = t * t;
				temp = temp/2;
			}
		}
		return res;
	}
};

// Main
int main(void)
{
	vector<vector<int>> res {{1, 1, 1}, {0, 1, 0}, {0, 0, 1}};
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			cout << res[i][j] << endl;
		}
	}
	return 0;
}