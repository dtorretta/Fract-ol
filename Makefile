# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 18:09:39 by dtorrett          #+#    #+#              #
#    Updated: 2024/05/22 00:29:02 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fract_ol
LIBFT = libft/libft.a
LIBMLX_DIR = libmlx
LIBMLX = $(LIBMLX_DIR)/libmlx_Linux.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L$(LIBMLX_DIR) -lXext -lX11 -lm
# -lXext represents Xext (extensions) library / -lX11 (principal) represents X11 library, both part of X Window System necesary to build graphic interphases
# -lm represents the math library

SRCS = main.c mandelbrot.c params.c julia.c events.c utils.c
OBJS = $(SRCS:.c=.o)

# Default target is to build the executable
all: $(NAME)

# Build the libft and minilibx library
$(LIBMLX):
	if [ ! -d "$(LIBMLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(LIBMLX_DIR); \
	fi
	$(MAKE) -C $(LIBMLX_DIR)

$(LIBFT):
	$(MAKE) -C libft all
	
# Build the executable using object files and libft
$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) -o $@ $(LIBFLAGS)
	@echo "\n------------------------------------------\n"
	@echo "📟 fract_ol ready!\n"
	@echo "------------------------------------------\n"
#-o specifies the output file
#$@ represents the target, which is the name of the executable

# Compile each source file into object files
%.o: %.c $(LIBMLX_DIR)
	$(CC) $(CFLAGS) -I $(LIBMLX_DIR) -I libft -I . -c $< -o $@
#-I $(LIBMLX_DIR): This flag specifies an additional directory to include header files from. In this case, it includes header files from the libmlx directory.
#-I .: This flag includes the current directory as a directory to search for header files. The dot (.) represents the current directory.
#-c: This flag tells the compiler to generate object files (*.o) without linking. It essentially compiles the source code into an object file.
#$<: This is an automatic variable that represents the first prerequisite (dependency) of the rule. In the context of a compilation rule, it typically represents the source file (*.c file).
#-o $@: This flag specifies the output file name. $@ is an automatic variable representing the target of the rule, which, in this case, is the object file (*.o). So, -o $@ indicates that the compiler should output the compiled object file with the same name as the target.

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	if [ -d "$(LIBMLX_DIR)" ]; then \
		$(MAKE) -C $(LIBMLX_DIR) clean; \
	fi
	@echo "\n------------------------------------------\n"
	@echo "💧 Clean: Removed all the \".o\" files \n"
	@echo "------------------------------------------\n"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	if [ -d "$(LIBMLX_DIR)" ]; then \
		rm -rf $(LIBMLX_DIR); \
	fi
	@echo "\n------------------------------------------\n"
	@echo "🧼 Fclean: Removed the executables \n"
	@echo "------------------------------------------\n"

re: fclean all

# Declare these targets as phony (not real files) to avoid conflicts
.PHONY: all clean fclean re