# THIS MAKEFILE COMPILES THE LIBFT LIBRARY

NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f

SRCDIR			=	./src/
BINDIR			=	./bin/
LIBDIR			=	../lib/
INCLUDEDIR		=	../include/
LIBFTHEADERDIR	=	./include/

SRCFILES		=	ft_isalnum.c			\
					ft_isprint.c			\
					ft_memcmp.c				\
					ft_putchar_fd.c			\
					ft_split.c 				\
					ft_strlcat.c 			\
					ft_strncmp.c 			\
					ft_substr.c				\
					ft_atoi.c 				\
					ft_isalpha.c 			\
					ft_itoa.c				\
					ft_memcpy.c				\
					ft_putendl_fd.c			\
					ft_strchr.c				\
					ft_strlcpy.c 			\
					ft_strnstr.c			\
					ft_tolower.c			\
					ft_bzero.c				\
					ft_isascii.c			\
					ft_memmove.c			\
					ft_putnbr_fd.c			\
					ft_strdup.c				\
					ft_strlen.c				\
					ft_strrchr.c 			\
					ft_toupper.c    		\
					ft_calloc.c				\
					ft_isdigit.c			\
					ft_memchr.c				\
					ft_memset.c  			\
					ft_putstr_fd.c			\
					ft_strjoin.c			\
					ft_strmapi.c			\
					ft_strtrim.c			\
					ft_striteri.c			\
					ft_lstnew.c				\
					ft_lstsize.c			\
					ft_lstadd_front.c		\
					ft_lstadd_back.c		\
					ft_lstlast.c 			\
					ft_lstdelone.c			\
					ft_lstclear.c			\
					ft_lstiter.c 			\
					ft_lstmap.c				\
					ft_isspace.c			\
					ft_abs.c				\
					ft_strrev.c				\
					ft_clampnbr.c			\
					ft_isupper.c			\
					ft_islower.c			\
					ft_putunbr_fd.c			\
					ft_puthex_fd.c			\
					ft_putptr_fd.c			\
					ft_printf.c				\
					ft_strnchr.c			\
					ft_min.c				\
					ft_max.c				\
					ft_ishdigit.c			\
					ft_htoi.c				\
					get_next_line.c			\
					get_next_line_utils.c	\

HEADERFILES		=	get_next_line.h			\
					libft.h					\

BINFILES	=		$(SRCFILES:.c=.o)

BINS		=		$(addprefix $(BINDIR), $(BINFILES))
HEADERS		=		$(addprefix $(LIBFTHEADERDIR), $(HEADERFILES))

all:			$(NAME)

$(NAME):		$(BINS)
					@mkdir -p $(LIBDIR)
					@mkdir -p $(INCLUDEDIR)
					@cp $(LIBFTHEADERDIR)libft.h $(INCLUDEDIR)
					ar rcs $(LIBDIR)$(NAME) $(BINS)

$(BINDIR)%.o:	$(SRCDIR)%.c $(LIBFTHEADERDIR)$(HEADERFILE)
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(LIBFTHEADERDIR) -c $< -o $@

clean:
					$(RM) $(BINS)

fclean:			clean
					@$(RM) $(LIBDIR)$(NAME)
					@$(RM) $(addprefix $(INCLUDEDIR), $(HEADERFILES))

re:				fclean $(NAME)

.PHONY:			all clean fclean re