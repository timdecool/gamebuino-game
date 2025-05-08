
// CONST
bool PLAYER_START_POSITION = false;
extern const int GRID_SIZE;
extern const int WALL_WIDTH;
extern const int WALL_HEIGHT;
extern int pattern[][16];

bool canMove(Point position) 
{
    // check x screen bounds
    if(position.x < 0 || position.x + PLAYER_WIDTH > gb.display.width()) {
        return false;
    }

    // check y screen bounds
    if(position.y < 0 || position.y + PLAYER_HEIGHT > gb.display.height()) {
        return false;
    }

    // check collision with obstacles
    return getPointValue(position.x, position.y) <= 0 
        && getPointValue(position.x + PLAYER_WIDTH, position.y) <= 0
        && getPointValue(position.x + PLAYER_WIDTH, position.y + PLAYER_HEIGHT) <= 0
        && getPointValue(position.x, position.y + PLAYER_HEIGHT) <= 0;
}

void move(int direction) 
{
    Point newPos;
    switch(direction) {
        case 1:
            newPos = { player.x - 1, player.y };
            break;
        case 2:
            newPos = { player.x, player.y - 1 };
            break;
        case 3:
            newPos = { player.x + 1, player.y };
            break;
        case 4:
            newPos = { player.x, player.y + 1 };
            break;
    }
    if(canMove(newPos)) {
        player = newPos;
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
                if (pattern[y][x] == -1)
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
    gb.display.setColor(WHITE);
    gb.display.fillRect(player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT);
}
