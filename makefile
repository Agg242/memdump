CC := vc
ECHO=mecho

SRCLIB := /SRCLIB/ez-C
SRCS=$(wildcard *.c)
INCS := $(wildcard *.h)
OBJS=$(patsubst %.c,%.o,$(SRCS))
TARGET := memdump 


# 163: accept l'utilisation de pragmas

CFLAGS := -g -warn=-1 -dontwarn=163 -c99 -+ -O=0 -warnings-as-errors -I$(SRCLIB) -DDEBUG

LFLAGS := -g

# the target build
.PHONY: all
all: $(TARGET)

$(OBJS): $(INCS) $(SRCLIB)/dbg/dbg.h

$(TARGET): $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

.PHONY: clean
clean:
	@-delete *.o
	@-delete $(TARGET)



