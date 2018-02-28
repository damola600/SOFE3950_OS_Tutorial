/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Anthea Ariyajeyam (100556294) Justin Kaipada (100590167)
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(struct player *players, int num_players, char *name)
{
    for (int i = 0; i < num_players; i++)
    {
      if (strcmp(players[i].name,name) == 0)
        return true;
    }
    return false;
}

// Go through the list of players and update the score for the
// player given their name
void update_score(struct player *players, int num_players, char *name, int score)
{
  for (int i = 0; i < num_players; i++)
  {
    if (strcmp(players[i].name,name) == 0)
    {
      players[i].score = players[i].score + score;
    }
  }
}

//Printing the players score
void print_score(struct player *players,int num_players)
{
  char playerName[MAX_LEN];
  printf("______________________________________________________________________________________________________________________" );
  printf("\n\n\t\t\t\t\t\t      Score Board\n");
  for (int i = 0; i < num_players; i++)
  {
    strncpy(playerName,players[i].name,MAX_LEN);
    strtok(playerName,"\n");
    printf("\t\t\t\t\t\t\t%s: %i\n", playerName,players[i].score);
  }
}
