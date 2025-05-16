#include <Gamebuino-Meta.h>
#include "./sprites.h"


// ---------------------
// STRUCT
// ---------------------
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

struct Player {
  Element element;
  bool moving;
  int direction;
};


// ----------------------
// GAME DATA
// ----------------------
const int MAX_LEVEL = 10;
int currentId = 0;
int currentLevel = 0;
bool levelEnd = false;
bool gameStarted = false;

const int LEFT = 1;
const int UP = 2;
const int RIGHT = 3;
const int DOWN = 4;

// PLAYER DATA
const int PLAYER_HEIGHT = 6;
const int PLAYER_WIDTH = 6;

Player player = {
  {
    ++currentId,
    { (gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2},
    PLAYER_WIDTH,
    PLAYER_HEIGHT
  },
  false,
  RIGHT
};


// --------------------------
// MAP DATA
// --------------------------

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
const int FILLED = -3;

int pattern[GRID_Y][GRID_X];

// ROCK DATA
Image avatar(PLAYER_DATA);

const int MAX_ROCKS = 10;
const int ROCK_SIZE = 8;
Rock rocks[MAX_ROCKS];


// -------------------------
// GAME FUNCTIONS
// -------------------------

void setup()
{
  gb.begin();
}

void loop()
{
  while (!gb.update());
  gb.display.clear();

  input();
  update();
  display();
}

void input()
{
  if(gb.buttons.repeat(BUTTON_A, 0)) {
    if (gb.buttons.repeat(BUTTON_LEFT, 0)) push(LEFT, player.element);
    else if (gb.buttons.repeat(BUTTON_UP, 0)) push(UP, player.element);
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) push(RIGHT, player.element);
    else if (gb.buttons.repeat(BUTTON_DOWN, 0)) push(DOWN, player.element);
  }

  if (gb.buttons.repeat(BUTTON_LEFT, 0)) {
    player.element.position = move(LEFT, player.element);
    player.moving = true;
    player.direction = LEFT;
  }
  else if (gb.buttons.repeat(BUTTON_UP, 0)) {
    player.element.position = move(UP, player.element);
    player.moving = true;
  }
  else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) {
    player.element.position = move(RIGHT, player.element);
    player.moving = true;
    player.direction = RIGHT;
  }
  else if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
     player.element.position = move(DOWN, player.element);
     player.moving = true;
  }
  else {
    player.moving = false;
  }

  if (gb.buttons.pressed(BUTTON_B))
  {
    initLevel();
  }
}

void update() {
  updateRocksPosition();
  fillHoles();
  checkWinCondition();
}

void display()
{
  if(!gameStarted) displayWelcomeScreen();
  else if(levelEnd) displayWinScreen();
  else 
  {
    gb.display.fill(LIGHTGREEN);
    drawRoom();
    drawRocks();
    drawPlayer();
  }
}

void checkWinCondition()
{
  int playerGridX = player.element.position.x / TILE_WIDTH;
  int playerGridY = player.element.position.y / TILE_HEIGHT;

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
  gb.display.setFontSize(1);
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
    if (currentLevel < MAX_LEVEL)
    {
      initLevel();
    }
  }
}

void displayWelcomeScreen()
{
  gb.display.clear();

  gb.display.setColor(YELLOW);
  gb.display.setCursor(10, 5);
  gb.display.println("LABYRINTHE");

  gb.display.setColor(WHITE);
  gb.display.setCursor(5, 20);
  gb.display.println("CROIX: DEPLAC.");
  gb.display.setCursor(5, 30);
  gb.display.println("A+CROIX: POUSSER");

  gb.display.setColor(GREEN);
  gb.display.setCursor(5, 40);
  gb.display.println("A: JOUER");

  if (gb.buttons.pressed(BUTTON_A))
  {
    initLevel();
    gameStarted = true;
  }
}