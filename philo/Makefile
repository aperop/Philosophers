# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 12:11:30 by dhawkgir          #+#    #+#              #
#    Updated: 2022/03/10 15:43:15 by dhawkgir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
SRCDIR	=	srcs
OBJDIR	=	objs
SRCS	=	$(SRCDIR)/dead.c 		\
			$(SRCDIR)/forks.c 		\
			$(SRCDIR)/input.c 		\
			$(SRCDIR)/main.c 		\
			$(SRCDIR)/print.c 		\
			$(SRCDIR)/routine.c 	\
			$(SRCDIR)/simulation.c 	\
			$(SRCDIR)/parse.c 		\
			$(SRCDIR)/timestamp.c 	\
			$(SRCDIR)/utils.c

OBJS	=	$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CC		=	cc
INCS	=	-Iincludes/
FLAGS	=	-O3 -Wall -Wextra -Werror

BUILD_MSG	=	"Building objects... %-33.33s\r"
COMPILE_MSG	=	"All objects have been built. Compiling...\r"
DONE_MSG	=	"All objects have been built. Compiling done.\n"
CLEAN_MSG	=	"Objects have been deleted."
FCLEAN_MSG	=	"Executable has been deleted."

all:		$(NAME)

$(NAME):	$(OBJS)
				@printf $(COMPILE_MSG)
				@$(CC) $(OBJS) $(FLAGS) -o $(NAME) -lpthread
				@echo $(DONE_MSG)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
				@mkdir -p $(OBJDIR)
				@printf $(BUILD_MSG) $@
				@$(CC) $(FLAGS) -c -o $@ $< $(INCS)

clean:
				@rm -rf $(OBJDIR)
				@echo $(CLEAN_MSG)

fclean:			clean
				@rm -rf $(NAME)
				@echo $(FCLEAN_MSG)

re:				fclean all

norm:
				norminette

.PHONY:			all clean fclean re norm
