void left()
{
    player.x -= 1;
}

void right()
{
    player.x += 1;
}

void up()
{
    player.y -= 1;
}

void down()
{
    player.y += 1;
}

void drawPlayer()
{
    gb.display.fillRect(player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT);
}