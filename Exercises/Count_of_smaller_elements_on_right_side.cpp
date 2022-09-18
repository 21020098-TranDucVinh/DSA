// 6, 3, 7 ,2
// OUTPUT: 2, 1, 1, 0

// C++ program to find the count of
// smaller elements on right side of
// each element in an Array
// using Merge sort 
// O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int ans[N];

// Utility function that merge the array
// and count smaller element on right side
void merge(pair<int, int> a[], int start,
				int mid, int end)
{
	pair<int, int> f[mid - start + 1],
				s[end - mid];
					
	int n = mid - start + 1;
	int m = end - mid;
	
	for(int i = start; i <= mid; i++)
		f[i - start] = a[i];
	for(int i = mid + 1; i <= end; i++)
		s[i - mid - 1] = a[i];
		
	int i = 0, j = 0, k = start;
	int cnt = 0;

	// Loop to store the count of smaller
	// Elements on right side when both
	// Array have some elements
	while(i < n && j < m)
	{
		if (f[i].second <= s[j].second)
		{
			ans[f[i].first] += cnt;
			a[k++] = f[i++];
		}
		else
		{
			cnt++;
			a[k++] = s[j++];
		}
	}

	// Loop to store the count of smaller
	// elements in right side when only
	// left array have some element
	while(i < n)
	{
		ans[f[i].first] += cnt;
		a[k++] = f[i++];
	}

	// Loop to store the count of smaller
	// elements in right side when only
	// right array have some element
	while(j < m)
	{
		a[k++] = s[j++];
	}
}

// Function to invoke merge sort.
void mergesort(pair<int, int> item[],
					int low, int high)
{
	if (low >= high)
		return;
		
	int mid = (low + high) / 2;
	mergesort(item, low, mid);
	mergesort(item, mid + 1, high);
	merge(item, low, mid, high);
}

// Utility function that prints
// out an array on a line
void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver code.
int main()
{
	int arr[] = { 10, 9, 5, 2, 7,
				6, 11, 0, 2 };
					
	int n = sizeof(arr) / sizeof(int);
	pair<int, int> a[n];
	memset(ans, 0, sizeof(ans));
	
	for(int i = 0; i < n; i++)
	{
		a[i].second = arr[i];
		a[i].first = i;
	}
	
	mergesort(a, 0, n - 1);
	print(ans, n);
	
	return 0;
}
