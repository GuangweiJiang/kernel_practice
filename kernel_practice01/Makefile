objs := head.o misc.o main.o

kernel_practice.bin: $(objs)
	arm-eabi-ld -Ttext 0x0010000 -o kernel_practice_elf $^
	arm-eabi-objcopy -O binary -S kernel_practice_elf $@
	arm-eabi-objdump -D -m arm kernel_practice_elf > kernel_practice.dis
	
%.o:%.c
	arm-eabi-gcc -Wall -c -o $@ $<

%.o:%.S
	arm-eabi-gcc -Wall -c -o $@ $<

clean:
	rm -f kernel_practice.bin kernel_practice_elf kernel_practice.dis *.o	
