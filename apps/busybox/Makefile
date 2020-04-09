NAME = busybox

include $(ROOTFS_HOME)/Makefile.app

export CROSS_COMPILE=$(ROOTFS_HOME)/../buildroot/output/host/bin/mipsel-buildroot-linux-uclibc-

$(CROSS_COMPILE)gcc:
	cd ../buildroot && make noop_defconfig && make toolchain

REPO_PATH = repo
$(REPO_PATH):
	mkdir -p $@
	git clone --depth 1 -b 1_29_stable git://git.busybox.net/busybox $@
	cp config $@/.config

$(APP): | $(CROSS_COMPILE)gcc $(REPO_PATH)
	$(MAKE) -C $(REPO_PATH)
	ln -sf $(abspath $(REPO_PATH)/busybox) $@
