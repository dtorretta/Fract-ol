# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 18:09:39 by dtorrett          #+#    #+#              #
#    Updated: 2024/05/03 19:28:35 by dtorrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			Variables				#
# The name of the executable
NAME = fract_ol
# The path to the libft and minilibx library
LIBFT = libft/libft.a
LIBMLX = libmlx/libmlx_Linux.a

CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFLAGS		= -lXext -lX11 -lm 
# -lXext represents Xext (extensions) library / -lX11 (principal) represents X11 library, both part of X Window System necesary to build graphic interphases
# -lm represents the math library

LEAKFLAGS		= -fsanitize=leak -fsanitize=address
# to detect memory leaks by using AddressSanitizer and LeakSanitizer

#			Source files			#
#SRCS = fractol.c mandelbrot.c
#SRCS = fractol.c buttons.c mandel.c
SRCS = main.c mandelbrot.c params.c

OBJS = $(SRCS:.c=.o)

# Default target is to build the executable
all: $(NAME)

# Build the libft and minilibx library
$(LIBFT):
	$(MAKE) -C libft all
$(LIBMLX):
	$(MAKE) -C libmlx all

# Build the executable using object files and libft
$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFLAGS)
	
# $^ represents all the prerequisites (object files, Libmlx and the libft library)
# -o specifies the output file
# $@ represents the target, which is the name of the executable

# Compile each source file into object files
%.o: %.c
	$(CC) $(CFLAGS) -I libft -I . -c $< -o $@
# -I$(LIBDIR): This flag specifies an additional directory to include header files from. In this case, it includes header files from the libft directory.
# -I .: This flag includes the current directory as a directory to search for header files. The dot (.) represents the current directory.
#-c: This flag tells the compiler to generate object files (*.o) without linking. It essentially compiles the source code into an object file.
# $<: This is an automatic variable that represents the first prerequisite (dependency) of the rule. In the context of a compilation rule, it typically represents the source file (*.c file).
#-o $@: This flag specifies the output file name. $@ is an automatic variable representing the target of the rule, which, in this case, is the object file (*.o). So, -o $@ indicates that the compiler should output the compiled object file with the same name as the target.

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C libmlx clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C libmlx clean

re: fclean all

leaks:
	$(MAKE) fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(LEAKFLAGS)"

# Declare these targets as phony (not real files) to avoid conflicts
.PHONY: all clean fclean re leaks