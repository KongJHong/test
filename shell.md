## 描述

```SHELL
#! /bin/bash
 echo "Hello World!"
 
 控制台
 $ chmod +x hello	##为脚本加上可执行权限（必须）
 $ ./hello			##执行脚本
```



> #! /bin/bash

这一行告诉Shell，运行这个脚本时应该使用哪个Shell程序



## 1.变量和运算符

变量是任何一种编程语言所必备的元素，运算符也是。

### 1.1变量的赋值和使用

```shell
#! /bin/bash

#将一个字符串赋给变量output
log="monday"					##赋值变量是“=”左右两边没空格
echo "The value of logfile is:"
echo $log						##在BASH中，美元符号“$”用于对一个变量进行解析
```



需要指出的是，变量只在其所在的脚本中有效。在上面这个脚本退出后，变量log就失效了，此时在shell中试图查看log的值将什么也得不到

```shell
$ echo $log
```



使用**source**命令可以强行让一个脚本**影响其父Shell环境**。以下面这种方式运行varible脚本可以让log变量在当前Shell中可见

```shell
$ source varible
The value of logfile is:
monday
$ echo $log
monday
```



另一个与之相反的命令是**export**。**export让脚本可以影响其子shell环境**。

```shell
$ export count=5	##输出变量count
$ bash				##启动子shell
$ echo $count		##在子shell中显示变量的值
5		
$ exit				##回到先前的shell中
exit
```



**使用unset命令可以手动注销一个变量.**

```shell
unset log
```

### 1.2变量转换

前面已经提到，美元提示符"$"用于解析变量。如果希望输出这个符号，那么就应该使用转移字符"\\"

```shell
$ log="monday"
$ echo "The value of \$log is $log"
The value of $log is Monday
```



Shell提供了花括号"{}"来限定一个变量的开始和结束。在紧跟变量输出字母后缀时，就必须使用这个功能。

```shell
$ word="big"
$ echo "This apple is ${word}ger"
This apple is bigger
```



