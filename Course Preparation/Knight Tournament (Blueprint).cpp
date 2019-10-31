#include <bits/stdc++.h>
using namespace std;

void Knight_Tournament(int n, int fights)
{
    /* Decalre a vector 'killer' (without specifying size)
     * Now, resize it to length 'n', and initialize it to zero 
     * The initialization should not use a for loop 
     */
     
    /* If you notice carefully, the input is 1 based
     * Now, we want to access the index as it is (without decrementing)
     * In short, we would want to access the 'n-th' index also
     * Make the vector of size 'n+1' by pushing an extra 0 at the back
     */
    
    /* Create a set called 'alive' */
    
    /* For each person, insert them into the set
     * Each person is numbered from 1 to 'n'
     * Do not change the indexing
     */
    
    
    /***************************************Experiment****************************
     1) Verify that the size of the set is 'n'
     2) Verify that the first element is 1 (Use iterator and then de-reference it)
     3) Verify that the last element is 'n' (.end() won't work. Why? Use .rbegin())
     4) Iterate the set using iterators and print each element (By de-referencing them)
     5) Iterate the set in a reverse manner and print each element. (Hint :: .rbegin, .rend)
     6) Iterate the set in a range based for loop and print each element
     7) Find and report whether '1' and 'n+1' exist in the set or not    
     8) Experiment with lower_bound and upper_bound and get comfortable with it 
     
     Note_1 : Use 'auto' for automatic type deduction while iterating the container 
     Note_2 : Please comment out the codes for this section before submission   
    /***************************************Experiment****************************/
    
    
    /* Scan each fight */
    for(int i = 0; i < fights; i++)
    {
        /* Scan three numbers 'left', 'right', 'winner' in a single line */
        
        /* Define an iterator 'itr' in the scope of the set container (Don't use 'auto')
         * If 'left' exists in the set, then get its iterator
         * Else, get the iterator of the first number greater than left
         * The above 2 tasks can be done in one line (Hint : Use a function from above)
         * De-reference the iterator and store it in a variable 'currentPerson'
         */
        
        // We want to keep deleting till we hit the right end-point of this query
        while(itr != alive.end() and ??? )
        {
            /* The killer of 'currentPerson' is the 'winner'
             * Record it in your vector 
             * Make sure not to make the 'winner' kill himself
             */
             
            /* Delete this current person from the set (using iterators)
             * Note : We will also delete the winner for now. Why?
             * It's a bit of a hassle to jump through ierators, hence we delete all elements
             */
            
            /* Get the iterator of the element which is next to the deleted element
             * Note : Note that once you delete it, 'itr++' won't work
             * Hint : Read up the documentation on the return type of std :: set.erase()
             * Update 'itr' to this iterator for this loop to continue
             */
             
            /* You also need to add one more line here. Can you guess what it is?
             * Hint : Look carefully at the loop conditions
             */
        }
        
        /* All persons in that range have been killed
         * But the winner should have been alive
         * Can you make it alive in a single line?
         */
    }
    
    /* Print the killer of each person using iterators
     * Hint : How do you get the iterator to the second element 
     */
}

int main()
{
    /* Scan 2 integers : 'n' and 'fights' in a single line using cin */
	
	// We'll scan the aliveing inputs in the function
	Knight_Tournament(n, fights);
	
	return 0;
}

/* What is the time complexity of this approach? Why?
 * Hint : How many times are you using std::set and what is the time taken?
 * Hint : Focus on the movement of a single element
 */
