#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include "GooseInZooDivTwo.h"
using namespace std;
#define oo 1<<31


int GooseInZooDivTwo::count(vector<string>field, int dist) {
	int M[100][100];
	memset(&M, -1, sizeof(M));
	int n = field[0].size();
	int m = field.size();

	queue<pair<int, int>> q;
	string firstLine = field[0];
	int numberOfSets = 0;
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[i].size(); j++) {

			if (M[i][j] == -1 && field[i][j] == 'v') {

				pair<int, int> start(i, j);
				q.push(start);
				while (!q.empty()) {
					pair<int, int> temp = q.front();
					q.pop();
					M[temp.first][temp.second] = 1;
					for (int x = -dist; x <= dist; x++) {
						for (int y = -dist; y <= dist; y++) {
							if (abs(x) + abs(y) <= dist) {
							int tempx = temp.first + x;
							int tempy = temp.second + y;
								if (onField(pair<int, int>(tempx,tempy),n,m))
									if (M[tempx][tempy] == -1 && field[tempx][tempy] == 'v')
										q.push(pair<int, int>(tempx, tempy));
							}
						}
					}
				}
				numberOfSets++;
			}
		}
	}
	int result = 1;
	for (int i = 0; i < numberOfSets; i++) {
		result = (2 * result) % 1000000007;
	}
	result--;
	return result;
}

bool GooseInZooDivTwo::onField(pair<int, int> p, int n, int m) {
	if (p.first>=0 && p.second >= 0 && p.first < m && p.second < n) return true;
	return false;
}