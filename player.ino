
// CONST
bool PLAYER_START_POSITION = false;
extern const int GRID_SIZE;
extern const int WALL_WIDTH;
extern const int WALL_HEIGHT;
extern int pattern[][16];

void left()
{
    player.x -= 1;
}

void right()
{
    player.x += 1;
}

void up()
{
    player.y -= 1;
}

void down()
{
    player.y += 1;
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
