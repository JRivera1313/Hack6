/**
  * struct_utils.h
  * Author(s): Jesus Rivea III
  * Date: 03/28/2019
  *
  *
  *
  *
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
  char *name;
  char *publisher;
  int publish_year;
} Game;

Game *createGame (char *name, char *publisher,
		  int publish_year);
void printGame (Game * game);
void destroyGame(Game** game);
void changePublishYear(Game* game, int new_year);
void changePublisher(Game* game, char* new_publisher);
void lowercaseName(Game* game);
Game* getEarliestYear(Game** games, int size);
Game* getLastGameName(Game** games, int size);
