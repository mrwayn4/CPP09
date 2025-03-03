SRC = main.cpp Span.cpp
RM = rm -f
NAME = span
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = Span.hpp
SRCO = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(SRCO)
	$(CC) $(FLAGS) $^ -o $@
%.o: %.cpp $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	$(RM) $(SRCO)
fclean: clean
	$(RM) $(NAME)
re: fclean all