
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "mazehelper.h"
#include "maze.h"

char * solveMaze(Maze * m) {
    //An obvious upper bound on the size of the solution path is the number
    //of squares in the maze + 1 (to account for the '\0'). You could make
    //this a tighter bound by accounting for how many walls there are, but
    //this approach is good enough!
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		free(retval);
		return NULL;
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {
	if(curpos.xpos < 0 || curpos.ypos < 0 || curpos.xpos >= m->width || curpos.ypos >= m->height) {
		return false;
	}
	if(m->maze[curpos.ypos][curpos.xpos].type == END) {
		path[step] = '\0';
		return true;
	}
	if(m->maze[curpos.ypos][curpos.xpos].type == WALL) {
		return false;
	}
	if(m->maze[curpos.ypos][curpos.xpos].visited == 1) {
		return false;
	}

	m->maze[curpos.ypos][curpos.xpos].visited = 1;

	curpos.ypos--;
	if(depthFirstSolve(m, curpos, path, (step + 1))) {
		path[step] = NORTH;
		return true;
	}
	curpos.ypos++;


	curpos.ypos++;
	if(depthFirstSolve(m, curpos, path, (step + 1))) {
		path[step] = SOUTH;
		return true;
	}
	curpos.ypos--;


	curpos.xpos++;
	if(depthFirstSolve(m, curpos, path, (step + 1))) {
		path[step] = EAST;
		return true;
	}
	curpos.xpos--;


	curpos.xpos--;
	if(depthFirstSolve(m, curpos, path, (step + 1))) {
		path[step] = WEST;
		return true;
	}
	curpos.xpos++;

	return false;
}
