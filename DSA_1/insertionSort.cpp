#include <iostream>
using namespace std;
int main (){
        int Elems =5;
        int arr[Elems] = { 23, 86, 11, 45, 67};

        for (int i = 0 ; i<Elems -1 ; i++) {
                int tmp = arr[i]; // Mark item element or devide by i
                int j = i; //Start shift at item

                while ( j > 0 && arr[j + 1] >= tmp) // until the one is smaller 
                {
                       arr [j] = arr [j - 1]; // shifts item to right 
                        --j ;                  // go left position
                }

                arr[j] = tmp; // insert mark item
        }
        // print array
       cout << "sorted Array : ";
       for ( int i = 0; i < Elems; i++){
          cout << arr[i] << " " ;
       }
  return 0;
}