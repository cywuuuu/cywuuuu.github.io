#include <iostream>
#include <stdlib.h>
using namespace std;
#define NUM 5
int MyCompare(const void * elem1,const void * elem2)
{
    double * p1 = (double *) elem1;
    double * p2 = (double *) elem2;
    return *p1-*p2;
}
int main()
{
    double arr[NUM]={1.0,55.0,7.0,192.0,32};
    qsort(arr,NUM,sizeof(double),MyCompare);
    for(int i=0;i<NUM;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
