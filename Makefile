all:
	$(MAKE) -C src/
	$(MAKE) -C server/
	$(MAKE) -C client/
	ln -sf ./src/game/gp ./gp
	ln -sf ./src/files/gc ./gc

clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C server/ clean
	$(MAKE) -C client/ clean
	rm gc
	rm gp
