int getPointValue(int x, int y)
{
    int gridX = x / TILE_WIDTH;
    int gridY = y / TILE_HEIGHT;
    return pattern[gridY][gridX];
}

void drawRoom()
{
    for (int i = 0; i < GRID_X; i++)
    {
        for (int j = 0; j < GRID_Y; j++)
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
            else if (pattern[j][i] == FILLED)
            {
                drawFilled(i, j);
            }
            else {
                drawFloor(i, j);
            }
        }
    }
}

void drawWall(int i, int j)
{
    gb.display.drawImage(i * TILE_WIDTH, j * TILE_HEIGHT, WALL_DATA);
}

void drawHole(int i, int j)
{
    gb.display.drawImage(i * TILE_WIDTH, j * TILE_HEIGHT, HOLE_DATA);
}

void drawStart(int i, int j)
{
    gb.display.setColor(ORANGE);
    gb.display.fillRect(i * TILE_WIDTH, j * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
}
void drawEnd(int i, int j)
{
    gb.display.drawImage(i * TILE_WIDTH, j * TILE_HEIGHT, END_DATA);

}
void drawFloor(int i, int j) {
    gb.display.drawImage(i * TILE_WIDTH, j * TILE_HEIGHT, FLOOR_DATA);
}

void drawFilled(int i, int j) {
    gb.display.drawImage(i * TILE_WIDTH, j * TILE_HEIGHT, FILLED_DATA);
}