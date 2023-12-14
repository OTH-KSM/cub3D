#include "header.h"

int main1(void)  {
    char *str;
    int i = 0;
    str = malloc(5 * sizeof(char));
    while (i < 5)   {
        str[i] = '5';
        i++;
    }
    char *line1 = ft_strtrim(str, "\t");
    free(line1);
    return (0);
}

int main(void)  {
    main1(); 
    system("leaks a.out");
}