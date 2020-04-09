$(shell mkdir -p image/build)

APPS = halt busybox hello
APPS_DIR = $(addprefix apps/, $(APPS))

.PHONY: image $(APPS_DIR) clean

export ROOTFS_HOME != pwd

INITRAMFS_TXT := $(PWD)/image/build/initramfs.txt

hello-image: $(addprefix apps/, hello)
	rm -f $(INITRAMFS_TXT)
	ln -s $(PWD)/image/skeleton/initramfs-hello.txt \
	  $(INITRAMFS_TXT)

busybox-image: $(APPS_DIR)
	rm -f $(INITRAMFS_TXT)
	ln -s $(PWD)/image/skeleton/initramfs-busybox.txt \
	  $(INITRAMFS_TXT)

$(APPS_DIR): %:
	-$(MAKE) -s -C $@ install

clean:
	-$(foreach app, $(APPS_DIR), $(MAKE) -s -C $(app) clean ;)
	-rm -f image/build/*
