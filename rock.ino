const int ROCK_MOVES[5] = {0, 1, 1, 2, 4};

void clearRocks() {
    for(int i = 0; i < MAX_ROCKS; i++) {
        rocks[i].element.width = 0;
    }
}

void initRocks() {
    int found = 0;
    for(int y = 0; y < GRID_Y; y++) {
        for(int x = 0; x < GRID_X; x++) {
            if(pattern[y][x] == 2) {
                rocks[found] = {
                    {
                        ++currentId,
                        { x * TILE_WIDTH, y * TILE_HEIGHT },
                        ROCK_SIZE,
                        ROCK_SIZE
                    },
                    0,
                    0
                };
                pattern[y][x] = 0;
                found++;
            }
        }
    }
}

bool isRockAhead(Point position, Element element)
{
    bool isRock = false;
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(rocks[i].element.width > 0 
        && gb.collide.rectRect(position.x, position.y, element.width, element.height, rocks[i].element.position.x, rocks[i].element.position.y, rocks[i].element.width, rocks[i].element.height) 
        && element.id != rocks[i].element.id)
        {
            isRock = true;
            break;
        }
    }
    return isRock;
}

void pushRock(Point position, Element element, int direction) {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(gb.collide.rectRect(position.x, position.y, element.width, element.height, rocks[i].element.position.x, rocks[i].element.position.y, rocks[i].element.width, rocks[i].element.height))
        {
            Point targetPosition = getTargetPosition(rocks[i].element.position, direction);
            if(canMove(targetPosition, rocks[i].element)) {
                switch(direction) {
                    case LEFT:
                        rocks[i].xVelocity = -4;
                        break;
                    case UP:
                        rocks[i].yVelocity = -4;
                        break;
                    case RIGHT:
                        rocks[i].xVelocity = 4;
                        break;
                    case DOWN:
                        rocks[i].yVelocity = 4;
                        break;
                }
            }
            break;
        }
    }
}

Point getTargetPosition(Point position, int direction) {
    Point targetPosition = { position.x, position.y };
    switch(direction) {
        case LEFT:
            targetPosition.x = targetPosition.x - TILE_WIDTH;
            break;
        case UP:
            targetPosition.y = targetPosition.y - TILE_HEIGHT;
            break;
        case RIGHT:
            targetPosition.x = targetPosition.x + TILE_WIDTH;
            break;
        case DOWN:
            targetPosition.y = targetPosition.y + TILE_HEIGHT;
            break;
    }
    return targetPosition;
}

void updateRocksPosition() {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(rocks[i].xVelocity != 0) {
            if(rocks[i].xVelocity > 0) {
                const int velocity = rocks[i].xVelocity;
                rocks[i].element.position.x += ROCK_MOVES[velocity];
                rocks[i].xVelocity -= 1;
            }
            else {
                const int velocity = -rocks[i].xVelocity;
                rocks[i].element.position.x -= ROCK_MOVES[velocity];
                rocks[i].xVelocity += 1;
            }

        }

        if(rocks[i].yVelocity != 0) {
            if(rocks[i].yVelocity > 0) {
                const int velocity = rocks[i].yVelocity;
                rocks[i].element.position.y += ROCK_MOVES[velocity];
                rocks[i].yVelocity -= 1;
            }
            else {
                const int velocity = -rocks[i].yVelocity;
                rocks[i].element.position.y -= ROCK_MOVES[velocity];
                rocks[i].yVelocity += 1;
            }
        }
    }
}

bool isInHole(Element element) {
    return element.width != 0
        && getPointValue(element.position.x, element.position.y) == 3 
        && getPointValue(element.position.x + element.width - 1, element.position.y) == 3
        && getPointValue(element.position.x + element.width - 1, element.position.y + element.height - 1) == 3
        && getPointValue(element.position.x, element.position.y + element.height - 1) == 3;
}

void fillHoles() {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(isInHole(rocks[i].element)) {
            pattern[rocks[i].element.position.y / TILE_HEIGHT][rocks[i].element.position.x / TILE_WIDTH] = FILLED;
            rocks[i].element.width = 0;            
        }
    }
}

void drawRocks() {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(rocks[i].element.width != 0) {
            drawRock(rocks[i]);
        }
    }
}

void drawRock(Rock rock) {
    gb.display.setColor(DARKGRAY);
    gb.display.drawImage(rock.element.position.x, rock.element.position.y, ROCK_DATA);
    // gb.display.fillRect(rock.element.position.x, rock.element.position.y, rock.element.width, rock.element.height);
}