# The binary this exercise builds
NAME := game

# Compiler and the gauntlet's mandatory flags //-Iraylib, when include -> look inside raylib/include
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -Iraylib/include

# List every .cpp file in the exercise here
SRCS := main.cpp codes/unit.cpp
OBJS := $(SRCS:.cpp=.o)
RAYS := -Lraylib/lib -Wl,-rpath,'$$ORIGIN/raylib/lib' -lraylib

# `make` / `make all`: build the binary -Lraylib = look inside raylib libraries in /lib, finds the path to lib, also link to library.lib
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(RAYS)

# Compile each .cpp into a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# `make clean`: remove object files
clean:
	rm -f $(OBJS)

# `make fclean`: remove objects AND the binary
fclean: clean
	rm -f $(NAME)

# `make re`: rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re