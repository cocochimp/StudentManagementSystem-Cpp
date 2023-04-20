#include "Student.h"
#include<iostream>

//��ʾ���ܱ�
void Student::showMenu() {
	cout << "        ѧ����Ϣ����(SIM)ϵͳ�˵�:  " << endl << endl;
	cout << "����        0���˳�SIMϵͳ           ����   " << endl;
	cout << "����        1�����ѧ����Ϣ          ����   " << endl;
	cout << "����        2����ʾ����ѧ����Ϣ      ����   " << endl;
	cout << "����        3��ɾ��ѧ����Ϣ          ����   " << endl;
	cout << "����        4���޸�ѧ����Ϣ          ����   " << endl;
	cout << "����        5������ѧ����Ϣ          ����   " << endl;
	cout << "����        6������ѧ���ɼ�          ����   " << endl;
	cout << "����        7����ȡtxt�ļ�           ����   " << endl;
	cout << "����        8��д��txt�ļ�           ����   " << endl << endl;
}


//0���˳�ϵͳ
void Student::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}


//1������ѧ����Ϣ
int Student::addStudent(int num) {

	array[num] = new Student[max];
	cout << "��������Ҫ��ӵ�ѧ����Ϣ��" << endl;
	
	//������Ϣ
	long long id;
	int age, klass, year;
	string name, sex, profession;	
	//�ɼ���Ϣ
	double math, english, dsa, java;

	//����
	cout << "����������" << endl;
	cin >> name;
	array[num]->s_name = name;
	cout << endl;

	//ѧ��
	cout << "����ѧ�ţ�" << endl;
	cout << "��1-4λΪ��ѧ��ݣ�2017-2020��"<<endl;
	cout << "��5-9λΪרҵ�ţ�������̣�11701 / �������ѧ�뼼����11602��"<<endl;
	while (true) {	
	part1:
		string s;
		cin >> s;
		while(ss(s) == 0)
		{
			cout << "����������������룡"<<endl;
			cin >> s;
		}
		id = atoll(s.c_str());
		//cin >> id;
		for (int i = 0; i <= num; i++) {
			if (id == array[i]->s_id) {
				cout << "ѧ���ظ�����������ӣ�" << endl<<endl;
				goto part1;
			}
		}
	part:
		    //�Ƶ�����ѧ��ݡ�רҵ���༶
			if (id / 100000000000 >= 1 && id / 100000000000 < 10 ) {
				if (id / 100000000 >= 2017 && id / 100000000 < 2021) {
					if (id / 1000 % 100000 == 11701) {
						Student::se(num, id);

						cout << "��������Ƴɼ���" << endl;
						cout << "�ߵ���ѧ��";
						cin >> math;
						Student::math(math, num);	
						cout << "��ѧӢ�";
						cin >> english;
						Student::english(english, num);
						cout << "���ݽṹ���㷨��";
						cin >> dsa;
						Student::dsa(dsa, num);
						array[num]->g_grade = (array[num]->a_math + array[num]->a_english + array[num]->b_dsa) / 3;

						break;
					}
					else if (id / 1000 % 100000 == 11602) {
						Student::cst(num, id);

						cout << "��������Ƴɼ���" << endl;
						cout << "�ߵ���ѧ��";
						cin >> math;
						Student::math(math, num);
						cout << "��ѧӢ�";
						cin >> english;
						Student::english(english, num);
						cout << "���ݽṹ���㷨��";
						cin >> java;
						Student::java(java, num);
						array[num]->g_grade = (array[num]->a_math + array[num]->a_english + array[num]->b_java) / 3;

						break;
					}
				}			
			}
			cout << "�������ѧ���������������룡" << endl;
		}


		//�Ա�
		cout << "�Ա�(�� or Ů)" << endl;
		cout << "��������0������" << endl;
		while (true) {
			cin >> sex;
			if (sex == "��" || sex == "Ů") {
				array[num]->s_sex = sex;
				break;
			}
			else if (sex == "0") {
				array[num]->s_sex = " x ";
				break;
			}
			else {
				cout << "��������Ա��������������룡" << endl;
			}
		}
		cout << endl;

	
	//����
		cout << "���䣺(14--28)" << endl;
		cout << "��������0������" << endl;
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
			cout << "������������������������룡" << endl;
		}
	};
	cout << endl;

	//�������Ӳ���
	cout << "���ѧ�������ɹ���" << endl;
	system("pause");
	system("cls");

	return ++num;
}


//2����ʾ����ѧ����Ϣ
void Student::showStudent(int num){
	cout << endl;
	//int a = 0;
		cout << "����ѧ��������Ϣ��" << endl;
		cout << "ѧ��ѧ�ţ�      ������    �༶��      �Ա�   ���䣺   רҵ��" << endl;
		for (int i = 0; i < num; i++) {
			//�п�
			if (array[i]->s_id != 0) {
				cout << array[i]->s_id << "    "
					<< array[i]->s_name << "      ";
				if (array[i]->s_id / 1000 % 100000 == 11701) {
					cout << "���" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				else if (array[i]->s_id / 1000 % 100000 == 11602) {
					cout << "�ƿ�" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				cout << array[i]->s_sex << "       "
					<< array[i]->s_age << "        "
					<< array[i]->s_profession << endl;
			}
		}

		cout << endl;

		cout << "����ѧ���ɼ���Ϣ��" << endl;

		cout << "�������ѧ����" << endl;
		//�������ѧ��
		cout << "ѧ��ѧ�ţ�       ������   �ߵ���ѧ��  ��ѧӢ�     ���ݽṹ���㷨��     �ܼ��㣺 " << endl;
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

		cout << "�������ѧ�뼼��ѧ����" << endl;
		//�������ѧ�뼼��ѧ��
		cout << "ѧ��ѧ�ţ�       ������   �ߵ���ѧ��  ��ѧӢ�     java������ƣ�      �ܼ��㣺 " << endl;
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
	

//3��ɾ��ѧ����Ϣ
int Student::deleteStudent(int num) {

	int choice = 0;
	long long id;
	cout << "��Ҫ����ĳ��ѧ����Ϣ��������Ϣɾ�����ǲ�����Ϣɾ����" << endl;
	head1:
	cout << "���� ���� 0" << endl;
	cout << "����ɾ�� ���� 1" << endl;
	cout << "����ɾ�� ���� 2" << endl;

	cin >> choice;
	cout << endl;
	if (choice == 0) {
		cout << "���سɹ���" << endl;
		system("pause");
		system("cls");
		return num;
	}
	else if (choice == 1) {
		cout << "������ѧ��ѧ�ţ�(12λ��Ч����)" << endl;
		//ɾ��ĳ��ѧ��������Ϣ
		cin >> id;
		for (int i = 0; i < num; i++) {
			if (id == array[i]->s_id) {
				array[i]->s_id = 0;  array[i]->s_name = "x";
				array[i]->s_klass = 0; array[i]->s_sex = "x";
				array[i]->s_age = 0; array[i]->s_profession = "x";
				array[i]->a_math = 0; array[i]->a_english = 0;
				array[i]->b_dsa = 0; array[i]->b_java = 0;
				array[i]->g_grade = 0;
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				system("cls");
				return --num;
			}
		}
		cout << endl;
		cout << "û���ҵ���ѧ����������ѡ����Ҫִ�еĲ�����" << endl;
		goto head1;
	}
	else if (choice == 2) {
		cout << "������ѧ��ѧ�ţ�(12λ��Ч����)" << endl;
		cin >> id;
		//ɾ��ѧ�����Ա����䡢�ܳɼ�
		int select = 0;
		for (int i = 0; i < num; i++) {
			if (id == array[i]->s_id) {
				cout << endl;
				cout << "�ҵ���ѧ����" << endl << endl;
				cout << "��������Ҫɾ���ĸ�ѧ����Ϣ��" << endl;
			head2:
				cout << "���Ա� ���� 1  ||  ���� ���� 2  ||  �ܼ��� ���� 3��" << endl;
				cin >> select;
				if (select == 1) {
					array[i]->s_sex = " x ";
					cout << "ɾ���ɹ���" << endl;
					system("pause");
					system("cls");
					return num;
				}
				else if (select == 2) {
					array[i]->s_age = 0;
					cout << "ɾ���ɹ���" << endl;
					system("pause");
					system("cls");
					return num;
				}
				else if (select == 3) {
					array[i]->g_grade = 0.0;
					cout << "ɾ���ɹ���" << endl;
					system("pause");
					system("cls");
					return num;
				}
				else {
					cout << "���������Ϣ�����������룡";
					goto head2;
				}
			}
		}
		cout << endl << endl;
		cout << "û���ҵ���ѧ�����˳�����" << endl;
		system("pause");
		system("cls");
		return num;
	}
	else {
		cout << "��ѡ��Ĺ��ܴ�������������:" << endl;
		goto head1;
	}
}

 
//4���޸�ѧ����Ϣ
void Student::modifyStudent(int num) {
	int choice1,choice2; 
	int i = 0;
	double math, english, dsa, java, grade;
	string name, sex, profession;
	int klass, age;
	long long id;

	cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
	head2:
	cin >> id;

	for (i; i < num; i++) {
		if (id == array[i]->s_id) {
			cout << "�ҵ�ѧ����" << endl;
			goto head1;
		}
	}
	cout << "û���ҵ���ѧ��������������ѧ�ţ�" << endl;
	i = 0;
	goto head2;

	head1:
	cout << "������Ҫ�޸ĵ���Ϣ��������Ϣ��1 / �ɼ���Ϣ��2����" << endl;
	cin >> choice1;

	if (choice1 == 2) {
		cout << "��ѡ����Ҫ�޸ĵ���Ϣ" << endl;
		head4:
		cout << "���ߵ���ѧ��1����ѧӢ�,2��רҵ��Ŀ��3���ܼ��㡪4��" << endl;
		cin >> choice2;
		if (choice2 == 1) {
			cout << "����������ѧ�ɼ���" << endl;
			cin >> math;
			array[i]->a_math = math;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "��������Ӣ��ɼ���" << endl;
			cin >> english;
			array[i]->a_english = english;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			if (array[i]->s_id / 1000 % 100000 == 11701) {
				cout << "���������ݽṹ���㷨�ɼ���" << endl;
				cin >> dsa;
				array[i]->b_dsa = dsa;
				cout << "�޸ĳɹ���" << endl;
				system("pause");
				system("cls");
			}
			else {
				cout << "��������java������Ƴɼ���" << endl;
				cin >> java;
				array[i]->b_java = java;
				cout << "�޸ĳɹ���" << endl;
				system("pause");
				system("cls");
			}
		}
		else if (choice2 == 4) {
			cout << "���������ܳɼ���" << endl;
			cin >> grade;
			array[i]->g_grade = grade;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "����ʧ�ܣ����������룡" << endl;
			goto head4;
		}
	}
	else if (choice1 == 1) {
		cout << "��ѡ����Ҫ�޸ĵ���Ϣ" << endl;
		head3:
		cout << "��������1���༶��2���Ա�3�����䡪4��רҵ��5��" << endl;
		cin >> choice2;

		if (choice2 == 1) {
			cout << "��������������" << endl;
			cin >> name;
			array[i]->s_name = name;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "�������°༶��" << endl;
			cin >> klass;
			array[i]->s_klass = klass;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			cout << "���������Ա�" << endl;
			cin >> sex;
			array[i]->s_sex = sex;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 4) {
			cout << "�����������䣺" << endl;
			cin >> age;
			array[i]->s_age = age;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else if(choice2 == 5) {
			cout << "��������רҵ��" << endl;
			cin >> profession;
			array[i]->s_profession = profession;
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "����ʧ�ܣ����������룡" << endl;
			goto head3;
		}

	}
	else {
		cout << "����ʧ�ܣ����������룡" << endl;
		goto head1;
	}
}


//5������ѧ����Ϣ
void Student::findStudent(int num) {
	long long id;
	int i = 0;
	int choice1, choice2;
	cout << "������Ҫ��ѯ��ѧ��ѧ�ţ�" << endl;

head2:
	cin >> id;
	for (i; i < num; i++) {
		if (id == array[i]->s_id) {
			cout << "�ҵ�ѧ����" << endl;
			goto head1;
		}
	}
	cout << "û���ҵ���ѧ��������������ѧ�ţ�" << endl;
	i = 0;
	goto head2;

head1:
	cout << "������Ҫ��ѯ��ѧ����Ϣ��" << endl;
	cout << "������Ҫ��ѯ����Ϣ��ȫ����Ϣ��1 / ������Ϣ��2 / �ɼ���Ϣ��3����" << endl;
	cin >> choice1;

	if (choice1 == 1) {
		cout << "��ѧ���Ļ�����Ϣ��" << endl;
		cout << "ѧ��ѧ�ţ�      ������    �༶��      �Ա�   ���䣺   רҵ��" << endl;
			//pankong
			if (array[i]->s_id != 0) {
				cout << array[i]->s_id << "    "
					<< array[i]->s_name << "      ";
				if (array[i]->s_id / 1000 % 100000 == 11701) {
					cout << "���" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				else if (array[i]->s_id / 1000 % 100000 == 11602) {
					cout << "�ƿ�" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "    ";
				}
				cout << array[i]->s_sex << "       "
					<< array[i]->s_age << "        "
					<< array[i]->s_profession << endl;
			}
		
		cout << endl;
		cout << "��ѧ���ĳɼ���Ϣ��" << endl;
		//�������ѧ��
			if (array[i]->s_id != 0 && array[i]->s_id / 1000 % 100000 == 11701) {
				cout << "ѧ��ѧ�ţ�       ������   �ߵ���ѧ��  ��ѧӢ�     ���ݽṹ���㷨��     �ܼ��㣺 " << endl;
				cout << array[i]->s_id << "     "
					<< array[i]->s_name << "     "
					<< array[i]->a_math << "          "
					<< array[i]->a_english << "            "
					<< array[i]->b_dsa << "                  "
					<< setprecision(3) << array[i]->g_grade << endl;
			}
		cout << endl;
		//�������ѧ�뼼��ѧ��
			if (array[i]->s_id != 0 && array[i]->s_id / 1000 % 100000 == 11602) {
				cout << "ѧ��ѧ�ţ�       ������   �ߵ���ѧ��  ��ѧӢ�     java������ƣ�      �ܼ��㣺 " << endl;
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
		cout << "������Ҫ��ѯ����Ϣ��" << endl;
	head3:
		cout << "��������1���༶��2���Ա�3�����䡪4��רҵ��5��" << endl;
		cin >> choice2;

		if (choice2 == 1) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ��������Ϊ��" << array[i]->s_name << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ���İ༶Ϊ��" << array[i]->s_klass <<"��" << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ�����Ա�Ϊ��" << array[i]->s_sex << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 4) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ��������Ϊ��" << array[i]->s_age << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 5) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ����רҵΪ��" << array[i]->s_profession << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "����ʧ�ܣ����������룡" << endl;
			goto head3;
		}
	}
	else if (choice1 == 3) {
		cout << "������Ҫ��ѯ����Ϣ��" << endl;
	head4:
		cout << "���ߵ���ѧ��1����ѧӢ�2��רҵ��Ŀ��3���ܼ��㡪4��" << endl;
		cin >> choice2;

		if (choice2 == 1) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ���ĸ�������Ϊ��" << array[i]->a_math << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 2) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ���Ĵ�Ӣ����Ϊ��" << array[i]->a_english << endl;
			system("pause");
			system("cls");
		}
		else if (choice2 == 3) {
			cout << "���ҳɹ���" << endl;
			if (array[i]->s_id / 1000 % 100000 == 11701) {
				cout << "��ѧ�������ݽṹ���㷨����Ϊ��" << array[i]->b_dsa << endl;
			}
			else if (array[i]->s_id / 1000 % 100000 == 11602) {
				cout << "��ѧ����java������Ƽ���Ϊ��" << array[i]->b_java << endl;
			}
			system("pause");
			system("cls");
		}
		else if (choice2 == 4) {
			cout << "���ҳɹ���" << endl;
			cout << "��ѧ�����ܼ���Ϊ��" << array[i]->g_grade << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "����ʧ�ܣ����������룡" << endl;
			goto head4;
		}
	}
	else {
		cout << "����ʧ�ܣ��˳��ù��ܣ�";
		system("pause");
		system("cls");
	}

}


//6������ѧ���ɼ�(�ܼ��� or ���Ƴɼ�)
void Student::sortStudent(int num) {
	/*Btree b;
	b.CreateBtree(array[big]->s_id);*/

	int choice;

	cout << "ѡ����Ҫ����Ķ���" << endl;
	head:
	cout << "���ܼ��㡪��1  ||  �ߵ���ѧ����2  ||  ��ѧӢ���3��"<<endl;
	cin >> choice;

	if (choice == 1) {
		for (int i = 0; i < num; i++) {
			array[i]->f_grade = array[i]->g_grade;     //����
			array[i]->f_id = array[i]->s_id;      //ѧ��
			array[i]->f_name = array[i]->s_name;     //����
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

		cout << "�ɼ��Ӵ�С����Ϊ��" << endl;
		for (int i = 0; i < num; i++) {
			cout << "������" << array[i]->s_name << "      "
				<< "ѧ�ţ�" << array[i]->s_id << "     "
				<< "�ܼ���Ϊ��" << array[i]->g_grade << endl;
		}

		for (int i = 0; i < num; i++) {
			array[i]->g_grade = array[i]->f_grade;
			array[i]->s_id = array[i]->f_id;
			array[i]->s_name = array[i]->f_name;
		}
	}
	else if (choice == 2) {
		for (int i = 0; i < num; i++) {
			array[i]->f_math = array[i]->a_math;     //����
			array[i]->f_id = array[i]->s_id;      //ѧ��
			array[i]->f_name = array[i]->s_name;     //����
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

		cout << "�ɼ��Ӵ�С����Ϊ��" << endl;
		for (int i = 0; i < num; i++) {
			cout << "������" << array[i]->s_name << "      "
				<< "ѧ�ţ�" << array[i]->s_id << "     "
				<< "��������Ϊ��" << array[i]->a_math << endl;
		}

		for (int i = 0; i < num; i++) {
			array[i]->a_math = array[i]->f_math;
			array[i]->s_id = array[i]->f_id;
			array[i]->s_name = array[i]->f_name;
		}
	}
	else if (choice == 3) {
		for (int i = 0; i < num; i++) {
			array[i]->f_english = array[i]->a_english;     //����
			array[i]->f_id = array[i]->s_id;      //ѧ��
			array[i]->f_name = array[i]->s_name;     //����
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

		cout << "�ɼ��Ӵ�С����Ϊ��" << endl;
		for (int i = 0; i < num; i++) {
			cout << "������" << array[i]->s_name << "      "
				<< "ѧ�ţ�" << array[i]->s_id << "     "
				<< "��Ӣ����Ϊ��" << array[i]->a_english << endl;
		}

		for (int i = 0; i < num; i++) {
			array[i]->a_english = array[i]->f_english;
			array[i]->s_id = array[i]->f_id;
			array[i]->s_name = array[i]->f_name;
		}
	}
	else {
		cout << "����������������룡" << endl;
		goto head;
	}

	system("pause");
	system("cls");
}


//7����ȡTXT�ļ�
int Student::readtxt(int num){
	array[max] = new Student[max];
	ifstream infile("E:\\רҵ����\\c++��Ŀ�ļ�\\��һ���£�\\SIMϵͳ\\SIMϵͳ\\ѧ����Ϣ.txt", ios::in );
	if (!infile.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}
	/*int i = 1;
	string line;
	while (getline(infile, line)) {
		cout << "��" << i << "�����ݣ�  "<<endl;
		cout << line<<endl;
		i++;
	}*/
	//string arr1[big][big];
	//int arr2[big][big];
	//double arr3[big][big];
	//long long arr4[big][big];

	//long long id;   //ѧ��
	//string name;   //����
	//int klass;    //�༶
	//string sex;   //�Ա�
	//int age;   //����
	//string profession;   //רҵ

	////�ɼ���Ϣ
	//double math;   //�ߵ���ѧ
	//double english;   //��ѧӢ��
	//double dsa;   //���ݽṹ���㷨
	//double java;   //java�������
	//double grade;  //�ܼ���
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
	//cout << "��ȡ�ɹ���" << endl;
	//cout << "ѧ������Ϣ��" << endl;
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


//8��д��TXT�ļ�
void Student::writetxt(int num) {
	
	ofstream outfile("E:\\רҵ����\\c++��Ŀ�ļ�\\��һ���£�\\SIMϵͳ\\SIMϵͳ\\ѧ����Ϣ.txt", ios::in | ios::out | ios::binary);
	if (!outfile.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(1);
	}
	for (int i = 0; i < num; i++) {

		outfile << array[i]->s_id << "   " << array[i]->s_name << "   ";
		
		if (array[i]->s_id / 1000 % 100000 == 11701) {
			outfile << "���" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "   ";
		}
		else if (array[i]->s_id / 1000 % 100000 == 11602) {
			outfile << "�ƿ�" << "1" << array[i]->s_id / 100000000 % 100 << array[i]->s_klass << "   ";
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

	cout << "¼��ѧ����Ϣ��ɣ�" << endl;
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


//��������������������������
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

		while (current != NULL)   //�ҵ�Ҫ����newnode�Ľڵ�ָ��
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
void Btree::Inorder(node* root)    //����������������
{
	if (root)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}


//����
//1-1��¼����Ƴɼ������㼨��
void Student::math(double math, int num) {
	while (true) {
		if (math >= 0 && math < 60) {
			array[num]->a_math = 0;
			cout << "�ÿ�Ŀ�����񣡼���Ϊ 0 " << endl << endl;
			break;
		}
		else if (math >= 60 && math <= 100) {
			array[num]->a_math = (math - 50) / 10;
			cout << "�ÿ�Ŀ���񣡼���Ϊ��"<< setprecision(3) << array[num]->a_math << endl << endl;
			break;
		}
		else {
			array[num]->a_math = 0;
			cout << "�ɼ����Ϸ�������Ϊ0 " << endl << endl;
			break;
		}
	}
}
void Student::english(double english, int num) {
	while (true) {
		if (english >= 0 && english < 60) {
			array[num]->a_english = 0;
			cout << "�ÿ�Ŀ�����񣡼���Ϊ 0 " << endl << endl;
			break;
		}
		else if (english >= 60 && english <= 100) {
			array[num]->a_english = (english - 50) / 10;
			cout << "�ÿ�Ŀ���񣡼���Ϊ��" << setprecision(3) << array[num]->a_english << endl << endl;
			break;
		}
		else {
			array[num]->a_english = 0;
			cout << "�ɼ����Ϸ�������Ϊ0 " << endl << endl;
			break;
		}
	}
}
void Student::dsa(double dsa, int num) {
	while (true) {
		if (dsa >= 0 && dsa < 60) {
			array[num]->b_dsa = 0;
			cout << "�ÿ�Ŀ�����񣡼���Ϊ 0 " << endl << endl;
			break;
		}
		else if (dsa >= 60 && dsa <= 100) {
			array[num]->b_dsa = (dsa - 50) / 10;
			cout << "�ÿ�Ŀ���񣡼���Ϊ��" << setprecision(3) << array[num]->b_dsa << endl << endl;
			break;
		}
		else {
			array[num]->a_math = 0;
			cout << "�ɼ����Ϸ�������Ϊ0 " << endl << endl;
			break;
		}
	}
}
void Student::java(double java, int num) {
	while (true) {
		if (java >= 0 && java < 60) {
			array[num]->b_java = 0;
			cout << "�ÿ�Ŀ�����񣡼���Ϊ 0 " << endl << endl;
			break;
		}
		else if (java >= 60 && java <= 100) {
			array[num]->b_java = (java - 50) / 10;
			cout << "�ÿ�Ŀ���񣡼���Ϊ��" << setprecision(3) << array[num]->b_java << endl << endl;
			break;
		}
		else {
			array[num]->b_java = 0;
			cout << "�ɼ����Ϸ�������Ϊ0 " << endl << endl;
			break;
		}
	}
}

//1-2���ƶ���Ϣ
void Student::se(int num, long long id) {
	array[num]->s_id = id;
	array[num]->s_profession = "�������";
	array[num]->s_klass = id / 100 % 10;
	cout << "ͨ��ѧ�ŵ�֪��ѧ����" << endl << endl;
	cout << "	��ѧ���Ϊ��";
	cout << id / 100000000 << endl;;
	cout << "	רҵΪ��";
	cout << array[num]->s_profession << endl;
	cout << "	�༶Ϊ��";
	cout << "���" << "1" << id / 100000000 % 100 << array[num]->s_klass << endl << endl;
}
void Student::cst(int num, long long id) {
	array[num]->s_id = id;
	array[num]->s_profession = "�������ѧ�뼼��";
	array[num]->s_klass = id / 100 % 10;
	cout << "ͨ��ѧ�ŵ�֪��ѧ����" << endl << endl;
	cout << "��ѧ���Ϊ��";
	cout << id / 100000000 << endl;;
	cout << "רҵΪ��";
	cout << array[num]->s_profession << endl;
	cout << "�༶Ϊ��";
	cout << "�ƿ�" << "1" << id / 100000000 % 100 << array[num]->s_klass << endl << endl;
}




