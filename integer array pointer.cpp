//Write a dynamic 2-D array program with using pointers to find minimum element in the given matrix.

#include <iostream>
using namespace std;

int main()
{
    int r,c,i,j,min;
    cin >> r >> c;
    int **a;
    
    a = (int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)
        *(a+i) = (int*)malloc(r*sizeof(int));
    
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin >> *(*(a+i)+j);
    
    min = *(*(a+0)+0);
    
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(*(*(a+i)+j) < min)
                min = *(*(a+i)+j);
            
    
    cout << "Smallest element in the given matrix is : " << min;
    
    return 0;
}