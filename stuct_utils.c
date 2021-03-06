/**
  * struct_utils.c
  * Author(s): Jesus Rivea III
  * Date: 03/28/2019
  *
  *Function bodys that do verious things.
  *
  *
  */

#include "struct_utils.h"

Game *createGame(char *name, char *publisher, int publish_year)
{
  Game *new_game = (Game *)malloc(sizeof(Game *) * 1);
  new_game->name = (char *)malloc(sizeof(char) * (strlen(name) + 1)); //Allocate enough memory to copy the name (plus 1 for the null-termination character)!
  strcpy(new_game->name, name);                                       //Copys the name into the Game struct. This is done instead of new_game.name = name because it will become read-only otherwise.

  new_game->publisher = (char *)malloc(sizeof(char) * (strlen(publisher) + 1));
  strcpy(new_game->publisher, publisher);

  new_game->publish_year = publish_year;

  return new_game;
}
void printGame(Game *Game){
  printf("%s\n", Game->name);
  printf("%s\n", Game->publisher);
  printf("%d\n", Game->publish_year);
}

void changePublishYear(Game *game, int new_count){
  game->publish_year = new_count;
}

void changePublisher(Game *game, char *new_publisher){
  //Creates enough memory space for new publisher name
  game->publisher = (char*)realloc(game->publisher, sizeof(char) * (strlen(new_publisher) + 1) );
  strcpy(game->publisher, new_publisher);
}

void lowercaseName(Game *game){
  int length = strlen(game->name);
  //itterates through each letter of the name string changing them to their lowercase form.
  for (int i = 0; i < length; i++) {
    game->name[i] = tolower(game->name[i]);
  }
}

void destroyGame(Game **Game)
{
  free((*Game)->name);
  free((*Game)->publisher);
  *Game = NULL;
}

Game *getEarliestYear(Game **games, int size){
  Game *EaryYear = games[0];
  //cycles throguh each game, compareing their year to the lowest found one thus far.
  for (int i = 0; i < size; i++) {
    if (games[i]->publish_year < EaryYear->publish_year ) {
      EaryYear = games[i];
    }
  }
  return EaryYear;
}

Game* getLastGameName(Game** games, int size){
  Game *EaryYear = games[0];
  //cycles throguh each game, compareing their name to the lowest found one thus far.
  for (int i = 0; i < size; i++) {
    if (strcmp(games[i]->name,EaryYear->name) > 0 ) {
      EaryYear = games[i];
    }
  }
  return  EaryYear;
}

int main()
{
  char TestName[]="TestName";
  char TestPublisher[] ="TestPublisher";
   Game *TestGame = createGame(TestName,TestPublisher, 2000);
   printGame(TestGame);

   char TestCAPS[]="DOOM";

   Game *TestGameCAPS = createGame(TestCAPS,TestPublisher, 1234);
   lowercaseName(TestGameCAPS);

   printGame(TestGameCAPS);
   destroyGame(&TestGame);

  return 0;
}
