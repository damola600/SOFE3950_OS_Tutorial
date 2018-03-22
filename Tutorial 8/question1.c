/* Operating Systems - Tutorial Activity Question 1
 * 
 * Group 1 (Wednesday)
 * Names: Anthea Ariyajeyam (100556294) Justin Kaipada 100590167
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proc_tree.h"



int main ()
{
    //Defining variables and pointers
    char buffer[MAX_LEN];   //Used to store the contents from process_tree.txt
    void *info;             //Contains the tokenized information from process_tree.txt
    int cpylen;             //Contains the number chars in void *infor
    int count = 0;          //Used to ensure the binary tree is initiallized once
    proc process;           //Contains the process being add to the binary tree
    
    

    //Read process.txt
    FILE * proTreeFD = fopen("processes_tree.txt","r");

    if (proTreeFD == NULL)
    {
        printf("Error");
        exit(0);
    }

    while (fgets(buffer, MAX_LEN, proTreeFD))
    {
        //Gathering contents from buffer to be assigned to properties of struct process
        for (int i = 0; i < CATEGORIES; i++)
        {
            info = strtok(buffer, ", ");
            
            if (i == 0)
                strcpy(process.parent, info);

            else if (i == 1)
                strcpy(process.name,info);

            else if (i == 2)
                process.priotiry = atoi(info);

            else
                process.memory = atoi(info);

            cpylen = strlen(info);
            strcpy(buffer,&buffer[cpylen+2]);
        }
        
        //Ensures that the tree is initialized only once
        if (count == 0)
        {
            tree = malloc(sizeof(proc_tree));
            initialize_tree(process);
            count++;
        }

        //Add process
        add_proc(process, tree);
    }

    //Print tree
    printProc_Tree(tree);
    
    free(tree);
    fclose(proTreeFD);
    

    return 0;
}