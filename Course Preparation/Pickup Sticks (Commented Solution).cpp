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
#define white 0
#define gray 1 
#define black 2

class Graph
{
public:
	/* Define an integer 'vertex'
	 * Define a boolean 'cyclePresent'
	 * Initialize the boolean to 'false'
	 */
	int vertex;
	bool cyclePresent = false;
	
	/* Define the adjacency list 'adj' (without the size)
	 * Define the vector to store the colors 
	 * Choose the right data type for the 'color' vector
	 */
	vector<vector<int>> adj;
	vector<int> color;

public:
	/* Define the constructor with one argument 'vertex'
	 * What is the return type of the constructor?
	 */
	Graph(int vertex); // There is no return type of constructor 
	
	/* Define a function to add an edge from 'u' to 'v'
	 * Define a function 'dfs' to perform dfs from a given 'source'
	 * Define a function 'dfs_wrapper' to initiate the dfs (why do we need this?)
	 * Define a function 'toplogicalSort' to return the topological sorting of the graph
	 * Note : You just need to define the function signature for now
	 */
	void addEdge(int u, int v);
	void dfs(int source);
	void dfs_wrapper();
	vector<int> topologicalSort();
};// Don't forget this semi-colon

/** Notice the 'scope' and the declaration of the constructor **/
Graph :: Graph(int vertex)
{
	/* Update the 'vertex' field of the object
	 * Hint : 'this'
	 */
	this->vertex = vertex; 

	/* Resize the adjacency list
	 * The adjacency list of each vertex should now exist
	 * It should also be empty
	 * The default value of a container holding  integers is '0'
	 * Is there a default value of a container holding 'vectors'?
	 */
	adj.resize(vertex);
	/*** The default value is the empty vector.
	 *** Hence, after resizing, each adjacency list becomes empty
	 ***/
	 
	/* Resize the 'color' vector
	 * Make all the vertices white 
	 */
	color.resize(vertex, white);
	// This function can be written in 3 lines
}


/** Complete the function to add a directed edge from 'u' to 'v' **/
void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph :: dfs(int source)
{
	/* Color the source as gray as we are going to explore it */
	color[source] = gray;
	
	// Traverse the adjacency list of this vertex
	for(auto ele : adj[source])
	{
		if(color[ele] == white)
			dfs(ele);
		else if(color[ele] == gray)
			cyclePresent = true;
		/* The element can have 3 color
		 * White : Unvisited vertex, visit it
		 * Gray : Found a back-edge, set 'cyclePresent' to true
		 * Black : Do nothing
		 * Should you use 3 'if' or 'if-else' chaining?  (It's very crucial)
		 */
		 
		 /*** We need `if-else` chaining
		  *** The color might change after one 'if' due to recursion
		  ***/ 
	}

	// This vertex has been explored completely. Mark it black
	color[source] = black;
}

void Graph :: dfs_wrapper()
{
	/* We want to make sure that all vertices are colored white initially
	 * We don't even know whether the vector has been resized or not
	 * The function 'assign' handles both these cases
	 * It would intialize the vector (resizing only if necessary)
	 */
	color.assign(vertex, white);
	/*** What if someone used dfs? The colors would not be white
	 *** We just want to be safe
	 ***/
	 
	// Start a dfs from each unvisited vertex
	for(int u = 0; u < vertex; u++)
		if(color[u] == white)
			dfs(u);

	/* Question_1 : Why do we need a dfs_wrapper?
	 * Question_2 : Why are we initialzing 'color' vector again?
	 *			  We already initialized it in the constructor
	 */
	
	/*** We need a wrapper as the graph might be disconnected ***/ 
}

/** Notice the scope and the return type **/
vector<int> Graph :: topologicalSort()
{
	/* Create a vector 'inDegree'
	 * It should be of size 'vertex' (obviously)
	 * Initialize it to zero
	 * Note : One line of code
	 */
	vector<int> inDegree(vertex, 0);
	
	 /* Adding an edge (u,v) increases indegree of 'v' by 1
	 * Use this fact to update the indegree of each element
	 * How do we find the end-point, 'v' of all the edges?
	 * Hint : Adjacency List
	 * Question : Why is there an '&' before 'row_vec'?
	 */
	for(auto &row_vec : adj)
		for(auto child : row_vec)
			inDegree[child]++;

	/* Declare the empty vector 'result' to hold the topological ordering
	 * Declare the queueu 'myQueue' to perform the topological sorting
	 */
	vector<int> result;
	queue<int> myQueue;
	
	/* Push all the vertices with indegree 0 into the queue
	 * Hint : 3 lines of code
	 */
	for(int node = 0; node < vertex; node++)
		if(inDegree[node] == 0)
			myQueue.push(node);
			
	// Perform the Topological Sort
	while(not myQueue.empty())
	{
		/* 1) Pop the front element of the queue in 'current'
		 * 2) Append it to the 'result'
		 */
		 int current = myQueue.front();
		 myQueue.pop();
		 
		 result.push_back(current);
		
		/* We need to delete 'current' vertex from the graph (virtually)
		 * Notice that we know how the 'indegree' vector would change
		 * Keep inserting the new elements with indegree 0 into the queue
		 */
		
		// Traverse the adjacency list and virtually delete it
		for(auto child : adj[current])
		{
			// 3 Lines of code (Don't use index)
			inDegree[child]--;
			if(inDegree[child] == 0)
				myQueue.push(child);
		}
	}
	
	/* Question : Do we need a 'visited' vector? Why not? */
	/* Answer : No, we don't as the indegree == 0 does the job */
	return result;
}

void pickup_sticks(int vertex, int edges)
{
	/* Declare a Graph object 'graph'
	 * Scan all the edges and add them to the graph
	 * Remember to do 'u--' and 'v--' to handle 1 based indexing
	 */
	Graph graph(vertex);
	
	for(int i = 0; i < edges; i++)
	{
		int u,v;
		cin >> u >> v;
		u--; v--;
		
		graph.addEdge(u,v);
	}
	
	// Run the dfs to detect cycle
	graph.dfs_wrapper();
	   
	/* If a cycle is present, print the answer and return */
	if(graph.cyclePresent)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	// Get the topogical ordering
	vector<int> result = graph.topologicalSort();

	/* Print the answer in a range based for loop
	 * Remember to handle 1 based indexing (while printing)
	 */
	for(auto ele : result)
	{
		ele++;
		cout << ele << endl;
	}
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
