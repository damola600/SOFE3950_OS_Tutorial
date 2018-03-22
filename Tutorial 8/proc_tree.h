/* Operating Systems - Tutorial Activity Question 1
 * 
 * Group 1 (Wednesday)
 * Names: Anthea Ariyajeyam (100556294) Justin Kaipada 100590167
*/

#ifndef PROC_TREE_H_
#define PROC_TREE_H_

#define CATEGORIES 4
#define MAX_LEN 256

typedef struct proc
{
    char parent[MAX_LEN];       //Name of parent process
    char name[MAX_LEN];         //Name of child process
    int priotiry;               //Process priority
    int memory;                 //Memory used by process (MB)
}proc;

typedef struct proc_tree proc_tree;

struct proc_tree
{
    proc node;                      //The data (i.e. process)
    proc_tree *leftChild;           //points to the proc_tree on the left
    proc_tree *rightChild;          //points to the proc_tree on the right
      
};
#endif 

extern proc_tree *tree;         //Represents the root of the binary tree

//Operation for Proc
extern void printProc(proc process);                      //Prints the contents of the process (i.e. name, parent, priority and memory)



//Operations for proc_tree
extern void initialize_tree(proc process);                //Initialize the binary tree

extern void add_proc(proc process, proc_tree *root);      //Add proc to the binary tree according to the proc's parent

extern void printProc_Tree(proc_tree *root);              //Print the procs in the proc_tree



