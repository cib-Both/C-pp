#include<iostream>
using namespace std;
int main()
{
    int arr[50], i, elem, pos, tot;
    cout<<"Enter the Size for Array: ";
    cin>>tot;

    cout<<"Enter "<<tot<<" Array Elements: ";
    for(i=0; i<tot; i++)
        cin>>arr[i];

    cout<<"\nEnter Element to Insert: ";
    cin>>elem;

    cout<<"What Position  ";
    cin>>pos;

    for(i=tot; i>=pos; i--) // Loop to shift elements to make space for the new element.
        arr[i] = arr[i-1];   // Shift elements to the right
    arr[i] = elem;   // insert the element
    tot++;  // increment the element
    
    cout<<"\nThe New Array is:\n";
    for(i=0; i<tot; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    return 0;
}