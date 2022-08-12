NAME = cub3D

CC = gcc

CFLAGS = -Wextra -Werror -Wall
LDFLAGS = -Llibft -L$(HOME) -Lmlx -lmlx -framework OpenGL -framework Appkit

AR = ar -rc

SRCS_DIR = ./src
OBJS_DIR = ./objs
INC_DIRS = -Ilibft -I$(HOME)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a

SRCS =  main.c \
		check_cub.c \
		get_next_line_utils.c \
		get_next_line.c \
		init_struct.c \
		check_error.c \
		check_cub_bis.c \
		check_cub_bis_bis.c \
		check_map.c \
		check_map_bis.c \
		init_world.c \
		init_texture.c \
		get_image.c \

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

.PHONY: all re clean fclean debug

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(MLX)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	$(MAKE) -C $(MLX_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC_DIRS) -o $@ -c $^

debug: CFLAGS += -g3 -fsanitize=address -fno-omit-frame-pointer
debug: LDFLAGS += -fsanitize=address
debug: $(LIBFT) $(OBJS) $(NAME)

valgrind: CFLAGS += -g3
valgrind: $(LIBFT) $(OBJS) $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJS_DIR)
	$(MAKE) -C mlx clean

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re : fclean all