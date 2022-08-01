NAME = cub3D
INCLUDE = cub3d.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror ./minilibx_opengl_20191021/libmlx.a -lmlx -framework OpenGL -framework AppKit

SRCS = main.c textures.c raycaster.c ft_utils.c checkMap_util.c movments.c rayCaster_util.c keys.c free.c get_next_line.c get_next_line_utils.c util.c parser.c utils2.c check_map.c

OBJS = 	$(SRCS:.c=.o)

.c.o:
	$(CC)  $< -o $@

$(NAME): $(SRCS) 
	$(CC) $(SRCS) $(CFLAGS)  -I$(INCLUDE)  -o $(NAME) 

all:$(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
