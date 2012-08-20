kernel_practice01 readme
By Guangwei_Jiang, 2012-08-20

程序目的：
向console打印"Hello World!".

测试平台：
android模拟器（基于qemu，android模拟器“评估板”的名称为goldfish）。

知识点：
1. 如何向android模拟器的console打印信息？
   android模拟器中，向地址“0xff002000”写内容将会输出到console, 请参考如下goldfish kernel source,
   arch/arm/mach-goldfish/include/mach/uncompress.h
   #define GOLDFISH_TTY_PUT_CHAR (*(volatile unsigned int *)0xff002000)
2. android模拟器的内存起始地址为多少？内存大小可以控制吗？
   android模拟器的内存起始地址为0x0; 大小可以通过“emulator”中的参数“-memory”控制；
   Goldfish kernel中，关于内存起始地址定义如下，
   arch/arm/mach-goldfish/include/mach/memory.h
   /*
    * Physical DRAM offset.
   */
   #define PHYS_OFFSET	UL(0x00000000)
   #define BUS_OFFSET	UL(0x00000000)
3. 我们编译的image，将会被加载到内存什么位置？
   这是一个好问题^_^
   目前我还没有找到比较有力的资料或代码，来证明image会加载到什么位置；
   但从测试结果来看，只有将"Ttext"设为0x00010000代码才能正常运行，推测image将会被加载到64KB处；
   如果代码真的被加载到了64KB处，那么向量表(vector table)就不能写在head.S的start处（因为此处的偏移地址为0x10000，64KB），
   而需要借助MMU映射到高处（Vector Table可以位于0x0或者0xFFFF0000处）；


****************************************    
如何build image:
运行"./build_image.sh" build image;
Tips:
1. "build_image.sh"中，首先设置"arm gcc"的环境变量，然后呼叫"make"进行编译和链接;
2. "Makefile"说明：
   2.1 "xx-gcc"：     为编译指令;
   2.2 "xx-ld"：      为链接指令, 其中参数“-Ttext”为链接初始地址，默认为0;
   2.3 “xx-objcopy”： 为二进制拷贝指令;
   2.4 “xx-objdump”： 为反编译指令，主要用于debug目的（如程序出问题，可查看汇编指令得到更多信息）；
   
如何清除bin以及obj档:
运行"make clean"清除bin以及obj档;
   
如何启动android模拟器：
运行“./launch_emulator.sh”启动android模拟器。
Tips:
emulator部分参数说明，更多信息请查看“emulator -help”，
1. "-kernel":       加载kernel，参数为kernel的文件名。我们生成的image将会通过此参数加载；
2. “-avd”：         android模拟器配置档，我们的测试虽然和android没有任何关系，但还必须填写这个参数；
3. “-show-kernel”： 通过console输出内核信息，可以帮助我们debug程序是否运行正确；
4. “-no-window”：   不显示模拟器窗口；
5. “-memory”：      内存大小设置，范围为32MB至2GB;

