CC      	= gcc
CFLAGS  	= -Wall -g -Werror
LDFLAGS		= -pthread
OBJFILES 	= threadsMutexLock.o
TARGET		= threadsMutexLock

default: all

all: $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~