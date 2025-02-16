CC = gcc
CFLAGS = -I ../include
SRCDIR = ./src
OBJDIR = ./obj
SCLIBDIR = ../mySimpleComputer
SCLIBDIR2 = ../myTerm
SCLIB = mySimpleComputer
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = pr01

all:$(TARGET)

$(TARGET):$(OBJS) $(SCLIBDIR)/lib$(SCLIB).a
	$(CC) -o $(TARGET) $(OBJS) -L$(SCLIBDIR) -l$(SCLIB) -L$(SCLIBDIR2) -l myTerm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(SCLIBDIR)/lib$(SCLIB).a:
	cd ../mySimpleComputer && make
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)