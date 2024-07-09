//Miguel Luna
//P02 A* Algorithm

/*
	* This class describes what a PuzzleState is.
	* The blank_position is for decreasing the time
	* to check what tile operator is applicable
*/

#ifndef _PUZZLESTATE_
#define _PUZZLESTATE_
#include <iostream>
#include <vector>

using namespace std;

class PuzzleState
{
public:
	// default constructor
	PuzzleState() {}

	//constructor
	PuzzleState(int n, int m);
	// destructor
	~PuzzleState();

	// copy constructor
	PuzzleState(const PuzzleState& rhs);

	bool  operator==(const PuzzleState& rhs) const;
	bool  operator!=(const PuzzleState& rhs) const;
	const PuzzleState& operator=(const PuzzleState& rhs);

	bool isNullState(); // can be excluded

	bool canMoveUp();
	bool canMoveDown();
	bool canMoveLeft();
	bool canMoveRight();

	PuzzleState moveBlankUp();
	PuzzleState moveBlankDown();
	PuzzleState moveBlankLeft();
	PuzzleState moveBlankRight();

	void read(istream& in);
	void print(ostream& out);

	void setHueristic(int h);
	int getHueristic();

	int getRows();

	// f = g + h
	int getF();

	static PuzzleState  NullState;
	vector<int> tiles;

private:
	size_t rows;
	size_t cols;
	size_t blank_position_row;
	size_t blank_position_col;
	int hueristic;
	int gVal;
};

istream& operator>>(istream& in, PuzzleState& rhs);
ostream& operator<<(ostream& out, PuzzleState& rhs);

#endif
