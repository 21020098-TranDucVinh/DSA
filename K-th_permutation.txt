// Hoán vị thứ k 
#include <bits/stdc++.h>
using namespace std;

long long findFirstNumIndex(long long& k, long long n)
{
	if (n == 1)
		return 0;
	n--;

	long long first_num_index;
	// n_actual_fact = n!
	long long n_partial_fact = n;

	while (k >= n_partial_fact
		&& n > 1) {
		n_partial_fact
			= n_partial_fact
			* (n - 1);
		n--;
	}

	// First position of the
	// kth sequence will be
	// occupied by the number present
	// at index = k / (n-1)!
	first_num_index = k / n_partial_fact;

	k = k % n_partial_fact;

	return first_num_index;
}

string findKthPermutation(long long n, long long k)
{
	string ans = "";
	set<long long> s;

	for (long long i = 1; i <= n; i++)
		s.insert(i);

	set<long long>::iterator itr;

	itr = s.begin();

	// subtract 1 to get 0 based indexing
	k = k - 1;

	for (int i = 0; i < n; i++) {

		long long index
			= findFirstNumIndex(k, n - i);

		advance(itr, index);

		// itr now polong longs to the
		// number at index in set s
		ans += (to_string(*itr)) + " ";

		// remove current number from the set
		s.erase(itr);

		itr = s.begin();
	}
	return ans;
}

int main()
{
	long long n, k;
    cin >> n >> k;

	string kth_perm_seq
		= findKthPermutation(n, k);

	cout << kth_perm_seq << endl;

	return 0;
}
