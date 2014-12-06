#include<iostream>
#include<string>
#include<algorithm>
#include "QuickSums.h"
#include "GooseInZooDivTwo.h"
#include "ChessMetric.h"
#include "FriendScore.h"
#include "BoardFolding.h"
#define oo 1<<30
using namespace std;


int main() {
	QuickSums qS;
	int r = qS.minSums("10002", 3);
	cout<<r<<endl<<endl;


	GooseInZooDivTwo gs;
	int dist1, dist2, dist3;
	vector<string> field1,field2,field3;
	field1.push_back("vvv");

	field2.push_back("v.v.v");

	string listofstrings[] = { 
		"v.v..................v............................"
	, ".v......v..................v.....................v"
	, "..v.....v....v.........v...............v......v..."
	, ".........vvv...vv.v.........v.v..................v"
	, ".....v..........v......v..v...v.......v..........."
	, "...................vv...............v.v..v.v..v..."
	, ".v.vv.................v..............v............"
	, "..vv.......v...vv.v............vv.....v.....v....."
	, "....v..........v....v........v.......v.v.v........"
	, ".v.......v.............v.v..........vv......v....."
	, "....v.v.......v........v.....v.................v.."
	, "....v..v..v.v..............v.v.v....v..........v.."
	, "..........v...v...................v..............v"
	, "..v........v..........................v....v..v..."
	, "....................v..v.........vv........v......"
	, "..v......v...............................v.v......"
	, "..v.v..............v........v...............vv.vv."
	, "...vv......v...............v.v..............v....."
	, "............................v..v.................v"
	, ".v.............v.......v.........................."
	, "......v...v........................v.............."
	, ".........v.....v..............vv.................."
	, "................v..v..v.........v....v.......v...."
	, "........v.....v.............v......v.v............"
	, "...........v....................v.v....v.v.v...v.."
	, "...........v......................v...v..........."
	, "..........vv...........v.v.....................v.."
	, ".....................v......v............v...v...."
	, ".....vv..........................vv.v.....v.v....."
	, ".vv.......v...............v.......v..v.....v......"
	, "............v................v..........v....v...."
	, "................vv...v............................"
	, "................v...........v........v...v....v..."
	, "..v...v...v.............v...v........v....v..v...."
	, "......v..v.......v........v..v....vv.............."
	, "...........v..........v........v.v................"
	, "v.v......v................v....................v.."
	, ".v........v................................v......"
	, "............................v...v.......v........."
	, "........................vv.v..............v...vv.."
	, ".......................vv........v.............v.."
	, "...v.............v.........................v......"
	, "....v......vv...........................v........."
	, "....vv....v................v...vv..............v.."
	, ".................................................."
	, "vv........v...v..v.....v..v..................v...."
	, ".........v..............v.vv.v.............v......"
	, ".......v.....v......v...............v............."
	, "..v..................v................v....v......"
	, ".....v.....v.....................v.v......v......." };

	for (int i = 0; i < 50; i++) {
		field3.push_back(listofstrings[i]);
	}

	//int k1 = gs.count(field1, 0);
	//int k2 = gs.count(field2, 0);
	int k3 = gs.count(field3, 3);




	cout << k3;// 1 << endl << k2 << endl << k3;
	
	
	ChessMetric cm;
	int start1[] {4,4};
	int end1[] {4,4};
	int chessMetricResult1 = cm.howMany(8, start1, end1, 6);
	cout << endl << endl << chessMetricResult1;


	int start2[] {0, 0};
	int end2[] {0, 99};
	long long chessMetricResult2 = cm.howMany(100, start2, end2, 50);
	cout << endl << endl << chessMetricResult2;

	
	FriendScore fs;
	vector<string> network1;

	network1.push_back("NNNNNNNNNNNNNNY");
		network1.push_back("NNNNNNNNNNNNNNN");
		network1.push_back("NNNNNNNYNNNNNNN");
		network1.push_back("NNNNNNNYNNNNNNY");
		network1.push_back("NNNNNNNNNNNNNNY");
		network1.push_back("NNNNNNNNYNNNNNN");
		network1.push_back("NNNNNNNNNNNNNNN");
		network1.push_back("NNYYNNNNNNNNNNN");
		network1.push_back("NNNNNYNNNNNYNNN");
		network1.push_back("NNNNNNNNNNNNNNY");
		network1.push_back("NNNNNNNNNNNNNNN");
		network1.push_back("NNNNNNNNYNNNNNN");
		network1.push_back("NNNNNNNNNNNNNNN");
		network1.push_back("NNNNNNNNNNNNNNN");
		network1.push_back("YNNYYNNNNYNNNNN");
	int friendScoreResult = fs.score(network1);
	cout << endl << endl << friendScoreResult;



	BoardFolding bf;
	vector<string> vectors1;
	vectors1.push_back("0110");
	vectors1.push_back("1001");
	vectors1.push_back("1001");
	vectors1.push_back("0110");
	int c = bf.count(vectors1);

	cout << endl << endl << c;


	cin.get();
	return 9;
}