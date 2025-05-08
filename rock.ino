extern const int GRID_SIZE;
extern const int WALL_WIDTH;
extern const int WALL_HEIGHT;
extern int pattern[][16];

int ROCK_SIZE = 4;
Element rocks[10];

void initRocks() {
    int found = 0;
    for(int y = 0; y < GRID_SIZE; y++) {
        for(int x = 0; x < GRID_SIZE; x++) {
            if(pattern[y][x] == 2) {
                rocks[found] = {
                    ++currentId,
                    { x * WALL_WIDTH, y * WALL_HEIGHT },
                    ROCK_SIZE,
                    ROCK_SIZE
                };
                pattern[y][x] = 0;
                found++;
            }
        }
    }
}

bool isRock(Point position, Element element) {
    bool isRock = false;
    for(int i = 0; i < 10; i++) {
        if(gb.collide.rectRect(position.x, position.y, element.width, element.height, rocks[i].position.x, rocks[i].position.y, rocks[i].width, rocks[i].height) && element.id != rocks[i].id)
        {
            isRock = true;
            break;
        }
    }
    return isRock;
}

Element pushRock(Point position, Element element, int direction) {
    for(int i = 0; i < 10; i++) {
        if(gb.collide.rectRect(position.x, position.y, element.width, element.height, rocks[i].position.x, rocks[i].position.y, rocks[i].width, rocks[i].height))
        {
            rocks[i].position = move(direction, rocks[i]);
            break;
        }
    }
}

void drawRocks() {
    for(int i = 0; i < 10; i++) {
        if(rocks[i].width != 0) {
            drawRock(rocks[i]);
        }
    }
}

void drawRock(Element rock) {
    gb.display.setColor(DARKGRAY);
    gb.display.fillRect(rock.position.x, rock.position.y, rock.width, rock.height);
}