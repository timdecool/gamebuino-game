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
            case LEFT:
                newPos = { element.position.x - 1, element.position.y };
                break;
            case UP:
                newPos = { element.position.x, element.position.y - 1 };
                break;
            case RIGHT:
                newPos = { element.position.x + 1, element.position.y };
                break;
            case DOWN:
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


void initPlayer()
{
    bool playerStartPosition = false;
    for (int y = 0; y < GRID_Y; y++)
        {
            for (int x = 0; x < GRID_X; x++)
            {
                if (pattern[y][x] == START)
                {
                    player.element.position.x = x * TILE_WIDTH + (TILE_WIDTH - player.element.width) / 2;
                    player.element.position.y = y * TILE_HEIGHT + (TILE_HEIGHT - player.element.height) / 2;
                    playerStartPosition = true;
                    pattern[y][x] = FLOOR;
                    break;
                }
            }
            if (playerStartPosition)
                break;
        }
}

void drawPlayer()
{
    int16_t orientation;
    if(player.direction == LEFT) orientation = player.element.width;
    else orientation = -player.element.width;
    if(!player.moving) {
        avatar.setFrame(1);
    }
    gb.display.drawImage(player.element.position.x, player.element.position.y, avatar, orientation, player.element.height);
}
