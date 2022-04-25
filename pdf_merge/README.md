

## 功能
- PDF合并

## 环境
- 安装pdftk，使用pdftk.exe
- Python

## 使用
- 处理文件夹里所有pdf，生成的文件名为文件夹的名字
- pdf_merge_no_input_path.bat
  - 放到对应文件夹
- pdf_merge_with_input_path.bat
  - 输入对应路径
- 修改bat文件里的py文件路径
- windows(linux则用其它代替bat)

## 例子
- A文件夹里有1.pdf和2.pdf
  - 运行pdf_merge_no_input_path.bat，得到A.pdf(把1.pdf和2.pdf合并了)
  - 运行pdf_merge_with_input_path.bat，输入A文件夹的路径，得到A.pdf(把1.pdf和2.pdf合并了)