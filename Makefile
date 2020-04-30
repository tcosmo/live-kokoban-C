CC=gcc
LIBS=-lallegro -lallegro_image
FILES=src/*.c
INC=$(shell pwd)

main: $(FILES)
	$(CC) -o kokoban.out $(FILES) $(LIBS) $(LIBS_ALLEGRO) -I ${INC}