#                        __________________							   #
#                         S |-| - D - \/\/ 							   #
#                        ==================							   #
# 																	   #
#    	   Original code developed during 42.fr curriculum. 		   #
#  			  Project renamed and refactored for clarity.			   #
#              Created: 2016-10-20 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				   #
# 																	   #
#    Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	   #

NAME=	choose

SRC=	c.c d.c e.c

OBJ=	$(SRC:.c=.o)

FLAGS=	-Wall -Wextra -Werror

all:
	@make $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC) -ltermcap

clean:
	rm $(NAME)

fclean: 
	@make clean

re:
	@rm $(NAME)
	@make all
