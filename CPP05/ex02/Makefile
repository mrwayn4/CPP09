SRC = main.cpp  Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
RM = rm -f
NAME = execute
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDE = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
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