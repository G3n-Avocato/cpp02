# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 22:27:18 by lamasson          #+#    #+#              #
#    Updated: 2023/12/10 16:18:49 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ./RPN
CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -g3
RM				= rm -rf

SRC				= main.cpp \
				  RPN.cpp

OBJ				= ${SRC:%.cpp=%.o}

${NAME}: ${OBJ}
		@${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

all:	${NAME}

clean:
		@${RM} ${OBJ}

fclean: clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
