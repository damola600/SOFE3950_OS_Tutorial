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
#include "questions.h"
#include "font.h"

/*  initialize_game()
      - Initializes the array of questions for the game by gathering the questions
      from the files: databases_questions.txt, programming_questions.txt and
      algorithms_questions.txt
*/
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    FILE *fp;
    char fileNames[3][MAX_LEN] = {"programming_questions.txt","algorithms_questions.txt","databases_questions.txt"};
    char str[MAX_LEN];
    int lineCounter = 1;
    int index = 0;



    for (int i = 0; i < 3; i++)
    {
      char *fileName = fileNames[i];

      fp = fopen(fileName, "r");
      if (fp == NULL)
      {
        printf("Error: %s\n", fileName);
        exit(0);
      }

      while(fgets(str, MAX_LEN, fp) != NULL)
      {
        /*Adding questions, answers, value and category from the files
          to struct question questions
        */
        if (lineCounter % 4 == 1)
          strncpy(questions[index].question,str,strlen(str));

        else if (lineCounter % 4 == 2)
          strncpy(questions[index].answer,str,strlen(str)-1);

        else if (lineCounter % 4 == 3)
        {
          questions[index].value = atoi(str);
          questions[index].answered = false;
          strcpy(questions[index].category,categories[i]);
        }
        else
          index++;

        lineCounter++;
      }

      fclose(fp);
      lineCounter = 1;
      index++;

    }
}


// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    int count = 0;
    int qindex = 0;
    int index[NUM_CATEGORIES];

    // print categories and dollar values for each unanswered question in questions array
    printf("\n\n");
    printf("\t\t\t\t\t\t\t J E O P A R D Y!");
    printf("\n\n\n");

    for (int i = 0; i < NUM_CATEGORIES; i++)
      printf("\t%s\t\t\t\t",categories[i] );
    printf("\n");

    for (int j = 1; j <= NUM_VALUES; j++ )
    {

      if (j == 1)
      {
        index[0] = 0;
        index[1] = 4;
        index[2] = 8;
      }
      else if (j == 2)
      {
        index[0] = 1;
        index[1] = 5;
        index[2] = 9;
      }
      else if (j == 3)
      {
        index[0] = 2;
        index[1] = 6;
        index[2] = 10;
      }

      else
      {
        index[0] = 3;
        index[1] = 7;
        index[2] = 11;
      }



      for (int k = 0; k < NUM_CATEGORIES; k++)
      {
        qindex = index[k];
        if (already_answered(questions[qindex].category,j*100) == false)
          printf("\t   %i\t\t\t\t\t", j*100 );
        else
          printf("\t    -\t\t\t\t\t");
        count++;
      }
      printf("\n");
    }




}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
  printf(blue);
  int i = searchQuestion(category,value);
  printf("QUESTION: %s\n",questions[i].question);
  questions[i].answered = true;
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    int i = searchQuestion(category,value);


    if (strcmp(answer,questions[i].answer) == 0)
      return true;

    else
      return false;

}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    //Make category (parameter) lowercase

    // lookup the question and see if it's already been marked as answered
    int i = searchQuestion(category,value);
    return questions[i].answered;
}


int searchQuestion (char *category, int value)
{
  for (int i = 0; i < NUM_QUESTIONS; i++)
  {
    if ((strcmp(questions[i].category,category) == 0 ) && (questions[i].value == value))
      return i;
  }
  return -1;
}
