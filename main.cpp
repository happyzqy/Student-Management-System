#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;




class object
{
public:
	char name[15] = { 0 };
};





//成绩类

class score:virtual public object
{
	friend class stu;
public:
	//构造函数
	score(int a = 0, int b = 0, int c = 0, int d = 0);
	//复制构造函数
	score(score& a);
	//析构函数
	~score() {}
	//修改语文成绩
	void setchinese(int a);
	//修改数学成绩
	void setmath(int a);
	//修改英语成绩
	void setenglish(int a);
	//修改cpp成绩
	void setcpp(int a);
	//获得语文成绩
	int getchinese();
	//获得数学成绩
	int getmath();
	//获得英语成绩
	int getenglish();
	//获得cpp成绩
	int getcpp();
	//总成绩计算
	void add();
	int getall();
private:
	int chinese, math, english, cpp,allscore;
};









				//总成绩计算
void score::add()
{
	allscore = chinese + math + english + cpp;
}
int score::getall()
{
	return allscore;
}
				//构造函数
score::score(int a , int b, int c, int d )
{
	chinese = a;
	math = b;
	english = c;
	cpp = d;
	add();
}
				//复制构造函数
score::score(score& a)
{
	chinese = a.chinese;
	math = a.math;
	english = a.english;
	cpp = a.cpp;
	allscore = a.allscore;
	add();
}
				//修改语文成绩
void score::setchinese(int a)
{
	chinese = a;
	add();
}
				//修改数学成绩
void score::setmath(int a)
{
	math = a;
	add();
}
				//修改英语成绩
void score::setenglish(int a)
{
	english = a;
	add();
}
				//修改cpp成绩
void score::setcpp(int a)
{
	cpp = a;
	add();
}
				//获得语文成绩
int score::getchinese()
{
	return chinese;
}
				//获得数学成绩
int score::getmath()
{
	return math;
}
				//获得英语成绩
int score::getenglish()
{
	return english;
}
				//获得cpp成绩
int score::getcpp()
{
	return cpp;
}









class namer:virtual public object
{
public:
	//修改名字
	void setname(const char* namee);
	//获得名字
	char* getname();
};




















//stu类


class stu:public score, public namer
{
	friend class score;
public:
	//无初始化
	stu();
	//构造函数
	stu(const char* namee, const char* sidd, const char* idd, score ss);
	//复制构造函数
	stu(stu& a);
	//析构函数
	~stu() {}
	
	//修改学号
	void setsid(const char* sidd);
	//修改身份证
	void setid(const char* idd);
	//修改成绩
	void setscore(score&a);
	//获得学号
	char* getsid();
	//获得身份证
	char* getid();
	//获得成绩
	score& getscore();
	//输入下一个
	void setnext(stu*a);
	//获得下一个
	stu* getnext();
	//设置上一个
	void setlast(stu* a);
	//获得上一个
	stu* getlast();
private:
	char  sid[20] = { 0 }, id[20] = { 0 };
	score s;
	stu* next = NULL;
	stu* last = NULL;
};




//无初始化
stu::stu()
{ 
	next = NULL;
	last = NULL;
}
//构造函数
stu::stu(const char * namee, const char * sidd, const char * idd, score ss)
{
	strcpy(name, namee);
	strcpy(sid, sidd);
	strcpy(id, idd);
	s = ss;
	next = NULL;
	last = NULL;
}
//复制构造函数
stu::stu(stu& a)
{
	strcpy(name, a.name);
	strcpy(sid, a.sid);
	strcpy(id, a.id);
	s = a.s;
	last = a.last;
	next = a.next;
}
//修改名字
void namer::setname(const char* namee)
{
	strcpy(name, namee);
}
//修改学号
void stu::setsid(const char* sidd)
{
	strcpy(sid, sidd);
}
//修改身份证
void stu::setid(const char* idd)
{
	strcpy(id, idd);
}
//修改成绩
void stu::setscore(score& a)
{
	s = a;
}
//获得名字
char* namer::getname()
{
	return name;
}
//获得学号
char* stu::getsid()
{
	return sid;
}
//获得身份证
char* stu::getid()
{
	return id;
}
//获得成绩
score& stu::getscore()
{
	return s;
}
//输入下一个
void stu::setnext(stu* a)
{
	next = a;
}
//获得下一个
stu* stu::getnext()
{
	return next;
}
//设置上一个
void stu::setlast(stu* a)
{
	last = a;
}
//获得上一个
stu* stu::getlast()
{
	return last;
}



//创建链表
void listt(const char* namee, const char* sidd, const char* idd, score& ss);
//删除某个节点
void del(stu* t);
//删除所有节点
void delall();
//保存学生信息到文件
void save();
//读取文件信息
void readin();
//创建学生信息
void pr_creat(void);
//开始界面
void pr_start();
//展现学生信息
void pr_display(int n,int cla,int pageall);			//(x,y,z)x:数组下缀，y：比较类型，z：总页数     0，总成绩，1，语文，2，数学，3，英语，4，cpp
//当前学生数量
int numget();
//排序
int sortt(int cla);
//分数段输入及查询
void pr_scoreseg(int cla);
//查询排名
void pr_seekrank();
//搜索压入vector
int seekpush(string a, string b, string c);					//cla:1,姓名，2，sid，3，id
int seekpush(int cla, int sta, int end);		//cla：1，all,2,chnese,3,math,4,english,5,cpp
//个人界面
void pr_indi(stu*stud);
//搜索删除
void pr_delete();








stu* head = new stu;
stu* now = head;
vector<stu*>holdon[1000];
stu* first=NULL;
stu* second = NULL;
stu* stb = NULL;
stu* eve = head;
stu* it = head;
vector<stu*>sor;




//创建链表
void listt(const char*namee,const char*sidd,const char*idd,score& ss)
{
	stu* it = new stu;
	now->setnext(it);
	it->setlast(now);
	it->setname(namee);
	it->setid(idd);
	it->setsid(sidd);
	it->setscore(ss);
	it->setnext(NULL);
	now = now->getnext();
}


//删除某个节点
void del(stu* t)
{
	if (t!=head)
	{
		if (t->getnext() == NULL)
			now = t->getlast();
			t->getlast()->setnext(t->getnext());
		delete t;
	}
}


//删除所有节点
void delall()
{
	while (now != head)
		del(now);
}






//保存学生信息到文件
void save()
{
	FILE* p = fopen("student.txt", "wb+ ");
	eve = head->getnext();
	while (eve != NULL)
	{
		char a[6] = { 0 };
		char all[70] = { 0 };
		strcpy(all, eve->getname());
		strcat(all, ".");

		strcat(all, eve->getsid());
		strcat(all, ".");

		strcat(all, eve->getid());
		strcat(all, ".");

		_itoa(eve->getscore().getchinese(), a, 10);

		strcat(all, a);
		strcat(all, "."); 

		_itoa(eve->getscore().getmath(), a, 10);

		strcat(all, a);
		strcat(all, ".");

		_itoa(eve->getscore().getenglish(), a, 10);

		strcat(all, a);
		strcat(all, ".");

		_itoa(eve->getscore().getcpp(), a, 10);
		strcat(all, a);
		strcat(all, ".");

		fwrite(all, 1, strlen(all), p);
		fwrite("\r\n", 1, strlen("\r\n"), p);
		eve = eve->getnext();
	}
	fclose(p);
}


//读取文件信息
void readin()
{
	head = new stu;
	now = head;
	FILE*p = fopen("student.txt", "rb+");
	char a[70] = { 0 };			//总字符
	while (NULL != fgets(a, 70, p))
	{
		char namee[20] = { 0 }, sidd[20] = { 0 }, idd[20] = { 0 }, c[4]={0}, m[4]={0}, e[4]={0}, pp[4]={0};
		int cnt = 0, j = 0;
		for (int i = 0; i < strlen(a); i++)
		{
			
			if (a[i] == '.')
			{
				j = 0;
				cnt++;
				continue;
			}
			if (cnt == 0)
			{
				namee[j] = a[i];
				j++;
			}
			else if (cnt == 1)
			{
				sidd[j] = a[i];
				j++;
			}
			else if (cnt == 2)
			{
				idd[j] = a[i];
				j++;
			}
			else if (cnt == 3)
			{
				c[j] = a[i];
				j++;
			}
			else if (cnt == 4)
			{
				m[j] = a[i];
				j++;
			}
			else if (cnt == 5)
			{
				e[j] = a[i];
				j++;
			}
			else if (cnt == 6)
			{
				pp[j] = a[i];
				j++;
			}
		}
		score d(atoi(c), atoi(m), atoi(e), atoi(pp));
		listt(namee, sidd, idd, d);
	}
	fclose(p);
}


//创建学生信息
void pr_creat(void)
{
	cleardevice();
	static char name[15] = { 0 };
	static char sid[20] = { 0 };
	static char id[20] = { 0 };
	static char chi[4] = { 0 };
	static char math[4] = { 0 };
	static char eng[4] = { 0 };
	static char cpp[4] = { 0 };
	static char s1[] = "Name:";
	static char s2[] = "Student id:";
	static char s3[] = "Id:";
	static char s4[] = "Chinese:";
	static char s5[] = "Math:";
	static char s6[] = "English:";
	static char s7[] = "Cpp:";
	static char ss[] = "please click here to input";
	static char ok1[] = "c";
	static char ok2[] = "r";
	static char ok3[] = "e";
	static char ok4[] = "a";
	static char ok5[] = "t";
	static char ok6[] = "e";
	static char ret1[] = "r";
	static char ret2[] = "e";
	static char ret3[] = "t";
	static char ret4[] = "u";
	static char ret5[] = "r";
	static char ret6[] = "n";
	//create
	outtextxy(22, 660, ok1);
	outtextxy(37, 660, ok2);
	outtextxy(52, 660, ok3);
	outtextxy(67, 660, ok4);
	outtextxy(82, 660, ok5);
	outtextxy(97, 660, ok6);
	//return
	outtextxy(395, 660, ret1);
	outtextxy(410, 660, ret2);
	outtextxy(425, 660, ret3);
	outtextxy(440, 660, ret4);
	outtextxy(455, 660, ret5);
	outtextxy(470, 660, ret6);
	string namee, sidd, idd, chii, mathh, engg, cppp, str;
	//每个信息的名称
	outtextxy(100, 30, s1);
	outtextxy(100, 100, s2);
	outtextxy(100, 170, s3);
	outtextxy(100, 240, s4);
	outtextxy(100, 310, s5);
	outtextxy(100, 380, s6);
	outtextxy(100, 450, s7);
	//creat的框
	rectangle(5, 650, 120, 690);
	//return的框
	rectangle(380, 650, 495, 690);	
	while (1)
	{
		if (namee.size() == 0)
			outtextxy(200, 30, ss);
		if (sidd.size() == 0)
			outtextxy(200, 100, ss);
		if (idd.size() == 0)
			outtextxy(200, 170, ss);
		if (chii.size() == 0)
			outtextxy(200, 240, ss);
		if (mathh.size() == 0)
			outtextxy(200, 310, ss);
		if (engg.size() == 0)
			outtextxy(200, 380, ss);
		if (cppp.size() == 0)
			outtextxy(200, 450, ss);
		ExMessage c;
		char cl;

		flushmessage(EM_MOUSE);
		c = getmessage(EM_MOUSE);
		while (_kbhit())
		{
			_getch();
		}
		if ((c.x > 200) && (c.x < 400) && (c.y>30) &&( c.y < 50) && (c.lbutton))
		{
			clearrectangle(200, 30, 400, 50);
			outtextxy(200, 30, namee.c_str());

			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (namee.size() != 0)
						namee = namee.substr(0, namee.size() - 1);
					else;
				else
				{
					str = cl;
					namee += str;
				}
				clearrectangle(200, 30, 400, 50);
				outtextxy(200, 30, namee.c_str());
			}

		}
		else if ((c.x > 200)&& (c.x < 400) &&( c.y>100) && (c.y < 120) &&( c.lbutton))
		{
			clearrectangle(200, 100, 400, 120);
			outtextxy(200, 100, sidd.c_str());
			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (sidd.size() != 0)
						sidd = sidd.substr(0, sidd.size() - 1);
					else;
				else
				{
					str = cl;
					sidd += str;
				}
				clearrectangle(200, 100, 400, 120);
				outtextxy(200, 100, sidd.c_str());
			}
		}
		else if ((c.x > 200) &&( c.x < 400 )&&( c.y>170 )&& (c.y < 190) &&( c.lbutton))
		{
			clearrectangle(200, 170, 400, 190);
			outtextxy(200, 170, idd.c_str());
			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (idd.size() != 0)
						idd = idd.substr(0, idd.size() - 1);
					else;
				else
				{
					str = cl;
					idd += str;
				}
				clearrectangle(200, 170, 400, 190);
				outtextxy(200, 170, idd.c_str());
			}

		}
		else if ((c.x > 200 )&& (c.x < 400) &&( c.y>240) && (c.y < 260) && (c.lbutton))
		{
			clearrectangle(200, 240, 400, 260);
			outtextxy(200, 240, chii.c_str());
			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (chii.size() != 0)
						chii = chii.substr(0, chii.size() - 1);
					else;
				else
				{
					str = cl;
					chii += str;
				}
				clearrectangle(200, 240, 400, 260);
				outtextxy(200, 240, chii.c_str());
			}
		}
		else if ((c.x > 200 )&& (c.x < 400) && (c.y>310) && (c.y < 330) && (c.lbutton))
		{
			clearrectangle(200, 310, 400, 330);
			outtextxy(200, 310, mathh.c_str());
			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (mathh.size() != 0)
						mathh = mathh.substr(0, mathh.size() - 1);
					else;
				else
				{
					str = cl;
					mathh += str;
				}
				clearrectangle(200, 310, 400, 330);
				outtextxy(200, 310, mathh.c_str());
			}
		}
		else if ((c.x > 200) && (c.x < 400) && (c.y>380) &&( c.y < 400 )&& (c.lbutton))
		{
			clearrectangle(200, 380, 400, 400);
			outtextxy(200, 380, engg.c_str());
			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (engg.size() != 0)
						engg = engg.substr(0, engg.size() - 1);
					else;
				else
				{
					str = cl;
					engg += str;
				}
				clearrectangle(200, 380, 400, 400);
				outtextxy(200, 380, engg.c_str());
			}
		}
		else if ((c.x > 200) && (c.x < 400) && (c.y>450) && (c.y < 470) && (c.lbutton))
		{
			clearrectangle(200, 450, 400, 470);
			outtextxy(200, 450, cppp.c_str());
			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (cppp.size() != 0)
						cppp = cppp.substr(0, cppp.size() - 1);
					else;
				else
				{
					str = cl;
					cppp += str;
				}
				clearrectangle(200, 450, 400, 470);
				outtextxy(200, 450, cppp.c_str());
			}
		}




		//create
		else if ((c.x > 5 )&& (c.x < 120) && (c.y>650 )&&(c.y < 690) &&( c.lbutton)	)		//5, 650, 120, 690
		{
			if ((namee.size()) && (sidd.size()) && (idd.size()) && (chii.size()) && (engg.size()) && (mathh.size()) && (cppp.size()))
			{
				score ss(atoi(chii.c_str()), atoi(mathh.c_str()), atoi(engg.c_str()), atoi(cppp.c_str()));
				listt(namee.c_str(), sidd.c_str(), idd.c_str(), ss);
				save();
				char se[] = "保存成功！！！";
				outtextxy(185, 625, se);
				Sleep(3000);
				clearrectangle(180, 625, 320, 670);
				pr_creat();
				break;
			}
			else
			{
				settextcolor(RED);
				char re[] = "还有信息未填入";
				outtextxy(180, 550, re);
				Sleep(3000);
				clearrectangle(180, 550, 320, 595);
				settextcolor(WHITE);
			}
		}



		//return
		else if ((c.x > 380) && (c.x < 495) && (c.y>650 )&& (c.y < 690) &&( c.lbutton))		
		{
			pr_start();
			break;
		}
	}

}


//开始界面
void pr_start()
{
	cleardevice();
	ExMessage mouse;
	rectangle(175, 120, 325, 170);
	rectangle(175, 200, 325, 250);
	rectangle(175, 280, 325, 330);
	rectangle(185, 385, 315, 425);
	static char cre[] = "Create new student",seg[]="Seek segment";
	outtextxy(190,135,cre);
	outtextxy(205, 215, seg);
	outtextxy(210, 295, "Seek student");
	outtextxy(223, 395, "E  X  I  T");
	while (1)
	{
		mouse = getmessage(EM_MOUSE);
		//创建学生
		if ((mouse.x > 175) && (mouse.x < 325) && (mouse.y > 120) && (mouse.y < 170) && (mouse.lbutton))
		{
			pr_creat();
			break;
		}
		else if ((mouse.x > 175) && (mouse.x < 325) && (mouse.y > 200) && (mouse.y < 250) && (mouse.lbutton))
		{
			pr_seekrank();
			break;
		}
		else if ((mouse.x > 175) && (mouse.x < 325) && (mouse.y > 280) && (mouse.y < 330) && (mouse.lbutton))
		{
			pr_delete();
			break;
		}
		else if ((mouse.x > 185) && (mouse.x < 315) && (mouse.y > 385) && (mouse.y < 425) && (mouse.lbutton))
			return;

	}
}

//展现学生信息
void pr_display(int n,int cla,int pageall)			//(x,y,z)x:数组下缀，y：比较类型，z：总页数     1，总成绩，2，语文，3，数学，4，英语，5，cpp
{

	cleardevice();
	static char b1[] = "Last", b2[] = "Next";
	char page1[7] = { 0 }, page2[7] = { 0 },pp='/';
	static char kk[] = "Return";
	_itoa(n+1, page1, 10);
	_itoa(pageall, page2, 10);

	//页数
	outtextxy(212, 640, page1);
	outtextxy(242, 640, pp);
	outtextxy(258, 640, page2);
	//返回
	rectangle(210,662,272,688);
	outtextxy(220, 667, kk);

	if (n == 0)
	{
		rectangle(380, 635, 436, 663);
		outtextxy(393, 640, b2);
	}
	else if (n == pageall - 1)
	{
		rectangle(50, 635, 106, 663);
		outtextxy(63, 640, b1);
	}
	else
	{
		rectangle(50, 635, 106, 663);	
		rectangle(380, 635, 436, 663);
		outtextxy(63, 640, b1);
		outtextxy(393, 640, b2);
	}


	static char rank[] = "Rank", namee[] = "Name", sidd[] = "School   Id", idd[] = "Id", alls[] = "Sumscore", chin[] = "Chinese", mathh[] = "Math", engl[] = "English", cp[] = "Cpp";
	
	
	


	
	
	//标题
	outtextxy(10, 10, rank);
	outtextxy(95, 10, namee);
	outtextxy(205, 10, sidd);
	if (cla == 1)
	{
		outtextxy(390, 10, alls);
	}

	else if (cla == 2)
	{
		outtextxy(390, 10, chin);
	}
	else if (cla == 3)
	{
		outtextxy(390, 10, mathh);
	}
	else if (cla == 4)
	{
		outtextxy(390, 10, engl);
	}
	else if (cla == 5)
	{
		outtextxy(390, 10, cp);
	}
	else if (cla == -1)
	{
		outtextxy(340, 10, "Id");
	}




	/*for (int i = 1; i <= holdon[n].size(); i++)
	{
		char a1[6] = { 0 };
		_itoa(i + 10 * n, a1, 10);
		char via[6] = { 0 };
		outtextxy(13, 60+50*(i-1), a1);
		outtextxy(95, 60 + 50 * (i - 1), holdon[n][i-1]->getname());
		outtextxy(205, 60 + 50 * (i - 1), holdon[n][i-1]->getsid());*/
	//	if (cla == 1)
	//	{
	//		_itoa(holdon[n][i-1]->getscore().getall(), via, 10);
	//		outtextxy(395, 60 + 50 * (i - 1), via);
	//	}

	//	else if (cla == 2)
	//	{
	//		_itoa(holdon[n][i-1]->getscore().getchinese(), via, 10);
	//		outtextxy(395, 60 + 50 * (i - 1), via);
	//	}
	//	else if (cla == 3)
	//	{
	//		_itoa(holdon[n][i-1]->getscore().getmath(), via, 10);
	//		outtextxy(395, 60 + 50 * (i - 1), via);
	//	}
	//	else if (cla == 4)
	//	{
	//		_itoa(holdon[n][i-1]->getscore().getenglish(), via, 10);
	//		outtextxy(395, 60 + 50 * (i - 1), via);
	//	}
	//	else if (cla == 5)
	//	{
	//		_itoa(holdon[n][i-1]->getscore().getcpp(), via, 10);
	//		outtextxy(395, 60 + 50 * (i - 1), via);
	//	}
	//	else if (cla == -1)
	//		outtextxy(340, 60 + 50 * (i - 1), holdon[n][i-1]->getid());
	//}
	char a1[4], a2[4], a3[4], a4[4], a5[4], a6[4], a7[4], a8[4], a9[4],a10[4];
	if (1 <= holdon[n].size())
	{
		_itoa(1 + 10 * n, a1, 10);
		char via[6] = { 0 };
		outtextxy(13, 60, a1);
		outtextxy(100, 60, holdon[n][0]->getname());
		outtextxy(210, 60, holdon[n][0]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][0]->getscore().getall(), via, 10);
			outtextxy(395, 60, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][1]->getscore().getchinese(), via, 10);
			outtextxy(395, 60, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][0]->getscore().getmath(), via, 10);
			outtextxy(395, 60, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][0]->getscore().getenglish(), via, 10);
			outtextxy(395, 60, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][0]->getscore().getcpp(), via, 10);
			outtextxy(395, 60, via);
		}
		else if (cla == -1)
			outtextxy(350, 60, holdon[n][0]->getid());
	}
	if (2 <= holdon[n].size())
	{
		_itoa(2 + 10 * n, a2, 10);
		char via[6] = { 0 };
		outtextxy(13, 110, a2);
		outtextxy(100, 110, holdon[n][1]->getname());
		outtextxy(210, 110, holdon[n][1]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][1]->getscore().getall(), via, 10);
			outtextxy(395, 110, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][1]->getscore().getchinese(), via, 10);
			outtextxy(395, 110, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][1]->getscore().getmath(), via, 10);
			outtextxy(395, 110, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][1]->getscore().getenglish(), via, 10);
			outtextxy(395, 110, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][1]->getscore().getcpp(), via, 10);
			outtextxy(395, 110, via);
		}
		else if (cla == -1)
			outtextxy(350, 110, holdon[n][1]->getid());
	}
	if (3 <= holdon[n].size())
	{
		_itoa(3 + 10 * n, a3, 10);
		char via[6] = { 0 };
		outtextxy(13, 160, a3);
		outtextxy(100, 160, holdon[n][2]->getname());
		outtextxy(210, 160, holdon[n][2]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][2]->getscore().getall(), via, 10);
			outtextxy(395, 160, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][2]->getscore().getchinese(), via, 10);
			outtextxy(395, 160, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][2]->getscore().getmath(), via, 10);
			outtextxy(395, 160, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][2]->getscore().getenglish(), via, 10);
			outtextxy(395, 160, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][2]->getscore().getcpp(), via, 10);
			outtextxy(395, 160, via);
		}
		else if (cla == -1)
			outtextxy(350, 160, holdon[n][2]->getid());
	}
	if (4 <= holdon[n].size())
	{
		_itoa(4 + 10 * n, a4, 10);
		char via[6] = { 0 };
		outtextxy(13, 210, a4);
		outtextxy(100, 210, holdon[n][3]->getname());
		outtextxy(210, 210, holdon[n][3]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][3]->getscore().getall(), via, 10);
			outtextxy(395, 210, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][3]->getscore().getchinese(), via, 10);
			outtextxy(395, 210, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][3]->getscore().getmath(), via, 10);
			outtextxy(395, 210, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][3]->getscore().getenglish(), via, 10);
			outtextxy(395, 210, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][3]->getscore().getcpp(), via, 10);
			outtextxy(395, 210, via);
		}
		else if (cla == -1)
			outtextxy(350, 210, holdon[n][3]->getid());
	}
	if (5 <= holdon[n].size())
	{
		_itoa(5+ 10 * n, a5, 10);
		char via[6] = { 0 };
		outtextxy(13, 260, a5);
		outtextxy(100, 260, holdon[n][4]->getname());
		outtextxy(210, 260, holdon[n][4]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][4]->getscore().getall(), via, 10);
			outtextxy(395, 260, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][4]->getscore().getchinese(), via, 10);
			outtextxy(395, 260, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][4]->getscore().getmath(), via, 10);
			outtextxy(395, 260, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][4]->getscore().getenglish(), via, 10);
			outtextxy(395, 260, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][4]->getscore().getcpp(), via, 10);
			outtextxy(395, 260, via);
		}
		else if (cla == -1)
			outtextxy(350, 260, holdon[n][4]->getid());
	}
	if (6 <= holdon[n].size())
	{
		_itoa(6 + 10 * n, a6, 10);
		char via[6] = { 0 };
		outtextxy(13, 310, a6);
		outtextxy(100, 310, holdon[n][5]->getname());
		outtextxy(210, 310, holdon[n][5]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][5]->getscore().getall(), via, 10);
			outtextxy(395, 310, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][5]->getscore().getchinese(), via, 10);
			outtextxy(395, 310, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][5]->getscore().getmath(), via, 10);
			outtextxy(395, 310, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][5]->getscore().getenglish(), via, 10);
			outtextxy(395, 310, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][5]->getscore().getcpp(), via, 10);
			outtextxy(395, 310, via);
		}
		else if (cla == -1)
			outtextxy(350, 310, holdon[n][5]->getid());
	}
	if (7 <= holdon[n].size())
	{
		_itoa(7 + 10 * n, a7, 10);
		char via[6] = { 0 };
		outtextxy(13, 360, a7);
		outtextxy(100, 360, holdon[n][6]->getname());
		outtextxy(210, 360, holdon[n][6]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][6]->getscore().getall(), via, 10);
			outtextxy(395, 360, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][6]->getscore().getchinese(), via, 10);
			outtextxy(395, 360, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][6]->getscore().getmath(), via, 10);
			outtextxy(395, 360, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][6]->getscore().getenglish(), via, 10);
			outtextxy(395, 360, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][6]->getscore().getcpp(), via, 10);
			outtextxy(395, 360, via);
		}
		else if (cla == -1)
			outtextxy(350, 360, holdon[n][6]->getid());
	}
	if (8 <= holdon[n].size())
	{
		_itoa(8 + 10 * n, a8, 10);
		char via[6] = { 0 };
		outtextxy(13, 410, a8);
		outtextxy(100, 410, holdon[n][7]->getname());
		outtextxy(210, 410, holdon[n][7]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][7]->getscore().getall(), via, 10);
			outtextxy(395, 410, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][7]->getscore().getchinese(), via, 10);
			outtextxy(395, 410, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][7]->getscore().getmath(), via, 10);
			outtextxy(395, 410, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][7]->getscore().getenglish(), via, 10);
			outtextxy(395, 410, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][7]->getscore().getcpp(), via, 10);
			outtextxy(395, 410, via);
		}
		else if (cla == -1)
			outtextxy(350, 410, holdon[n][7]->getid());
	}
	if (9 <= holdon[n].size())
	{
		_itoa(9 + 10 * n, a9, 10);
		char via[6] = { 0 };
		outtextxy(13, 460, a9);
		outtextxy(100, 460, holdon[n][8]->getname());
		outtextxy(210, 460, holdon[n][8]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][8]->getscore().getall(), via, 10);
			outtextxy(395, 460, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][8]->getscore().getchinese(), via, 10);
			outtextxy(395, 460, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][8]->getscore().getmath(), via, 10);
			outtextxy(395, 460, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][8]->getscore().getenglish(), via, 10);
			outtextxy(395, 460, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][8]->getscore().getcpp(), via, 10);
			outtextxy(395, 460, via);
		}
		else if (cla == -1)
			outtextxy(350, 460, holdon[n][8]->getid());
	}
	if (10 <= holdon[n].size())
	{
		_itoa(10 + 10 * n, a10, 10);
		char via[6] = { 0 };
		outtextxy(13, 510, a10);
		outtextxy(100, 510, holdon[n][9]->getname());
		outtextxy(210, 510, holdon[n][9]->getsid());
		if (cla == 1)
		{
			_itoa(holdon[n][9]->getscore().getall(), via, 10);
			outtextxy(395, 510, via);
		}

		else if (cla == 2)
		{
			_itoa(holdon[n][9]->getscore().getchinese(), via, 10);
			outtextxy(395, 510, via);
		}
		else if (cla == 3)
		{
			_itoa(holdon[n][9]->getscore().getmath(), via, 10);
			outtextxy(395, 510, via);
		}
		else if (cla == 4)
		{
			_itoa(holdon[n][9]->getscore().getenglish(), via, 10);
			outtextxy(395, 510, via);
		}
		else if (cla == 5)
		{
			_itoa(holdon[n][9]->getscore().getcpp(), via, 10);
			outtextxy(395, 510, via);
		}
		else if (cla == -1)
			outtextxy(350, 510, holdon[n][9]->getid());
	}


}


//排序
int sortt(int cla)
{
	int t = numget()-1;
	int r = 0;
	first = head->getnext();
	second = NULL;
	stb = head;
	if (first != NULL)
	{
		if (first->getnext() != NULL)
			second = first->getnext();
		else
			return r;
	}
	else
		return r;
	if (cla == 1)//总成绩排序
	{
		while (t--)
		{
			while (second != NULL)
			{
				r = max(r, first->getscore().getall());
				if ((first->getscore().getall()) < (second->getscore().getall()))
				{
					first->setnext(second->getnext());
					second->setlast(first->getlast());
					first->setlast(second);
					second->setnext(first);
					if (first->getnext() != NULL)
						first->getnext()->setlast(first);
					stb->setnext(second);
				}
				first = stb->getnext()->getnext();
				second = first->getnext();
				stb = stb->getnext();
			}
			first = head->getnext();
			second = first->getnext();
			stb = head;
		}
	}
	else if (cla == 2)//语文排名
	{
		while (t--)
		{
			while (second != NULL)
			{
				if ((first->getscore().getchinese()) < (second->getscore().getchinese()))
				{
					r = max(r, first->getscore().getchinese());
					first->setnext(second->getnext());
					second->setlast(first->getlast());
					first->setlast(second);
					second->setnext(first);
					if (first->getnext() != NULL)
						first->getnext()->setlast(first);
					stb->setnext(second);
				}
				first = ((stb->getnext())->getnext());
				second = first->getnext();
				stb = stb->getnext();
			}
			first = head->getnext();
			second = first->getnext();
			stb = head;
		}
	}
	else if (cla == 3)//数学排名
	{
		while (t--)
		{
			while (second != NULL)
			{
				r = max(r, first->getscore().getmath());
				if ((first->getscore().getmath()) < (second->getscore().getmath()))
				{
					first->setnext(second->getnext());
					second->setlast(first->getlast());
					first->setlast(second);
					second->setnext(first);
					if (first->getnext() != NULL)
						first->getnext()->setlast(first);
					stb->setnext(second);
				}
				first = stb->getnext()->getnext();
				second = first->getnext();
				stb = stb->getnext();
			}
			first = head->getnext();
			second = first->getnext();
			stb = head;
		}
	}
	else if (cla == 4)//英语排名
	{
		while (t--)
		{
			while (second != NULL)
			{
				r = max(r, first->getscore().getenglish());
				if ((first->getscore().getenglish()) < (second->getscore().getenglish()))
				{
					first->setnext(second->getnext());
					second->setlast(first->getlast());
					first->setlast(second);
					second->setnext(first);
					if (first->getnext() != NULL)
						first->getnext()->setlast(first);
					stb->setnext(second);
				}
				first = stb->getnext()->getnext();
				second = first->getnext();
				stb = stb->getnext();
			}
			first = head->getnext();
			second = first->getnext();
			stb = head;
		}
	}
	else if (cla == 5)
	{
		while (t--)
		{
			while (second != NULL)
			{
				r = max(r, first->getscore().getcpp());
				if ((first->getscore().getcpp()) < (second->getscore().getcpp()))
				{
					first->setnext(second->getnext());
					second->setlast(first->getlast());
					first->setlast(second);
					second->setnext(first);
					if (first->getnext() != NULL)
						first->getnext()->setlast(first);
					stb->setnext(second);
				}
				first = stb->getnext()->getnext();
				second = first->getnext();
				stb = stb->getnext();
			}
			first = head->getnext();
			second = first->getnext();
			stb = head;
		}
	}
	while (now->getnext() != NULL)
		now = now->getnext();
	return r;
}

//当前学生数量
int numget()
{
	eve = head;
	int n=0;
	while (eve->getnext() != NULL)
	{
		n++;
		eve = eve->getnext();
	}
	eve = head;
	return n;
}




//分数段输入及查询
void pr_scoreseg(int cla)
{
	cleardevice();
		static char a1[] = "Please input the start and the end";
		static char a2[] = "~~~~~";
		static char a3[] = "Seek", a4[] = "Return";
		rectangle(135,235,190,270);
		rectangle(300,235,355,270);
		rectangle(90, 408, 140, 440);
		rectangle(350, 408, 404, 440);
		outtextxy(135, 150, a1);
		outtextxy(236, 245, a2);
		outtextxy(98, 415, a3);
		outtextxy(355, 415, a4);
		string st, end , str;
	while (1)
	{
		ExMessage a = getmessage();
		while (_kbhit())
			{
				_getch();
			}
		char cl;
		if ((a.x > 135) && (a.x < 190) && (a.y > 235) && (a.y < 270) && (a.lbutton))
		{
			
			while ((cl = _getch()) != '\r')
			{
				
				if (cl == '\b')
					if (st.size() != 0)
						st = st.substr(0, st.size() - 1);
					else;
				else
				{
					str = cl;
					st += str;
				}
				clearrectangle(136, 236, 189, 269);
				outtextxy(152, 245, st.c_str());
			}
		}
		else if ((a.x > 300) && (a.x < 355) && (a.y > 235) && (a.y < 270) && (a.lbutton))
		{


			while ((cl = _getch()) != '\r')
			{

				if (cl == '\b')
					if (end.size() != 0)
						end = end.substr(0, end.size() - 1);
					else;
				else
				{
					str = cl;
					end += str;
				}
				clearrectangle(301, 236, 354, 269);
				outtextxy(310, 245, end.c_str());
			}
		}
		else if ((a.x > 90) && (a.x < 140) && (a.y > 408) && (a.y < 440) && (a.lbutton))
		{
			int pageall=seekpush(cla, atoi(st.c_str()), atoi(end.c_str()));
			pr_display(0, cla, pageall);
			int pagenow = 0;
			while (1)
			{
				ExMessage mouse = getmessage(EM_MOUSE);
				//功能按键
				if ((mouse.x > 50) && (mouse.x < 106) && (mouse.y > 635) && (mouse.y < 663) && (mouse.lbutton))
				{
					if (pagenow != 0)
					{
						pagenow--;
						pr_display(pagenow, cla, pageall);
					}
				}
				else if ((mouse.x > 380) && (mouse.x < 436) && (mouse.y > 635) && (mouse.y < 663) && (mouse.lbutton))
				{
					if (pagenow != pageall - 1)
					{
						pagenow++;
						pr_display(pagenow, cla, pageall);
					}
				}

				else if ((mouse.x > 210) && (mouse.x < 272) && (mouse.y > 662) && (mouse.y < 688) && (mouse.lbutton))
					break;
				//点击学生
				for(int i=1;i<=holdon[pagenow].size();i++)
					if ((mouse.x > 13) && (mouse.x < 40) && (mouse.y > 60+(i-1)*50) && (mouse.y < 80+ (i - 1) * 50) && (mouse.lbutton))
					{
						pr_indi(holdon[pagenow][i - 1]);
						cleardevice();
						for (int j = 0; j < pageall; j++)
							holdon[j].clear();
						sortt(cla);
						int pageal = seekpush(cla, atoi(st.c_str()), atoi(end.c_str()));
						pageall = pageal;
						pagenow = 0;
						pr_display(0, cla, pageall);
					}
			}
			for (int y = 0; y < pageall; y++)
				holdon[y].clear();
			pr_scoreseg(cla);
			break;
		}
		else if ((a.x > 350) && (a.x < 404) && (a.y > 408) && (a.y < 440) && (a.lbutton))
			break;
	}
	pr_seekrank();
}
//寻找然后压入vector

int seekpush(int cla, int sta,int end)
{
	it = head->getnext();
	int page = 0, rank = 0;
	if (cla == 1)
	{
		while (it != NULL)
		{
			int score = it->getscore().getall();
			if ((score >= sta) && (score <= end))
			{
				holdon[page].push_back(it);
				rank++;
			}
			if (rank == 10)
			{
				rank = 0;
				page++;
			}
			it = it->getnext();
		}
	}
	if (cla == 2)
	{
		while (it != NULL)
		{
			int score = it->getscore().getchinese();
			if ((score >= sta) && (score <= end))
			{
				holdon[page].push_back(it);
				rank++;
			}
			if (rank == 10)
			{
				rank = 0;
				page++;
			}
			it = it->getnext();
		}
	}
	if (cla == 3)
	{
		while (it != NULL)
		{
			int score = it->getscore().getmath();
			if ((score >= sta) && (score <= end))
			{
				holdon[page].push_back(it);
				rank++;
			}
			if (rank == 10)
			{
				rank = 0;
				page++;
			}
			it = it->getnext();
		}
	}
	if (cla == 4)
	{
		while (it != NULL)
		{
			int score = it->getscore().getenglish();
			if ((score >= sta) && (score <= end))
			{
				holdon[page].push_back(it);
				rank++;
			}
			if (rank == 10)
			{
				rank = 0;
				page++;
			}
			it = it->getnext();
		}
	}
	if (cla == 5)
	{
		while (it != NULL)
		{
			int score = it->getscore().getcpp();
			if ((score >= sta) && (score <= end))
			{
				holdon[page].push_back(it);
				rank++;
			}
			if (rank == 10)
			{
				rank = 0;
				page++;
			}
			it = it->getnext();
		}
	}
	return page + 1;
}
int seekpush(string a,string b,string c)
{
	int num1 = a.size(), num2 = b.size(), num3 = c.size();
	it = head->getnext();
	int page = 0, rank = 0;

		while (it != NULL)													//_itoa
		{
			int ifwin = 0;
			if ((num1 <= strlen(it->getname()))&&(num2 <= strlen(it->getsid()))&&(num3 <= strlen(it->getid())))
			{
				if (num1 != 0)
					for (int i = 0; i < num1; i++)
					{
						if (a[i] != (it->getname()[i]))
						{
							ifwin = 1;
							break;
						}
					}

				if (num2 != 0)
					for (int i = 0; i < num2; i++)
					{
						if (b[i] != (it->getsid()[i]))
						{
							ifwin = 1;
							break;
						}
					}

				if (num3 != 0)
					for (int i = 0; i < num3; i++)
					{
						if (c[i] != (it->getid()[i]))
						{
							ifwin = 1;
							break;
						}
					}
				if (ifwin == 0)
				{
					holdon[page].push_back(it);
					rank++;
				}
			}
			if (rank == 10)
			{
				rank = 0;
				page++;
			}
			it = it->getnext();
		}
	//}
	//else if (cla == 2)
	//{
	//	while (it != NULL)													//_itoa
	//	{
	//		if (num <= strlen(it->getsid()))
	//		{
	//			for (int i = 0; i < num; i++)
	//			{
	//				if (a[i] != (it->getsid()[i]))
	//					break;
	//				if (i == num - 1)
	//				{
	//					holdon[page].push_back(it);
	//					rank++;
	//				}
	//			}
	//		}
	//		if (rank == 10)
	//		{
	//			rank = 0;
	//			page++;
	//		}
	//		it = it->getnext();
	//	}
	//}
	//else if (cla == 3)
	//{
	//	while (it != NULL)													//_itoa
	//	{
	//		if (num <= strlen(it->getid()))
	//		{
	//			for (int i = 0; i < num; i++)
	//			{
	//				if (a[i] != (it->getid()[i]))
	//					break;
	//				if (i == num - 1)
	//				{
	//					holdon[page].push_back(it);
	//					rank++;
	//				}
	//			}
	//		}
	//		if (rank == 10)
	//		{
	//			rank = 0;
	//			page++;
	//		}
	//		it = it->getnext();
	//	}
	//}
	return page + 1;
}





//查询排名
void pr_seekrank()
{
	static char choose[]="C H O O S E     O N E",alll[] = "Sumscore", ch[] = "Chinese", mat[] = "Math", en[] = "English", cpk[] = "Cpp",ret[]="Return";
	cleardevice();
		outtextxy(187, 130, choose);
		rectangle(200, 168, 300, 202);
		rectangle(200, 238, 300, 272);
		rectangle(200, 308, 300, 342);
		rectangle(200, 378, 300, 412);
		rectangle(200, 448, 300, 482);
		rectangle(390, 600, 447, 635);
		outtextxy(218, 175, alll);
		outtextxy(222, 245, ch);
		outtextxy(233, 315, mat);
		outtextxy(225, 385, en);
		outtextxy(237, 455, cpk);
		outtextxy(398, 608, ret);
		//最高分
		for (int i = 1; i <= 5; i++)
		{
			int m;
			char mm[7];
			
			m = sortt(i);
			_itoa(m, mm, 10);
			setcolor(GREEN);
			outtextxy(340, 175+(i-1)*70,mm);
			setcolor(WHITE);
		}
	while (1)
	{	

		ExMessage a = getmessage(EM_MOUSE);
		if ((a.x > 200) && (a.x < 300) && (a.y > 168) && (a.y < 202) && (a.lbutton))
		{
			sortt(2);
			sortt(4);
			sortt(5);
			sortt(3);
			sortt(1);
			pr_scoreseg(1);
			break;
		}
		else if ((a.x > 200) && (a.x < 300) && (a.y > 238) && (a.y < 272) && (a.lbutton))
		{
			sortt(4);
			sortt(5);
			sortt(3);
			sortt(1);
			sortt(2);
			pr_scoreseg(2);
			break;
		}
		else if ((a.x > 200) && (a.x < 300) && (a.y > 308) && (a.y < 342) && (a.lbutton))
		{
			sortt(2);
			sortt(4);
			sortt(5);
			sortt(1);
			sortt(3);
			pr_scoreseg(3);
			break;
		}
		else if ((a.x > 200) && (a.x < 300) && (a.y > 378) && (a.y < 412) && (a.lbutton))
		{
			sortt(2);
			sortt(5);
			sortt(3);
			sortt(1);
			sortt(4);
			pr_scoreseg(4);
			break;
		}
		else if ((a.x > 200) && (a.x < 300) && (a.y > 448) && (a.y < 482) && (a.lbutton))
		{
			sortt(2);
			sortt(4);
			sortt(3);
			sortt(1);
			sortt(5);
			pr_scoreseg(5);
			break; 
		}
		else if ((a.x > 390) && (a.x < 447) && (a.y > 600) && (a.y < 635) && (a.lbutton))
		{
			pr_start();
			break;
		}
	}
}


//个人界面
void pr_indi(stu* stud)
{
	cleardevice();
	static char r[] = "I  N  D  I  V  I  D  U  A  L";
	static char rt[] = "S  C  O  R  E";
	static char s1[] = "Name:";
	static char s2[] = "Student id:";
	static char s3[] = "Id:";
	static char s4[] = "Chinese:";
	static char s5[] = "Math:";
	static char s6[] = "English:";
	static char s7[] = "Cpp:";
	static char s8[] = "SumScore:";
	static char s9[] = "Revise";
	static char s10[] = "Delete";
	static char s11[] = "Return";
	string n, x, s, y, shu, yi, cy,summary;
	char nn[20], xx[20], ss[20], yy[6], shuu[6], yii[6], cyy[6],summ[6];
	int summa = stud->getscore().getall();
	n = stud->getname();
	x = stud->getsid();
	s = stud->getid();
	_itoa(stud->getscore().getchinese(), yy, 10);
	_itoa(stud->getscore().getmath(), shuu, 10);
	_itoa(stud->getscore().getenglish(), yii, 10);
	_itoa(stud->getscore().getcpp(), cyy, 10);
	_itoa(summa, summ, 10);
	y = yy;
	shu = shuu;
	yi = yii;
	cy = cyy;
	summary = summ;
	settextcolor(GREEN);
	outtextxy(170, 60, r);
	outtextxy(195, 270, rt);
	settextcolor(WHITE);
	//个人信息
	outtextxy(122, 120, s1);
	outtextxy(96, 180, s2);
	outtextxy(150, 230, s3);
	//成绩
	outtextxy(110, 310, s4);
	outtextxy(132, 370, s5);
	outtextxy(115, 430, s6);
	outtextxy(140, 490, s7);
	outtextxy(100, 550, s8);
	//投影各项数据
	outtextxy(200, 120, n.c_str());
	outtextxy(200, 180, x.c_str());
	outtextxy(200, 230, s.c_str());
	outtextxy(200, 310, y.c_str());
	outtextxy(200, 370, shu.c_str());
	outtextxy(200, 430, yi.c_str());
	outtextxy(200, 490, cy.c_str());
	outtextxy(200, 550, summary.c_str());
	//投影操作按键
	rectangle(60, 620, 120, 650);
	outtextxy(68, 626, s9);
	rectangle(213, 620, 273, 650);
	outtextxy(221, 626, s10);
	rectangle(353, 620, 413, 650);
	outtextxy(361, 626, s11);

	while (1)
	{
		ExMessage mouse;
		mouse = getmessage(EM_MOUSE);
		string str;
		if ((mouse.x > 60) && (mouse.x < 120) && (mouse.y > 620) && (mouse.y < 650) && (mouse.lbutton))
		{
			clearrectangle(61, 621, 119, 649);
			outtextxy(75, 626, "Sure");
			ExMessage ty;
			while (1)
			{
				char cl;
				string str;
				ty= getmessage();
				while (_kbhit())
				{
					_getch();
				}
				if ((ty.x > 200) && (ty.x < 300) && (ty.y > 120) && (ty.y < 140) && (ty.lbutton))
				{
					clearrectangle(200, 120, 500, 140);
					outtextxy(200, 120,n.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (n.size() != 0)
								n = n.substr(0, n.size() - 1);
							else;
						else
						{
							str = cl;
							n += str;
						}
						clearrectangle(200,120, 500, 140);
						outtextxy(200, 120, n.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 180) && (ty.y < 200) && (ty.lbutton))
				{
					clearrectangle(200, 180, 500, 200);
					outtextxy(200, 180, x.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (x.size() != 0)
								x = x.substr(0, x.size() - 1);
							else;
						else
						{
							str = cl;
							x+= str;
						}
						clearrectangle(200, 180, 500, 200);
						outtextxy(200, 180, x.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 230) && (ty.y < 250) && (ty.lbutton))
				{
					clearrectangle(200, 230, 500, 250);
					outtextxy(200, 230, s.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (s.size() != 0)
								s = s.substr(0, s.size() - 1);
							else;
						else
						{
							str = cl;
							s += str;
						}
						clearrectangle(200, 230, 500, 250);
						outtextxy(200, 230, s.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 310) && (ty.y < 330) && (ty.lbutton))
				{
					clearrectangle(200, 310, 500, 330);
					outtextxy(200, 310, y.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (y.size() != 0)
								y = y.substr(0, y.size() - 1);
							else;
						else
						{
							str = cl;
							y += str;
						}
						clearrectangle(200, 310, 500, 330);
						outtextxy(200, 310, y.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 370) && (ty.y < 390) && (ty.lbutton))
				{
					clearrectangle(200, 370, 500, 390);
					outtextxy(200, 370, shu.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (shu.size() != 0)
								shu = shu.substr(0, shu.size() - 1);
							else;
						else
						{
							str = cl;
							shu += str;
						}
						clearrectangle(200, 370, 500, 390);
						outtextxy(200, 370, shu.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 430) && (ty.y < 450) && (ty.lbutton))
				{
					clearrectangle(200, 430, 500, 450);
					outtextxy(200, 430, yi.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (yi.size() != 0)
								yi = yi.substr(0, yi.size() - 1);
							else;
						else
						{
							str = cl;
							yi += str;
						}
						clearrectangle(200, 430, 500, 450);
						outtextxy(200, 430, yi.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 490) && (ty.y < 510) && (ty.lbutton))
				{
					clearrectangle(200, 490, 500, 510);
					outtextxy(200, 490, cy.c_str());

					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (cy.size() != 0)
								cy = cy.substr(0, cy.size() - 1);
							else;
						else
						{
							str = cl;
							cy += str;
						}
						clearrectangle(200, 490, 500, 510);
						outtextxy(200, 490, cy.c_str());
					}
				}
				else if ((ty.x > 200) && (ty.x < 300) && (ty.y > 550) && (ty.y < 570) && (ty.lbutton))
				{
					setcolor(RED);
					outtextxy(270, 550, "can not revise sumscore!!!");
					Sleep(1000);
					setcolor(WHITE);
					clearrectangle(270, 550, 500, 570);
					/*clearrectangle(200, 550, 500, 570);
					outtextxy(200, 550, summary.c_str());
	
					while ((cl = _getch()) != '\r')
					{
						if (cl == '\b')
							if (summary.size() != 0)
								summary = summary.substr(0, summary.size() - 1);
							else;
						else
						{
							str = cl;
							summary += str;
						}
						clearrectangle(200, 550, 500, 570);
						outtextxy(200, 550, summary.c_str());
					}*/
				}
				else if ((ty.x > 60) && (ty.x < 120) && (ty.y > 620) && (ty.y < 650) && (ty.lbutton))
				{
				char nameee[15], siddd[20], iddd[20];
				strcpy(nameee , n.c_str());
				strcpy(siddd, x.c_str());
				strcpy(iddd, s.c_str());
				stud->setname(nameee);
				stud->setsid(siddd);
				stud->setid(iddd);
				stud->getscore().setchinese(atoi(y.c_str()));
				stud->getscore().setmath(atoi(shu.c_str()));
				stud->getscore().setenglish(atoi(yi.c_str()));
				stud->getscore().setcpp(atoi(cy.c_str()));
				save();
				clearrectangle(61, 621, 119, 649);
				outtextxy(68, 626, s9);
				break;
				}
			}								
		}									
		else if ((mouse.x > 213) && (mouse.x < 353) && (mouse.y > 620) && (mouse.y < 650) && (mouse.lbutton))
		{
			del(stud);
			save();
			settextcolor(RED);
			outtextxy(175, 580, "Delete Successfully");
			Sleep(3000);
			settextcolor(WHITE);
			break;
		}
		else if ((mouse.x > 353) && (mouse.x < 413) && (mouse.y > 620) && (mouse.y < 650) && (mouse.lbutton))
			break;
	}

}


//搜索删除
void pr_delete()
{
	cleardevice();
	static char f1[16] = "Student name:", f2[12] = "Student id:",f3[4]="Id:";
	string r1, r2, r3;

	//查找和退出
	rectangle(111, 432, 161, 467);
	rectangle(318, 432, 372, 467);
	outtextxy(120, 440, "Seek");
	outtextxy(324, 440, "Return");
	//信息填入
	outtextxy(70, 180, f1);
	outtextxy(95, 250, f2);
	outtextxy(148, 320, f3);
	while (1)
	{
		flushmessage(EM_MOUSE);
		ExMessage c = getmessage(EM_MOUSE);
		while (_kbhit())
		{
			_getch();
		}
		char cl;
		string str;
		if ((c.x > 200) && (c.x < 400) && (c.y > 180) && (c.y < 200) && (c.lbutton))
		{
			clearrectangle(200, 180, 400, 200);
			outtextxy(200,180,r1.c_str());

			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (r1.size() != 0)
						r1 = r1.substr(0, r1.size() - 1);
					else;
				else
				{
					str = cl;
					r1+= str;
				}
				clearrectangle(200, 180, 400, 200);
				outtextxy(200, 180, r1.c_str());
			}

		}
		else if ((c.x > 200) && (c.x < 400) && (c.y > 250) && (c.y < 270) && (c.lbutton))
		{
			clearrectangle(200, 250, 400, 270);
			outtextxy(200, 250, r2.c_str());

			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (r2.size() != 0)
						r2 = r2.substr(0, r2.size() - 1);
					else;
				else
				{
					str = cl;
					r2 += str;
				}
				clearrectangle(200, 250, 400, 270);
				outtextxy(200, 250, r2.c_str());
			}

		}
		else if ((c.x > 200) && (c.x < 400) && (c.y > 320) && (c.y < 340) && (c.lbutton))
		{
			clearrectangle(200, 320, 400, 340);
			outtextxy(200, 320, r3.c_str());

			while ((cl = _getch()) != '\r')
			{
				if (cl == '\b')
					if (r3.size() != 0)
						r3 = r3.substr(0, r3.size() - 1);
					else;
				else
				{
					str = cl;
					r3 += str;
				}
				clearrectangle(200, 320, 400, 340);
				outtextxy(200, 320, r3.c_str());
			}
		}
		else if ((c.x > 111) && (c.x < 161) && (c.y > 432) && (c.y < 467) && (c.lbutton))
		{
			int pageall=seekpush(r1, r2, r3);
			pr_display(0, -1,pageall);
			int pagenow = 0;
			while (1)
			{
				ExMessage mouse = getmessage(EM_MOUSE);
				//功能按键
				if ((mouse.x > 50) && (mouse.x < 106) && (mouse.y > 635) && (mouse.y < 663) && (mouse.lbutton))
				{
					if (pagenow != 0)
					{
						pagenow--;
						pr_display(pagenow, -1, pageall);
					}
				}
				else if ((mouse.x > 380) && (mouse.x < 436) && (mouse.y > 635) && (mouse.y < 663) && (mouse.lbutton))
				{
					if (pagenow != pageall - 1)
					{
						pagenow++;
						pr_display(pagenow, -1, pageall);
					}
				}

				else if ((mouse.x > 210) && (mouse.x < 272) && (mouse.y > 662) && (mouse.y < 688) && (mouse.lbutton))
					break;
				//点击学生
				for (int i = 1; i <= holdon[pagenow].size(); i++)
					if ((mouse.x > 13) && (mouse.x < 40) && (mouse.y > 60 + (i - 1) * 50) && (mouse.y < 80 + (i - 1) * 50) && (mouse.lbutton))
					{
						pr_indi(holdon[pagenow][i - 1]);
						cleardevice();
						for (int j = 0; j < pageall; j++)
							holdon[j].clear();
						sortt(1);
						int pageal = seekpush(r1,r2,r3);
						pageall = pageal;
						pagenow = 0;
						pr_display(0, -1, pageall);
					}
			}
			for (int i = 0; i < pageall; i++)
				holdon[i].clear();
			pr_delete();
			break;
		}
		else if ((c.x > 318) && (c.x < 372) && (c.y > 432) && (c.y < 467) && (c.lbutton))
		{
			pr_start();
			break;
		}
	}
}





int main(void)
{
	readin();
	initgraph(500, 700);
//	sortt(1);
	pr_start();
//	pr_indi(head->getnext());
//	pr_delete();
//	seekpush("m", "", "");
	save();
	delall();
	return 0;
}


