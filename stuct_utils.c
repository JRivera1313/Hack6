/**
  * struct_utils.c
  * Author(s): Jesus Rivea III
  * Date: 03/28/2019
  *
  *
  *
  *
  */

#include "struct_utils.h"

Game *createGame(char *name, char *publisher, int publish_year)
{
  Game *new_game = (Game *)malloc(sizeof(Game *) * 1);
  new_game->name = (char *)malloc(sizeof(char) * (strlen(name) + 1)); //Allocate enough memory to copy the name (plus 1 for the null-termination character)!
  strcpy(new_game->name, name);                                       //Copy the name into the Game struct. This is done instead of new_game.name = name because it will become read-only otherwise.

  new_game->publisher = (char *)malloc(sizeof(char) * (strlen(publisher) + 1));
  strcpy(new_game->publisher, publisher);                                       .

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
  game->publisher = (*char)realloc(game->publisher, sizeof(char) * (strlen(new_publisher) + 1) )
  strcpy(game->publisher, new_publisher);
}

void lowercaseName(Game *game){

}

void destroyGame(Game **Game)
{
  free((*Game)->name);//A hint for how to approach this
}

Game *getEarliestYear(Game **games, int size){

}

Game* getLastGameName(Game** games, int size){

}

int main()
{
   //Feel free to use this as your testbed.
  return 0;
}
