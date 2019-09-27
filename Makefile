# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 09:03:24 by rengelbr          #+#    #+#              #
#    Updated: 2019/09/09 09:08:29 by rengelbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
MAKELIB = -C libft
LIB = libft/libft.a
FLGS = -Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -g
SRC = lem-in.c \
	$(LIB) \
	src/*.c

all: $(MAKELIB) $(NAME)

$(MAKELIB):
	@$(MAKE) $(MAKELIB)

$(NAME):
	gcc $(FLGS) $(SRC) libft/libft.a -o $(NAME)

db:
	gcc $(DBFLG) $(SRC) libft/libft.a -o $(NAME)

clean:
	rm -fr $(NAME) $(NAME).dSYM
	rm -f libft/*.o

fclean: clean
	rm -f libft/*.o libft/libft.a

re: clean all

redb: clean db
