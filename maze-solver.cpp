#include <iostream>
using namespace std;

enum { CONTENT, POSITION, PREDECESSOR, VISITED};

struct Cell {
    public: 
    char content;
    int visited;
    int position[2];
    int predecessor[2];
    Cell() {
        content = '.';
        visited = 0;
        position[0] = -1;
        position[1] = -1;
        predecessor[0] = -1;
        predecessor[1] = -1;
    };
};


void printMaze(Cell** maze, int data, int yDim, int xDim) {
    cout << "MAZE: -----------------------------" << endl;

    for (int r = 0; r < yDim; r++ ) {
        for (int c = 0; c < xDim; c++) {
            string text;
            switch(data) {
                case CONTENT:
                    text = maze[r][c].content;
                    break;
                case VISITED:
                    text =  to_string(maze[r][c].visited);
                    break;
                case POSITION:
                    text =  "(" + to_string(maze[r][c].position[0]) + "," + to_string(maze[r][c].position[1]) + ")";                    
                    break;
                case PREDECESSOR:
                    text =  "(" + to_string(maze[r][c].predecessor[0]) + "," + to_string(maze[r][c].predecessor[1]) + ")";
                    break;
            }
            // cout << maze[r][c].content << " ";
            cout << text << " ";
        }
        cout << endl;
    }
}
void printMaze(Cell** maze, int yDim, int xDim) {
    cout << "MAZE: -----------------------------" << endl;
    for (int r = 0; r < yDim; r++ ) {
        string contentText = "";
        string visitedText = "";
        string predecessorText = "";
        string space = "     ";
        for (int c = 0; c < xDim; c++) {
            contentText += (char) maze[r][c].content;
            contentText += " ";
            visitedText += to_string(maze[r][c].visited) + " ";
            predecessorText += "(" + to_string(maze[r][c].predecessor[0]) + "," + to_string(maze[r][c].predecessor[1]) + ") ";
        }
        cout << contentText + space + visitedText + space + predecessorText << endl;
    }
}

Cell* processNextCell(int row, int col, int prevRow, int prevCol, Cell** maze, int yDim, int xDim) {
    // boundary check;
    if (row < 0 || col < 0 || row >= yDim || col >= xDim) return NULL;
    Cell* cellPtr = &maze[row][col];
    // invalid check;
    if (cellPtr->content == '#') return NULL;
    if (cellPtr->visited == 1) return NULL;

    cellPtr->predecessor[0] = prevRow;
    cellPtr->predecessor[1] = prevCol;
    cellPtr->visited = 1;

    return cellPtr;
}

void processPath(Cell** maze, int row, int col) {
    Cell* prevCell = &maze[row][col];
    while(prevCell->predecessor[0] != -1 && prevCell ->predecessor[1] != -1) {
        prevCell->content = '*';
        prevCell = &maze[prevCell->predecessor[0]][prevCell->predecessor[1]];
    }
}

void printQueue(Cell** queue, int dim) {
    for (int i = 0; i < dim; i++)  {
        if (queue[i] != NULL)
        cout << i << ": " << queue[i]->content << " (" << queue[i]->position[0] << "," << queue[i]->position[1] << ")" << endl;
    }

}

int main() {
    // int yDim = 4;
    // int xDim = 4;
    int yDim = 16;
    int xDim = 16;

    Cell** maze = new Cell*[yDim];
    for (int r = 0; r < yDim; r++) {
        maze[r] = new Cell[xDim];
    }
    for (int r = 0; r < yDim; r++) {
        for (int c = 0; c < xDim; c++) {
            maze[r][c].position[0] = r;
            maze[r][c].position[1] = c;
        }
    }
    // maze[1][0].content = 'S';
    // maze[13][13].content = 'F';
    // maze[1][1].content = '#';
    // maze[2][1].content = '#';
    // maze[1][3].content = '#';
    // maze[2][3].content = '#';
    // maze[3][3].content = '#';

    maze[1][0].content = 'S';
    // maze[1][2].content = 'F';
    maze[13][13].content = 'F';
    maze[1][1].content = '#';
    maze[2][1].content = '#';
    maze[0][3].content = '#';
    maze[1][3].content = '#';
    maze[2][3].content = '#';
    maze[3][3].content = '#';
    maze[3][9].content = '#';
    maze[4][9].content = '#';
    maze[5][9].content = '#';
    maze[6][9].content = '#';   
    maze[7][9].content = '#';
    maze[8][9].content = '#';
    maze[9][9].content = '#';
    maze[10][9].content = '#';
    maze[11][9].content = '#';
    maze[11][8].content = '#';
    maze[11][7].content = '#';
    maze[11][6].content = '#';
    maze[11][5].content = '#';
    maze[11][4].content = '#';
    maze[11][3].content = '#';
    maze[11][2].content = '#';
    maze[11][1].content = '#';
    maze[11][0].content = '#';
    printMaze(maze, CONTENT, yDim, xDim);
    // printMaze(maze, yDim, xDim);

    int currIndex = 0;  // current search position
    int lastIndex = 0;  // last index to add
    Cell* finishedCell = NULL;
    Cell** queue = new Cell*[xDim * yDim];

    queue[0] = &maze[1][0];
    queue[0]->visited = 1;

    // Cell* testCell = processNextCell(0, 0, 0, 1, maze, yDim, xDim);
    // if (testCell) {
    //     cout << "Test Cell: " << testCell->content << endl;
    //     cout << "Test Cell: " << testCell->predecessor[0] << "," << testCell->predecessor[1] << endl;

    // } else cout << "Invalid Cell!!" << endl;

    // testCell = processNextCell(0, 0, 0, 1, maze, yDim, xDim);
    // if (testCell) {
    //     cout << "Test Cell: " << testCell->content << endl;
    //     cout << "Test Cell: " << testCell->predecessor[0] << "," << testCell->predecessor[1] << endl;

    // } else cout << "Invalid Cell!!" << endl;

    while (currIndex < (yDim * xDim)) {
        Cell* tmp = queue[currIndex];
        int row = tmp->position[0];
        int col = tmp->position[1];

        Cell* upCell = processNextCell(row - 1, col, row, col, maze, yDim, xDim);
        Cell* rightCell = processNextCell(row, col + 1, row, col, maze, yDim, xDim);
        Cell* downCell = processNextCell(row + 1, col, row, col, maze, yDim, xDim);
        Cell* leftCell = processNextCell(row, col - 1, row, col, maze, yDim, xDim);

        if (upCell) {
            if (upCell->content == 'F') {
                finishedCell = upCell;
                break;
            } else {
                queue[++lastIndex] = upCell;
            }
        }
        if (rightCell) {
            if (rightCell->content == 'F') {
                finishedCell = rightCell;
                break;
            } else {
                queue[++lastIndex] = rightCell;
            }
        }
        if (downCell) {
            if (downCell->content == 'F') {
                finishedCell = downCell;
                break;
            } else {
                queue[++lastIndex] = downCell;
            }
        }
        if (leftCell) {
            if (leftCell->content == 'F') {
                finishedCell = leftCell;
                break;
            } else {
                queue[++lastIndex] = leftCell;
            }
        }
        currIndex++;
        // cout << "--Ind: " << currIndex << ":" << lastIndex << endl;
    }

    // printQueue(queue, yDim * xDim);
    processPath(maze, finishedCell->predecessor[0], finishedCell->predecessor[1]);
    printMaze(maze, CONTENT, yDim, xDim);

    for (int i = 0; i < yDim; i++) {
        delete [] maze[i];
    }

    delete [] maze;
    delete [] queue;

    return 0;
}