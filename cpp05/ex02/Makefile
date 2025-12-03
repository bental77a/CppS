C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
INFILES = 	AForm.cpp Bureaucrat.cpp main.cpp PresidentialPardonForm.cpp \
			 RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
INCS = 	AForm.hpp Bureaucrat.hpp PresidentialPardonForm.hpp \
		 RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

EXTRA_FILES = *_shrubbery

OBJFILES = $(INFILES:.cpp=.o)

NAME = Bureaucrat

all: $(NAME)

$(NAME):$(OBJFILES) $(INCS)
	$(C++) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) $(EXTRA_FILES)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re