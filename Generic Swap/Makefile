CC      	= gcc
CFLAGS  	= -Wall -g
LDFLAGS		=
OBJFILES 	= main.o
TARGET		= swap

default: all

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~