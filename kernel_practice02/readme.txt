kernel_practice02 readme
By Guangwei_Jiang, 2012-08-24

程序目的：
主程序(main)创建两个子程序（task01,task02），然后两个子程序相互切换。

测试平台：
android模拟器（基于qemu，android模拟器“评估板”的名称为goldfish）。

知识点：
1. 深入理解内存layout
   kernel_practice02的内存layout如下，主要分为3大类型区块:
   a. Image Code Area: 存放代码的区域（思考, 代码是被谁搬到这块区域？）；
   b. 任务栈顶指针保存区(Tasks' Stack Address Saved Area)：保存不同任务的栈顶指针（思考：如果没有这个区域，可以吗？）；
   c. 堆栈区(Task Stack Area): 不同的任务都有自己的堆栈区域，本程序的堆栈是自上向下生长；
		|--------------------| 0x00000000
		|     reserved       |
		|--------------------| 0x00001000
		|     Image Code     |
		|        Area        |
		|--------------------| 0x00100000
		|   Tasks' Stack     |
		|   Address Saved    |
		|        Area        |
		|--------------------| 0x00180000
		|     Main Task      |
		|     Stack Area     |
		|--------------------| 0x00200000
		|       Task01       |
		|     Stack Area     |
		|--------------------| 0x00280000
		|       Task02       |
		|     Stack Area     |
		|--------------------| 0x00300000
		|                    |
		|     reserved       |
		|                    |
		
2. 什么是任务运行的上下文(context)？
   就我的理解而言，“上下文(context)”就是指除去代码外，运行这个任务所需要的环境。
   “上下文(context)”主要包括任务运行所需要的寄存器和堆栈。
3. 如何创建任务运行的“上下文(context)”？
   创建任务运行的“上下文(context)”主要包括两个部分，
   一是，初始化寄存器，其中PC指向要执行代码的地址；
   二是，为新的任务分配堆栈空间（思考：如何分配堆栈空间？分配时需要注意什么？）；
   具体代码，请参考tasks.c中的函数task_create（）。
4. 为什么要创建多个任务？现在的系统都需要多任务系统吗？
   这是一个很好的问题^_^
   对于功能比较简单且实时性要求很高的系统，如果单任务系统可以完成目标，则不推荐使用多任务系统；
   如果必须要用多任务系统，则推荐使用比较成熟的系统如linux/uc-os等，这样更经济高效。
   （思考：为什么单任务系统会比多任务系统更加高效？）
5. 多任务系统如何实现？
   为使问题单纯，我们这里谈到的运行平台，都是单CPU架构。
   所以，问题变成了，单个CPU如何同时运行多个任务？
   我们知道，任务运行需要“上下文(context)”，即寄存器和堆栈；
   堆栈空间可以从内存中划分一块，但是CPU只有一套寄存器，该如何办呢？
   方法就是，同一时间只允许运行一个任务；
   正在运行的任务完全拥有CPU所有寄存器的使用权；而其他处于休眠状态的任务，它们的寄存器状态则暂存在堆栈中。
   当任务切换时，先把当前任务的寄存器状态暂存在堆栈中；然后把将要运行任务的寄存器，从堆栈中恢复。
   具体代码，请参考head.S中的函数task_sched_main_to_01()/task_sched_01_to_02()/task_sched_02_to_01().
  
未解之谜：
1. 宏定义的问题
   如果在tasks.h中，这样定义TASK01_STK_PTR和TASK02_STK_PTR.
   奇怪的是，从反汇编代码(kernel_practice.dis)中看,
   TASK01_STK_PTR不是期望中的0x00100004, 而是0x00100010;
   TASK02_STK_PTR不是期望中的0x00100008, 而是0x00100020;
   造成任务创建失败。
   #define STK_PTR_SIZE				0x4		
   #define TASK_MAIN_STK_PTR		((unsigned long *)0x00100000)
   #define TASK01_STK_PTR			((unsigned long *)(TASK_MAIN_STK_PTR + STK_PTR_SIZE))
   #define TASK02_STK_PTR			((unsigned long *)(TASK01_STK_PTR + STK_PTR_SIZE)) 
   移除前面的(unsigned long *)后，问题消失。
   有兴趣的可以琢磨其中的缘由。

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

