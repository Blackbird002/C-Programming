CC      	= gcc
CFLAGS  	= -Wall -g
LDFLAGS		=
OBJFILES 	= stringToNumber.o
TARGET		= strToNum

default: all

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~