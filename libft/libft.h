/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:28:10 by tlamarch          #+#    #+#             */
/*   Updated: 2024/04/08 16:16:29 by tlamarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//libft
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *first, const char *second, size_t length);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// GNL
char	*get_next_line(int fd);
int		checkempty(char *buffer);
int		checkbackn(char *buf);
void	*ft_realloc(char *buf, char *buffer, int begin);
int		ft_strlenp(char *buf, int begin, int mod);
void	ft_strcat(char *dest, char *src, int begin, int mod);
void	ft_test_backn(char **tbuf, char *buf, int stopn, ssize_t *cr);
void	initvar(char *tempbuf, ssize_t *charread);

// ft_printf
int		ft_printf(const char *buf, ...);
int		condition3(const char *buf);
int		checkbuf(char c, char *key);
void	treatment(const char *buf, va_list *args, int *i, int *r);
void	ft_puthexmi(unsigned int nbr, int mod, int *r);
void	ft_puthexmaj(unsigned int nbr, int mod, int *r);
void	ft_puthexmil(unsigned long n, int mod, int *r);
void	ft_puthexmitab(unsigned int n, int mod, char *tab);
void	ft_puthexmiltab(unsigned long n, int mod, char *tab);
void	ft_puthexmajtab(unsigned int n, int mod, char *tab);
void	ft_putunint(unsigned int n, int *r);
void	ft_putchar(char c, int *r);
void	ft_putstr(char *s, int *r);
void	ft_putnbr(int n, int *r);
void	treatfldi(const char *buf, int d, int *r);
void	treatnofl(const char *buf, va_list *args, int *i, int *r);
void	treatfl1(const char *buf, va_list *args, int *i, int *r);
void	treatfl2(const char *buf, va_list *args, int *i, int *r);
int		treattab(char *tab, const char *buf, va_list *args);
void	ft_tabcpy(char *tab, char *nbr);
void	printfield(const char *buf, char *tab, int *r, int s_field);
void	ft_treatflagp(unsigned long n, char *tab);
void	ft_treatflagu(unsigned int i, char *tab);
void	ft_treatflagx(unsigned int i, char *tab);
void	ft_treatflagx2(unsigned int i, char *tab);
int		calcfield(const char *buf);
void	ft_putuninttab(unsigned int n, char *tab);
void	ft_putstrtab(char *s, char *tab);
void	ft_putnbrtab(int n, char *tab);
void	ft_rev_tab(char *tab);
int		testprint(char **tab, const char *buf, int *s_field, int *r);
#endif