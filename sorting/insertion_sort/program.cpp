#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{
  int n = arr.size();
  
  for (int i = 1; i < n; i++)
  {
    int current = arr[i];
    int j = i - 1;

    while (j >= 0 and arr[j] > current)
    {
      swap(arr[j], arr[j + 1]);
      j--;
    }
    arr[j + 1] = current;
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
  vector<int> arr = {0, -4, -5, 10, 45, 3234, -232, 4, 5};

  insertion_sort(arr);
  display(arr);

  return 0;
}