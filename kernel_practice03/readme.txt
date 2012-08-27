kernel_practice03 readme
By Guangwei_Jiang, 2012-08-27

程序目的：
主程序(main)创建两个子程序（task01,task02），然后两个子程序相互切换。
改进程序，只需调用函数task_sched()即可实现不同任务之间的切换。

测试平台：
android模拟器（基于qemu，android模拟器“评估板”的名称为goldfish）。

知识点：
1. 轮转调度法
   kernel_practice03里采用了最简单的“轮转调度法”，即task01->task02->task03->...->task01->...
   任务调度过程中，在保存当前任务堆栈的同时，会计算下一个任务的栈顶指针；
   程序中定义了四个十分重要的宏：
   TASK_MIN_STK_PTR，指向第一个任务的“栈顶指针”存放位置；
   TASK_MAX_STK_PTR，指向最后一个任务的“栈顶指针”存放位置；
   TASK_CUR_STK_PTR，指向当前任务的“栈顶指针”存放位置；
   TASK_NEXT_STK_PTR，指向下一个任务的“栈顶指针”存放位置；
   **注意：如果增加新的任务，需要调整“TASK_MAX_STK_PTR”为指向最后一个任务的“栈顶指针”存放位置；
   
思考题：
1. 如何再增加第三/第四个任务，并且循环调用(调用函数task_sched())？
2. 程序中，子程序“主动”调用task_sched()来放弃自己的时间片；
   这就有一个问题：如果某些子程序永远不调用task_sched()，即不愿放弃自己的时间片，就有失公允；
   想一想，可以通过什么策略来防止这种情况发生？

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

