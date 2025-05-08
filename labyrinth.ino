#include <Gamebuino-Meta.h>

// CONST
int PLAYER_HEIGHT = 3;
int PLAYER_WIDTH = 3;

// STRUCT
struct Point
{
  int x;
  int y;
};

// VAR
Point player = {(gb.display.width() - PLAYER_WIDTH / 2) / 2, (gb.display.height() - PLAYER_HEIGHT / 2) / 2};
Point newPos = player;

// GAME FUNCTIONS
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
  if (gb.buttons.repeat(BUTTON_LEFT, 0))
  {
    left();
  }
  else if (gb.buttons.repeat(BUTTON_RIGHT, 0))
  {
    right();
  }
  else if (gb.buttons.repeat(BUTTON_UP, 0))
  {
    up();
  }
  else if (gb.buttons.repeat(BUTTON_DOWN, 0))
  {
    down();
  }
}

void update() {
}

void display()
{
  drawPlayer();
  drawRoom();
}