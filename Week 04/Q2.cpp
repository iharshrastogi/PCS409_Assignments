#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int comp=0,swaps=0;
void quick_sort(int arr[],int lb,int ub)
{
    if (lb>=ub)
       return ;
    else{
        int pivot=arr[lb];
        int i=lb,j=ub;
      
        while (i<j)
        {
            comp++;
            while (pivot>=arr[i] && i<j)
                  i++;
            while (pivot<arr[j])
                  j--;
            if (i<j)
             swap(&arr[i],&arr[j]);
        }
        swaps++;
        swap(&arr[lb],&arr[j]);
        quick_sort(arr,lb,j-1);
        quick_sort(arr,j+1,ub);
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++)
           cin>>arr[i];
        
        quick_sort(arr,0,n-1);

        for (int i=0;i<n;i++)
           cout<<arr[i]<<" ";

        cout<<endl<<"Swaps:"<<swaps<<endl;
        cout<<"Comparisions:"<<comp<<endl;
        swaps=0;
        comp=0;
    }
    return 0;
}
