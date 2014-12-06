#include<string>
#include<iostream>
#include<vector>
#include<stack>
#include "BoardFolding.h"
#define For(i,n) for(int i=0;i<n;i++)
using namespace std;


int BoardFolding::count(vector<string> board) {

	int n = board.size();
	int m = board[0].size();

	bool visited [20][20][20][20];
	memset(visited, false, sizeof(visited) / sizeof(bool));
	stack< pair<vector<string>, pair<int,int>>> s;
	s.push(pair<vector<string>, pair<int,int>>(board, pair<int,int>(0,0)));
	while (!s.empty()) {
		pair<vector<string>, pair<int, int>> temp = s.top();
		s.pop();
		int a = temp.first.size();
		int b = temp.first[0].size();
		int c = temp.second.first;
		int d = temp.second.second;
		if (visited[a][b][c][d]) continue;
			visited[a][b][c][d] = true;
		For(row, temp.first.size()) {
			vector<string> half1, half2;
			For(half1Row, row) half1.push_back(temp.first[half1Row]);
			for (int half2Row = row; half2Row < temp.first.size(); half2Row++) 
				half2.push_back(temp.first[half2Row]);
			int folding = willFoldVertical(half1, half2);
			if (folding == 0) continue;
			if (folding == 1)
				s.push(pair<vector<string>, pair<int, int>>(half2,pair<int,int>(temp.second.first+row, temp.second.second)));
			if (folding == 2)
				s.push(pair<vector<string>, pair<int, int>>(half1, temp.second));
			if (folding == 3) {
				s.push(pair<vector<string>, pair<int, int>>(half2, pair<int, int>(temp.second.first + row, temp.second.second)));
				s.push(pair<vector<string>, pair<int, int>>(half1, temp.second));
			}
		}

		For(column, temp.first[0].size()) {
			vector<string> half1, half2;
			For(row, temp.first.size()) {
				string s1 = temp.first[row].substr(0, column);
				string s2 = temp.first[row].substr(column, temp.first[row].size() - column);
				half1.push_back(s1);
				half2.push_back(s2);
			}
			int folding = willFoldHorizontal(half1, half2);
			if (folding == 0) continue;
			if (folding == 1)
				s.push(pair<vector<string>, pair<int, int>>(half2, pair<int, int>(temp.second.first, temp.second.second + column)));
			if (folding == 2)
				s.push(pair<vector<string>, pair<int, int>>(half1, temp.second));
			if (folding == 3) {
				s.push(pair<vector<string>, pair<int, int>>(half2, pair<int, int>(temp.second.first, temp.second.second + column)));
				s.push(pair<vector<string>, pair<int, int>>(half1, temp.second));
			}
		}
	}
	int total = 0;
	For(a, 20)
		For(b, 20)
			For(c, 20)
				For(d, 20)
					if (visited[a][b][c][d])
						total++;
	return total;
}

int BoardFolding::willFoldVertical(vector<string> half1, vector<string> half2) {
	bool foldDown = false;
	bool foldUp = false;
	if (half1.size() <= half2.size()) {
		For(i, half1.size()) {
			For(j, half2[i].size()) {
				if (!(half2[i][j] == half1[half1.size() - 1 - i][j])) return 0;
			}
		}
		foldDown = true;
	}
	if (half1.size() >= half2.size()) 
	{
		For(i, half2.size()) {
			For(j, half2[i].size()) {
				if (!(half2[i][j] == half1[half1.size() - 1 - i][j])) return 0;
			}
		}
		foldUp = true;
	}
	if (foldUp && foldDown) return 3;
	if (foldUp) return 2;
	if (foldDown) return 1;
	return 0;
}

int BoardFolding::willFoldHorizontal(vector<string> half1, vector<string> half2) {
	bool foldRight = false;
	bool foldLeft = false;
	if (half1[0].size() <= half2[0].size()) {
		For(i, half1[0].size()) {
			For(j, half2.size()) {
				if (!(half2[j][i] == half1[j][half1[0].size() - 1 - i])) return 0;
			}
		}
		foldRight = true;
	}
	if (half1[0].size() >= half2[0].size())
	{
		For(i, half2[0].size()) {
			For(j, half2.size()) {
				if (!(half2[j][i] == half1[j][half1[0].size() - 1 - i])) return 0;
			}
		}
		foldLeft = true;
	}
	if (foldLeft && foldRight) return 3;
	if (foldLeft) return 2;
	if (foldRight) return 1;
	return 0;
}
