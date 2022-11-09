NAME		=	fix

SRCS		=	main.cpp \
				Fixed.cpp

OBJS		=	$(SRCS:.cpp=.o)

DEPS		=	$(OBJS:.o=.d)

CC			=	c++

CXXFLAGS	= 	-Wall -Werror -Wextra -std=c++98

RM			=	rm -f


$(NAME):	$(OBJS) Fixed.hpp
			$(CC) $(CXXFLAGS) $(OBJS) -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(DEPS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all