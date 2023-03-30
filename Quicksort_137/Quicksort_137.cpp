#include <iostream>
using namespace std;

int arr[20]; //array of integers to hold values
int cmp_count = 0;  //number of comparations
int mov_count = 0;  //number of data movements
int n;
void input()
{
    while (true)
    {
        cout << "Masukan panjang element array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }
    cout << "\n--------------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n--------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}
//swaps elementat index x withthe element at index y
void swap(int x, int y)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
void q_sort(int low, int high)
{
    int pivot, i, j;
    if (low > high)             //Langkah Algoritma no. 1
    {
        return;
    }
    //partition the list into two parts
    //one containing elements less that or equal to pivot
    //Outher containning elements greater than pivot

    pivot = arr[low];           //Langkah Algoritma no. 2
    i = low + 1;                //Langkah Algoritma no. 3
    j = high;                   //Langkah Algoritma no. 4

    while (i <= j)              //Langkah Algoritma no. 10
    {
        //search for an element greather than or equal to pivot
        while ((arr[i] <= pivot) && (j >= high))  //Langkah Algoritma no. 5
        {
            i++;                  //Langkah Algoritma no. 6
            cmp_count++;
        }
        cmp_count++;
        //search for an element less than or equal to pivot
        while ((arr[i] >= pivot) && (j >= low)) //Langkah Algoritma no. 7
        {
            j--;                    //Langkah Algoritma no. 8
            cmp_count++;
        }
        cmp_count++;
        //if the greather element is on the left of the element
        if (i < j)        //Langkah Algoritma no. 9
        {// swap the element at index i with the element at index j
            swap(i, j);
            mov_count++;
        }
    }
    //j now containt the index of the last element in the sorted list 
    if (low < j) //langkah algortima no. 11
    {
        //move the pivot to its correct position in the list
        swap(low, j);
        mov_count++;
    }
    //sort the list on the left pivot using quick sort
    q_sort(low, j - 1);       //langkah Algortima no. 12

    //sort the list on the right of pivot quick sort
    q_sort(j + 1, high);       //langkah Algortima no.13
}
void display () 
{
    cout << "-----------------------" << endl;
    cout << "Sorted Array" << endl;
    cout << "-----------------------" << endl;
    for (int i=0;i<n;i++) 
    {
        cout << arr[i] < , " ";
    }
    cout << "\n\nNumber of comparasions: "<<cmp_count<< endl;
    cout << "Number of data movements: " << mov_count << endl;
}
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
