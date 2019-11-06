#include <bits/stdc++.h>
using namespace std;

/* The vertices are 'ALWAYS' indexed from zero
 * Modify the input accordingly
 */

/* Define 3 macros, 'white', 'gray', 'black'
 * Assign them integer values 0, 1 and 2
 * Now, there's no need to use integers for color in your code
 * Hint : #define
 */

class Graph
{
public:
	/* Define an integer 'vertex'
	 * Define a boolean 'cyclePresent'
	 * Initialize the boolean to 'false'
	 */

	/* Define the adjacency list 'adj' (without the size)
	 * Define the vector to store the colors 
	 * Choose the right data type for the 'color' vector
	 */

public:
	/* Define the constructor with one argument 'vertex'
	 * What is the return type of the constructor?
	 */
	
	/* Define a function to add an edge from 'u' to 'v'
	 * Define a function 'dfs' to perform dfs from a given 'source'
	 * Define a function 'dfs_wrapper' to initiate the dfs (why do we need this?)
	 * Define a function 'toplogicalSort' to return the topological sorting of the graph
	 * Note : You just need to define the function signature for now
	 */
};// Don't forget this semi-colon

/** Notice the 'scope' and the declaration of the constructor **/
Graph :: Graph(int vertex)
{
	/* Update the 'vertex' field of the object
	 * Hint : 'this'
	 */

	/* Resize the adjacency list
	 * The adjacency list of each vertex should now exist
	 * It should also be empty
	 * The default value of a container holding  integers is '0'
	 * Is there a default value of a container holding 'vectors'?
	 */

	/* Resize the 'color' vector
	 * Make all the vertices white 
	 */

	// This function can be written in 3 lines
}


/** Complete the function to add a directed edge from 'u' to 'v' **/


void Graph :: dfs(int source)
{
	/* Color the source as gray as we are going to explore it */

	// Traverse the adjacency list of this vertex
	for(auto ele : adj[source])
	{
		/* The element can have 3 color
		 * White : Unvisited vertex, visit it
		 * Gray : Found a back-edge, set 'cyclePresent' to true
		 * Black : Do nothing
		 * Should you use 3 'if' or 'if-else' chaining?  (It's very crucial)
		 */
	}

	// This vertex has been explored completely. Mark it black
}

void Graph :: dfs_wrapper()
{
	/* We want to make sure that all vertices are colored white initially
	 * We don't even know whether the vector has been resized or not
	 * The function 'assign' handles both these cases
	 * It would intialize the vector (resizing only if necessary)
	 */
	color.assign(vertex, white);

	// Start a dfs from each unvisited vertex
	for(???)
		if(color[u] == ??? )
			dfs(u);

	/* Question_1 : Why do we need a dfs_wrapper?
	 * Question_2 : Why are we initialzing 'color' vector again?
	 *              We already initialized it in the constructor
	 */
}

/** Notice the scope and the return type **/
vector<int> Graph :: topologicalSort()
{
	/* Create a vector 'inDegree'
	 * It should be of size 'vertex' (obviously)
	 * Initialize it to zero
	 * Note : One line of code
	 */
	
	 /* Adding an edge (u,v) increases indegree of 'v' by 1
	 * Use this fact to update the indegree of each element
	 * How do we find the end-point, 'v' of all the edges?
	 * Hint : Adjacency List
	 * Question : Why is there an '&' before 'row_vec'?
	 */
	for(auto &row_vec : adj)
		for(auto ??? )
			???

	/* Declare the empty vector 'result' to hold the topological ordering
	 * Declare the queue 'myQueue' to perform the topological sorting
	 */

	/* Push all the vertices with indegree 0 into the queue
	 * Hint : 3 lines of code
	 */
	
	// Perform the Topological Sort
	while(!myQueue.empty())
	{
		/* 1) Pop the front element of the queue in 'current'
		 * 2) Append it to the 'result'
		 */
		
		/* We need to delete 'current' vertex from the graph (virtually)
		 * Notice that we know how the 'indegree' vector would change
		 * Keep inserting the new elements with indegree 0 into the queue
		 */

		// Traverse the adjacency list and virtually delete it
		for(auto neighbour : adj[current])
		{
			// 3 Lines of code (Don't use index)
		}
	}
	
	/* Question : Do we need a 'visited' vector? Why not? */

	return result;
}

void pickup_sticks(int vertex, int edges)
{
	/* Declare a Graph object 'graph'
	 * Scan all the edges and add them to the graph
	 * Remember to do 'u--' and 'v--' to handle 1 based indexing
	 */
    
	// Run the dfs to detect cycle
	graph.dfs_wrapper();
   	
	/* If a cycle is present, print the answer and return */

	// Get the topogical ordering
	vector<int> result = graph.topologicalSort();

	/* Print the answer in a range based for loop
	 * Remember to handle 1 based indexing (while printing)
	 */
}

int main()
{
	int vertex, edges;

	cin >> vertex >> edges;

	while(vertex > 0 and edges > 0)
	{
		pickup_sticks(vertex, edges);
		cin >> vertex >> edges;
	}

	return 0;
}
