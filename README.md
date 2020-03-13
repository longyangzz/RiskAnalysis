# RiskAnalysis

读取各个指标的值，进行计算分析输出风险系数、风险值、风险等级

## 原始数据说明

1、数据库样本库样例![1584099099636](.\screenshot\database.png)

2、将数据库文件，输入的已知量，参数控制文件，整理成逗号分隔的标准文本格式，以供程序读取输出

## 样例数据及程序设计

1、database.txt数据库

![1584101180445](.\screenshot\databasetxt.png)

2、input.txt输入数据，需要进行分析的已知数据

![1584101293931](.\screenshot\input.png)

3、database_param.txt数据库参数文件

![1584102071686](.\screenshot\controlparams.png)

4、output.txt根据输入文件，计算后的输出文件，增加两列计算值

![1584102176389](.\screenshot\output.png)

**特别说明：**OUT_LEVEL是风险等级，等级编号规则，示意图如下：

![1584102872229](.\screenshot\risknumber.png)

## 使用注意事项

1. 使用文件均使用文本格式，通用扩展名.txt

2. 文本内内容使用逗号分隔符

3. 参数控制文件使用#特殊符号代表注释，PARAM_开头为接下来内容的描述

4. 共使用到4个文件，且名称是固定的

   | 文件名              | 内容描述   |
   | ------------------- | ---------- |
   | database.txt        | 数据库样本 |
   | database_params.txt | 控制参数   |
   | input.txt           | 输入文件   |
   | output.txt          | 输出文件   |

5. 文本内的参数描述，命名使用全大写，关键词以下划线_分隔

6. 计算涉及的文件默认存放于exe程序的同级data目录下

7. 单个database.txt文本中每行的数据记录要与第一行的字段个数一致，必须有ID列，有效数据从第二列解析

8. 控制参数文件由于使用了#符号注释，文件可以有空行，也可以有注释，其它输入文件，第一行为表头，第二为内容

9. 输入和输出也都带ID为第一列，便于验证数据是否正确，这里的ID值，只是行记录号，与database中的ID不一个意义，database.txt中的ID在后续的计算中没有用到

10. 如果字段输入中没有安全系数值，设置默认值为0

11. 等于阈值的时候，风险等级怎么区分？

12. 不存在合适的区间，默认返回风险等级0

13. 你确定你的风险等级编号既不是逆时针也不是顺时针？

14. 公式编码有两种，1,2不是 0,1。如果非这几个值，则为异常值，默认使用1方法

    ## 如何运行

    默认情况下，运行exe程序，会自动读取输入文件input.txt，并计算后写输出结果到output.txt中，行尾增加两列，一列风险值，一列风险等级

    后续优化后支持，数据样本中增减字段，输入字段比数据样本中字段少的话，需要重新制定阈值参数