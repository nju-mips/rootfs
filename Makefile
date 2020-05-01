APPS     := hello busybox halt
APPS_DIR := $(addprefix apps/, $(APPS))
OBJ_DIR  := build

NEMU_DIR      := ../nemu
NEMU_MIPS32   := $(NEMU_DIR)/build/nemu
IMAGE_CPIO    := $(OBJ_DIR)/rootfs.cpio
IMAGE_CPIO_GZ := $(IMAGE_CPIO).gz

.PHONY: image $(APPS_DIR) clean

export ROOTFS_HOME != pwd

image: $(IMAGE_CPIO_GZ)
$(IMAGE_CPIO_GZ): $(IMAGE_CPIO)
	gzip -9 -c -n $< > $@

$(IMAGE_CPIO): $(APPS_DIR)
	cd build/root && \
	  find . | cpio --quiet -o -H newc > ../$(@F)

$(APPS_DIR): %:
	-$(MAKE) -s -C $@ install

clean:
	-$(foreach app, $(APPS_DIR), $(MAKE) -s -C $(app) clean ;)
	-rm -rf $(OBJ_DIR)
