#include <Gamebuino-Meta.h>

// STRUCT
struct Point
{
  int x;
  int y;
};

struct Element 
{
  int id;
  Point position;
  int width;
  int height;
};

struct Rock {
  Element element;
  int xVelocity;
  int yVelocity;
};


// GAME DATA
const int MAX_LEVEL = 10;
int currentId = 0;
int currentLevel = 0;
bool levelEnd = false;

const int LEFT = 1;
const int UP = 2;
const int RIGHT = 3;
const int DOWN = 4;

// PLAYER DATA
const int PLAYER_HEIGHT = 6;
const int PLAYER_WIDTH = 6;

Element player = {
  ++currentId,
  { (gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2},
  PLAYER_WIDTH,
  PLAYER_HEIGHT
};

// MAP DATA

const int GRID_X = 10;
const int GRID_Y = 8;
extern const int maps[MAX_LEVEL][GRID_Y][GRID_X];
const int TILE_WIDTH = gb.display.width() / GRID_X;
const int TILE_HEIGHT = gb.display.height() / GRID_Y;

const int END = -2;
const int START = -1;
const int FLOOR = 0;
const int WALL = 1;
const int ROCK = 2;
const int HOLE = 3;

int pattern[GRID_Y][GRID_X];

// ROCK DATA
const int MAX_ROCKS = 10;
const int ROCK_SIZE = 8;
Rock rocks[MAX_ROCKS];

// GAME FUNCTIONS
void setup()
{
  gb.begin();
  initLevel();
}

void loop()
{
  while (!gb.update());
  gb.display.clear();

  if (levelEnd)
  {
    displayWinScreen();
  }
  else
  {
    input();
    update();
    checkWinCondition();
    display();
  }
}

void input()
{
  if(gb.buttons.repeat(BUTTON_A, 0)) {
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) push(LEFT, player);
    else if (gb.buttons.repeat(BUTTON_UP, 0)) push(UP, player);
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) push(RIGHT, player);
    else if (gb.buttons.repeat(BUTTON_DOWN, 0)) push(DOWN, player);
  }

  if (gb.buttons.repeat(BUTTON_LEFT, 0)) player.position = move(LEFT, player);
  else if (gb.buttons.repeat(BUTTON_UP, 0)) player.position = move(UP, player);
  else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) player.position = move(RIGHT, player);
  else if (gb.buttons.repeat(BUTTON_DOWN, 0)) player.position = move(DOWN, player);

  if(gb.buttons.pressed(BUTTON_B)) {
    initLevel();
  }
}

void update() {
  updateRocksPosition();
  fillHoles();
}

void display()
{
  gb.display.fill(LIGHTGREEN);
  drawRoom();
  drawRocks();
  drawPlayer();
}

void checkWinCondition()
{
  int playerGridX = player.position.x / TILE_WIDTH;
  int playerGridY = player.position.y / TILE_HEIGHT;

  if (playerGridX >= 0 && playerGridX < GRID_X &&
      playerGridY >= 0 && playerGridY < GRID_Y)
  {
    if (pattern[playerGridY][playerGridX] == END)
    {
      levelEnd = true;
    }
  }
}

void displayWinScreen()
{
  gb.display.clear();
  gb.display.setColor(WHITE);
  gb.display.println("");
  gb.display.println("  FELICITATIONS!");
  gb.display.println("");
  gb.display.println("  Vous avez fini");
  gb.display.println("  le labyrinthe!");
  gb.display.println("");
  gb.display.println("  Appuyez sur A");
  gb.display.println("  pour continuer");

  if (gb.buttons.pressed(BUTTON_A))
  {
    currentLevel++;
    levelEnd = false;
    if(currentLevel < MAX_LEVEL) {
      initLevel();
    }
  }
}