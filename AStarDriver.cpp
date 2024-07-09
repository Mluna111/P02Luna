//Miguel Luna
//P02 A* Algorithm

#include "PuzzleMove.h"
#include "PuzzleState.h"
#include <iostream>x
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

struct CompareF;		//struct is for priority queue ordering
bool inClosedList(PuzzleState& const currentState, vector<PuzzleMove>& const closed);
void expand(PuzzleMove& const currentMove, priority_queue<PuzzleMove, vector<PuzzleMove>,CompareF>& fringe, 
			vector<PuzzleMove>& const closed, PuzzleState& const goal);
void PrintPath(PuzzleMove currentMove, vector<PuzzleMove>& const closed); 
void solve(PuzzleState& start, PuzzleState& goal, vector<PuzzleMove>& closed);
void getManhattanDist(PuzzleState& currState, PuzzleState goal);

int main() {

	int rows = 0;
	int cols = 0;
	cout << "Enter number of rows and columns: ";
	cin >> rows;// >> cols;
	cols = rows;

	if (rows != cols || cols == 0 || rows == 0) {		//checking for square vector n*n where n > 0
		cout << "\n*** No solution found, incorrect number of rows and/or columns ***";
	}

	cout << "\nEnter Start State row by row:\n";
	PuzzleState start(rows, cols);
	cin >> start;

	cout << "\nEnter End State row by row:\n";
	PuzzleState goal(rows, cols);
	cin >> goal;

	if (start == goal) {
		cout << "\n*** Solution found immediately: start state is the goal state. ***";
	}
	vector<PuzzleMove> closed;
	solve(start, goal, closed);
}

/*	Test Runs	*/
// 2 1 2 0 3 1 2 3 0
// 3 1 3 5 4 2 0 7 8 6 1 2 3 4 5 6 7 8 0
// 3 1 0 2 7 4 3 6 5 8 1 2 3 4 5 6 7 8 0
// 3 0 2 3 1 4 6 7 5 8 1 2 3 4 5 6 7 8 0
// 4 0 2 3 4 1 5 7 8 9 6 10 12 13 14 11 15 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0
// 2 1 3 2 0 1 2 3 0
// 4 0 2 12 1 6 5 3 15 8 4 11 9 13 10 7 14 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0


struct CompareF {
	bool operator()(PuzzleMove& const p1, PuzzleMove& const p2)
	{
		return (p1.getState()).getF() > (p2.getState()).getF();
	}
};


bool inClosedList(PuzzleState& const currentState, vector<PuzzleMove>& const closed) {

	bool val = 0;
	for (int i = 0; i < closed.size(); i++) {
		if (currentState == closed[i].getState()) {
			val = 1;
		}
	}
	return val;
}

// creates new states by moving tile
void expand(PuzzleMove& const currentMove, priority_queue<PuzzleMove, vector<PuzzleMove>, CompareF>& fringe,
			vector<PuzzleMove>& const closed, PuzzleState& const goal) {

	PuzzleState currentState = currentMove.getState();
	PuzzleState tempState;

	if (currentState.canMoveDown()) {
		tempState = currentState;
		tempState.moveBlankDown();
		if (!(currentMove.getParent() == tempState)) { //checking that new state is not equal to parent of state expanded
			getManhattanDist(tempState, goal);
			fringe.push(PuzzleMove(tempState, currentState, down));
		}
	}
	if (currentState.canMoveLeft()) {
		tempState = currentState;
		tempState.moveBlankLeft();
		if (!(currentMove.getParent() == tempState)) {
			getManhattanDist(tempState, goal);
			fringe.push(PuzzleMove(tempState, currentState, ::left));
		}
	}
	if (currentState.canMoveUp()) {
		tempState = currentState;
		tempState.moveBlankUp();
		if (!(currentMove.getParent() == tempState)) {
			getManhattanDist(tempState, goal);
			fringe.push(PuzzleMove(tempState, currentState, up));
		}
	}
	if (currentState.canMoveRight()) {
		tempState = currentState;
		tempState.moveBlankRight();
		if (!(currentMove.getParent() == tempState)) {
			getManhattanDist(tempState, goal);
			fringe.push(PuzzleMove(tempState, currentState, ::right));
		}
	}
}

void PrintPath(PuzzleMove currentMove, vector<PuzzleMove>& const closed) {

	PuzzleState pathState;
	stack<PuzzleMove> sol;

	do {
		pathState = currentMove.getParent();
		sol.push(currentMove);
		for (int i = 0; i < closed.size(); i++) {
			if (pathState == closed[i].getState()) {
				currentMove = closed[i];
			}
		}
	} while (currentMove.getState() != currentMove.getParent());

	cout << "\nSolution Found:";
	//cout << "\nNumber of nodes expanded: " << closed.size();
	//cout << "\nPath length to Goal: " << sol.size();

	cout << endl << endl << currentMove.getState();

	while (!sol.empty()) {
		currentMove = sol.top();
		sol.pop();
		cout << endl << moves[currentMove.getMoveName()] << endl << endl << currentMove.getState();

	}
}

void solve(PuzzleState& start, PuzzleState& goal, vector<PuzzleMove>& closed) {
	priority_queue<PuzzleMove,vector<PuzzleMove>, CompareF> fringe;
	PuzzleMove test;
	PuzzleMove currentMove;
	PuzzleState currentState;
	PuzzleState tempState;
	getManhattanDist(start, goal);
	currentState = start;
	PuzzleMove root(start, start, nullMove);
	fringe.push(root);
	bool solution = 0;
	while (fringe.empty() != 1 && solution == 0) {
		currentMove = fringe.top();
		fringe.pop();
		currentState = currentMove.getState();
		if (currentState == goal) {
			PrintPath(currentMove, closed);
			solution = 1;
		}
		else {
			if (!(inClosedList(currentState, closed))) {
				closed.push_back(currentMove);
				expand(currentMove, fringe, closed, goal);
			}
		}
	}
	if (solution == 0)
		cout << "\nNo Solution Found";

}

void getManhattanDist(PuzzleState& currState, PuzzleState goal) {
	// subtrating rows gives the number of moves up or down
	// subtrating cols gives the number of moves right or left
	// sum 
	int current;
	int rows = goal.getRows();
	int cols = rows;
	int sum = 0;
	//two for loops to iterate through goal matrix/vector
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			current = goal.tiles[size_t(rows) * i + j];
			if (current != 0)	//dont count blank's or 0's distance in hueristic
				//2 loops to find goal tile in current state matrix/vector 
				//to calculate # of moves from goal position
				for (int k = 0; k < rows; k++) {
					for (int m = 0; m < cols; m++) {
						if (currState.tiles[size_t(k) * rows + m] == current) {
							sum += abs(i - k); //account for column distance and row distances
							sum += abs(j - m); 
						}
					}
				}
		}
	}
	currState.setHueristic(sum);
}
