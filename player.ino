void left()
{
    newPos.x = player.x - 1;
    gb.display.setCursor(6, 6);
    if(newPos.x > 0 && !getPointValue(newPos.x - 1, newPos.y) == 1) {
        player.x = newPos.x;
    }
}

void right()
{
    newPos.x = player.x + 1;
    if(newPos.x + PLAYER_WIDTH < gb.display.width() && !getPointValue(newPos.x + PLAYER_WIDTH, newPos.y) == 1) {
        player.x = newPos.x;
    }
}

void up()
{
    newPos.y = player.y - 1;
    if(newPos.y >= 0 && !getPointValue(newPos.x, newPos.y - 1) == 1) {
        player.y = newPos.y;
    }
}

void down()
{
    newPos.y = player.y + 1;
    if(newPos.y + PLAYER_HEIGHT <= gb.display.height() && !getPointValue(newPos.x, newPos.y + PLAYER_HEIGHT) == 1) {
        player.y = newPos.y;
    }
}

void drawPlayer()
{
    gb.display.fillRect(player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT);
}