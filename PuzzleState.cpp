//Miguel Luna
//P02 A* Algorithm

#ifndef _PUZZLESTATECPP_
#define _PUZZLESTATECPP_

#include "PuzzleState.h"

using namespace std;

// default constructor

//constructor
PuzzleState::PuzzleState(int n, int m) {
	tiles.resize(size_t(n) * m);
	rows = n;
	cols = m;
	hueristic = 0;
	gVal = 0;
}
// destructor
PuzzleState::~PuzzleState() { }

// copy constructor
PuzzleState::PuzzleState(const PuzzleState& rhs)
	: rows(rhs.rows), cols(rhs.cols), tiles(rhs.tiles),
	blank_position_row(rhs.blank_position_row),
	blank_position_col(rhs.blank_position_col),
	hueristic(rhs.hueristic), gVal(rhs.gVal)
{	}

bool PuzzleState::operator==(const PuzzleState& rhs) const {
	if (rows == rhs.rows
		|| cols == rhs.cols				//checking if rows, cols, and blank position match before looping.
		|| blank_position_col == rhs.blank_position_col
		|| blank_position_row == rhs.blank_position_row)
	{
		for (int i = 0; i < tiles.size(); i++) {
			if (tiles[i] != rhs.tiles[i]) {					//looping to check all tiles are equal
				return 0;
			}
		}
		return 1;
	}
	else {
		return 0;

	}
};

bool PuzzleState::operator!=(const PuzzleState& rhs) const {
	return !(*this == rhs);
};

const PuzzleState& PuzzleState::operator=(const PuzzleState& rhs) {
	if (this == &rhs) {
		return *this;
	}
	rows = rhs.rows;
	cols = rhs.cols;
	tiles = rhs.tiles;
	blank_position_row = rhs.blank_position_row;
	blank_position_col = rhs.blank_position_col;
	hueristic = rhs.hueristic;
	gVal = rhs.gVal;
	return *this;

}; //assignment op

bool PuzzleState::isNullState() { return rows == 0; } // can be excluded

bool PuzzleState::canMoveUp() {
	if (blank_position_row == 0) {
		return false;
	}
	return true;
};

bool PuzzleState::canMoveDown() {
	if (blank_position_row == rows - 1) {
		return false;
	}
	return true;
};

bool PuzzleState::canMoveLeft() {
	if (blank_position_col == 0) {
		return false;
	}
	return true;
};

bool PuzzleState::canMoveRight() {
	if (blank_position_col == cols - 1) {
		return false;
	}
	return true;
};

PuzzleState PuzzleState::moveBlankUp() {
	int temp;
	if (canMoveUp()) {
		temp = tiles[(blank_position_row - 1) * cols + blank_position_col]; //getting elemnt where blank is moving
		tiles[(blank_position_row - 1) * cols + blank_position_col] = 0; // moving blank up
		tiles[blank_position_row * cols + blank_position_col] = temp; // placing temp in previous blank 
		blank_position_row--; // adjusting blanks column postion
	}
	gVal++;
	return *this;

};

PuzzleState PuzzleState::moveBlankDown() {
	int temp;
	if (canMoveDown()) {
		temp = tiles[(blank_position_row + 1) * cols + blank_position_col]; //getting elemnt where blank is moving
		tiles[(blank_position_row + 1) * cols + blank_position_col] = 0; // moving blank up
		tiles[blank_position_row * cols + blank_position_col] = temp; // placing temp in previous blank 
		blank_position_row++; // adjusting blanks column postion
	}
	gVal++;
	return *this;
};

PuzzleState PuzzleState::moveBlankLeft() {
	int temp;
	if (canMoveLeft()) {
		temp = tiles[blank_position_row * cols + (blank_position_col - 1)]; //getting elemnt where blank is moving
		tiles[blank_position_row * cols + (blank_position_col - 1)] = 0; // moving blank up
		tiles[blank_position_row * cols + blank_position_col] = temp; // placing temp in previous blank 
		blank_position_col--; // adjusting blanks column postion
	}
	gVal++;
	return *this;
};

PuzzleState PuzzleState::moveBlankRight() {
	int temp;
	if (canMoveRight()) {
		temp = tiles[blank_position_row * cols + (blank_position_col + 1)]; //getting elemnt where blank is moving
		tiles[blank_position_row * cols + (blank_position_col + 1)] = 0; // moving blank up
		tiles[blank_position_row * cols + blank_position_col] = temp; // placing temp in previous blank 
		blank_position_col++; // adjusting blanks column postion
	}
	gVal++;
	return *this;
};

void PuzzleState::read(istream& in) {

	vector<bool> used;
	used.resize(rows * cols);

	for (int i = 0; i < used.size(); i++) {
		used[i] = 0;
	}


	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			in >> tiles[i * cols + j];
			if (tiles[i * cols + j] == 0) {
				blank_position_row = i;
				blank_position_col = j;
			}
			if (tiles[i * cols + j] >= (rows * cols)) {
				cout << "\nInvalid Puzzle Input: Enter numbers between 0 and " << (rows * rows)-1;
				exit(1);
			}
			if (used[tiles[i * cols + j]] == 1) {
				cout << "\nInvalid Puzzle Input: no repeat #'s allowed";
				exit(1);
			}
			used[tiles[i * cols + j]] = true;
		}
	}

};

void PuzzleState::print(ostream& out) {

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			out << tiles[i * cols + j] << " ";
		}
		out << endl;
	}
};

void PuzzleState::setHueristic(int h) { hueristic = h; }

int PuzzleState::getHueristic() {
	return hueristic;
}
int PuzzleState::getRows() { return rows; }

// f = g + h
int PuzzleState::getF() { return (gVal + hueristic); }

istream& operator>>(istream& in, PuzzleState& rhs) {
	rhs.read(in);
	return in;

};
ostream& operator<<(ostream& out, PuzzleState& rhs) {
	rhs.print(out);
	return out;

};

#endif


