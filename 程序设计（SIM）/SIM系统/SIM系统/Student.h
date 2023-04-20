#include<iostream>
#include<string>
#include <iomanip>  //������Чλ��
#include<fstream>   //txt�ļ���ȡ/д��

using namespace std;
#define max 100
#define big 10

//��������������������������
struct node                     //���������ṹ
{
	int data;
	node* left;                 //���������ָ��
	node* right;                //���������ָ��
};
class Btree
{
	node* root;                 //������ָ��
public:
	Btree()
	{
		root = NULL;
	}
	void CreateBtree(int);
	void Inorder()              //�������������
	{
		Inorder(root);
		cout << endl;
	}
	void Inorder(node*);       //��������ӹ���
};

//ѧ����
class Student
{
private:
	//������Ϣ
	long long s_id;   //ѧ��
	string s_name;   //����
	int s_klass;    //�༶
	string s_sex;   //�Ա�
	int s_age;   //����
	string s_profession;   //רҵ

	//�ɼ���Ϣ
	double a_math;   //�ߵ���ѧ
	double a_english;   //��ѧӢ��
	double b_dsa;   //���ݽṹ���㷨
	double b_java;   //java�������
	double g_grade;  //�ܼ���

	//���浥λ
	double f_grade,f_id,f_math,f_english;  
	string f_name;  

	Student**array = new Student *  [max];

public:
	
	//��ʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//1������ѧ����Ϣ
	int addStudent(int num);

	//2����ʾѧ����Ϣ
	void showStudent(int num);

	//3��ɾ��ѧ����Ϣ
	int deleteStudent(int num);

	//4���޸�ѧ����Ϣ
	void modifyStudent(int num);

	//5������ѧ����Ϣ
	void findStudent(int num);

	//6������ѧ���ɼ�(�ܼ��� or ���Ƴɼ�)
	void sortStudent(int num);

	//7����ȡtxt�ļ�
	int readtxt(int num);
	int ss(string s);

	//8��������д��txt�ļ���
	void writetxt(int num);


	//����
    //1-1��¼����Ƴɼ�
	void math(double math, int num);
	void english(double english, int num);
	void dsa(double dsa, int num);
	void java(double java, int num);
	void allGrade(double math, double english, double professionKlass,int num);

	//1-2���������ѧ��ѧ���ƶϳ�����Ϣ
	void se(int num, long long id);
	void cst(int num, long long id);
};


