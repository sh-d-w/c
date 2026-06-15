/*                       __________________							  */
/*                        S |-| - D - \/\/ 							  */
/*                       ==================							  */
/*																	  */
/*   	   Original code developed during 42.fr curriculum. 		  */
/* 			  Project renamed and refactored for clarity.			  */
/*             Created: 2016-11-18 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  */
/*																	  */
/*   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  */

#ifndef I_CLIBRARY_H
# define I_CLIBRARY_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
#include <termcap.h>
#include <term.h>
# include <termios.h>

#ifdef __APPLE__
# include <libc.h>
#endif

#include <stdarg.h>	// for printf

//to fix: strchr strrchr strsplit memchr

typedef struct		s_list
{
	void		*content;
	size_t		content_size;
	struct s_list	*next;
}			t_list;

int			i_isalpha(int c);
int			i_isdigit(int c);
int			i_toupper(int c);
int			i_tolower(int c);
int			i_isalnum(int c);
int			i_isascii(int c);
int			i_isprint(int c);
int			i_atoi(const char *str);
int			i_strcmp(const char *s1, const char *s2);
int			i_strequ(char const *s1, char const *s2);
int			i_strcmp(const char *s1, const char *s2);
int			i_memcmp(const void *s1, const void *s2, size_t n);
int			i_strncmp(const char *s1, const char *s2, size_t n);
int			i_strnequ(char const *s1, char const *s2, size_t n);
int			non_canonical(struct termios *term, char *status);
char			*file_get_contents(char *s);
char			*i_itoa(int n);
char			*i_strnew(size_t size);
char			*i_strdup(const char *s1);
char			*i_strtrim(char const *s);
char			*i_strchr(const char *s, int c);
char			*i_strrchr(const char *s, int c);
char			**i_strsplit(char const *s, char c);
char			*i_strcat(char *s1, const char *s2);
char			*i_strcpy(char *dst, const char *src);
char			*i_strmap(char const *s, char (*f)(char));
char			*i_strjoin(char const *s1, char const *s2);
char			*i_strncat(char *s1, const char *s2, size_t n);
char			*i_strstr(const char *big, const char *little);
char			*i_strncpy(char *dst, const char *src, size_t len);
char			*i_strsub(char const *s, unsigned int start, size_t len);
char			*i_strmapi(char const *s, char (*f)(unsigned int, char));
char			*i_strnstr(const char *big, const char *little, size_t len);
char			*str_replace(char *s, char *t, char *u);
char			*strconcat(const char *s, ...);
void			i_putendl(char const *s);
void			i_strclr(char *s);
void			i_putnbr(int n);
void			i_putchar(char c);
void			i_putstr(char const *s);
void			*i_memalloc(size_t size);
void			i_putnbr_fd(int n, int fd);
void			i_bzero(void *s, size_t n);
void			i_putchar_fd(char c, int fd);
void			i_putstr_fd(char const *s, int fd);
void			i_putendl_fd(char const *s, int fd);
void			i_lstadd(t_list **alst, t_list *new);
void			*i_memset(void *b, int c, size_t len);
void			i_striter(char *s, void (*f)(char *));
void			i_lstiter(t_list *lst, void (*f)(t_list *elem));
void			*i_memcpy(void *dst, const void *src, size_t n);
void			*i_memmove(void *dst, const void *src, size_t len);
void			i_striteri(char *s, void (*f)(unsigned int, char *));
void			i_lstdel(t_list **alst, void (*del)(void *, size_t));
void			*i_memccpy(void *dst, const void *src, int c, size_t n);
void			*i_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			*i_memchr(const void *s, int c, size_t n);
size_t			i_strlen(const char *s);
size_t			i_strlcat(char *dst, const char *src, size_t size);
t_list			*i_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*i_lstnew(void const *content, size_t content_size);
#endif
