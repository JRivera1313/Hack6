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
// given  title, author, word count, outputs a Game struct that contains said information.
Game *createGame (char *name, char *publisher, int publish_year);

//Prints out informations about a ?book?.
void printGame (Game * game);

// given a game struct and an integer value, will change the word_count of said book.
void changePublishYear(Game* game, int new_year);

//given a game struct and a string (or char*), will change the author of said book
void changePublisher(Game* game, char* new_publisher);

// given a game struct, will modify its name to be all lowercase letters
void lowercaseName(Game* game);

//given a POINTER to a game struct, will "destroy" the struct via freeing all allocated memory
void destroyGame(Game** game);

// takes in an array of Game structs (called games), and returns the Game with the earliest publish year
Game* getEarliestYear(Game** games, int size);

// takes in an array of Game structs (called games), and returns the Game with the title that would appear last according to lexicographic sorting.
Game* getLastGameName(Game** games, int size);
