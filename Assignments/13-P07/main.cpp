///////////////////////////////////////////////////////////////////////////////
//
// Author:           Khethulwazi Kunene
// Email:            khethokunene@gmail.com
// Label:            P07
// Title:            Program 07 - Mice and Maze uVa problem 1112
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//    This program will calculate and predicts the number of
//    mice that will exit the maze, using the shortest path algorithm.    
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;

int AdjMat[120][120];

int main() {
	int cases;
	int total_numCells, exit_cellNum, countdown_timer, num_ofConnections, cellA, cellB, travel_time;

	cin >> cases;

	while (cases--) {
		cin >> total_numCells;
    cin >> exit_cellNum;
    cin >> countdown_timer;
    cin >> num_ofConnections;
		memset(AdjMat, 63, sizeof AdjMat);
		total_numCells++;

		for (int i = 0; i < num_ofConnections; i++) {
			cin >> cellA;
      cin >> cellB; 
      cin >> travel_time;
			AdjMat[cellA][cellB] = travel_time;
		}

		for (int k = 0; k < total_numCells; k++)
			for (int i = 0; i < total_numCells; i++)
				for (int j = 0; j < total_numCells; j++)
					AdjMat[i][j] = min(AdjMat[i][j],
							AdjMat[i][k] + AdjMat[k][j]);

		int ans = 0;
		for (int i = 0; i < total_numCells; i++)
			if (AdjMat[i][exit_cellNum] <= countdown_timer || (i == exit_cellNum))
				ans++;

		cout << ans << endl;
		if (cases)
			cout << endl;
	}

	return 0;
}
