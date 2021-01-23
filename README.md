# newCprojectforVscode
这个小玩意可以迅速建立linux-vscode下的C工程结构，快速生成适应多文件编译调试的*.json文件(linux平台下)

## 使用说明
在ubuntu中，使用vscode打开该工程，再确认*.json文件中的gcc路径以及gdb路径（或其他用于编译或者调试的工具路径）正确时，ctrl+shift+B即可编译，F5调试运行。

最好将生成的可执行文件路径加入PATH环境变量，该程序需要两个参数，工程名以及可执行文件名，参数一定要正确。

## 目录说明
root_dir/

&emsp;|---.vscode/
   
&emsp;&emsp;|----tasks.json      //默认生成任务
          
&emsp;&emsp;|----launch.json     //调试运行文件
          
&emsp;|---include/                //存放.h文件
   
&emsp;|---src/                    //存放.c文件
   
&emsp;&emsp;|----root_dir.c      //样例.c文件
