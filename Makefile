OBJ_DIR := build
IMAGE := $(OBJ_DIR)/rootfs.cpio.gz

$(IMAGE): $(shell find skeleton -type f)
	cp -r skeleton $(OBJ_DIR)
	cd $(OBJ_DIR)/skeleton/sbin && mips-linux-gnu-gcc -EL \
	  init.c -o init -nostdlib
	cd $(OBJ_DIR)/skeleton && find . | cpio --quiet -o -H newc > ../rootfs.cpio
	gzip -9 -c -n $(OBJ_DIR)/rootfs.cpio > $@
