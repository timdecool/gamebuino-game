#include <Gamebuino-Meta.h>

// CONST
int PLAYER_HEIGHT = 3;
int PLAYER_WIDTH = 3;
bool GAME_END = false;
extern const int GRID_SIZE;
extern const int WALL_WIDTH;
extern const int WALL_HEIGHT;
extern int pattern[][16];
extern bool PLAYER_START_POSITION;
int currentId = 0;

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

// VAR
Element player = {
  ++currentId,
  { (gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2},
  PLAYER_WIDTH,
  PLAYER_HEIGHT
};

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
  int playerGridX = player.position.x / WALL_WIDTH;
  int playerGridY = player.position.y / WALL_HEIGHT;

  if (playerGridX >= 0 && playerGridX < GRID_SIZE &&
      playerGridY >= 0 && playerGridY < GRID_SIZE)
  {
    if (pattern[playerGridY][playerGridX] == 5)
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