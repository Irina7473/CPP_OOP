#include "Header.h"

	class Student
	{
		char* name;

	public:

		explicit Student(const char* name) : name{ new char[strlen(name) + 1] }   //������ ������� ����� ������������ � 1 ���������� - explicit  
			//2 ���������, ���� �� ������� �� ��������� - ���� �����
		{
			strcpy_s(this->name, strlen(name) + 1, name);

		}
		explicit Student(Student&& other)  //����������� ����������� (�������� ��� ����, � ������ ��������).   && - ��� ������ �� �������������� ��������
		{
			name = other.name;
			other.name = nullptr;

		}

		~Student()
		{
			delete[] name;
		}

		Student(const Student& other) :Student(other.name) //����� ���� ������� ������ ����� ������
		{
		}

		Student& operator=(const Student& other) // ����� ��� ����������, ������ ���� ���� ���������
		{
			if (this != &other)  //�������� �� ������������ ������ ����
			{
				delete[]name;
				name = new char[strlen(other.name) + 1];
				strcpy_s(name, strlen(other.name) + 1, other.name);
			}
			return *this;  //������� ������ �� ������ ��� ������������� ������������
		}

		bool operator< (const Student& right) const
		{
			return strcmp(name, right.name) < 0;
		}

		bool operator== (const Student& other) const // �������� 1, �� ������ ���� this const � ������ ������� �����������, ��� �� ������ �� ������
		{
			return strcmp(name, other.name) == 0;
		}

		friend bool operator!= (const Student& left, const Student& right);  //������������� �������, �� �� ����� ������
		
		const char* getName() 
		{
			name = 0; //���� �������� ���
			return name;
		}

		const char* getName() const  //�������� ����������� � ������������� ������ const �����, � const  �� - ��� ��� ������� ��������
		{ 
			name[0] = 'a'; //�� ���� �������� ���, ���� �������� ��������� �������
			return name; 
		}

	};


	//�� �������� ������� �������� - ��� ���������� �������. �� 2 ���������
	// ��� ������� ������� � �����

	bool operator!= (const Student& left, const Student& right)  //�� � ������� ������ ������
	{
		return strcmp(left.getName(), right.getName()) != 0;
	}

	std::ostream& operator<<(std::ostream& os, const Student& student) //������ ������� ����
	{
		os << student.getName();
		return os;
	}

	std::istream& operator<<(std::istream& is, Student& student) 
	{
		char buffer[200];
		is >> buffer;
		//���-��������
		return is;
	}


	class Group 
	{
		Student** students;
		int capaciti = 10;
		int count = 0;

	public:
		//Group() = default; //������� ���������� �� ���������
		//Group() = delete;  // ������� ����������� ��� ����������, ����� ����� �� ���� ��������� �����, ������ ������


		Group()
		{
			students = new Student * [capaciti];
			for (int i = 0; i < capaciti; i++)
				students[i] = nullptr;
			
		}

		~Group()
		{
			for (int i = 0; i < capaciti; i++)
				delete students[i];   // ����� ����������� ��������� ��������
			delete[] students;
		}

		friend Student; //�������� ������� �������������, �� ������ � �������� ����� �������� �� ����� �������.
		//��� 2���� ���� � ����� ������� ���������

		void creatStudent(const char* name)
		{
			Student* stud = new Student(name);
			addStudents(stud);

		}


//	private:
		void addStudents(Student* stud)
		{
			students[count] = stud;
			count++;
		}



	};



	void f(Student s)
	{

	}


	int main()
	{
		using namespace std;
		
		/*
		Student* stud = new Student();
		Group group;
		group.addStudents(stud);
		// ����� ��������� �� �������, �.�. �� ������ � ������

		Student stud2 ("Ira");
		Group group;
		group.addStudents(&stud2);
		//����� deete �� �����. �� ����� ������ ����� ������ ��� ������ new
		
		group.creatStudent("valya");
		Student vova = "Vova";   //������� ����� ������������ � 1 ���������� ���� � ������� ��������. ��� ����� ��������� - explicit
		

		Student stud("Petya");
		cout << stud->getName();

		const Student stud("Vasya");
		cout << stud->getName();
			

		Student s1("1"), s2("2");
		s1 == s2;

		const Student stud("Petya");
		cout << stud << stud2<< 1;

		ofstream file("out.txt");  // ofstream  ��������� ostream  ������ � ����
		file << stud << stud2;
		*/


		Student students[] = { Student("Alex"),Student("Yana"),Student("Danil"), Student("Boris") };

		sort(students, students + 4);
		for (int i = 0; i < 4; i++)
			cout << students[i] << ' ';

		Student a("a");
		Student b("b");
		Student c("c");
		a = b = c;

		f(a);
		f(Student("Temp"));  //��������� ������ ����� ����� ��������� ����� ������ �������
		Student d = move(a);  //��� ������� ���� ���������� �������������� ������, ������������ ��� ����������� �������


		Group g1;
		Group g2;
		g2 = g1; //���� ����� �����, �� �� ����� ��� ��������


	}