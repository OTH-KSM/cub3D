#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    int i;

    i = 0;
    if(str)
    {
        while(str[i])
            i++;
    }
    return(i);
}

char    *ft_strdup(const char *str)
{
    int i;
    char *ret;

    i = 0;
    ret = malloc(ft_strlen(str) + 1);
    while(str[i])
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = '\0';
    return(ret);
}

char    *ft_strjoin(char *str1, char *str2)
{
    int i;
    int j;
    char *ret;

    i = 0;
    j = 0;
    if(!str1 && str2)
        return(ft_strdup(str2));
    ret = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
    while(str1[i])
    {
        ret[i] = str1[i];
        i++;
    }
    while(str2[j])
    {
        ret[i] = str2[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    return(ret);
}

char    *ft_strchr(const char *str, char c)
{
    int i;
    char *ret;

    i = 0;
    ret = (char *)str;
    if(ret)
    {
        while(ret[i])
        {
            if(ret[i] == c)
                return(ret + i);
            i++;
        }
    }
    return(NULL);
}

char    *ft_add_save(char *save, int fd)
{
    int ret;
    char *buf;

    buf = malloc((size_t)BUFFER_SIZE + 1);
    while(!ft_strchr(save, '\n'))
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if(ret == 0)
            break;
        if(ret == -1)
        {
            free(buf);
            free(save);
            return(NULL);
        }
        buf[ret]= '\0';
        save = ft_strjoin(save, buf);
    }
    free(buf);
    return(save);
}

char    *ft_line(char   *save)
{
    int i;
    int j;
    char *ret;

    i = 0;
    while(save[i] && save[i] != '\n')
        i++;
    if(save[i] == '\0')
        return(ft_strdup(save));
    i++;
    ret = malloc(i + 1);
    j = 0;
    while(j < i)
    {
        ret[j] = save[j];
        j++;
    }
    ret[j] = '\0';
    return(ret);
}

char    *ft_save(char *save, char *line)
{
    int i;
    int j;
    char *ret;

    i = ft_strlen(line);
    j = ft_strlen(save) + 1;
    ret = malloc(j - i);
    j = 0;
    while(save[i])
    {
        ret[j] = save[i];
        j++;
        i++;
    }
    ret[j] = '\0';
    free(save);
    return(ret);
}

char    *get_next_line(int fd)
{
    static char *save;
    char    *line;

    if(BUFFER_SIZE < 0)
        return(NULL);
    save = ft_add_save(save, fd);
    if(!save || save[0] == '\0')
    {
        free(save);
        save = NULL;
        return(NULL);
    }
    line = ft_line(save);
    save = ft_save(save, line);
    return(line);
}

int main()
{
    int fd;
    fd = open("test", O_RDONLY);
    
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
    //printf("%s", get_next_line(fd));
}