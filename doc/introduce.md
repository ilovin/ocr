# 识别
### 算法流程
### 现状
将发票的第11行的item设置为empty，暂时不做ocr识别
### GTD
- 加入设置文件夹功能，识别文件夹下所有图片
- 去除识别出的乱码符号

### 依赖
#### link flags
\`pkg-config --cflags --libs opencv\` 
-lstdc++fs //directory iterator
-pthread //multi thread

