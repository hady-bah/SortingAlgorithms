//Hady Bah
#include <iostream>
#include <chrono>
using namespace std;

int counter {};

void Mrge(int *a, int lw, int hgh, int md, int y[])

{
                int *tmp;
                tmp = new int[hgh-lw+1];

                int i, j, k;

                i = lw;

                k = 0;

                j = md + 1;

                while (i <= md && j <= hgh)

                {

                                if (y[i] < y[j])

                                {

                                                tmp[k] = y[i];

                                                k++;

                                                i++;

                                                counter++;

                                }

                                else

                                {

                                                tmp[k] = y[j];

                                                k++;

                                                j++;

                                                counter++;

                                }

                }

               

                while (i <= md)

                {

                                tmp[k] = y[i];

                                k++;

                                i++;

                                counter++;

                }

               

                while (j <= hgh)

                {

                                tmp[k] = y[j];

                                k++;

                                j++;

                                counter++;

                }

                for (i = lw; i <= hgh; i++)

                {

                                y[i] = tmp[i-lw];


                }

}

void MrgeSort(int *a, int lw, int hgh)

{

                int md;

                if (lw < hgh)

                {

                                md=(lw+hgh)/2;

                                MrgeSort(a, lw, md);

                                MrgeSort(a, md+1, hgh);
                                
                                Mrge(a, lw, hgh, md, a);

                }

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
                    MrgeSort(p, 0, n[i]-1);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

                    cout<<"Array after merge sort for "<<n[i]<<" elements: ";

                    cout<<"\nsteps: "<<counter;
                    counter = 0;

                    printf("\nTime measured: %.3f seconds.\n", elapsed.count() * 1e-9);


                   
                }


                return 0;
}