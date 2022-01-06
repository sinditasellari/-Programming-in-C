/*
   CH-230-A
   a8 p9.c
   Sindi Tasellari
   stasellari@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE **fptr, *output;

    int n;
    scanf("%d", &n);
    getchar();

    int i = 0, flag = 0, idx;
    char fname[20];
    char buff[64];
    memset(buff, '\0', 64);

    /* Dynamic memory allocation */
    fptr = (FILE**)malloc(sizeof(FILE) * n);

    output = fopen("output.txt", "w"); // open file

    /* Getting the name of the files */
    for (idx=0; idx<n; idx++)
    {
        fgets(fname, 20, stdin);
        fname[strlen(fname)-1] = '\0';
        /* Opening the files */
        fptr[idx] = fopen(fname, "r");
        if(fptr[idx]==NULL)
        {
            printf("Error on %d file", idx+1);
            exit(1);
        }
    }

    int a = 0;
    /* Taking the content from the files and writing it on the other file */
    while(i!=n)
    {
        flag = 0;
        memset(buff, '\0', 64);

        while (fread(buff, 64, 1, fptr[i])==0)
        {
            fwrite(buff, 1, 64, output);
            fprintf(output, "\r");
            printf("%s\n", buff);
            memset(buff, '\0', 64);
            i++;
            flag = 1;
            
            if(i==n)
            {
                break;
                a=1;
            }
        }

        if(flag==1)
            continue;

        while(a==0)
        {
            fwrite(buff, 1, 64, output);
            printf("%s\n", buff);
        }
    }
    printf("The result was written into output.txt");

    /* Closing all the files */
    for(idx=0; idx<n; idx++)
    {
        fclose(fptr[idx]);
    }

    free(fptr);
    fclose(output);
    return 0;
}