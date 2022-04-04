#include <iostream>

namespace OneLoopSort
{

    void oneloopsort_bubble(int arr[], int size)
    {
        int i = 0, j = 0;
        int temp;
        while (i < size - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            if (j < size - 1 - i)
            {
                j++;
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }

    void oneloopsort_selection(int arr[], int size)
    {
        int i = 0, j = i + 1, min_i = i;
        int temp;
        while (i < size - 1)
        {
            if (arr[j] < arr[min_i])
            {
                min_i = j;
            }
            if (j + 1 < size)
            {
                j++;
            }
            else
            {
                temp = arr[i];
                arr[i] = arr[min_i];
                arr[min_i] = temp;
                i++;
                j = i + 1;
                min_i = i;
            }
        }
    }

    void oneloopsort_insertion(int arr[], int size)
    {
        int i = 1, j = i - 1;
        int key = arr[i];
        while (i < size)
        {
            if (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                arr[j + 1] = key;
                i++;
                key = arr[i];
                j = i - 1;
            }
        }
    }

}

void print(int arr[], int size)
{
    using namespace std;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main()
{
    using namespace std;
    using namespace OneLoopSort;
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "Unsorted :\t";
    print(arr, size);
    oneloopsort_bubble(arr, size);
    // oneloopsort_selection(arr, size);
    // oneloopsort_insertion(arr, size);
    cout << "Sorted :\t";
    print(arr, size);
    cin.get();
    return 0;
}
