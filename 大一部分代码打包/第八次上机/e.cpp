#include <stdio.h>
#include <string.h>

int main()
{
    char line[305], *p;
    int count = 0, i;

    while((fgets(line, 300, stdin)) != NULL)
    {
        for(i = 0; i < strlen(line); i++)
        {
            if(line[i] >= 'A' && line[i] <= 'Z') line[i] += 'a' - 'A';
        }
        p = strstr(line, "bug");
        while(p != NULL && *(p++) != '\0')
        {
            count++;
            p = strstr(p, "bug");
        }
    }
    printf("%d", count);
    return 0;
}
