#include "quicksort.h"
#include <cstdlib>
#include <ctime>

int insert_sort(std::vector<int>& A, int _p, int _r)
{
    int* a = new int; 
    if (A[_p] > A[_r])
    {
	*a = A[_p];
	A[_p] = A[_r];
	A[_r] = *a;
    }
    
    delete a;    
    return 0;
};

int hoare_partition(std::vector<int>& A, int _p, int _r)
{
    int* a = new int; 
    int x = A[_p];
    int i = _p-1;
    int j = _r+1;
    while(1)
    {
	j = j - 1;
	while(A[j] > x)
	    j = j - 1;

	i = i + 1;
	while(A[i] < x)
	    i = i + 1;

	if (i < j)
	{
	    *a = A[i];
	    A[i] = A[j];
	    A[j] = *a;
	}
	else
	{
	    delete a;
	    return j;
	}    
    }
};

int random_num(std::vector<int>& A, int _p, int _r)
{
    srand(time(NULL)); // 随机种子

    int i = rand() % (_r-_p+1) + _p;
    int* a = new int;
    *a = A[_p];
    A[_p] = A[i];
    A[i] = *a;

    delete a;
    return 0;
};

int randomized_quicksort(std::vector<int>& A, int _p, int _r)
{ 
    if (_p == _r)
	return 0;
    if (_r-_p == 1)
    {
	insert_sort(A, _p, _r);
	return 0;
    }
    //else
    //randomize
    random_num(A, _p, _r);
    
    int q = hoare_partition(A, _p, _r);
    randomized_quicksort(A, _p, q);
    randomized_quicksort(A, q+1, _r);

    return 0;
};

int quicksort(std::vector<int> &A)
{
    int p = 0;
    int r = A.size() - 1;
    std:: cout << r << std::endl; 
    if (r == -1)
	std::cout << "Null array cannot be sorted." << std::endl;
    randomized_quicksort(A, p, r);
    return 0;
};

int *generateRandomArray(int n, int rangeL, int rangeR) {
    
	int *arr = new int[n]; // 创建一个 n个元素的数组
	
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
	    arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
	return arr;
};
