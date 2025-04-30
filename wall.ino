
const int GRID_SIZE = 10;
int pattern[GRID_SIZE][GRID_SIZE] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

void drawRoom() {
    for(int i=0; i < GRID_SIZE; i++) {
        for(int j=0; j < GRID_SIZE; j++) {
            if(pattern[j][i] > 0) {
                drawWall(i,j);
            }
        }
    }
}

void drawWall(int i,int j) {
    gb.display.fillRect(i*GRID_SIZE, j*GRID_SIZE, gb.display.width()/GRID_SIZE, gb.display.height()/GRID_SIZE);
}