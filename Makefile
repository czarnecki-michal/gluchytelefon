LKM=lkm
APP=src

all: uninstall chardev compileapp install run

chardev:
	cd $(LKM) && $(MAKE) build

compileapp:
	cd $(APP) && $(MAKE)

install:
	$(MAKE) -C $(LKM) install

uninstall:
	$(MAKE) -C $(LKM) uninstall

clean:
	cd $(LKM) && $(MAKE) clean
	cd $(APP) && $(MAKE) clean

run:
	cd $(APP) && ./1_konsola.out
