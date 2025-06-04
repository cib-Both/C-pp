#include<iostream>
using namespace std;
int main()
{
    int arr[100], tot, i, elem, j, found=0;
    cout<<"Enter the Size: ";
    cin>>tot;
    cout<<"Enter "<<tot<<" Array Elements: ";
    for(i=0; i<tot; i++)
        cin>>arr[i];
    cout<<"\nEnter Element to Delete: ";
    cin>>elem;
    for(i=0; i<tot; i++)
    {
        if(arr[i]==elem) // the element match delete 
        {
            for(j=i; j<(tot-1); j++) // Loop to shift elements after deletion
                arr[j] = arr[j+1];  // Shift elements one position to the left
            found=1;  // set the found 
            i--;  // decrement i
            tot--; // decrement total number
        }
    }
    if(found==0)
        cout<<"\nElement doesn't found in the Array!";
    else
    {
        cout<<"\nThe New Array is:\n";
        for(i=0; i<tot; i++)
            cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}