# rootfs - A simplified version of root file system

notes:
* this repo depends on github.com/nju-mips/buildroot
    * before building rootfs, buildroot needs to be downloaded
    * buildroot provides uclibc-gcc, which is used to compile busybox
* busybox is automatically downloaded from git://git.busybox.net/busybox, branch 1_29_stable
    * busybox's configure file is located at apps/busybox/config
* halt is similar to poweroff, it terminates the emulator
    * it write value 0 to nemu trap address 0xb0000000
