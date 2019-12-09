all:
	$(MAKE) -C src/
	ln -sf ./src/game/gp ./gp
	ln -sf ./src/files/gc ./gc

clean:
	$(MAKE) -C src/ clean
	rm gc
	rm gp
