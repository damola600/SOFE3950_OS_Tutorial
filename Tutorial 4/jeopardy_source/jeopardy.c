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
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"
#include "font.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4



// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens)
{
  char *token[2] = {"?","what is "};
  tokens = &(token[0]);
  input = strtok(input,*tokens);

  tokens = &(token[1]);
  unsigned int index = (int)strlen(*tokens);

  if (strlen(input) > index +1)
  {
    strncpy(input,&(input[index]),strlen(input)-index+1);
  }


}


// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players)
{

  //Finding the user with the highest score using bubble sort
  for (int j = 0; j < num_players-1; j++)
  {
    for (int i = 0; i < num_players-j-1; i++)
    {
      if (players[i].score < players[i+1].score)
      {
        struct player temp = *(players + i);
        *(players + i) = *(players +(i+1));
        *(players + (i+1)) = temp;
      }
    }

  }
  //Prints score
  print_score(players,num_players);
  strtok(players[0].name, "\n");
  printf(boldGreen);
  printf("\n\n\t\t\t\t\t\t THE WINNER IS %s!\n\n",players[0].name );
}


//Declaring Variables
int game_state;



int main(int argc, char *argv[])
{
    //Allocating memeory for players and questions pointers
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player *players = malloc(NUM_PLAYERS * sizeof(struct player));
    questions = malloc(NUM_QUESTIONS *sizeof(question));
    char *category = malloc(MAX_LEN *sizeof(char));
    char *value = malloc(sizeof(int));
    char **tokens = malloc(2 * sizeof (char*));
    char *userAnswer;
    int currentPlayer = 0;
    int valueAsInt = 0;
    int location = 0;
    int numofQuestions = 0;
    char buffer[BUFFER_LEN] = { 0 }; // Buffer for user input
    char playerName[NUM_PLAYERS];

    bool validInput = true;
    int count = 0;

    // Display the game introduction and initialize the questions
    initialize_game();


    // Prompt for players names
    printf("Enter player names\n");
    printf("Player 1: ");
    fgets(players[0].name, BUFFER_LEN, stdin);

    for (int i = 1; i < NUM_PLAYERS; i++ )
    {
      printf("Player %i: ",i +1 );

      // Verify that the player does not already exists using the player_exists()
      fgets(playerName, BUFFER_LEN, stdin);

      if (player_exists(players, i,playerName))
      {
        printf("\nName already exists please enter another\n");
        i--;
      }

      else
      {
        strcpy(players[i].name,playerName);
      }
    }

    // initialize each of the players in the array with a score of zero
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
      players[i].score = 0;
    }


    system("clear");
    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    while (game_state)
    {
        //Print categories & score board
        printf(yellow);
        display_categories();
        print_score(players,NUM_PLAYERS);


        //User Input - the player picks the category and value
        printf("\nSelect a category and value %s\n",players[currentPlayer].name);

        while (validInput)
        {
          printf("\ncategory:");
          fgets(category, MAX_LEN, stdin);
          printf("value:");
          fgets(value, MAX_LEN, stdin);

          valueAsInt = atoi(value);
          category = strtok(category,"\n");

          for (int i = 0; i < NUM_CATEGORIES; i++)
          {
            if (strcmp(categories[i],category) == 0)
              count++;
          }
          if (valueAsInt == 100 || valueAsInt == 200 || valueAsInt == 400 || valueAsInt == 300)
            count++;

          if (count == 2)
          {
            validInput = already_answered(category,valueAsInt);
            if (validInput == true)
              printf("\n\nQuestion has already been answerd\n");
          }

          else
            printf("\n\nInvalid input. Try again.\n");

          count = 0;
        }

        //Display Question
        system("clear");
        display_question(category,valueAsInt);

        //User input - Their answer
        printf("Answer:");
        fgets(buffer, BUFFER_LEN, stdin);


        //Validate User's answer
        //tokenizing user's input
        userAnswer = buffer;
        tokenize(userAnswer,tokens);

        //comparing user's answer with the correct answer and updating score apporaiately
        if (valid_answer(category,valueAsInt,userAnswer))
        {
          printf(white);
          printf("\nCORRECT!\n");
          update_score(players,NUM_PLAYERS,players[currentPlayer].name, valueAsInt);
          printf("Your current score is: %i\n",players[currentPlayer].score);
        }
        else
        {
          printf(red);
          printf("\nINCORRECT\n");
          location = searchQuestion(category,valueAsInt);
          printf("The correct answer is: What is %s?\n",questions[location].answer);
        }
        printf("\n\nPress any key to continue\n");
        getchar();

        //Players
        currentPlayer++;
        if (currentPlayer == 4)
          currentPlayer = 0;
        system("clear");

        // Execute the game until all questions are answered
        numofQuestions++;

        // Display the final results and exit
        if (numofQuestions == NUM_QUESTIONS)
        {
          printf(white);
          show_results(players, NUM_PLAYERS);
          game_state = 0;
        }

        validInput = true;

    }



    free(players);
    free(questions);
    free(category);
    free(value);
    free(tokens);

    return EXIT_SUCCESS;
}
