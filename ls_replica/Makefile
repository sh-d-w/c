#                       __________________							  #
#                        S |-| - D - \/\/ 							  #
#                       ==================							  #
#																	  #
#   	   Original code developed during 42.fr curriculum. 		  #
# 			  Project renamed and refactored for clarity.			  #
#             Created: 2016-06-18 by S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ				  #
#																	  #
#   Copyright [2026] [S𝔥𝔞⁽ᵃʰⁱ⁾d M𝔞𝔥𝔬𝔪𝔢ᵈ] under Apache 2.0 License	  #

NAME = i_ls

FLAGS = -Wall -Wextra #-Werror

all:
	@make libraries
	@make $(NAME)

libraries:
	@git clone "https://github.com/sh-d-w/c.git"
	@make -C ./c/c-library

$(NAME):
#		@make -C ./c/c-library/
		@gcc $(FLAGS) -I includes/ i_ls.c i_checks.c i_list.c i_sort.c i_printf.c ./c/c-library/clibrary.a -o $(NAME)
#		@mv a.out i_ls
#		@echo Made!

clean: 	
		@make -C ./c/c-library clean
		@echo Cleaned

fclean: 
		# clean
		@rm -rf $(NAME)
		@rm -rf ./c/
		@echo very clean

re:		
		@make fclean
		@make all
