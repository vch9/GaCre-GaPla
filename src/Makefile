DIRS = elems actions common board game cells files

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

