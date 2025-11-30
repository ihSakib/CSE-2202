#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int left, int right)
{
  // Base case: single element
  if (left == right)
    return arr[left];

  int mid = (left + right) / 2;

  // Left and right maximum subarray sums
  int left_mss = maxSum(arr, left, mid);
  int right_mss = maxSum(arr, mid + 1, right);
 
  // Compute cross-sum (CSS)
  int left_sum = INT_MIN;
  int right_sum = INT_MIN;

  int sum = 0;

  // Left part: from mid → left
  sum = 0;
  for (int i = mid; i >= left; i--)
  {
    sum += arr[i];
    left_sum = max(left_sum, sum);
  }

  // Right part: from mid+1 → right
  sum = 0;
  for (int i = mid + 1; i <= right; i++)
  {
    sum += arr[i];
    right_sum = max(right_sum, sum);
  }

  int css = left_sum + right_sum;

  return max(max(left_mss, right_mss), css);
}

int main()
{

  return 0;
}