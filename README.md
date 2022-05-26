# c----
## 项目名称
*学生管理系统*
## 前言
本系统是c++的相关使用，包括类的封装，以及easyx相关库的使用，同时运用了多线程相关操作增加了运行速率，提高效率，本系统纯gui化，简单实用。
## 相关模块及函数
*创建链表*

void listt(const char* namee, const char* sidd, const char* idd, score& ss);

*删除某个节点*

void del(stu* t);

*删除所有节点*

void delall();

*保存学生信息到文件*

void save();

*读取文件信息*

void readin(void*);

*创建学生信息*

void pr_creat(void);

*开始界面*

void pr_start();

*展现学生信息*

void pr_display(int n,int cla,int pageall);			*(x,y,z)x:数组下缀，y：比较类型，z：总页数     0，总成绩，1，语文，2，数学，3，英语，4，cpp*

*当前学生数量*
int numget();

*排序*

int sortt(int cla);

*分数段输入及查询*

void pr_scoreseg(int cla);

*查询排名*

void pr_seekrank();

*搜索压入vector*

int seekpush(string a, string b, string c);					//cla:1,姓名，2，sid，3，id

int seekpush(int cla, int sta, int end);		//cla：1，all,2,chnese,3,math,4,english,5,cpp

*个人界面*

void pr_indi(stu*stud);

*搜索删除*

void pr_delete();

*比较函数*

bool cmpsum(stu* a, stu* b);

bool cmpchinese(stu* a, stu* b);

bool cmpmath(stu* a, stu* b);

bool cmpenglish(stu* a, stu* b);

bool cmpcpp(stu* a, stu* b);
## 环境部署
### 一、安装visual studio 2022
#### 1.进入微软官网，打开visual studio的下载页面 <https://visualstudio.microsoft.com/> 
#### 2.点击下载，选择适合的系统版本安装，visual studio共有*community*,*professional*和*business version*，这里推荐使用*communuty*版本，适合个人用户使用
#### 3.尽量安装在默认路径，有些tool必须安装在系统盘，在配置visual studio 2022的时候，选择*使用c++的桌面开发*，点击安装，等待片刻即可
#### 4.安装完毕后需要重启
### 二、安装Easyx库
#### 1.百度搜索Easyx，打开<https://easyx.cn/>，直接下载即可
#### 2.打开exe文件，会自动检索系统中存在的visual studio版本，选择2022版本即可，点击安装，等待安装完毕即可
### 三、运行文件
#### 下载源码，保存到合适路径，选择sln文件，选择打开路径，选择visual studio 2022打开，直接运行即可
## 使用说明
### */本系统可实现基本功能，创建，检索，排名，基本覆盖使用需求/*
### 一、.创建
#### */name只能输入英文名/*
#### 点击*create new student*按钮，分别点击每个输入框进行输入，输入完毕后需要回车，需填写完所有信息才可点击create
### 二、分数段查询：
#### 1.支持科目分数查询，点击*seek segment*，然后选择合适的科目：*sumscore*,*chinese**math*,*english*,*cpp*,右侧为该科目或总分最高的名字或分数
#### 2.选择完科目后，输入起始分数和最高分数，然后点击*seek*，会根据相应科目进行排名，同时点击排名会展现该学生具体信息
#### 3.在学生信息界面可对学生信息进行修改或删除该学生信息，点击*revise*然后直接点击想修改的信息，输入修改后的信息，点击*sure*即可保存，直接点击*delete*即可删除该学生
### 三、学生查询
#### 1.点击*seek student*，分别点击输入*student name*，*student id*，*id*的相应内容，可进行模糊搜索。
#### 2.输入完毕点击*seek*，会将符合条件的学生列成表格，可进行与*二*同样的操作，对学生的信息进行修改或者删除
### 四、退出
## 源码地址
<https://github.com/weatol/c---->
## 联系方式
如果在使用过程中发现bug，请反馈到邮箱709751645@qq.com
## 后续开发期望
将不断完善相关内容，添加更多功能，完善分离前后端，使用数据库等存储数据，使数据更加持久化，同时建立相关社区，可以共同讨论，使用qt等相关软件开发跨平台app，同时会支持相关账户登录，分离独立账户，可以多人协作，完善内容
