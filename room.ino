int getPointValue(int x, int y)
{
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