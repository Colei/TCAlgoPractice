//GooseInZooDivTwo.h
#include<string>
#include<vector>
using namespace std;

#ifndef __GOOSEINZOODIVTWO_H_INCLUDED__   // if x.h hasn't been included yet...
#define __GOOSEINZOODIVTWO_H_INCLUDED__   //   #define this so the compiler knows it has been included

class GooseInZooDivTwo {


public:
	int count(vector<string> field, int dist);
	bool onField(pair<int, int> p, int m, int n);
};

#endif 