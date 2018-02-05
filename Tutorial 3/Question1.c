/**
 * A small snippet to learn scaf and printf
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char first_name[20];
    int age = 0, height = 0;
    printf("Enter your first name: ");
    scanf("%19s", first_name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your height in centi-meters: ");
    scanf("%d", &height);

    printf("This is what I know..\n");
    printf("Your name is %s\n", first_name);
    printf("You are %d years old\n", age);
    printf("You are %dcms tall\n", height);

    return 0;
}
