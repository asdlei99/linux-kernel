obj-m += hello.o  
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
test:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo dmesg -C
	sudo insmod hello.ko
	lsmod | grep hello
	sudo rmmod hello.ko
	dmesg