/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, Anthea Ariyajeyam (100556294) Justin Kaipada (100590167)
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(struct player *players, int num_players);

#endif /* JEOPARDY_H_ */
