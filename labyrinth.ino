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

// GAME DATA
int currentId = 0;
bool GAME_END = false;

// PLAYER DATA
bool PLAYER_START_POSITION = false;
int PLAYER_HEIGHT = 3;
int PLAYER_WIDTH = 3;

Element player = {
  ++currentId,
  { (gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2},
  PLAYER_WIDTH,
  PLAYER_HEIGHT
};

// MAP DATA
extern int pattern[][16];
const int GRID_SIZE = 16;
const int TILE_WIDTH = gb.display.width() / GRID_SIZE;
const int TILE_HEIGHT = gb.display.height() / GRID_SIZE;

const int END = -2;
const int START = -1;
const int FLOOR = 0;
const int WALL = 1;
const int ROCK = 2;
const int HOLE = 3;

int pattern[GRID_SIZE][GRID_SIZE] = {
    {-1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 0, 2, 0, 1, 0, 1, 3, 1, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, -2, 0, 0}};

// ROCK DATA
const int MAX_ROCKS = 10;
const int ROCK_SIZE = 4;
Element rocks[MAX_ROCKS];

// GAME FUNCTIONS
void setup()
{
  gb.begin();
  initRocks();
}

void loop()
{
  while (!gb.update());
  gb.display.clear();

  if (GAME_END)
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
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) push(1, player);
    else if (gb.buttons.repeat(BUTTON_UP, 0)) push(2, player);
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) push(3, player);
    else if (gb.buttons.repeat(BUTTON_DOWN, 0)) push(4, player);
  }

  if (gb.buttons.repeat(BUTTON_LEFT, 0)) player.position = move(1, player);
  else if (gb.buttons.repeat(BUTTON_UP, 0)) player.position = move(2, player);
  else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) player.position = move(3, player);
  else if (gb.buttons.repeat(BUTTON_DOWN, 0)) player.position = move(4, player);
}

void update() {
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

  if (playerGridX >= 0 && playerGridX < GRID_SIZE &&
      playerGridY >= 0 && playerGridY < GRID_SIZE)
  {
    if (pattern[playerGridY][playerGridX] == END)
    {
      GAME_END = true;
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
  gb.display.println("  Vous avez terminé");
  gb.display.println("  le labyrinthe!");
  gb.display.println("");
  gb.display.println("  Appuyez sur A");
  gb.display.println("  pour recommencer");

  if (gb.buttons.pressed(BUTTON_A))
  {
    GAME_END = false;
    PLAYER_START_POSITION = false;
  }
}