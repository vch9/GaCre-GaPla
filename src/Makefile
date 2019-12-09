DIRS = elems actions common board cells files view game

all:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done

