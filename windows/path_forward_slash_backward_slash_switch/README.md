
## 功能
- （windows中，），对于剪贴板的路径，进行斜杠的转换。若路径包含'\'，则改为'/'；若路径包含'/'，则改为'\'

## 例子
- 剪贴板为"E:\1\2"
  - 改为"E:/1/2"
- 剪贴板为"E:/1/2"
  - 改为"E:\1\2"

## 环境
- 安装python
- 运行bat文件(run_py_path_forward_slash_backward_slash_switch.py.bat)
- bat放在如"C:\Users\{Username}\Documents"里。按"Win"键，搜索"slash"或其它，然后这个bat就有显示，点击bat，即可完成。也可以放在按"Win"键后显示的磁贴里，或设置快捷方式运行

## 使用原因
- 一般用于需要提供路径：从windows复制的，为'\'，而有时需要包含'/'的路径

## 其它方式
- some software(aim for better daily use of computer), shortkey
- ditto, script post-operation