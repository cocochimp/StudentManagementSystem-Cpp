#include<iostream>
using namespace std;
#include "Student.h"

int main() {
	Student s;

	int choice = 0;
	int num = 0;

	while (true)
	{
		//展示菜单
		s.showMenu();
		cout << "选择你所需的功能(输入序号):" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			s.exitSystem();
			break;
		case 1: //添加学生
			num=s.addStudent(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 2: //显示学生
			s.showStudent(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 3: //删除学生
			num=s.deleteStudent(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 4: //修改学生
			s.modifyStudent(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 5: //查找学生
			s.findStudent(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 6: //排序成绩
			s.sortStudent(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 7: //读取TXT文件
			num=s.readtxt(num);
			cout << endl;
			cout << "表中学生人数为：" << num << endl << endl;
			break;
		case 8: //写入TXT文件
			s.writetxt(num);
			break;
		default:
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}