# RiskAnalysis

读取各个指标的值，进行计算分析输出风险系数、风险值、风险等级

## 原始数据说明

1、数据库样本库样例![1584099099636](H:\3.open\RiskAnalysis\screenshot\数据库格式.png)

2、将数据库文件，输入的已知量，参数控制文件，整理成逗号分隔的标准文本格式，以供程序读取输出

## 样例数据及程序设计

1、database.txt数据库

![1584101180445](H:\3.open\RiskAnalysis\screenshot\数据库格式文件示例.png)

2、input.txt输入数据，需要进行分析的已知数据

![1584101293931](H:\3.open\RiskAnalysis\screenshot\输入数据示例.png)

3、database_param.txt数据库参数文件

![1584102071686](H:\3.open\RiskAnalysis\screenshot\控制参数示例.png)

4、output.txt根据输入文件，计算后的输出文件，增加两列计算值

![1584102176389](H:\3.open\RiskAnalysis\screenshot\计算结果示例.png)

**特别说明：**OUT_LEVEL是风险等级，等级编号规则，示意图如下：

![1584102872229](H:\3.open\RiskAnalysis\screenshot\风险等级编号示意图.png)

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

   ## 如何运行

   默认情况下，运行exe程序，会自动读取输入文件input.txt，并计算后写输出结果到output.txt中，行尾增加两列，一列风险值，一列风险等级

   后续优化后支持，数据样本中增减字段，输入字段比数据样本中字段少的话，需要重新制定阈值参数