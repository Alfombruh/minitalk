SERVER = server
CLIENT = client
CC = clang
CFLAGS = -Werror -Wall -Wextra 
RM = rm -rfv

FILES = libft/ft_putstr_fd \
		libft/ft_putchar_fd \
		libft/ft_putnbr_fd	\
		libft/ft_strlen	\
   		libft/ft_atoi 


SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))
SERVER_SRCS = $(addsuffix .c, $(SERVER))
SERVER_OBJS = $(addsuffix .o, $(SERVER))
CLIENT_SRCS = $(addsuffix .c, $(CLIENT))
CLIENT_OBJS = $(addsuffix .o, $(CLIENT))

.c.o: $(FILES) $(SERVER) $(CLIENT)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(CLIENT) $(SERVER) : $(CLIENT_OBJS) $(SERVER_OBJS)
	@$(MAKE) -C libft
	@$(CC) $(CLIENT_SRCS) $(SRCS) -o $(CLIENT)
	@printf "\e[32mCLIENT CREATED😎\e[0m\n"
	@$(CC) $(SERVER_SRCS) $(SRCS) -o $(SERVER)
	@printf "\e[31mSERVER CREATED🤠\e[0m\n"
	$(RM) *.o
	

clean :
	@rm -f client.o server.o libft/*.o
	@printf "\e[31m.o files deleted\e[0m\n"

fclean : clean
	@rm -f $(SERVER) $(CLIENT) libft/libft.a
	@printf "\e[31mServer and Client deleted + ratio\e[0m\n"

all : $(SERVER) $(CLIENT)

re: fclean all 

.PHONY: all clean fclean re

