#                        __________________							   #
#                         S |-| - D - \/\/ 							   #
#                        ==================							   #
# 																	   #
#    	   Original code developed during 42.fr curriculum. 		   #
#  			  Project renamed and refactored for clarity.			   #
#              Created: 2016-11-18 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				   #
# 																	   #
#    Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	   #

NAME = clibrary.a

SRC		= i_memset.c i_bzero.c i_memcpy.c i_memccpy.c i_memmove.c \
		  i_memchr.c i_memcmp.c i_strlen.c i_strdup.c i_strcpy.c \
		  i_strncpy.c i_strcat.c i_strncat.c i_strlcat.c \
		  i_strchr.c i_strrchr.c i_strstr.c i_strnstr.c \
		  i_strcmp.c i_strncmp.c i_atoi.c i_isalpha.c i_isdigit.c \
		  i_isalnum.c i_isascii.c i_isprint.c i_toupper.c \
		  i_tolower.c i_memalloc.c i_memdel.c i_strnew.c \
		  i_strdel.c i_strclr.c i_striter.c i_striteri.c \
		  i_strmap.c i_strmapi.c i_strequ.c i_strnequ.c \
		  i_strsub.c i_strjoin.c i_strtrim.c i_strsplit.c \
		  i_itoa.c i_putchar.c i_putstr.c i_putendl.c i_putnbr.c \
		  i_putchar_fd.c i_putstr_fd.c i_putendl_fd.c i_putnbr_fd.c \
		  i_lstdelone.c i_lstdel.c i_lstadd.c i_lstiter.c i_lstnew.c \
		  i_lstmap.c \

OBJ		= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
AR		= ar
ARFLAGS	= rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
