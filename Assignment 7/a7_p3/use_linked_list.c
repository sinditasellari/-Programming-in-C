/*
   CH-230-A
   a7 p3.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main () {
    struct list *special_list=NULL;
    int n=1;

    while(n)
    {
        char c;
        scanf("%c", &c); /* Getting the input */

        int x1, x2;

        switch(c)
        {
        case 'a':
            scanf("%d", &x1);
            special_list = push_back(special_list, x1);
            break;

        case 'b' :
            scanf("%d", &x2);
            special_list = push_front(special_list, x2);
            break;

        case 'r':
            special_list = delete_firstel(special_list);
            break;

        case 'p':
            print_list(special_list);
            break;

        case 'q':
            dispose_list(special_list);
            n=0;
            break;
        }
    }
    return 0;
}