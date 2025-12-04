NAME = accounts
SRC = Account.cpp tests.cpp
OBJ_DIR = ./obj/
OBJ = $(SRC:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJ:.o=.d)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

$(OBJ_DIR)%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@


clean:
	rm -rf $(OBJ) $(DEPS)

fclean: clean
	rm -rf $(NAME) a.out $(OBJ_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
