#include<iostream>
#include "ChessMetric.h"
#define ll long long;
using namespace std;

long long ChessMetric::howMany(int size, int start[], int end[], int numMoves) {
	int singleMovex[] = { -2, -2, -1, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 1, 2, 2 };
	int singleMovey[] = { -1, 1, -2, -1, 0, 1, 2, -1, 1, -2, -1, 0, 1, 2, 1, -1 };
	long long table1[100][100], table2[100][100];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			table1[i][j] = 0;
		}
	}
	table1[start[0]][start[1]] = 1;
	for (int i = 0; i < numMoves; i++) {
		for (int t2x = 0; t2x < size; t2x++) {
			for (int t2y = 0; t2y < size; t2y++) {
				table2[t2x][t2y] = 0;
			}
		}
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				for (int moveInd = 0; moveInd < 16; moveInd++) {
					int tempx = x + singleMovex[moveInd];
					int tempy = y + singleMovey[moveInd];
					if (onTable(pair<int, int>(tempx, tempy), size))
						table2[tempx][tempy] += table1[x][y];
				}
			}
		}
		for (int t1x = 0; t1x < size; t1x++) {
			for (int t1y = 0; t1y < size; t1y++) {
				table1[t1x][t1y] = table2[t1x][t1y];
			}
		}
	}
	return table2[end[0]][end[1]];
}

bool ChessMetric::onTable(pair<int, int> p, int size) {
	if (p.first >= 0 && p.second >= 0 && p.first < size && p.second < size) return true;
	return false;
}