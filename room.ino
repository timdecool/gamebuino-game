const int GRID_SIZE = 16;
const int TILE_WIDTH = gb.display.width() / GRID_SIZE;
const int TILE_HEIGHT = gb.display.height() / GRID_SIZE;

int pattern[GRID_SIZE][GRID_SIZE] = {
    {-1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 2, 0, 1, 0, 1, 3, 1, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, -2, 0, 0}};


int getPointValue(int x, int y) {
    int gridX = x / TILE_WIDTH;
    int gridY = y / TILE_HEIGHT;
    return pattern[gridY][gridX];
}

void drawRoom()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (pattern[j][i] == WALL)
            {
                drawWall(i, j);
            }
            else if (pattern[j][i] == HOLE)
            {
                drawHole(i, j);
            }
            else if (pattern[j][i] == START)
            {
                drawStart(i, j);
            }
            else if (pattern[j][i] == END)
            {
                drawEnd(i, j);
            }
        }
    }
}

void drawWall(int i, int j)
{
    gb.display.setColor(BROWN);
    gb.display.fillRect(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}

void drawHole(int i, int j)
{
    gb.display.setColor(BLACK);
    gb.display.fillRect(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}

void drawStart(int i, int j)
{
    gb.display.setColor(ORANGE);
    gb.display.fillRect(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}
void drawEnd(int i, int j)
{
    gb.display.setColor(RED);
    gb.display.fillRect(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}