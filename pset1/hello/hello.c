#include <stdio.h>
#include <cs50.h>
int main(void)
{
    //prompts the user for their name
    string name= get_string("What's your name?");
    //prints hello, user name
    printf("hello, %s\n", name);
}