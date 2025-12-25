C++ = c++
C++_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
INFILES =	main.cpp
INCS =	Array.hpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = array

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