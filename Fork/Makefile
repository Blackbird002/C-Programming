CC      	= gcc
CFLAGS  	= -Wall -g
LDFLAGS		=
OBJFILES 	= fork.o
TARGET		= fork

default: all

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~