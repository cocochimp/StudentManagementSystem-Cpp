#include<iostream>
using namespace std;
#include "Student.h"

int main() {
	Student s;

	int choice = 0;
	int num = 0;

	while (true)
	{
		//չʾ�˵�
		s.showMenu();
		cout << "ѡ��������Ĺ���(�������):" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			s.exitSystem();
			break;
		case 1: //���ѧ��
			num=s.addStudent(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 2: //��ʾѧ��
			s.showStudent(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 3: //ɾ��ѧ��
			num=s.deleteStudent(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 4: //�޸�ѧ��
			s.modifyStudent(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 5: //����ѧ��
			s.findStudent(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 6: //����ɼ�
			s.sortStudent(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 7: //��ȡTXT�ļ�
			num=s.readtxt(num);
			cout << endl;
			cout << "����ѧ������Ϊ��" << num << endl << endl;
			break;
		case 8: //д��TXT�ļ�
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