//Hady Bah

#include <iostream>
#include <chrono>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

int counter {};
//reversely sorted
void QuickSort(int a[], int left, int right)
       {
              int i = left;
              int j = right;
              int temp = a[i];

       if( left < right)
              {
                     while(i < j)
                     {
                            while(a[j] <= temp && i < j)
                            {
                                   j--;
                                   counter++;
                            }
                            a[i] = a[j];

                     while(a[i] >= temp && i < j)
                            {
                                   i++;
                                   counter++;
                            }
                            a[j] = a[i];
                     }
                     a[i] = temp;

                     QuickSort(a, left, i - 1);
                     QuickSort(a, j + 1, right);
              }
       }

int main()
       {
       int a[8] = {100,300,500,1000,3000,5000,10000,50000};
       int i, j, b;
       int p[50000];

       
       for (j = 0; j < 8; j++){
              srand(time(0));
              for(b=0;b<a[j];++b){
                     p[b] = 1+(rand()) % a[j];
              }

              auto begin = std::chrono::high_resolution_clock::now();
              QuickSort(p, 0, a[j]);
              auto end = std::chrono::high_resolution_clock::now();
              auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);


              cout<<"Array after quick sort reversed for "<<a[j]<<" elements: ";

              cout<<"\nsteps: "<<counter;
              counter = 0;

              printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);
       }

    return 0;
}