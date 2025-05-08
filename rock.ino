void initRocks() {
    int found = 0;
    for(int y = 0; y < GRID_SIZE; y++) {
        for(int x = 0; x < GRID_SIZE; x++) {
            if(pattern[y][x] == 2) {
                rocks[found] = {
                    ++currentId,
                    { x * TILE_WIDTH, y * TILE_HEIGHT },
                    ROCK_SIZE,
                    ROCK_SIZE
                };
                pattern[y][x] = 0;
                found++;
            }
        }
    }
}

bool isRockAhead(Point position, Element element) {
    bool isRock = false;
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(rocks[i].width > 0 
        && gb.collide.rectRect(position.x, position.y, element.width, element.height, rocks[i].position.x, rocks[i].position.y, rocks[i].width, rocks[i].height) 
        && element.id != rocks[i].id)
        {
            isRock = true;
            break;
        }
    }
    return isRock;
}

Element pushRock(Point position, Element element, int direction) {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(gb.collide.rectRect(position.x, position.y, element.width, element.height, rocks[i].position.x, rocks[i].position.y, rocks[i].width, rocks[i].height))
        {
            rocks[i].position = move(direction, rocks[i]);
            break;
        }
    }
}

bool isInHole(Element element) {
    return getPointValue(element.position.x, element.position.y) == 3 
        && getPointValue(element.position.x + element.width - 1, element.position.y) == 3
        && getPointValue(element.position.x + element.width - 1, element.position.y + element.height - 1) == 3
        && getPointValue(element.position.x, element.position.y + element.height - 1) == 3;
}

void fillHoles() {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(isInHole(rocks[i])) {
            pattern[rocks[i].position.y / TILE_HEIGHT][rocks[i].position.x / TILE_WIDTH] = FLOOR;
            rocks[i].width = 0;            
        }
    }
}

void drawRocks() {
    for(int i = 0; i < MAX_ROCKS; i++) {
        if(rocks[i].width != 0) {
            drawRock(rocks[i]);
        }
    }
}

void drawRock(Element rock) {
    gb.display.setColor(DARKGRAY);
    gb.display.fillRect(rock.position.x, rock.position.y, rock.width, rock.height);
}