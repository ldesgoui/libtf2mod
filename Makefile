
CFLAGS :=-m32 -I. -shared -fPIC -rdynamic -std=gnu11 -fno-omit-frame-pointer -O2 -g -Wall -fdiagnostics-color=always -Wno-unused-variable -Wno-unused-function -march=native -mtune=native -pthread -maccumulate-outgoing-args -masm=intel
LDFLAGS:=-Wl,-z,defs -Wl,--no-undefined -lstdc++ -lm -ldl -lbsd -lelf -liberty
NASMFLAGS:=-f elf32 -g -F dwarf -i. -Ox

SRC_C:=$(shell find . -follow -type f -name '*.c')
OBJ_C:=$(patsubst %.c,%.o,$(SRC_C))
HDR_C:=$(shell find . -follow -type f -name '*.h')

SRC_ASM:=$(shell find . -follow -type f -name '*.s')
OBJ_ASM:=$(patsubst %.s,%.o,$(SRC_ASM))
HDR_ASM:=$(shell find . -follow -type f -name '*.inc')

SOURCES:=$(SRC_C) $(SRC_ASM)
OBJECTS:=$(OBJ_C) $(OBJ_ASM)
HEADERS:=$(HDR_C) $(HDR_ASM)

CHEATS:=0
DUMP:=0


.PHONY: all clean fclean re
all: libtf2mod.so
clean:
	rm -rf $(shell find . -iname '*.o')

fclean: clean
	rm -f libtf2mod.so

re: fclean all

libtf2mod.so: $(OBJECTS) Makefile
	gcc $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.c $(HDR_C) Makefile
	@printf '$@                                              \r'
	@gcc $(CFLAGS) -DCHEATS=$(CHEATS) -DDUMP=$(DUMP) -o $@ -c $<

%.o: %.s $(HDR_ASM) Makefile
	@printf '$@                                              \r'
	@nasm $(NASMFLAGS) -o $@ $<
