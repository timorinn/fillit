# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bford <bford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 11:34:46 by bford             #+#    #+#              #
#    Updated: 2019/09/20 20:10:28 by bford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES		= ./libft/*.c ./libft/libft.h
NEW_FILES	= fillit.h
OBJECTS		= $(SOURCES:.c=.o)

clean:		
			/bin/rm -f *.o

fclean: 	clean
			/bin/rm -f $(NAME)

myclean:	clean
			/bin/rm -f $(NAME) libft.h.gch a.out

re:			fclean all

norm:		
			norminette $(SOURCES)

exe:
			gcc -Wall -Werror -Wextra main.c $(SOURCES) $(NEW_FILES)
			./a.out "text.txt"