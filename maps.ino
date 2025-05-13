const int maps[MAX_LEVEL][GRID_Y][GRID_X] = {
       {
        { START, FLOOR,  WALL,  WALL, FLOOR, FLOOR,  WALL,  WALL,  WALL,   END},
        { FLOOR,  ROCK,  FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  HOLE},
        { FLOOR, FLOOR,  FLOOR, FLOOR,  WALL,  WALL, FLOOR, FLOOR, FLOOR, FLOOR},
        { FLOOR, FLOOR,  WALL,  WALL, FLOOR,  WALL, FLOOR, FLOOR, FLOOR, FLOOR},
        { FLOOR, FLOOR,  HOLE,  ROCK, FLOOR, FLOOR, FLOOR,  ROCK, FLOOR, FLOOR},
        {  WALL,  WALL,  WALL,  WALL, FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR},
        { FLOOR, FLOOR, FLOOR,  WALL,  WALL,  WALL,  WALL,  WALL, FLOOR, FLOOR},
        { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR}
       },
       {
        { START, FLOOR, FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR,   END, FLOOR},
        { FLOOR,  ROCK, FLOOR,  ROCK, FLOOR,  WALL, FLOOR, FLOOR, FLOOR, FLOOR},
        { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR, FLOOR, FLOOR},
        { FLOOR,  ROCK, FLOOR, FLOOR, FLOOR,  WALL,  WALL,  HOLE,  WALL,  WALL},
        {  WALL,  WALL,  HOLE,  HOLE,  HOLE,  WALL, FLOOR, FLOOR, FLOOR, FLOOR},
        { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR, FLOOR, FLOOR},
        {  WALL, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  WALL},
        {  WALL,  WALL, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  WALL,  WALL}
       },
       {
        { FLOOR, FLOOR, FLOOR,  WALL,  WALL,  WALL,  WALL,  WALL, FLOOR,   END},
        { START, FLOOR, FLOOR,  WALL,  WALL, FLOOR, FLOOR,  WALL, FLOOR, FLOOR},
        { FLOOR,  ROCK, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR},
        { FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR, FLOOR,  WALL,  HOLE,  WALL},
        { FLOOR, FLOOR, FLOOR,  WALL,  HOLE,  WALL,  WALL,  WALL, FLOOR, FLOOR},
        {  WALL,  WALL, FLOOR,  WALL, FLOOR, FLOOR,  WALL,  WALL, FLOOR, FLOOR},
        { FLOOR, FLOOR,  ROCK, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  HOLE},
        {  WALL, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR,  WALL}
       },
       {
        { START, FLOOR,  WALL,  WALL,  WALL,  WALL,  WALL, FLOOR,   END, FLOOR},
        { FLOOR, FLOOR,  WALL,  WALL,  WALL,  WALL,  WALL, FLOOR, FLOOR, FLOOR},
        {  WALL, FLOOR, FLOOR,  ROCK, FLOOR, FLOOR,  WALL, FLOOR,  HOLE, FLOOR},
        {  WALL, FLOOR,  ROCK, FLOOR,  ROCK,  ROCK,  WALL,  WALL,  HOLE,  WALL},
        {  WALL, FLOOR,  ROCK, FLOOR, FLOOR,  ROCK,  WALL, FLOOR,  HOLE, FLOOR},
        {  WALL, FLOOR, FLOOR,  ROCK,  ROCK,  ROCK,  HOLE, FLOOR, FLOOR, FLOOR},
        {  WALL, FLOOR, FLOOR,  ROCK, FLOOR, FLOOR,  WALL, FLOOR, FLOOR, FLOOR},
        {  WALL,  WALL,  WALL, FLOOR, FLOOR, FLOOR,  WALL, FLOOR, FLOOR, FLOOR}        
       }
    // {
    //     {-1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    //     {0, 0, 0, 2, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 3, 1},
    //     {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, -2, 1}
    // },
    // { 
    //     {-1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //     {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    //     {1, 0, 0, 0, 1, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 0},
    //     {1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1},
    //     {0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 1, 0, 0, 0, 0},
    //     {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    //     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    //     {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
    //     {1, 0, 2, 0, 1, 0, 1, 3, 1, 0, 0, 0, 0, 0, 1, 0},
    //     {1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    //     {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0},
    //     {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0},
    //     {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    //     {0, 0, 0, 0, 1, 1, 1, 1, 0, 3, 0, 0, 1, -2, 0, 0}
    // }
};

// {
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR},
//   { FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR}
// }
  


void initLevel() {
  for(int i = 0; i < GRID_X; i++) {
    for(int j = 0; j < GRID_Y; j++) {
      pattern[j][i] = maps[currentLevel][j][i];
    }
  }
  initRocks();
  initPlayer();
}