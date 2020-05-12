///////////////////////////////////////////////////////////////////////////////
//
// Author:           Khethulwazi Kunene
// Email:            khethokunene@gmail.com
// Label:            P04
// Title:            Program 04 - 459
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This program will output the number of maximal connected
//       subgraphs of any connected or unconnected graph.
//       
//
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

typedef vector<int> vi;  // vector of integers
typedef vector<int> vii; // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;     // container to keep track of who get visited
vector<vii> AdjList; // AdjList stores our edge lists

/**
 * Depth First Search
 * 
 * Params:
 *  int u - starting node id
 * 
 */
void dfs(int u)
{
    // In DFS we use a stack structure to keep track of who to visit next.
    // Recursive acts just like a stack so we dont need to declare any
    // structure to keep track for us, we let the recursive calls do it for us
    been_visited[u] = VISITED; // mark u as visited

    // Loop over adjacency list looking for connections
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {

        // v is a pair representing a neighbor
        int v = AdjList[u][j];

        // check to see if our neighbor was visited
        if (been_visited[v] == UNVISITED)
        {
            dfs(v);
        }
    }
}

int main(int argc, char **argv)
{

    int number_of_cases;
    int m, n;
    int subset_count;
    char largestNode;
    int caseCount = 0;

    // inputs the number of cases following each item
    cin >> number_of_cases;

    cin.ignore();
    cin.ignore();

    while (caseCount < number_of_cases)
    {

        // input character/ largest node
        cin >> largestNode;

        cin.ignore();

        int node = int(largestNode) - int('A');

        AdjList.resize(node + 1);

        been_visited.resize(node + 1, UNVISITED);

        string edge;

        // loop to get edges to load unto vector
        while (getline(cin, edge) && edge != "")
        {

            // subtract A from where it should start
            m = edge[0] - int('A');
            n = edge[1] - int('A');

            AdjList[m].push_back(n);
            AdjList[n].push_back(m);
        }

        // As long as there are unvisited nodes start a dfs on them
        subset_count = 0;

        for (int i = 0; i < (node + 1); i++)
        {

            if (been_visited[i] == UNVISITED)
            {
                dfs(i);
                // Counts the amount of time dfs is called
                // inorder to get the amount of subgraphs
                subset_count++;
            }
        }
        cout << subset_count << endl;

        caseCount++;

        if (caseCount != number_of_cases)
        {
            cout << endl;
        }

        // Clear structures used
        been_visited.clear();
        AdjList.clear();
    }

    return 0;
}

// g++ = compile my program

// g++ <program to compile> -o <whats my output file>

// g++ main.cpp -o whateveryouwant
