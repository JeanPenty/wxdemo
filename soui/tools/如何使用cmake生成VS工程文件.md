感谢网友“知之”提供的cmake脚本。

要使用cmake生成VS工程首先需要自己安装cmake(使用cmake 3.4.3 或以上版本)

下面以命令行为例演示如何使用cmake来生成VS工程（将下面代码复制到cmd里执行即可）

```cmd

rem 假定你的cmake安装在d:\cmake-3.5.2-win32-x86，假定你还没有把cmake\bin目录添加到path环境变量。
rem 把当前目录切换到soui目录。

set path=%path%;d:\cmake-3.5.2-win32-x86\bin
mkdir build
cd build

rem 生成sln
rem cmake .. -G"Visual Studio 9 2008"
rem 生成makefile
cmake .. -G"NMake Makefiles"
nmake

```