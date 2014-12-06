//BoardFolding.h
#include<string>
#include<vector>
using namespace std;

#ifndef __BOARDFOLDING_H_INCLUDED__   // if x.h hasn't been included yet...
#define __BOARDFOLDING_H_INCLUDED__   //   #define this so the compiler knows it has been included

class BoardFolding {


public:
	int count(vector<string> board);
	int willFoldVertical(vector<string> half1, vector<string>half2);
	int willFoldHorizontal(vector<string> half1, vector<string>half2);
};

#endif 