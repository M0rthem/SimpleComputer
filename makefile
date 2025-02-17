CC = gcc
INCLUDES = -I ../include
SRC = src
OBJ = obj

INCLUDES = ./include

CONSOLEDIR = ./console
SRCS_CONSOLE = $(wildcard $(CONSOLEDIR)/$(SRC)/*.c)
OBJS_CONSOLE = $(SRCS_CONSOLE:$(CONSOLEDIR)/$(SRC)/%.c=$(CONSOLEDIR)/$(OBJ)/%.o)

COMPUTERDIR = ./mySimpleComputer
SRCS_COMPUTER = $(wildcard $(COMPUTERDIR)/$(SRC)/*c)
OBJS_COMPUTER = $(SRCS_COMPUTER:$(COMPUTERDIR)/$(SRC)/%.c=$(COMPUTERDIR)/$(OBJ)/%.o)
LIBCOMPUTER = mySimpleComputer
LIBCOMPUTERPATH = $(COMPUTERDIR)/lib$(LIBCOMPUTER).a

TERMDIR = ./myTerm
SRCS_TERM = $(wildcard $(TERMDIR)/$(SRC)/*.c)
OBJS_TERM = $(SRCS_TERM:$(TERMDIR)/$(SRC)/%.c=$(TERMDIR)/$(OBJ)/%.o)
LIBTERMINC = myTerm
LIBTERMPATH = $(TERMDIR)/lib$(LIBTERMINC).a

all: ./console/console

./console/console: $(OBJS_CONSOLE) $(LIBCOMPUTERPATH) $(LIBTERMPATH)
	$(CC) $(OBJS_CONSOLE) -L $(COMPUTERDIR) -L $(TERMDIR) -l$(LIBCOMPUTER) -l$(LIBTERMINC) -o ./console/console

$(CONSOLEDIR)/$(OBJ)/%.o: $(CONSOLEDIR)/$(SRC)/%.c
	$(CC) -c -I $(INCLUDES) $< -o $@


$(LIBCOMPUTERPATH): $(OBJS_COMPUTER)
	ar rcs $(LIBCOMPUTERPATH) $(OBJS_COMPUTER)

$(COMPUTERDIR)/$(OBJ)/%.o: $(COMPUTERDIR)/$(SRC)/%.c
	$(CC) -c -I $(INCLUDES) $< -o $@



$(LIBTERMPATH): $(OBJS_TERM)
	ar rcs $(LIBTERMPATH) $(OBJS_TERM)

$(TERMDIR)/$(OBJ)/%.o: $(TERMDIR)/$(SRC)/%.c
	$(CC) -c -I $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS_CONSOLE) $(OBJS_TERM) $(OBJS_COMPUTER) $(LIBTERMPATH) $(LIBCOMPUTERPATH) ./console/console
