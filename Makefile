# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:37:19 by ivda-cru          #+#    #+#              #
#    Updated: 2022/04/25 20:39:31 by ivda-cru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
# END of Colors

NAME = libftprintf.a
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
INCLUDES = -I.
OBJ = $(SRCS:.c=.o)
RM = rm -rf


SOURCES = ft_printf.c\
			ft_printf_utils.c\
			ft_printf_hexs.c\
			ft_printf_getlen.c\
			libft_functions.c\



all: $(NAME)

$(NAME): 
	$(OBJ)
	@echo "$(BLUE)COmpiling ObJecTs$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES)
	@$(AR) $(NAME) *.o

clean:
	@echo "$(YELLOW)CleAnINg ObJecTs$(DEF_COLOR)"
	@$(RM) *.o
fclean: clean
	@echo "$(YELLOW)CleAnINg liBFile$(DEF_COLOR)"
	@$(RM) $(NAME)
re: fclean

erase: re
	@echo "$(YELLOW)CleAnINg A.OUT$(DEF_COLOR)"
	@$(RM) a.out

test2: $(NAME)
	@$(CC) $(NAME) main.c && ./a.out
test: test2
	@echo "$(RED)ComPiLing EveRYthING aNd DeLEtINg aLs0$(DEF_COLOR)"
	make erase

.PHONY = all
	
norm:
	@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

#GIT UPLOAD

ft_printfREPO = git remote add origin https://github.com/IDC87/ft_printf.git

GitPush = git push -u origin main
SetStream = git push --set-upstream origin master
CleanUrl = git remote rm origin

fetch: 
	@git fetch https://github.com/IDC87/ft_printf.git

pull:
	@git pull https://github.com/IDC87/ft_printf.git
GitCommit:
	@git add .
	@git commit -m "$(shell date)"
#	@git commit -m "$m"
REPOLibft:
	$(ft_printfREPO)
UploadGit:
	@$(SetStream)
CleanUrl: 
	@$(CleanUrl)
push: GitCommit REPOLibft UploadGit CleanUrl
	@echo
	@echo "$(GREEN)UPDATE SUCCESSFUL! REPO CLEAN ALSO SUCCESSFUL!$(DEF_COLOR)"
	@echo
#FINAL COMMAND should be: make Push m="message". 

#FIM DO GIT

	





