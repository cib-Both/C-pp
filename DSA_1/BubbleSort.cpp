#include <iostream>
using namespace std;
int main (){
        int Elems =5;
        int arr[Elems] = { 23, 86, 11, 45, 67};
        for (int i = 0 ; i<Elems -1 ; i++) // number sort element
        {
                for (int j = 0 ; j < Elems - i -1 ; j++)// take the tallest to the right
                {
                  if (arr[j] > arr[j+1]) // if the left is  taller 
                  {
                        // swap array
                        int tmp = arr[i];
                        arr [j] = arr [j + 1];
                        arr [j + 1] = tmp;
                  }      
                }
        }
        // print array
        cout << "Bubble sort array : ";
        for (int i =0 ; i<Elems ; i++){
              cout << arr[i] << " ";
        }
        return 0;
}