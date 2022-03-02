#include <iostream>
using namespace std;

void findMaxMin(int arr[], int l, int h, int &max, int &min)
{
    int max1, min1;
    //if there is only one element in the array
    if (l == h)
    {
        max = min = arr[l];
        return;
    }

    //if there are two elements in the array
    if (l == h - 1)
    {
        if (arr[l] > arr[h])
        {
            max = arr[l];
            min = arr[h];
        }
        else if (arr[l] < arr[h])
        {
            max = arr[h];
            min = arr[l];
        }
        return;
    }

    else
    {
        int mid = (l + h) / 2;
        //to find in left subarray
        findMaxMin(arr, l, mid, max, min);
        //to find in right subarray
        findMaxMin(arr, mid + 1, h, max1, min1);

        if (max < max1)
        {
            max = max1;
        }
        if (min > min1)
        {
            min = min1;
        }
        return;
    }
}

int main()
{
    int n, i;
    cout << "Enter size of array  : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max, min;
    findMaxMin(arr, 0, n - 1, max, min);
    cout << "Maximum element in the array : " << max << endl;
    cout << "Minimum element in the array : " << min << endl;
    cout << "\n";
    return 0;
}
