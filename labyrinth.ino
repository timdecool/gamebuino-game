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
const int MAX_LEVEL = 10;
int currentId = 0;
int currentLevel = 0;
bool levelEnd = false;
bool gameStarted = false;

// PLAYER DATA
const int PLAYER_HEIGHT = 3;
const int PLAYER_WIDTH = 3;

Element player = {
    ++currentId,
    {(gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2},
    PLAYER_WIDTH,
    PLAYER_HEIGHT};

// MAP DATA

const int GRID_SIZE = 16;
extern const int maps[MAX_LEVEL][GRID_SIZE][GRID_SIZE];
const int TILE_WIDTH = gb.display.width() / GRID_SIZE;
const int TILE_HEIGHT = gb.display.height() / GRID_SIZE;

const int END = -2;
const int START = -1;
const int FLOOR = 0;
const int WALL = 1;
const int ROCK = 2;
const int HOLE = 3;

int pattern[GRID_SIZE][GRID_SIZE];

// ROCK DATA
const int MAX_ROCKS = 10;
const int ROCK_SIZE = 4;
Element rocks[MAX_ROCKS];

// GAME FUNCTIONS
void setup()
{
  gameStarted = true;
  gb.begin();
  initLevel();
}

void loop()
{
  while (!gb.update())
    ;
  gb.display.clear();

  if (gameStarted)
  {
    displayWelcomeScreen();
  }
  else if (levelEnd)
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
  if (gb.buttons.repeat(BUTTON_A, 0))
  {
    if (gb.buttons.repeat(BUTTON_LEFT, 0))
      push(1, player);
    else if (gb.buttons.repeat(BUTTON_UP, 0))
      push(2, player);
    else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
      push(3, player);
    else if (gb.buttons.repeat(BUTTON_DOWN, 0))
      push(4, player);
  }

  if (gb.buttons.repeat(BUTTON_LEFT, 0))
    player.position = move(1, player);
  else if (gb.buttons.repeat(BUTTON_UP, 0))
    player.position = move(2, player);
  else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
    player.position = move(3, player);
  else if (gb.buttons.repeat(BUTTON_DOWN, 0))
    player.position = move(4, player);

  if (gb.buttons.pressed(BUTTON_B))
  {
    initLevel();
  }
}

void update()
{
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
      levelEnd = true;
    }
  }
}

void displayWinScreen()
{
  gb.display.clear();
  gb.display.setColor(YELLOW);
  gb.display.setCursor(10, 5);
  gb.display.println("FELICITATIONS!");
  gb.display.setCursor(5, 20);
  gb.display.println("Vous avez fini le");
  gb.display.setCursor(5, 30);
  gb.display.println("labyrinthe !");
  gb.display.setColor(GREEN);
  gb.display.setCursor(5, 50);
  gb.display.println("Appuyez sur A pour continuer");

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
    gameStarted = false;
  }
}