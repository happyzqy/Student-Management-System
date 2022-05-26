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
###
#### 1.进入微软官网，打开visual studio的下载页面 <https://visualstudio.microsoft.com/> 。
#### 2.点击下载，选择适合的系统版本安装，visual studio共有community,professional和企业版本，这里推荐使用communuty版本，适合个人用户使用
#### 
## 源码地址
<https://github.com/weatol/c---->
## 联系方式
如果在使用过程中发现bug，请反馈到邮箱709751645@qq.com
## 后续开发期望
将不断完善相关内容，添加更多功能，完善分离前后端，使用数据库等存储数据，使数据更加持久化，同时建立相关社区，可以共同讨论，使用qt等相关软件开发跨平台app，同时会支持相关账户登录，分离独立账户，可以多人协作，完善内容
