/*#include <stdio.h>

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = 10, target = 23;
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            printf("Target found at index %d", mid);
            return 0;
        }
        else if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("Target not found");
    return 0;
}




#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[50];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};

    int n1 = 6, n2 = 7;

    mergeSort(arr, 0, n1 - 1);
    mergeSort(arr2, 0, n2 - 1);

    printf("Sorted first array:\n");
    printArray(arr, n1);

    printf("Sorted second array:\n");
    printArray(arr2, n2);

    return 0;
}*/



#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    int i = low, j = high;
    int pivot = arr[low];
    int temp;

    if (low < high)
    {
        while (i < j)
        {
            while (arr[i] <= pivot && i < high)
                i++;

            while (arr[j] > pivot)
                j--;

            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[] = {4, 2, 6, 9, 2};
    int n = 5;

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}


