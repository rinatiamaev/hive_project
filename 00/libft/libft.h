#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(const void *s1, const void *s2, int n);
int		ft_strlen(char *src);
int		ft_strlcat(char *dest, char *src, int destsize);
int		ft_strlcpy(char *dest, const char *src, int destsize);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_bzero(void *s, int n);
void	*ft_memccpy(void *dest, const void *src, int c, int n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_memset(void *s, int c, int n);
void	*ft_calloc(int nmem, int size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strnstr(const char *str, const char *to_find, int len);
char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
char	**ft_split(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
t_list	ft_lstadd_front(t_list **lst, t_list *new);

#endif
