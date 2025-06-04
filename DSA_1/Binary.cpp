#include <iostream>
using namespace std;
int find (int key){
        int lower = 0;
        int upper = 100-1;
        int number ;
        while (true)
        {
           number = (lower + upper ) /2;
           if ( number == key){
                cout << number ; // found
                break;
           }  
           else if ( lower > upper) {
                return 100;  // can't found it
           }   
           else {  // devide range
                if ( number < key ){
                   lower = number + 1;// in upper half
                }
                else {
                  upper = number - 1;// in lower half
                }
           }
           cout << number << " ";
        }
}
   int main (){
        find (83);
        return 0;
}    