#include<iostream>
#include<stdio.h>
#include<fstream>
#include<time.h>
using namespace std;
unsigned short int z;

int main()
{
	//srand(time(0));
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "\n����� �������?";
		cin >> z;
		if (z == 0)
		{
			break;
		}
		else if (z == 1)
		{
			//1.���� ������������������ ����� �����, �������������� �����. �������� ��� ����� ������������������ � �������������� ����
			ofstream out;
			out.open("write.txt");
			if (!out.is_open())
			{
				cout << "Error" << endl;
			}
			else
			{
				int x[5];
				for (int i = 0; i < 5; i++)
				{
					x[i] = rand() % 20;
					out << x[i] << "\t";
				}
			}
		}
		else if (z == 2)
		{
			//2.��� ���� f, ���������� �������� �������� ������ �������. �������� � ���� g ��� ������ ����� ����� f, � � ���� h � ��� ��������. ������� ���������� ����� �����������
			ofstream write;
			write.open("f.txt");
			if (!write.is_open())
			{
				cout << "Error";
			}
			else
			{
				int a[10];
				for (int i = 0; i < 10; i++)
				{
					a[i] = rand() % 50;
					write << a[i] << "\t";
				}
			}
			write.close();
			ifstream read;
			read.open("f.txt");
			if (!read.is_open())
			{
				cout << "Error";
			}
			else
			{
				while (!read.eof())
				{
					ofstream chet;
					chet.open("g.txt");
					ofstream nchet;
					nchet.open("h.txt");
					int a[10];
					for (int i = 0;i<10; i++)
					{
						read >> a[i];
						if (a[i] % 2 == 0)
							chet << a[i] << "\t";
						else if (a[i] % 2 != 0)
							nchet << a[i] << "\t";
					}
					chet.close();
					nchet.close();
				}
				cout << "� ���� g �������� ��� ������ ����� ����� f, � � ���� h � ��� ��������" << endl;
			}
			read.close();
		}
		else if (z == 3)
		{
			//3.	��� ���������� ���� f. �������� � ���� g ���������� ����� f � �������� �������
			ifstream read;
			read.open("f2.txt");
			if (!read.is_open())
			{
				cout << "error";
			}
			else
			{
				ofstream write;
				write.open("g2.txt");
				char s[20];
				int i = 0;
				int count = 0;
				while (!read.eof())
				{
					read >> s[i];
					i++;
					count++;
				}
				for (int i = count - 2; i >= 0; i--)
				{
					write << s[i];
				}
				write.close();
			}
			read.close();
		}
		else if (z == 4)
		{
			/*4.��� ���� f, ���������� �������� �������� ������ �������.������� �� ��������� ����� �� ����� ����.���� f �������� ������� �� ������������� �����, ������� � �������������.��������� ��������������� ���� h, ���������� ���������� ����� f � ���� g ���, ����� � ����� g :
			a.�� ���� ���� �������� ����� � ����� ������
				b.������� ��� �������������, ����� ������������� �����
				c.����� ��� � ��������� ������� : ��� ��������������, ��� �������������, ��� �������������, ��� ������������� � �.�. (��������������, ��� ����� ��������� � ����� f ������� �� 4)*/
			ifstream in;
			in.open("f4.txt");
			ofstream out;
			out.open("g4.txt");
			int mas[20];
			int count = 0;
			while(!in.eof())
			{
				in >> mas[count];
				count++;
			}
			for (int i = 0; i < count/2; i++)
			{
				if (mas[i] > 0)
					out << mas[i] << " ";
			}
			for (int i = count/2; i < count; i++)
			{
				if (mas[i] < 0)
					out << mas[i] << " ";
			}

			in.close();

		}

	}
	system("pause");
	return 0;
}
