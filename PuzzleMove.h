//Miguel Luna
//P02 A* Algorithm

#ifndef _PUZZLEMOVE_
#define _PUZZLEMOVE_

#include "PuzzleState.h"
#include <string>
using namespace std;

enum MoveType { down, left, right, up, nullMove };
string moves[]{ "down", "left", "right", "up", "nullMove" };

class PuzzleMove {
public:
	PuzzleMove() { }

	PuzzleMove(PuzzleState s, PuzzleState p, MoveType m) : state(s),
			parent(p), move(m) { }

	PuzzleMove(const PuzzleMove& rhs) : state(rhs.state), parent(rhs.parent), move(rhs.move) { }

	PuzzleState& getState() { return state; }

	PuzzleState& getParent() { return parent; }

	MoveType getMoveName() { return move; }


private:

	PuzzleState state;
	PuzzleState parent;
	MoveType move;
};
#endif

