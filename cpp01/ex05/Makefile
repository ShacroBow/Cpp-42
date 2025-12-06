NAME = harl
SRC = main.cpp Harl.cpp
OBJ_DIR = ./obj/
OBJ = $(SRC:%.cpp=$(OBJ_DIR)%.o)
#OBJ_BONUS = $(SRC_BONUS:%.cpp=$(OBJ_DIR)%.o)
DEPS = $(OBJ:.o=.d)
###DEPS_BONUS = $(OBJ_BONUS:.o=.d)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP #-g


all: $(NAME)

#bonus: $(NAME_BONUS)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CXX) $(OBJ) $(CXXFLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJ_DIR) $(OBJ_BONUS) 
	$(CXX) $(OBJ_BONUS) $(CXXFLAGS) -o $@ 

$(OBJ_DIR)%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@


clean:
	rm -rf $(OBJ) $(DEPS)
#	rm -rf $(OBJ_BONUS) $(DEPS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS) a.out $(OBJ_DIR)

re: fclean all

# Include auto-generated dependency files
###-include $(DEPS)
###-include $(DEPS_BONUS)

.PHONY: all clean fclean re #bonus