#include "Student.h"
#include<iostream>

//显示功能表
void Student::showMenu() {
	cout << "        学生信息管理(SIM)系统菜单:  " << endl << endl;
	cout << "——        0、退出SIM系统           ——   " << endl;
	cout << "——        1、添加学生信息          ——   " << endl;
	cout << "——        2、显示所有学生信息      ——   " << endl;
	cout << "——        3、删除学生信息          ——   " << endl;
	cout << "——        4、修改学生信息          ——   " << endl;
	cout << "——        5、查找学生信息          ——   " << endl;
	cout << "——        6、排序学生成绩          ——   " << endl;
	cout << "——        7、读取txt文件           ——   " << endl;
	cout << "——        8、写入txt文件           ——   " << endl << endl;
}


//0、退出系统
void Student::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


//1、增加学生信息
int Student::addStudent(int num) {

	array[num] = new Student[max];
	cout << "请输入你要添加的学生信息：" << endl;
	
	//基本信息
	long long id;
	int age, klass, year;
	string name, sex, profession;	
	//成绩信息
	double math, english, dsa, java;

	//姓名
	cout << "输入姓名：" << endl;
	cin >> name;
	array[num]->s_name = name;
	cout << endl;

	//学号
	cout << "输入学号：" << endl;
	cout << "【1-4位为入学年份：2017-2020】"<<endl;
	cout << "【5-9位为专业号：软件工程：11701 / 计算机科学与技术：11602】"<<endl;
	while (true) {	
	part1:
		string s;
		cin >> s;
		while(ss(s) == 0)
		{
			cout << "输入错误，请重新输入！"<<endl;
			cin >> s;
		}
		id = atoll(s.c_str());
		//cin >> id;
		for (int i = 0; i <= num; i++) {
			if (id == array[i]->s_id) {
				cout << "学号重复！请重新添加！" << endl<<endl;
				goto part1;
			}
		}
	part:
		    //推导：入学年份、专业、班级
			if (id / 100000000000 >= 1 && id / 100000000000 < 10 ) {
				if (id / 100000000 >= 2017 && id / 100000000 < 2021) {
					if (id / 1000 % 100000 == 11701) {
						Student::se(num, id);

						cout << "请输入各科成绩：" << endl;
						cout << "高等数学：";
						cin >> math;
						Student::math(math, num);	
						cout << "大学英语：";
						cin >> english;
						Student::english(english, num);
						cout << "数据结构与算法：";
						cin >> dsa;
						Student::dsa(dsa, num);
						array[num]->g_grade = (array[num]->a_math + array[num]->a_english + array[num]->b_dsa) / 3;

						break;
					}
					else if (id / 1000 % 100000 == 11602) {
						Student::cst(num, id);

						cout << "请输入各科成绩：" << endl;
						cout << "高等数学：";
						cin >> math;
						Student::math(math, num);
						cout << "大学英语：";
						cin >> english;
						Student::english(english, num);
						cout << "数据结构与算法：";
						cin >> java;
						Student::java(java, num);
						array[num]->g_grade = (array[num]->a_math + array[num]->a_english + array[num]->b_java) / 3;

						break;
					}
				}			
			}
			cout << "您输入的学号有误！请重新输入！" << endl;
		}


		//性别
		cout << "性别：(男 or 女)" << endl;
		cout << "【可输入0跳过】" << endl;
		while (true) {
			cin >> sex;
			if (sex == "男" || sex == "女") {
				array[num]->s_sex = sex;
				break;
			}
			else if (sex == "0") {
				array[num]->s_sex = " x ";
				break;
			}
			else {
				cout << "您输入的性别有误！请重新输入！" << endl;
			}
		}
		cout << endl;

	
	//年龄
		cout << "年龄：(14--28)" << endl;
		cout << "【可输入0跳过】" << endl;
	while (true) {
		cin >> age;
		if (age <= 28 && age >= 14) {
			array[num]->s_age = age;
			break;
		}
		else if (age == 0) {
			array[num]->s_age = 000;
			break;
		}
		else {
			cout << "您输入的年龄有误！请重新输入！" << endl;
		}
	};
	cout << endl;

	//结束增加操作
	cout << "添加学生操作成功！" << endl;
	system("pause");
	system("cls");

	return ++num;
}


//2、显示所有学生信息
void Student::showStudent(int num){
	cout << endl;
	//int a = 0;
		cout << "所有学生基本信息：" << endl;
		cout << "学生学号：      姓名：    班级：      性别：   年龄：   专业：" << endl;
		for (int i = 0; i < num; i++) {
			//判空
			if (array[i]->s_id != 0) {
				cout << array[i]->s_id << "    "
					<< array[i]->s_name << "      ";
				if (array[i]->s_id / 1000 % 100000 == 11701) {
					cout << "软件" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				else if (array[i]->s_id / 1000 % 100000 == 11602) {
					cout << "计科" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				cout << array[i]->s_sex << "       "
					<< array[i]->s_age << "        "
					<< array[i]->s_profession << endl;
			}
		}

		cout << endl;

		cout << "所有学生成绩信息：" << endl;

		cout << "软件工程学生：" << endl;
		//软件工程学生
		cout << "学生学号：       姓名：   高等数学：  大学英语：     数据结构与算法：     总绩点： " << endl;
		for (int i = 0; i < num; i++) {
			if (array[i]->s_id!=0 && array[i]->s_id / 1000 % 100000 == 11701) {
				cout << array[i]->s_id << "     "
					<< array[i]->s_name << "     "
					<< array[i]->a_math << "          "
					<< array[i]->a_english << "            "
					<< array[i]->b_dsa << "                  "
					<< setprecision(3) << array[i]->g_grade << endl;
			}
		}

		cout << endl;

		cout << "计算机科学与技术学生：" << endl;
		//计算机科学与技术学生
		cout << "学生学号：       姓名：   高等数学：  大学英语：     java程序设计：      总绩点： " << endl;
		for (int i = 0; i < num; i++) {
			if (array[i]->s_id != 0 && array[i]->s_id / 1000 % 100000 == 11602) {
				cout << array[i]->s_id << "     "
					<< array[i]->s_name << "     "
					<< array[i]->a_math << "          "
					<< array[i]->a_english << "            "
					<< array[i]->b_java << "                "
					<< setprecision(3) << array[i]->g_grade << endl;
			}
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	

//3、删除学生信息
int Student::deleteStudent(int num) {

	int choice = 0;
	long long id;
	cout << "您要进行某个学生信息的整体信息删除还是部分信息删除？" << endl;
	head1:
	cout << "返回 —— 0" << endl;
	cout << "整体删除 —— 1" << endl;
	cout << "部分删除 —— 2" << endl;

	cin >> choice;
	cout << endl;
	if (choice == 0) {
		cout << "返回成功！" << endl;
		system("pause");
		system("cls");
		return num;
	}
	else if (choice == 1) {
		cout << "请输入学生学号：(12位有效数字)" << endl;
		//删除某个学生所有信息
		cin >> id;
		for (int i = 0; i < num; i++) {
			if (id == array[i]->s_id) {
				array[i]->s_id = 0;  array[i]->s_name = "x";
				array[i]->s_klass = 0; array[i]->s_sex = "x";
				array[i]->s_age = 0; array[i]->s_profession = "x";
				array[i]->a_math = 0; array[i]->a_english = 0;
				array[i]->b_dsa = 0; array[i]->b_java = 0;
				array[i]->g_grade = 0;
				cout << "删除成功！" << endl;
				system("pause");
				system("cls");
				return --num;
			}
		}
		cout << endl;
		cout << "没有找到该学生！请重新选择你要执行的操作：" << endl;
		goto head1;
	}
	else if (choice == 2) {
		cout << "请输入学生学号：(12位有效数字)" << endl;
		cin >> id;
		//删除学生的性别、年龄、总成绩
		int select = 0;
		for (int i = 0; i < num; i++) {
			if (id == array[i]->s_id) {
				cout << endl;
				cout << "找到该学生！" << endl << endl;
				cout << "请输入你要删除的该学生信息：" << endl;
			head2:
				cout << "【性别 —— 1  ||  年龄 —— 2  ||  总绩点 —— 3】" << endl;
				cin >> select;
				if (select == 1) {
					array[i]->s_sex = " x ";
					cout << "删除成功！" << endl;
					system("pause");
					system("cls");
					return num;
				}
				else if (select == 2) {
					array[i]->s_age = 0;
					cout << "删除成功！" << endl;
					system("pause");
					system("cls");
					return num;
				}
				else if (select == 3) {
					array[i]->g_grade = 0.0;
					cout << "删除成功！" << endl;
					system("pause");
					system("cls");
					return num;
				}
				else {
					cout << "输入错误信息，请重新输入！";
					goto head2;
				}
			}
		}
		cout << endl << endl;
		cout << "没有找到该学生！退出功能" << endl;
		system("pause");
		system("cls");
		return num;
	}
	else {
		cout << "你选择的功能错误，请重新输入:" << endl;
		goto head1;
	}
}

 
//4、修改学生信息
void Student::modifyStudent(int num) {
	int choice1,choice2; 
	int i = 0;
	double math, english, dsa, java, grade;
	string name, sex, profession;
	int klass, age;
	long long id;

	cout << "输入你要修改的学生学号：" << endl;
	head2:
	cin >> id;

	for (i; i < num; i++) {
		if (id == array[i]->s_id) {
			cout << "找到学生！" << endl;
			goto head1;
		}
	}
	cout << "没有找到该学生，请重新输入学号！" << endl;
	i = 0;
	goto head2;

	head1:
	cout << "输入你要修改的信息（基本信息—1 / 成绩信息—2）：" << endl;
	cin >> choice1;

	if (choice1 == 2) {
		cout << "请选择你要修改的信息" << endl;
		head4:
		cout << "【高等数学—1，大学英语—,2，专业科目—3，总绩点—4】" << endl;
		cin >> choice2;
		if (choice2 == 1) {
			cout << "请输入新数学成绩：" << endl;
			cin >> math;
			array[i]->a_math = math;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "请输入新英语成绩：" << endl;
			cin >> english;
			array[i]->a_english = english;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			if (array[i]->s_id / 1000 % 100000 == 11701) {
				cout << "请输入数据结构与算法成绩：" << endl;
				cin >> dsa;
				array[i]->b_dsa = dsa;
				cout << "修改成功！" << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "请输入新java程序设计成绩：" << endl;
				cin >> java;
				array[i]->b_java = java;
				cout << "修改成功！" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (choice2 == 4) {
			cout << "请输入新总成绩：" << endl;
			cin >> grade;
			array[i]->g_grade = grade;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "操作失败，请重新输入！" << endl;
			goto head4;
		}
	}
	else if (choice1 == 1) {
		cout << "请选择你要修改的信息" << endl;
		head3:
		cout << "【姓名—1，班级—2，性别—3，年龄—4，专业—5】" << endl;
		cin >> choice2;

		if (choice2 == 1) {
			cout << "请输入新姓名：" << endl;
			cin >> name;
			array[i]->s_name = name;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "请输入新班级：" << endl;
			cin >> klass;
			array[i]->s_klass = klass;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			cout << "请输入新性别：" << endl;
			cin >> sex;
			array[i]->s_sex = sex;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 4) {
			cout << "请输入新年龄：" << endl;
			cin >> age;
			array[i]->s_age = age;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else if(choice2 == 5) {
			cout << "请输入新专业：" << endl;
			cin >> profession;
			array[i]->s_profession = profession;
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "操作失败，请重新输入！" << endl;
			goto head3;
		}

	}
	else {
		cout << "操作失败，请重新输入！" << endl;
		goto head1;
	}
}


//5、查找学生信息
void Student::findStudent(int num) {
	long long id;
	int i = 0;
	int choice1, choice2;
	cout << "输入你要查询的学生学号：" << endl;

head2:
	cin >> id;
	for (i; i < num; i++) {
		if (id == array[i]->s_id) {
			cout << "找到学生！" << endl;
			goto head1;
		}
	}
	cout << "没有找到该学生，请重新输入学号！" << endl;
	i = 0;
	goto head2;

head1:
	cout << "输入你要查询的学生信息：" << endl;
	cout << "输入你要查询的信息（全部信息—1 / 基本信息—2 / 成绩信息—3）：" << endl;
	cin >> choice1;

	if (choice1 == 1) {
		cout << "该学生的基本信息：" << endl;
		cout << "学生学号：      姓名：    班级：      性别：   年龄：   专业：" << endl;
			//pankong
			if (array[i]->s_id != 0) {
				cout << array[i]->s_id << "    "
					<< array[i]->s_name << "      ";
				if (array[i]->s_id / 1000 % 100000 == 11701) {
					cout << "软件" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				else if (array[i]->s_id / 1000 % 100000 == 11602) {
					cout << "计科" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				cout << array[i]->s_sex << "       "
					<< array[i]->s_age << "        "
					<< array[i]->s_profession << endl;
			}
		
		cout << endl;
		cout << "该学生的成绩信息：" << endl;
		//软件工程学生
			if (array[i]->s_id != 0 && array[i]->s_id / 1000 % 100000 == 11701) {
				cout << "学生学号：       姓名：   高等数学：  大学英语：     数据结构与算法：     总绩点： " << endl;
				cout << array[i]->s_id << "     "
					<< array[i]->s_name << "     "
					<< array[i]->a_math << "          "
					<< array[i]->a_english << "            "
					<< array[i]->b_dsa << "                  "
					<< setprecision(3) << array[i]->g_grade << endl;
			}
		cout << endl;
		//计算机科学与技术学生
			if (array[i]->s_id != 0 && array[i]->s_id / 1000 % 100000 == 11602) {
				cout << "学生学号：       姓名：   高等数学：  大学英语：     java程序设计：      总绩点： " << endl;
				cout << array[i]->s_id << "     "
					<< array[i]->s_name << "     "
					<< array[i]->a_math << "          "
					<< array[i]->a_english << "            "
					<< array[i]->b_java << "                "
					<< setprecision(3) << array[i]->g_grade << endl;
			}
		
		cout << endl;
		system("pause");
		system("cls");
	}
	else if (choice1 == 2) {
		cout << "输入你要查询的信息：" << endl;
	head3:
		cout << "【姓名—1，班级—2，性别—3，年龄—4，专业—5】" << endl;
		cin >> choice2;

		if (choice2 == 1) {
			cout << "查找成功！" << endl;
			cout << "本学生的姓名为：" << array[i]->s_name << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "查找成功！" << endl;
			cout << "本学生的班级为：" << array[i]->s_klass <<"班" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			cout << "查找成功！" << endl;
			cout << "本学生的性别为：" << array[i]->s_sex << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 4) {
			cout << "查找成功！" << endl;
			cout << "本学生的年龄为：" << array[i]->s_age << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 5) {
			cout << "查找成功！" << endl;
			cout << "本学生的专业为：" << array[i]->s_profession << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "操作失败，请重新输入！" << endl;
			goto head3;
		}
	}
	else if (choice1 == 3) {
		cout << "输入你要查询的信息：" << endl;
	head4:
		cout << "【高等数学—1，大学英语—2，专业科目—3，总绩点—4】" << endl;
		cin >> choice2;

		if (choice2 == 1) {
			cout << "查找成功！" << endl;
			cout << "本学生的高数绩点为：" << array[i]->a_math << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "查找成功！" << endl;
			cout << "本学生的大英绩点为：" << array[i]->a_english << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			cout << "查找成功！" << endl;
			if (array[i]->s_id / 1000 % 100000 == 11701) {
				cout << "本学生的数据结构与算法绩点为：" << array[i]->b_dsa << endl;
			}
			else if (array[i]->s_id / 1000 % 100000 == 11602) {
				cout << "本学生的java程序设计绩点为：" << array[i]->b_java << endl;
			}
			system("pause");
			system("cls");
		}
		else if (choice2 == 4) {
			cout << "查找成功！" << endl;
			cout << "本学生的总绩点为：" << array[i]->g_grade << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "操作失败，请重新输入！" << endl;
			goto head4;
		}
	}
	else {
		cout << "查找失败，退出该功能！";
		system("pause");
		system("cls");
	}

}


//6、排序学生成绩(总绩点 or 各科成绩)
void Student::sortStudent(int num) {
	/*Btree b;
	b.CreateBtree(array[big]->s_id);*/

	int choice;

	cout << "选择你要排序的对象：" << endl;
	head:
	cout << "【总绩点——1  ||  高等数学——2  ||  大学英语——3】"<<endl;
	cin >> choice;

	if (choice == 1) {
		for (int i = 0; i < num; i++) {
			array[i]->f_grade = array[i]->g_grade;     //绩点
			array[i]->f_id = array[i]->s_id;      //学号
			array[i]->f_name = array[i]->s_name;     //姓名
		}

		for (int i = 0; i < num - 1; i++) {
			//
			for (int j = 0; j < num - i - 1; j++) {
				if (array[j]->g_grade < array[j + 1]->g_grade) {
					double temp1 = array[j]->g_grade;
					double temp2 = array[j]->s_id;
					string temp3 = array[j]->s_name;

					array[j]->g_grade = array[j + 1]->g_grade;
					array[j]->s_id = array[j + 1]->s_id;
					array[j]->s_name = array[j + 1]->s_name;

					array[j + 1]->g_grade = temp1;
					array[j + 1]->s_id = temp2;
					array[j + 1]->s_name = temp3;
				}
			}
		}

		cout << "成绩从大到小排序为：" << endl;
		for (int i = 0; i < num; i++) {
			cout << "姓名：" << array[i]->s_name << "      "
				<< "学号：" << array[i]->s_id << "     "
				<< "总绩点为：" << array[i]->g_grade << endl;
		}

		for (int i = 0; i < num; i++) {
			array[i]->g_grade = array[i]->f_grade;
			array[i]->s_id = array[i]->f_id;
			array[i]->s_name = array[i]->f_name;
		}
	}
	else if (choice == 2) {
		for (int i = 0; i < num; i++) {
			array[i]->f_math = array[i]->a_math;     //绩点
			array[i]->f_id = array[i]->s_id;      //学号
			array[i]->f_name = array[i]->s_name;     //姓名
		}

		for (int i = 0; i < num - 1; i++) {
			//
			for (int j = 0; j < num - i - 1; j++) {
				if (array[j]->a_math < array[j + 1]->a_math) {
					double temp1 = array[j]->a_math;
					double temp2 = array[j]->s_id;
					string temp3 = array[j]->s_name;

					array[j]->a_math = array[j + 1]->a_math;
					array[j]->s_id = array[j + 1]->s_id;
					array[j]->s_name = array[j + 1]->s_name;

					array[j + 1]->a_math = temp1;
					array[j + 1]->s_id = temp2;
					array[j + 1]->s_name = temp3;
				}
			}
		}

		cout << "成绩从大到小排序为：" << endl;
		for (int i = 0; i < num; i++) {
			cout << "姓名：" << array[i]->s_name << "      "
				<< "学号：" << array[i]->s_id << "     "
				<< "高数绩点为：" << array[i]->a_math << endl;
		}

		for (int i = 0; i < num; i++) {
			array[i]->a_math = array[i]->f_math;
			array[i]->s_id = array[i]->f_id;
			array[i]->s_name = array[i]->f_name;
		}
	}
	else if (choice == 3) {
		for (int i = 0; i < num; i++) {
			array[i]->f_english = array[i]->a_english;     //绩点
			array[i]->f_id = array[i]->s_id;      //学号
			array[i]->f_name = array[i]->s_name;     //姓名
		}

		for (int i = 0; i < num - 1; i++) {
			//
			for (int j = 0; j < num - i - 1; j++) {
				if (array[j]->a_english < array[j + 1]->a_english) {
					double temp1 = array[j]->a_english;
					double temp2 = array[j]->s_id;
					string temp3 = array[j]->s_name;

					array[j]->a_english = array[j + 1]->a_english;
					array[j]->s_id = array[j + 1]->s_id;
					array[j]->s_name = array[j + 1]->s_name;

					array[j + 1]->a_english = temp1;
					array[j + 1]->s_id = temp2;
					array[j + 1]->s_name = temp3;
				}
			}
		}

		cout << "成绩从大到小排序为：" << endl;
		for (int i = 0; i < num; i++) {
			cout << "姓名：" << array[i]->s_name << "      "
				<< "学号：" << array[i]->s_id << "     "
				<< "大英绩点为：" << array[i]->a_english << endl;
		}

		for (int i = 0; i < num; i++) {
			array[i]->a_english = array[i]->f_english;
			array[i]->s_id = array[i]->f_id;
			array[i]->s_name = array[i]->f_name;
		}
	}
	else {
		cout << "输入错误！请重新输入！" << endl;
		goto head;
	}

	system("pause");
	system("cls");
}


//7、读取TXT文件
int Student::readtxt(int num){
	array[max] = new Student[max];
	ifstream infile("E:\\专业资料\\c++项目文件\\大一（下）\\SIM系统\\SIM系统\\学生信息.txt", ios::in );
	if (!infile.is_open())
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	/*int i = 1;
	string line;
	while (getline(infile, line)) {
		cout << "第" << i << "行数据：  "<<endl;
		cout << line<<endl;
		i++;
	}*/
	//string arr1[big][big];
	//int arr2[big][big];
	//double arr3[big][big];
	//long long arr4[big][big];

	//long long id;   //学号
	//string name;   //姓名
	//int klass;    //班级
	//string sex;   //性别
	//int age;   //年龄
	//string profession;   //专业

	////成绩信息
	//double math;   //高等数学
	//double english;   //大学英语
	//double dsa;   //数据结构与算法
	//double java;   //java程序设计
	//double grade;  //总绩点
	string s;
	while (getline(infile,s)) {
		cout << s << endl;
		num++;
	}
	//int i = 0;
	//int num = 0;
	//while (infile >> id && infile >> name && infile>>klass &&infile>>sex
	//	&&infile>>age && infile >> profession && infile >> math && 
	//	infile >> english  && infile >> grade)
	//{
	//	arr4[i][0] = id; arr1[i][1] = name;
	//	arr2[i][2] = klass;arr1[i][3] = sex;
	//	arr2[i][4] = age;arr1[i][5] = profession;
	//	arr3[i][6] = math;arr3[i][7] = english;
	//	arr3[i][8] = grade;
	//	i++;
	//	num++;
	//}
	//cout << "读取成功！" << endl;
	//cout << "学生表信息：" << endl;
	//for (int j = 0; j < i; j++) {
	//	cout << arr4[j][0] << "    "<< arr1[j][1] << "    "
	//		<< arr2[j][2] << "    "<< arr1[j][3] << "    "
	//		<< arr2[j][4] << "    "<< arr1[j][5] << "    "
	//		<< arr3[j][6] << "    "<< arr3[j][7] << "    "
	//		<< arr3[j][8] << "    " << endl;
	//}


	infile.close();

	////array[i]->s_id = id;
	////array[i]->s_name = name;
	////array[i]->s_klass = klass;
	////array[i]->s_sex = sex;
	////array[i]->s_age = age;
	////array[i]->s_profession = profession;
	////array[i]->a_math = math;
	////array[i]->a_english = english;
	////array[i]->g_grade = grade;
	system("pause");
	system("cls");
	return num;
}


//8、写入TXT文件
void Student::writetxt(int num) {
	
	ofstream outfile("E:\\专业资料\\c++项目文件\\大一（下）\\SIM系统\\SIM系统\\学生信息.txt", ios::in | ios::out | ios::binary);
	if (!outfile.is_open())
	{
		cout << "文件打开失败！" << endl;
		exit(1);
	}
	for (int i = 0; i < num; i++) {

		outfile << array[i]->s_id << "   " << array[i]->s_name << "   ";
		
		if (array[i]->s_id / 1000 % 100000 == 11701) {
			outfile << "软件" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "   ";
		}
		else if (array[i]->s_id / 1000 % 100000 == 11602) {
			outfile << "计科" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "   ";
		}
		outfile << array[i]->s_klass << "  ";

		outfile << array[i]->s_sex << "   " << array[i]->s_age << "   " << array[i]->s_profession << "    "
			<< array[i]->a_math << "    " << array[i]->a_english<<"    ";


		if (array[i]->s_id / 1000 % 100000 == 11701) {
			outfile << array[i]->b_dsa << "   ";
		}
		else if (array[i]->s_id / 1000 % 100000 == 11602) {
			outfile << array[i]->b_java << "   ";
		}

		outfile << setprecision(3) << array[i]->g_grade << " ";

		outfile << "\r\n";
	}
	outfile.close();

	cout << "录入学生信息完成！" << endl;
	system("pause");
	system("cls");
}


int  Student::ss(string s) {
	int l = s.length();
	for (int i = 0; i < l; i++) {
		string j = s.substr(i, 1) + "1";
		if (atoi(j.c_str() ) ==0){
			return 0;
		}
	}
	return atoi(s.c_str()) + 1;
}


//创建排序二叉树并进行中序遍历
void Btree::CreateBtree(int x)
{
	node* newnode = new node;
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	if (NULL == root)
	{
		root = newnode;
	}
	else
	{
		node* back=nullptr;
		node* current = root;

		while (current != NULL)   //找到要插入newnode的节点指针
		{
			back = current;
			if (current->data > x)
			{
				current = current->left;
			}
			else
			{
				current = current->right;
			}
		}

		if (back->data > x)
		{
			back->left = newnode;
		}
		else
		{
			back->right = newnode;
		}
	}
}
void Btree::Inorder(node* root)    //中序遍历排序二叉树
{
	if (root)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}


//附：
//1-1、录入各科成绩，计算绩点
void Student::math(double math, int num) {
	while (true) {
		if (math >= 0 && math < 60) {
			array[num]->a_math = 0;
			cout << "该科目不及格！绩点为 0 " << endl << endl;
			break;
		}
		else if (math >= 60 && math <= 100) {
			array[num]->a_math = (math - 50) / 10;
			cout << "该科目及格！绩点为："<< setprecision(3) << array[num]->a_math << endl << endl;
			break;
		}
		else {
			array[num]->a_math = 0;
			cout << "成绩不合法！绩点为0 " << endl << endl;
			break;
		}
	}
}
void Student::english(double english, int num) {
	while (true) {
		if (english >= 0 && english < 60) {
			array[num]->a_english = 0;
			cout << "该科目不及格！绩点为 0 " << endl << endl;
			break;
		}
		else if (english >= 60 && english <= 100) {
			array[num]->a_english = (english - 50) / 10;
			cout << "该科目及格！绩点为：" << setprecision(3) << array[num]->a_english << endl << endl;
			break;
		}
		else {
			array[num]->a_english = 0;
			cout << "成绩不合法！绩点为0 " << endl << endl;
			break;
		}
	}
}
void Student::dsa(double dsa, int num) {
	while (true) {
		if (dsa >= 0 && dsa < 60) {
			array[num]->b_dsa = 0;
			cout << "该科目不及格！绩点为 0 " << endl << endl;
			break;
		}
		else if (dsa >= 60 && dsa <= 100) {
			array[num]->b_dsa = (dsa - 50) / 10;
			cout << "该科目及格！绩点为：" << setprecision(3) << array[num]->b_dsa << endl << endl;
			break;
		}
		else {
			array[num]->a_math = 0;
			cout << "成绩不合法！绩点为0 " << endl << endl;
			break;
		}
	}
}
void Student::java(double java, int num) {
	while (true) {
		if (java >= 0 && java < 60) {
			array[num]->b_java = 0;
			cout << "该科目不及格！绩点为 0 " << endl << endl;
			break;
		}
		else if (java >= 60 && java <= 100) {
			array[num]->b_java = (java - 50) / 10;
			cout << "该科目及格！绩点为：" << setprecision(3) << array[num]->b_java << endl << endl;
			break;
		}
		else {
			array[num]->b_java = 0;
			cout << "成绩不合法！绩点为0 " << endl << endl;
			break;
		}
	}
}

//1-2、推断信息
void Student::se(int num, long long id) {
	array[num]->s_id = id;
	array[num]->s_profession = "软件工程";
	array[num]->s_klass = id / 100 % 10;
	cout << "通过学号得知该学生：" << endl << endl;
	cout << "	入学年份为：";
	cout << id / 100000000 << endl;;
	cout << "	专业为：";
	cout << array[num]->s_profession << endl;
	cout << "	班级为：";
	cout << "软件" << "1" << id / 100000000 % 100 << array[num]->s_klass << endl << endl;
}
void Student::cst(int num, long long id) {
	array[num]->s_id = id;
	array[num]->s_profession = "计算机科学与技术";
	array[num]->s_klass = id / 100 % 10;
	cout << "通过学号得知该学生：" << endl << endl;
	cout << "入学年份为：";
	cout << id / 100000000 << endl;;
	cout << "专业为：";
	cout << array[num]->s_profession << endl;
	cout << "班级为：";
	cout << "计科" << "1" << id / 100000000 % 100 << array[num]->s_klass << endl << endl;
}




