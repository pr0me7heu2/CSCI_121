// Brasher, Bryan R
// 21-APR-2019
// Project 7

#include <iostream>

using namespace std;

void menu();
//post-condition: menu is presented to user and user input is returned

void fill_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is filled from keyboard

void print_array(int arr[], int size);
// pre-condition: The arr has actual size that is greater than or equal to size
// post-condition: arr[0], ..., arr[size-1] is printed to screen with 5 elements per line

int linear_search(int arr[], int size, int key);
// pre-condition: arr has given size
// post-condition: The index of first occurrence of key in arr is returned. If
// the key cannot be found in arr, -1 is returned

void select_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void insert_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void bubble_sort(int arr[], int size);
// pre-condition: arr has given size
// post-condition: the elements in arr are rearranged from least to largest

void swap(int *xp, int *yp);
// pre-condition: xp and yp are integer pointers
// post-condition: values associated with xp and yp are swapped



int main() {
    int choice;
    int a[9];
    do{
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                fill_array(a, 9);
                cout << "Enter the key you want to search: ";
                int key;
                cin >> key;
                int index = linear_search(a, 9, key);
                if(index == -1)
                    cout << "The key " << key << " is not in array\n";
                else
                    cout << "The key " << key << " is #" << (index + 1) << " element in array\n";
                print_array(a,9);
                break;
            }
            case 2:
            {
                fill_array(a, 9);
                select_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 3:
            {
                fill_array(a, 9);
                insert_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 4:
            {
                fill_array(a, 9);
                bubble_sort(a, 9);
                cout << "After sort, the array is:\n";
                print_array(a, 9);
                break;
            }
            case 5:
            {
                cout << "Thank you for using the array functions\n";
                break;
            }
            default:
            {
                cout << "Wrong choice. Please choose from menu: ";
                break;
            }
        }
    }while(choice != 5);
    return 0;
}

void menu()
{
    cout << "********FUNCTION TEST**************" << endl;
    cout << "** 1. linear_search()            **" << endl;
    cout << "** 2. select_sort()              **" << endl;
    cout << "** 3. insert_sort()              **" << endl;
    cout << "** 4. bubble_sort()              **" << endl;
    cout << "** 5. Quit                       **" << endl;
    cout << "***********************************" << endl;

    return;
}

void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i];

        if ((i+1) % 5 == 0)
            cout << endl;
    }
}

void fill_array(int arr[], int size)
{
    cout << "Input nine integers separated by a space." << endl;
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }
}

int linear_search(int arr[], int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if (key == arr[i])
            return i;
    }
    return -1;
}

void select_sort(int arr[], int size)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    return;
}


void insert_sort(int arr[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return;
}

void bubble_sort(int arr[], int size)
{
    for(int i = size- 1; i > 0; i--)
        for(int j = 0; j < i; j++)
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
    return;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
