//Hady Bah
#include<iostream>
#include <chrono>
using namespace std;


int counter {};
void Merge(int a[], int low, int high, int mid)
{

int i=low,j=mid+1,k=0;
int temp[high-low+1];

while(i<=mid && j<= high)
{
    if(a[i]>a[j]){               //comparison step
        temp[k++]=a[i++];
        counter++;
    }

    else{
        temp[k++]=a[j++];
        counter++;
    }


}

while(i<=mid)
    {
        temp[k++]=a[i++];
        counter++;
    }

while(j<=high)
    {
        temp[k++]=a[j++];
        counter++;
    }

for(i=low;i<=high;i++)
{

    a[i]=temp[i-low];

}


return;
}


void MergeSort(int a[],int low, int high)
 {
int mid;

if(low<high)
{
    mid=(low+high)/2;

    MergeSort(a,low,mid);
    MergeSort(a,mid+1,high);

    Merge(a,low,high,mid);
}

return;
}


int main()
{

    
    int n[8] = {100,300,500,1000,3000,5000,10000,50000};
    int p[50000];
    int i, b;
         

    for(i = 0; i < 8; i++){

        srand(time(0));
        for(b=0;b<n[i];++b){
            p[b] = 1+(rand()) % n[i];
        }

        auto begin = std::chrono::high_resolution_clock::now();
        MergeSort(p,0,n[i]);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        cout<<"Array after merge sort reversed for "<<n[i]<<" elements: ";

        cout<<"\nsteps: "<<counter;
        counter = 0;

        printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);
    

    }

    return 0;
}