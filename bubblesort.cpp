//Hady Bah

#include<iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <time.h>
using namespace std;


int main()

{

    int p[50000],b,c,tmp;
    int counter = 0;
    int n[8] = {100,300,500,1000,3000,5000,10000,50000};
    
    
    
for (int i = 0; i<8; i++){
   
    srand(time(0));
    for(b=0;b<n[i];++b){
        p[b] = 1+(rand()) % n[i];
    }


    auto begin = std::chrono::high_resolution_clock::now();
    for(b=1;b<n[i];++b)

    {

        for(c=0;c<(n[i]-b);++c)

            if(p[c]>p[c+1])

            {

                tmp=p[c];

                p[c]=p[c+1];

                p[c+1]=tmp;

                counter ++;

            }

    }   
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Array after bubble sort for "<<n[i]<<" elements: ";

    cout<<"\nsteps: "<<counter;

    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);

    begin = std::chrono::high_resolution_clock::now();
    //reversely sorted
    counter = 0;
    for(b=1;b<n[i];++b)

    {

        for(c=0;c<(n[i]-b);++c)

            if(p[c]<p[c+1])

            {

                tmp=p[c];

                p[c]=p[c+1];

                p[c+1]=tmp;

                counter ++;

            }

    }   
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout<<"Array after bubble sort reversed for "<<n[i]<<" elements";

    cout<<"\nsteps: "<<counter;   

    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);


}
    return 0;

}