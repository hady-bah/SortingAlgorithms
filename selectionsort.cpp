//Hady Bah
#include<iostream>
#include <chrono>
#include <time.h>
using namespace std;

int main()

{

    int i,j,location,tmp,low,m[50000];
    int n[8] = {100,300,500,1000,3000,5000,10000,50000};
    int counter;

for (int e = 0; e<8; e++){

    srand(time(0));
    for(j=0;j<n[e];++j){
        m[j] = 1+(rand()) % n[e];
    }

    auto begin = std::chrono::high_resolution_clock::now();    
    for(i=0;i<n[e]-1;i++)

    {

        low=m[i];

        location=i;

        for(j=i+1;j<n[e];j++)

        {

            if(low>m[j])

            {

                low=m[j];

                location=j;

                counter ++;
            }

        }

        tmp=m[i];

        m[i]=m[location];

        m[location]=tmp;

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Array after selection sort for "<<n[e]<<" elements: ";
    
    cout<<"\nsteps: "<<counter;

    //cout<<"\nCPU time measured: \n"<< elapsed_time_ns / 1e9 <<std::endl;
    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);

    begin = std::chrono::high_resolution_clock::now();
    //reversely sorted
    counter = 0;
    for(i=0;i<n[e]-1;i++)

    {

        low=m[i];

        location=i;

        for(j=i+1;j<n[e];j++)

        {

            if(low<m[j])

            {

                low=m[j];

                location=j;

                counter ++;
            }

        }

        tmp=m[i];

        m[i]=m[location];

        m[location]=tmp;

    }

    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Array after selection sort for "<<n[e]<<" elements: ";
    
    cout<<"\nsteps: "<<counter;


    //cout<<"\nCPU time measured: \n"<< elapsed_time_ns / 1e9 <<std::endl;
    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);

}
    return 0;

}