#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//��������� � ������� � ��������
struct Student
{
	int id; //����� �� �������
	string surname; //�������
	string name; //���
	string patronymic; //��������
	int Record_Book_Number; //����� �������
	int grades[5]; //������ �� �������
};

//������� ���������� ��������� �� ����� ������� txt
//��������� �� ���� ��� ����� txt
//���������� ������ ��������� ��������� 
vector<Student> Read_Students_From_File(const string& filename)
{
	ifstream file(filename);
	vector<Student> students;

	while (!file.eof())
	{
		Student student;
		file >> student.id;
		file >> student.surname;
		file >> student.name;
		file >> student.patronymic;
		file >> student.Record_Book_Number;

		for (int i = 0; i < 5; ++i)
			file >> student.grades[i];


		students.push_back(student);
	}

	return students;
}

//������� ������ �� ����� ������� ���������
//��������� �� ���� ������ ���������
void Print_Students(const vector<Student>& students)
{
	for (const auto& student : students)
	{
		cout << "ID: " << student.id << "\n";
		cout << "�������: " << student.surname << "\n";
		cout << "���: " << student.name << "\n";
		cout << "��������: " << student.patronymic << "\n";
		cout << "����� �������� ������: " << student.Record_Book_Number << "\n";
		cout << "������: ";

		for (int i = 0; i < 5; ++i)
			cout << student.grades[i] << " ";


		cout << "\n\n";
	}
}
//������� ���������� ������� ��������� �� �������
//��������� �� ���� ������ ���������
void Sort_Students_By_Surname(vector<Student>& students)
{
	for (int i = 0; i < students.size(); ++i)
		for (int j = i + 1; j < students.size(); ++j)
			if (students[i].surname > students[j].surname)
				swap(students[i], students[j]);



}
//������� ���������� ������� ��������� �� �����
//��������� �� ���� ������ ���������
void Sort_Students_By_Name(vector<Student>& students)
{
	for (int i = 0; i < students.size(); ++i)
		for (int j = i + 1; j < students.size(); ++j)
			if (students[i].name > students[j].name)
				swap(students[i], students[j]);



}
//������� ���������� ������� ��������� �� ��������
//��������� �� ���� ������ ���������
void Sort_Students_By_Patronymic(vector<Student>& students)
{
	for (int i = 0; i < students.size(); ++i)
		for (int j = i + 1; j < students.size(); ++j)
			if (students[i].patronymic > students[j].patronymic)
				swap(students[i], students[j]);

}

//������� ���������� ������� ��������� �� ������� �� �������
//��������� �� ���� ������ ���������, ����� ��������
void Sort_Students_By_Grade(vector<Student>& students, int subject_Index)
{
	for (int i = 0; i < students.size(); ++i)
		for (int j = i + 1; j < students.size(); ++j)
			if (students[i].grades[subject_Index] < students[j].grades[subject_Index])
				swap(students[i], students[j]);



}
//������� ���������� ������� ��������� �� �������� ����� ��������
//��������� �� ���� ������ ���������
void Sort_Students_By_Average_Grade(vector<Student>& students)
{
	for (int i = 0; i < students.size(); ++i)
		for (int j = i + 1; j < students.size(); ++j)
		{
			float Average_Grade_I = 0;
			float Average_Grade_J = 0;

			for (int k = 0; k < 5; ++k)
			{
				Average_Grade_I += students[i].grades[k];
				Average_Grade_J += students[j].grades[k];
			}

			Average_Grade_I /= 5;
			Average_Grade_J /= 5;

			if (Average_Grade_I < Average_Grade_J)
				swap(students[i], students[j]);
		}

}
//������� ������ ������� ��������� �� �������
//��������� �� ���� ������ ���������, ������� ��������
//���� ���������� ��������� ���������� � ����� ������
vector<Student> Find_Students_By_Surname(const vector<Student>& students, const string& surname)
{
	vector<Student> Found_Students;

	for (const auto& student : students)
		if (student.surname == surname)
			Found_Students.push_back(student);



	return Found_Students;
}
//������� ������ ������� ��������� �� ���
//��������� �� ���� ������ ���������, ��� ��������
//���� ���������� ��������� ���������� � ����� ������
vector<Student> Find_Students_By_FullName(const vector<Student>& students, const string& surname, const string& name, const string& patronymic)
{
	vector<Student> Found_Students;

	for (const auto& student : students)
		if (student.surname == surname && student.name == name && student.patronymic == patronymic)
			Found_Students.push_back(student);



	return Found_Students;
}
//������� ������ ������� ��������� �� ������ �������
//��������� �� ���� ������ ���������, ����� �������
//���� ���������� ��������� ���������� � ����� ������
vector<Student> Find_Students_By_Record_Book_Number(const vector<Student>& students, int Record_Book_Number)
{
	vector<Student> Found_Students;

	for (const auto& student : students)
		if (student.Record_Book_Number == Record_Book_Number)
			Found_Students.push_back(student);



	return Found_Students;
}


int main()
{
	system("chcp 1251");

	vector<Student> students = Read_Students_From_File("students.txt");

	// ����� ���������� � ��������� �� �����
	Print_Students(students);

	int command;
	cout << "\n\n";
	cout << "������� ��� ����������:\n0)�����\n1)���������� �� �������\n2)���������� �� �����\n3)���������� �� ��������\n4)���������� �� ������\n5)���������� �� �������� ����� ��������\n";
	cin >> command;

	switch (command)
	{
	case 0:
		system("pause");
		return 0;
		break;
	case 1:
		// ���������� �� �������
		Sort_Students_By_Surname(students);
		Print_Students(students);
		break;
	case 2:
		// ���������� �� �����
		Sort_Students_By_Name(students);
		Print_Students(students);
		break;
	case 3:
		// ���������� �� �����
		Sort_Students_By_Patronymic(students);
		Print_Students(students);
		break;
	case 4:
		int id_grade;
		cout << "������� ��� ����������:\n0)�����������\n1)���������\n2)���.������\n3)���������� ����������\n4)��.��.\n";
		cin >> id_grade;
		// ���������� �� ������
		Sort_Students_By_Grade(students, id_grade);
		Print_Students(students);
		break;
	case 5:
		// ���������� �� �������� ����� �������� 
		Sort_Students_By_Average_Grade(students);
		Print_Students(students);
		break;
	}

	int command1 = 0;
	cout << "\n\n";
	cout << "������� ��� ����������:\n0)�����\n1)����� �� �������\n2)����� �� �������\n";
	cin >> command1;

	switch (command1)
	{
	case 0:
		system("pause");
		return 0;
		break;
	case 1:
	{
		string surname;
		getline(cin, surname);
	
		vector<Student> Found_Students = Find_Students_By_Surname(students, surname);
	
		if (Found_Students.empty())
			cout << "������: ������� � �������� " << surname << " �� ������.\n";
		else
			Print_Students(Found_Students);
		
		break;
	}
	case 2:
	{
		int Record_Book_Number_To_Find;
		cin >> Record_Book_Number_To_Find;

		vector<Student> Found_Students = Find_Students_By_Record_Book_Number(students, Record_Book_Number_To_Find);

	
		if (Found_Students.empty())
			cout << "������: ������� � ������� �������� ������ " << Record_Book_Number_To_Find << " �� ������.\n";
		else
			Print_Students(Found_Students);
	
		break;
	}
	}

	system("pause");
	return 0;
}
