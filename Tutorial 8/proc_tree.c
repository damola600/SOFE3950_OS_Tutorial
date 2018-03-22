/* Operating Systems - Tutorial Activity Question 1
 * 
 * Group 1 (Wednesday)
 * Names: Anthea Ariyajeyam (100556294) Justin Kaipada 100590167
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "proc_tree.h"


proc_tree *tree;

/* printProc
 * prints the contents of the process
*/
void printProc(proc process)
{
    printf("\tName: %s \tParent: %s \tPriority: %i \tMemory: %i\n", process.name, process.parent, process.priotiry, process.memory);
}

/* initialize_tree
 * Sets the process as the root of the binary tree
*/
void initialize_tree(proc process)
{
    if (strcmp(process.parent, "NULL") == 0)
    {
        tree->node = process;
        tree->leftChild = NULL;
        tree->rightChild = NULL;
        printf("\tprocess: root\n");
    }
}

/* add_proc
 * Adds the process to the binary tree
*/
void add_proc(proc process, proc_tree *root)
{   
    /* Finds out the name of the parent is same as the root of proc_tree, if it is it will assign the 
     * process to the left and right child of the node approperiately otherwise it will recusively call
     * this function until process is assigned
    */
    if (strcmp(process.parent, root->node.name) == 0)
    {
        proc_tree *dummy = malloc(sizeof(proc_tree));       //dummy proc_tree 
        
        //If there is no child on the left
        if(root->leftChild == NULL)
        {
            root->leftChild = dummy;
            root->leftChild->node = process;
        }

        //if there is no child on the right
        else if (root->rightChild == NULL)
        {
            root->rightChild = dummy;
            root->rightChild->node = process;
        }           
    }
 
    else
    {   
        if (root->leftChild != NULL)
            add_proc(process,root->leftChild);
        if (root->rightChild != NULL)
            add_proc(process,root->rightChild);
    }
}

/* printProc_Tree
 * prints the parent of each proc_tree in the binary tree and its children
*/
void printProc_Tree(proc_tree *root)
{
    if (root->rightChild != NULL && root->leftChild != NULL )
    {
        printf("Parent:\n");
        printProc(root->node);

        printf("\n   Children:\n");
        printProc(root->leftChild->node);
        printProc(root->rightChild->node);

        printProc_Tree(root->leftChild);
        printProc_Tree(root->rightChild);
    }
}









