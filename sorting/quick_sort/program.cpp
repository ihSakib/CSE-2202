#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int i = low - 1;
  int pivot = arr[high];

  for (size_t j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);

  return i + 1;
}

void quick_sort(vector<int> &arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}

void display(vector<int> &arr)
{
  for (auto i : arr)
  {
    cout << i << " ";
  }
}

int main()
{
  vector<int> arr = {0, -4, -5, 10, 45, 3234, 10, -232, 4, 5};

  quick_sort(arr, 0, arr.size() - 1);
  display(arr);

  return 0;
}