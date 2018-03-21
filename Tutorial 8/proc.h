#ifndef PROC_HPP
#define PROC_HPP

struct Proc {
    char name[256];
    int priority;
    int pid;
    int address;
    int memory;
    int runtime;
    int suspended;
} Proc;

#endif /* PROC_HPP */
