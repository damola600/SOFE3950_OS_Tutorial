/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Anthea Ariyajeyam (100556294) Justin Kaipada (100590167)
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256

// Player struct for each player
struct player {
    char name[MAX_LEN];
    int score;
};

// Returns true if the player name matches one of the existing players
extern bool player_exists(struct player *players, int num_players, char *name);

// Go through the list of players and update the score for the
// player given their name
extern void update_score(struct player *players, int num_players, char *name, int score);

//Print user scores
extern void print_score(struct player *players,int num_players);
#endif /* PLAYERS_H_ */
