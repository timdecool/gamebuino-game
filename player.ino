
// CONST
bool PLAYER_START_POSITION = false;
extern const int GRID_SIZE;
extern const int WALL_WIDTH;
extern const int WALL_HEIGHT;
extern int pattern[][16];

void left()
{
    newPos.x = player.x - 1;
    gb.display.setCursor(6, 6);
    if(newPos.x > 0 && !getPointValue(newPos.x - 1, newPos.y) == 1) {
        player.x = newPos.x;
    }
}

void right()
{
    newPos.x = player.x + 1;
    if(newPos.x + PLAYER_WIDTH < gb.display.width() && !getPointValue(newPos.x + PLAYER_WIDTH, newPos.y) == 1) {
        player.x = newPos.x;
    }
}

void up()
{
    newPos.y = player.y - 1;
    if(newPos.y >= 0 && !getPointValue(newPos.x, newPos.y - 1) == 1) {
        player.y = newPos.y;
    }
}

void down()
{
    newPos.y = player.y + 1;
    if(newPos.y + PLAYER_HEIGHT <= gb.display.height() && !getPointValue(newPos.x, newPos.y + PLAYER_HEIGHT) == 1) {
        player.y = newPos.y;
    }
}

void drawPlayer()
{
    if (!PLAYER_START_POSITION)
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            for (int x = 0; x < GRID_SIZE; x++)
            {
                if (pattern[y][x] == 4)
                {
                    player.x = x * WALL_WIDTH + (WALL_WIDTH - PLAYER_WIDTH) / 2;
                    player.y = y * WALL_HEIGHT + (WALL_HEIGHT - PLAYER_HEIGHT) / 2;
                    PLAYER_START_POSITION = true;
                    break;
                }
            }
            if (PLAYER_START_POSITION)
                break;
        }
    }
    gb.display.fillRect(player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT);
}
