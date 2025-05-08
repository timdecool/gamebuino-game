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

// STRUCT
struct Point
{
  int x;
  int y;
};

// VAR
Point player = {(gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2};

// GAME FUNCTIONS
void setup()
{
  gb.begin();
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
  if (gb.buttons.repeat(BUTTON_LEFT, 0)) move(1);
  else if (gb.buttons.repeat(BUTTON_UP, 0)) move(2);
  else if (gb.buttons.repeat(BUTTON_RIGHT, 0)) move(3);
  else if (gb.buttons.repeat(BUTTON_DOWN, 0)) move(4);
}

void update() {
}

void display()
{
  gb.display.fill(LIGHTGREEN);
  drawRoom();
  drawPlayer();
}

void checkWinCondition()
{
  int playerGridX = player.x / WALL_WIDTH;
  int playerGridY = player.y / WALL_HEIGHT;

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