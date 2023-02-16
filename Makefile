NAME					=	fdf

LIBFTDIR				=	./libft/
MLXDIR					=	./mlx42/
SRCDIR					=	./src/
LIBDIR					=	./lib/
INCLUDEDIR				=	./include/

LIBFTNAME				=	libft.a
MLXNAME					=	libmlx42.a
SRCFILES				=	fdf.c			\
							init.c			\
							parse.c			\
							screen.c		\
							draw.c			\
							hooks.c			\
							wireframe.c		\
							util/vectors.c	\
							util/matrices.c	\
							util/color.c	\
							util/grid.c		\
							util/math.c		\
							util/misc.c		\

SRCS					=	$(addprefix $(SRCDIR), $(SRCFILES))

CC						=	gcc
CFLAGS					=	-Wall -Wextra -Werror -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
RM						=	rm -f

all:					$(NAME)

$(NAME):				$(LIBDIR)$(LIBFTNAME) $(LIBDIR)$(MLXNAME) $(SRCS) $(INCLUDEDIR)fdf.h
							$(CC) $(CFLAGS) $(SRCS) $(LIBDIR)$(LIBFTNAME) $(LIBDIR)$(MLXNAME) -I $(INCLUDEDIR) -o $(NAME)

$(LIBDIR)$(LIBFTNAME):
							$(MAKE) -C $(LIBFTDIR)

$(LIBDIR)$(MLXNAME):
							$(MAKE) -C $(MLXDIR)

clean:
							$(RM) $(NAME)

fclean:					clean
							$(MAKE) fclean -C $(LIBFTDIR)
							$(MAKE) fclean -C $(MLXDIR)

re:						fclean all

.PHONY:					all clean fclean re

