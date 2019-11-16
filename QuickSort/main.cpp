#include "quicksort.h"

int main(int argc, char* argv[])
{
    
    std::vector<int> C{3, 1, 0};
    for (int i = 0; i < 3; i++)
    	std::cout << C[i] << " ";
    std::cout << std::endl;
    quicksort(C);
    for (int i = 0; i < 3; i++)
    	std::cout << C[i] << " ";
    std::cout << std::endl;

   
    
    std::vector<int> B = {6, 2, 3, 5, 8, 13, 10, 11};
    for (int i = 0; i < 8; i++)
    	std::cout << B[i] << " ";
    std::cout << std::endl;

    quicksort(B);
    for (int i = 0; i < 8; i++)
    	std::cout << B[i] << " ";
    std::cout << std::endl;
    
    // for (int i = 0; i < 100; i++)
    // {
    // 	srand(time(0));
    // 	int j = rand() % 200;
    // 	std::cout << j <<" ";
    // 	A[i] = j;      
    // }

//    std::cout << A << std::endl;
    int* arr; 
    arr = generateRandomArray(1000000, 10, 5000000);  //Generate a random array of lengt100
    std::vector<int> A(arr, arr+100);
    //output the array A
    for (int i = 0; i < 100; i++)
    	std::cout << A[i] << " ";
    std::cout << std::endl;      
    
    quicksort(A);
    
    for (int i = 0; i < 100; i++)
    	std::cout << A[i] << " ";
    std::cout << std::endl;
    
    return 0;
};
