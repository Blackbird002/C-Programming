CC      	= gcc
CFLAGS  	= -Wall
LDFLAGS		=
OBJFILES 	= Stack.o main.o
TARGET		= stackTest

default: all

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~