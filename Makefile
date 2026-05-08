CC      = cc
CFLAGS  = -Wall -Wextra -Werror

NAME    = so_long

SRC_DIR = src
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

LIBFT   = $(LIBFT_DIR)/libft.a
MLX     = $(MLX_DIR)/libmlx.a

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LDFLAGS  = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/error.c \
      $(SRC_DIR)/map_read.c \
      $(SRC_DIR)/map_validate.c \
      $(SRC_DIR)/map_path.c \
      $(SRC_DIR)/game_init.c \
      $(SRC_DIR)/render.c \
      $(SRC_DIR)/input.c \
      $(SRC_DIR)/move.c \
      $(SRC_DIR)/cleanup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR) CFLAGS="-O3 -std=gnu89 -I/usr/include"

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

%.o: %.c $(INC_DIR)/so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
