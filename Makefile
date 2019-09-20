# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:34:46 by bford             #+#    #+#              #
#    Updated: 2019/09/20 18:51:18 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=	./libft/*.c ./libft/libft.h

OBJECTS =	$(SOURCES:.c=.o)

NAME =		libft.a

all:		$(NAME)

$(NAME):	$(OBJECTS)
			gcc -Wall -Wextra -Werror -c $(SOURCES)
			ar rcs $(NAME) $(OBJECTS)
			ranlib $(NAME)

clean:		
			/bin/rm -f *.o

fclean: 	clean
			/bin/rm -f $(NAME)

myclean:	clean
			/bin/rm -f $(NAME) libft.h.gch a.out

re:			fclean all

norm:		
			norminette $(SOURCES) libft.h

exe:
			gcc -Wall -Werror -Wextra main.c $(SOURCES)
			./a.out