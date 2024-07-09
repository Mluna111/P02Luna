<h1>Puzzle Solver with A*</h1>

<h2>Description</h2>
<p>This project implements a puzzle solver using the A* search algorithm. The solver works on an N x N grid where the objective is to move tiles to achieve a goal state. The project consists of four main files: <code>AStarDriver.cpp</code>, <code>PuzzleMove.h</code>, <code>PuzzleMove.cpp</code>, and <code>PuzzleState.h</code>.</p>

<h2>Files in the Project</h2>
<ul>
    <li><b><code>AStarDriver.cpp</code></b>: The main driver file that performs the A* search to solve the puzzle.</li>
    <li><b><code>PuzzleMove.h</code></b>: Defines the <code>PuzzleMove</code> class, which represents a move in the puzzle.</li>
    <li><b><code>PuzzleState.h</code></b>: Defines the <code>PuzzleState</code> class, which represents the state of the puzzle.</li>
    <li><b><code>PuzzleState.cpp</code></b>: Implements the methods of the <code>PuzzleState</code> class.</li>
</ul>

<h2>Libraries Used</h2>
<ul>
    <li><b>iostream</b>: For input and output operations.</li>
    <li><b>queue</b>: For implementing the priority queue used in the A* algorithm.</li>
    <li><b>stack</b>: For storing the solution path.</li>
    <li><b>cmath</b>: For calculating the Manhattan distance heuristic.</li>
    <li><b>vector</b>: For managing collections of puzzle moves and states.</li>
</ul>

<h2>How to Run</h2>
<ol>
    <li><b>Compile the project</b>:
        <pre><code>g++ -o PuzzleSolver AStarDriver.cpp PuzzleState.cpp</code></pre>
    </li>
    <li><b>Run the executable</b>:
        <pre><code>./PuzzleSolver</code></pre>
    </li>
</ol>

<h2>Input</h2>
<p>The program will prompt the user to enter the number of rows and columns (which should be the same for an N x N grid). Then, the user will enter the start and goal states of the puzzle, row by row.</p>

<h2>Output</h2>
<p>The program will output the solution path if a solution is found, including the number of nodes expanded and the path length to the goal. If no solution is found, it will indicate that as well.</p>

<h2>Sample Run</h2>

<p align="center">
<br/>
<img src="https://imgur.com/U0q9zgU.png" height="80%" width="80%" />
<br />
</p>
