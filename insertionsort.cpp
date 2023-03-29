//Hady Bah

#include<iostream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <ctime>
using namespace std;

int main()

{

    int a,b,tmp,d[50000];
    int c[8] = {100,300,500,1000,3000,5000,10000,50000};
    int counter;

    

for (int i = 0; i<8; i++){

    srand(time(0));
    for(b=0;b<c[i];++b){
        d[b] = 1+(rand()) % c[i];
    }


    auto begin = std::chrono::high_resolution_clock::now();    
    for(a=1;a<=c[i]-1;a++)

    {

        tmp=d[a];

        b=a-1;

        while((tmp<d[b])&&(b>=0))

        {

            d[b+1]=d[b];   

            b=b-1;

            counter++;

        }

        d[b+1]=tmp;    //insert element in proper place

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Array after insertion sort for "<<c[i]<<" elements: ";
    
    cout<<"\nsteps: "<<counter;


    //cout<<"\nCPU time measured: \n"<< elapsed_time_ns / 1e9 <<std::endl;
    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);


    begin = std::chrono::high_resolution_clock::now();
    //reversely sorted
    counter = 0;
    for(a=1;a<=c[i]-1;a++)

    {

        tmp=d[a];

        b=a-1;

        while((tmp>d[b])&&(b>=0))

        {

            d[b+1]=d[b];   

            b=b-1;

            counter++;

        }

        d[b+1]=tmp;    //insert element in proper place

    }



    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Array after insertion sort for "<<c[i]<<" elements: ";
    
    cout<<"\nsteps: "<<counter;


    //cout<<"\nCPU time measured: \n"<< elapsed_time_ns / 1e9 <<std::endl;
    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);


}


    return 0;

}

//300 3000 50000 500 100 1000 5000 10000