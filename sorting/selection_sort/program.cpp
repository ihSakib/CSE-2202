#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr)
{

  int n = arr.size();

  for (size_t i = 0; i < n - 1; i++)
  {
    size_t min_index = i;
    size_t current_index = i;
    for (size_t j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_index])
      {
        min_index = j;
      }
    }

    swap(arr[current_index], arr[min_index]);
  }
}

int main()
{
  vector<int> arr = {0, 4, -5, 10, 45, 3234, -232, 4, 5};
  selection_sort(arr);

  for (auto i : arr)
  {
    cout << i << " ";
  }

  return 0;
}