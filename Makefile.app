ifeq ($(ROOTFS_HOME),)
	$(error ROOTFS_HOME is not defined)
endif

ifeq (run, $(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

APP_DIR ?= $(shell pwd)
INC_DIR += $(APP_DIR)/include/
DST_DIR ?= $(APP_DIR)/build/
APP ?= $(APP_DIR)/build/$(NAME)

.DEFAULT_GOAL = $(APP)

$(shell mkdir -p $(DST_DIR))

.PHONY: install clean

install: $(APP)
	@ln -sf $(APP) $(ROOTFS_HOME)/image/build/$(NAME)

clean: 
	rm -rf $(APP_DIR)/build/
