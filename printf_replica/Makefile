#                        __________________							   #
#                         S |-| - D - \/\/ 							   #
#                        ==================							   #
# 																	   #
#    	   Original code developed during 42.fr curriculum. 		   #
#  			  Project renamed and refactored for clarity.			   #
#              Created: 2016-05-24 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				   #
# 																	   #
#    Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	   #

NAME = i_printf

FLAGS = -Wall -Wextra -Werror

all:
	@make libraries
	@make $(NAME)

libraries:
	@git clone "https://github.com/sh-d-w/c.git"

$(NAME):
		@make -C ./c/c-library
		@gcc -o i_printf $(FLAGS) i_printf.c ./c/c-library/clibrary.a
		@echo Made!

clean:
		@make -C ./c/c-library clean
		@echo Cleaned

fclean:
		@rm -rf $(NAME)
		@rm -rf ./c/
		@echo very clean

re:
		@make fclean
		@make all
