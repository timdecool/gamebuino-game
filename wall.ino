const int GRID_SIZE = 16;
const int WALL_WIDTH = gb.display.width() / GRID_SIZE;
const int WALL_HEIGHT = gb.display.height() / GRID_SIZE;
const int ROCK_WIDTH = gb.display.width() / GRID_SIZE;
const int ROCK_HEIGHT = gb.display.height() / GRID_SIZE;
const int HOLE_WIDTH = gb.display.width() / GRID_SIZE;
const int HOLE_HEIGHT = gb.display.height() / GRID_SIZE;
const int START_HEIGHT = gb.display.height() / GRID_SIZE;
const int START_WIDTH = gb.display.width() / GRID_SIZE;
const int END_HEIGHT = gb.display.height() / GRID_SIZE;
const int END_WIDTH = gb.display.width() / GRID_SIZE;

int pattern[GRID_SIZE][GRID_SIZE] = {
    {-1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 0, 0, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
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
    int gridX = x / WALL_WIDTH;
    int gridY = y / WALL_HEIGHT;
    gb.display.print(pattern[gridY][gridX]);
    return pattern[gridY][gridX];
}

void drawRoom()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (pattern[j][i] == 1)
            {
                drawWall(i, j);
            }
            else if (pattern[j][i] == 2)
            {
                drawRocks(i, j);
            }
            else if (pattern[j][i] == 3)
            {
                drawHole(i, j);
            }
            else if (pattern[j][i] == -1)
            {
                drawStart(i, j);
            }
            else if (pattern[j][i] == -2)
            {
                drawEnd(i, j);
            }
        }
    }
}

void drawWall(int i, int j)
{
    gb.display.setColor(BROWN);
    gb.display.fillRect(i * WALL_WIDTH, j * WALL_HEIGHT, WALL_WIDTH, WALL_HEIGHT);
}

void drawRocks(int i, int j)
{
    gb.display.setColor(DARKGRAY);
    gb.display.fillRect(i * WALL_WIDTH, j * WALL_HEIGHT, ROCK_WIDTH, ROCK_HEIGHT);
}
void drawHole(int i, int j)
{
    gb.display.setColor(BLACK);
    gb.display.fillRect(i * HOLE_WIDTH, j * HOLE_HEIGHT, WALL_WIDTH, WALL_HEIGHT);
}

void drawStart(int i, int j)
{
    gb.display.setColor(ORANGE);
    gb.display.fillRect(i * START_WIDTH, j * START_HEIGHT, START_WIDTH, START_HEIGHT);
}
void drawEnd(int i, int j)
{
    gb.display.setColor(RED);
    gb.display.fillRect(i * END_WIDTH, j * END_HEIGHT, END_WIDTH, END_HEIGHT);
}