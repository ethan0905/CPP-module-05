# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 14:59:45 by esafar            #+#    #+#              #
#    Updated: 2022/08/05 11:26:37 by c2h6             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

GCC = c++
FLAGS = -g -Wextra -Wall -Werror -std=c++98 
OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${GCC} ${FLAGS} ${OBJS} -I includes -o ${NAME}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS} ${NAME} *_shrubbery

re:	fclean all

%.o: %.cpp ${INCL}
	${GCC} ${FLAGS} -c $< -o ${<:.cpp=.o}

.PHONY: all clean fclean re
