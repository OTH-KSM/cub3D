// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>
// #include <ctype.h>

// char *str_replace(char *orig, char *rep, char *with) {
//     char *result; // the return string
//     char *ins;    // the next insert point
//     char *tmp;    // varies
//     int len_rep;  // length of rep (the string to remove)
//     int len_with; // length of with (the string to replace rep with)
//     int len_front; // distance between rep and end of last rep
//     int count;    // number of replacements

//     // sanity checks and initialization
//     if (!orig || !rep)
//         return NULL;
//     len_rep = strlen(rep);
//     if (len_rep == 0)
//         return NULL; // empty rep causes infinite loop during count
//     if (!with)
//         with = "";
//     len_with = strlen(with);

//     // count the number of replacements needed
//     ins = orig;
//     for (count = 0; tmp = strstr(ins, rep); ++count) {
//         ins = tmp + len_rep;
//     }

//     tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

//     if (!result)
//         return NULL;

//     // first time through the loop, all the variable are set correctly
//     // from here on,
//     //    tmp points to the end of the result string
//     //    ins points to the next occurrence of rep in orig
//     //    orig points to the remainder of orig after "end of rep"
//     while (count--) {
//         ins = strstr(orig, rep);
//         len_front = ins - orig;
//         tmp = strncpy(tmp, orig, len_front) + len_front;
//         tmp = strcpy(tmp, with) + len_with;
//         orig += len_front + len_rep; // move to next "end of rep"
//     }
//     strcpy(tmp, orig);
//     return result;
// }

// static	int			ft_itoa_size(int n)
// {
// 	int				size;
// 	int				neg;

// 	size = 0;
// 	neg = 0;
// 	if (n < 0 && n > -2147483648)
// 	{
// 		neg = 1;
// 		size++;
// 		n = -n;
// 	}
// 	else if (n == 0)
// 		return (1);
// 	else if (n == -2147483648)
// 		return (11);
// 	while (n >= 1)
// 	{
// 		n /= 10;
// 		size++;
// 	}
// 	return (size);
// }

// char				*ft_itoa(int n)
// {
// 	char			*str;
// 	int				i;
// 	int				size;
// 	int				neg;
// 	unsigned int	tmp;

// 	size = ft_itoa_size(n);
// 	neg = (n < 0 ? 1 : 0);
// 	i = 1;
// 	if (!((str = (char *)malloc(sizeof(char) * ft_itoa_size(n) + 1))))
// 		return (NULL);
// 	tmp = (n < 0 ? -n : n);
// 	if (tmp == 0)
// 		str[tmp] = '0';
// 	while (tmp >= 1)
// 	{
// 		str[size - i] = (tmp % 10) + '0';
// 		tmp /= 10;
// 		i++;
// 	}
// 	if (neg)
// 		*str = '-';
// 	str[size] = '\0';
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*new_str;
// 	size_t	i;
// 	size_t	j;

// 	if (!s || !(new_str = (char *)malloc(len + 1)))
// 		return (0);
// 	i = start;
// 	j = 0;
// 	while (i < strlen(s) && j < len)
// 		new_str[j++] = s[i++];
// 	new_str[j] = '\0';
// 	return (new_str);
// }

// char *replace_str(char *str, char *orig, char *rep)
// {
//   static char buffer[4096];
//   char *p;

//   if(!(p = strstr(str, orig)))
//     return str;

//   strncpy(buffer, str, p-str);
//   buffer[p-str] = '\0';
//   return buffer;
// }

// int easy_calc(char *s)
// {
//     int i = 0;
//     int res = 0;
//     char operator = '+';
//     while(s[i])
//     {
//         if(isdigit(s[i]) != 0 && operator == '+')
//             res += s[i] - '0';
//         else if(isdigit(s[i]) != 0 && operator == '-')
//             res -= s[i] - '0';
//         else if(s[i] == '+' || s[i] == '-')
//             operator = s[i];
//         i++;
//     }
//     return (res);
// }
// int calculate(char* s) {
//     int i = 0;
//     int res = 0;
//     char operator = '+';
//     while(s[i])
//     {
//         if(isdigit(s[i]) != 0 && operator == '+')
//             res += s[i] - '0';
//         else if(isdigit(s[i]) != 0 && operator == '-')
//             res -= s[i] - '0';
//         else if(s[i] == '+' || s[i] == '-')
//             operator = s[i];
//         i++;
//     }
//     return (res);
// }

// int main()
// {
//     printf("this is the final result %d \n", calculate("(1+(4+5+2)-3)+(6+8)"));
// }