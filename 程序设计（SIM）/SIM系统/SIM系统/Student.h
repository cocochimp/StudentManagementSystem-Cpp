#include<iostream>
#include<string>
#include <iomanip>  //控制有效位数
#include<fstream>   //txt文件读取/写入

using namespace std;
#define max 100
#define big 10

//建立排序二叉树并进行中序遍历
struct node                     //二叉树结点结构
{
	int data;
	node* left;                 //右子树结点指针
	node* right;                //左子树结点指针
};
class Btree
{
	node* root;                 //根结点的指针
public:
	Btree()
	{
		root = NULL;
	}
	void CreateBtree(int);
	void Inorder()              //中序遍历主过程
	{
		Inorder(root);
		cout << endl;
	}
	void Inorder(node*);       //中序遍历子过程
};

//学生类
class Student
{
private:
	//基本信息
	long long s_id;   //学号
	string s_name;   //姓名
	int s_klass;    //班级
	string s_sex;   //性别
	int s_age;   //年龄
	string s_profession;   //专业

	//成绩信息
	double a_math;   //高等数学
	double a_english;   //大学英语
	double b_dsa;   //数据结构与算法
	double b_java;   //java程序设计
	double g_grade;  //总绩点

	//储存单位
	double f_grade,f_id,f_math,f_english;  
	string f_name;  

	Student**array = new Student *  [max];

public:
	
	//显示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//1、增加学生信息
	int addStudent(int num);

	//2、显示学生信息
	void showStudent(int num);

	//3、删除学生信息
	int deleteStudent(int num);

	//4、修改学生信息
	void modifyStudent(int num);

	//5、查找学生信息
	void findStudent(int num);

	//6、排序学生成绩(总绩点 or 各科成绩)
	void sortStudent(int num);

	//7、读取txt文件
	int readtxt(int num);
	int ss(string s);

	//8、将数据写入txt文件中
	void writetxt(int num);


	//附：
    //1-1、录入各科成绩
	void math(double math, int num);
	void english(double english, int num);
	void dsa(double dsa, int num);
	void java(double java, int num);
	void allGrade(double math, double english, double professionKlass,int num);

	//1-2、输出根据学生学号推断出的信息
	void se(int num, long long id);
	void cst(int num, long long id);
};


