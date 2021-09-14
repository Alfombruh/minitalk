CC = clang

CFLAGS = -Werror -Wall -Wextra 

SERVER = server
SERVER_SRCS = server.o

CLIENT = client
CLIENT_SRCS = client.o 

SRCS = 	libft/ft_putstr_fd.o \
	   	libft/ft_putchar_fd.o \
	   	libft/ft_atoi.o \ 
		libft/ft_putnbr_fd.o \ 

all : $(SERVER) $(CLIENT)

$(CLIENT) : $(CLIENT_SRCS)
	$(MAKE) -c libft
	@$(CC) $(CLIENT_SRCS) $(SRCS) -o $(CLIENT)

$(SERVER) : $(SERVER_SRCS)
	$(CC) $(SERVER_SRCS) $(SRCS) -o $(SERVER)

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :

