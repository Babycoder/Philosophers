/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:21:26 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:07:32 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILL_H
# define UTILL_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_itvar
{
	unsigned int		nb;
	int					len;
	char				*res;
}				t_itvar;

char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
void		ft_bzero(void *argv, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int x);
int			ft_isalpha(int x);
int			ft_isdigit(int x);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_itoa(int n);
int         ft_strcmp(char *s1, char *s2);

#endif
