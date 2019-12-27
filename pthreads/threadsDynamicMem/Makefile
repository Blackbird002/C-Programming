CC      	= gcc
CFLAGS  	= -Wall -g -Werror
LDFLAGS		= -pthread
OBJFILES 	= threadsDynamicMem.o
TARGET		= threadsDynamicMem

default: all

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~