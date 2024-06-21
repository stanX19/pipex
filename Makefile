SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h') $(shell find $(INCLUDE_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

LIBS		= $(LIBFT)

IFLAGS		:= -I. $(HEADERS_INC)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
AR			= ar -rcs
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= pipex
ARGV		= "input.txt" "sleep 1" "sleep 1" "sleep 1" "sleep 1" "sleep 1" "sleep 1" "/dev/stdout"

run: all
	./$(NAME) $(ARGV)

LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

$(LIBFT_DIR):
	touch .gitmodules
	git submodule add --force git@github.com:stanX19/libft.git $(LIBFT_DIR)
	git config -f .gitmodules submodule.$(LIBFT_DIR).branch main
	git submodule update --init --recursive --remote

init_libft: $(LIBFT_DIR)


$(NAME): $(LIBS) $(OBJDIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBS) -o $(NAME)

all: $(NAME)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out

re: fclean $(NAME)

push:
	@echo -n "Commit name: "; read name; make fclean;\
	git add .; git commit -m "$$name"; git push;\
	cd $(LIBFT_DIR); git add .; git commit -m "$$name"; git push;

.PHONY: all clean fclean re bonus push