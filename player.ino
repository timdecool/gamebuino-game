bool canMove(Point position, Element element) 
{
    // check x screen bounds
    if(position.x < 0 || position.x + element.width > gb.display.width()) {
        return false;
    }

    // check y screen bounds
    if(position.y < 0 || position.y + element.height > gb.display.height()) {
        return false;
    }

    // check collision with obstacles
    // for rocks
    if(element.id > 1) {
        return !isRockAhead(position, element)
        && (getPointValue(position.x, position.y) <= FLOOR 
        && getPointValue(position.x + element.width - 1, position.y) <= FLOOR
        && getPointValue(position.x + element.width - 1, position.y + element.height - 1) <= FLOOR
        && getPointValue(position.x, position.y + element.height - 1) <= FLOOR)
        || (getPointValue(position.x, position.y) == HOLE 
        || getPointValue(position.x + element.width - 1, position.y) == HOLE
        || getPointValue(position.x + element.width - 1, position.y + element.height - 1) == HOLE
        || getPointValue(position.x, position.y + element.height - 1) == HOLE);
    }
    // for player
    else {
        return !isRockAhead(position, element)
        && getPointValue(position.x, position.y) <= FLOOR 
        && getPointValue(position.x + element.width - 1, position.y) <= FLOOR
        && getPointValue(position.x + element.width - 1, position.y + element.height - 1) <= FLOOR
        && getPointValue(position.x, position.y + element.height - 1) <= FLOOR;
    }

}

Point getNewPosition(int direction, Element element) {
    Point newPos;
        switch(direction) {
            case 1:
                newPos = { element.position.x - 1, element.position.y };
                break;
            case 2:
                newPos = { element.position.x, element.position.y - 1 };
                break;
            case 3:
                newPos = { element.position.x + 1, element.position.y };
                break;
            case 4:
                newPos = { element.position.x, element.position.y + 1 };
                break;
        }
    return newPos;
}


Point move(int direction, Element element) 
{
    Point newPos = getNewPosition(direction, element);
    if(canMove(newPos, element)) return newPos;        
    else return element.position;
}

void push(int direction, Element element) 
{
    Point newPos = getNewPosition(direction, element);
    if(isRockAhead(newPos, element)) {
        pushRock(newPos, element, direction);
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
                if (pattern[y][x] == START)
                {
                    player.position.x = x * TILE_WIDTH + (TILE_WIDTH - player.width) / 2;
                    player.position.y = y * TILE_HEIGHT + (TILE_HEIGHT - player.height) / 2;
                    PLAYER_START_POSITION = true;
                    break;
                }
            }
            if (PLAYER_START_POSITION)
                break;
        }
    }
    gb.display.setColor(WHITE);
    gb.display.fillRect(player.position.x, player.position.y, player.width, player.height);
}
