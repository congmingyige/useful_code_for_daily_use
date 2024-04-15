
## 功能
- 自动创建若干个CodeBlocks Project，用于编程比赛等
  - auto create/build several CodeBlocks Project, for programming competition and so on.

- 优点
  - layout文件，设置了一开始的鼠标位置

## 操作
  - 选择你要用的模板项目文件名，默认为muban_name="muban1"。修改muban1里面的main.cpp文件，即你的main.cpp代码。也可以直接用"#include <bits/stdc++.h>"。
  - 选择项目文件名，文件名是从l2变量到r2变量，默认是A-G。也可以设置文件名为数目，这样要设置project_name_mode=1，然后文件名从l2变量到r2变量






# 这是之前写的内容

- 输入
  - way1: 在程序里修改
    - path_out_dir: 创建project的路径
  - way2: cmd argv
    - path l r
      - path: 创建project的路径
      - 输入数字(可以为二位数字或更大)
        - 1 3 :创建文件名为1、2、3的project
      - 输入字母(小写、大写都可以)
        - A C :创建文件名为A、B、C的project
- 其它参数
  - path_old_cbp、path_old_layout: 参考模板(需要修改路径!)
    - 或者可以自动寻找对应路径(TODO)
    从"_getcwd(path_temp, 256);"开始，path_temp依次到达上一级，寻找文件名是否为"for_codeblocks_create_project"
      ```
    int pos = 0;
    int ret = -1;
    while (pos != -1)
    {
        pos = path.find_first_of("/\\", pos + 1);
        _mkdir(path.substr(0, pos).c_str());
    }
      ```
  - add_test_project: 如果为True，则比如有1001文件夹，那么也将有test_1001文件夹

## 例子
- E:\scientific\sci_code\cpp\codeblocks_create_project_auto_test_1 1001 1010
  - E:\scientific\sci_code\cpp\codeblocks_create_project_auto_test_1 有文件夹1001-1010，均为CodeBlocks Project
  - 另外，如果设置了add_test_project=True，那么有文件名为test_1001-test_1010的CodeBlocks Project
- E:\scientific\sci_code\cpp\codeblocks_create_project_auto_test_2 A I
  - E:\scientific\sci_code\cpp\codeblocks_create_project_auto_test_2 有文件夹A-I，均为CodeBlocks Project

## 其它方法
- script
  - https://wiki.codeblocks.org/index.php/Scripting_commands
    - NewProject

## 注意
- path_old_cbp、path_old_layout需要修改路径