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

NAME = libftprintf.a
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra 
AR = ar -rcs
INCLUDES = -I.
OBJ = $(SRCS:.c=.o)
RM = rm -rf


SOURCES = ft_printf.c\
			ft_printf_utils.c\
			ft_printf_hexs.c\
			ft_printf_getlen.c\
			 main.c\



all: $(NAME)

$(NAME): 
	$(OBJ)
	@echo "COmpiling"
	@$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES)
	@$(AR) $(NAME) *.o

clean:
	@$(RM) *.o
fclean: clean
	@$(RM) $(NAME)
re: fclean


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

	





