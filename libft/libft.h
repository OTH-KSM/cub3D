/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:47:43 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/14 20:12:51 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//    ***    Get_next_line Part    **
typedef struct s_struct
{
	char		*temp;
	char		*buffer;
	char		*line;
	int			rdd;
	int			jeton;
	int			j;
	int			check;
}t_pos;

char	*get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*ft_gnlstrchr(char *s, int c);
char	*ft_gnlsubstr(char *s, unsigned int start, size_t len);

//    ***    Libft Part    **


void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_bzero(void *str, int n);
void	*ft_memchr(void *str, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *str, int c, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(char *str, char *to_find, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *nptr);
int		ft_isalnum(int para);
int		ft_isalpha(int para);
int		ft_isascii(int para);
int		ft_isdigit(int para);
int		ft_isprint(int para);
int		ft_tolower(int para);
int		ft_toupper(int para);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif