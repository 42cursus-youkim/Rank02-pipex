/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:12:11 by youkim            #+#    #+#             */
/*   Updated: 2021/08/16 21:34:00 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define OK 0
# define ERROR 1
# define STDIN 0
# define STDOUT 1

/*
** qsplit binary operation
*/
#define	INQ	01
#define INW	02
#define FW	04

/*
** linked list struct
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;


void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_atoi(const char *str);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_qsplit(char const *s, char lim);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** put
*/
int			ft_putchar_fd(int fd, char c);
int			ft_putstr_fd(int fd, char *s);
void		ft_putnbr_fd(int fd, int n);
void		ft_putendl_fd(int fd, char *s);
int			ft_putchar(char c);
int			ft_putstr(char *s);
/*
** BONUS
*/
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
** CUSTOM
*/

int			ft_isupper(int c);
int			ft_islower(int c);

int			ft_sign(int n);
int			ft_abs(int n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_lsign(long long n);
long long	ft_labs(long long n);
long long	ft_lmin(long long a, long long b);
long long	ft_lmax(long long a, long long b);

char		*ft_itoa_base(long long n, char *baseset);
char		**ft_purge2str(char **str2d);
void		ft_error(char *error);

#endif