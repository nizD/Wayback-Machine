#include <bits/stdc++.h>
using namespace std;

/* There are 2 styles of handling sliding windows
 * 1) Print at the beginning of the 'for' loop and handle the last window manually
 * 2) Print at the end of the 'for' loop and handle the first window manually
 * We'll follow the second technique
 */

void max_in_every_window(vector<int> &a, int window_size)
{
	// Extract the size of the array
	int n = ???
	
	// This would give SIGBART error if the input is invalid
	assert(window_size <= n);

	/* Create an empty deque 'dq' 
	 * Note the spelling
	 * It's different from what one would expect (queue)
	 */
	
	/* Travese the first window */
	for(int i = 0; i < window_size; i++)
	{
		int incoming_index = ???
		
		/* Remove the strictly smaller elements standing at the back of the queue */
		while(??? and ???)
			???
		
		/* Insert the incoming_index in its rightful place in the queue */
	}
	
	/* Always handle the first window manually. Why?
	 * Think of the case where (k == n)
	 */
	cout << a[dq.front()] << " ";
	
	for(int i = window_size; i < n; i++)
	{
		/* Find the index of the incoming and leaving element */
		int leaving_index  = ???
		int incoming_index = ???
		
		/* Delete the leaving_index if it is present */
		if(???)
			???
		
		/* Remove the strictly smaller elements standing at the back of the queue */
		while(??? and ???)
			???
		
		/* Insert the incoming_index in its rightful place in the queue */
		
		/* Print the answer for this window
		 * Would this technique take care of the last window?
		 * What about the first ?
		 */
	}
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> a(n);
	
	/* A different style for taking inputs
	 * Note the reference (to change actual values)
	 * This ensures that we do not mix up loop variables 'i', 'j', etc
	 */
	for(auto &ele : a)
		cin >> ele;
	
	int window_size;
	cin >> window_size;
	
	max_in_every_window(a, window_size);
}
