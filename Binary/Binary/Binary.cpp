#pragma once
#include "Binary.h"

//����������� �� ���������
Binary::Binary() : Size(10), Binnum(new int[10]{})
{
	for (int i = 0; i < Size; i++) Binnum[i] = 0;
	cout << "DefaultConstructor:\t" << this << endl;
}

//����������� �� ��������
Binary:: Binary(int size, const int binnum[]) : 
	Size (size), Binnum ( new int[Size] {} )
{
	for (int i = 0; i < Size; i++) 
		Binnum[i] = binnum[i];
	cout << "SignConstructor:\t" << this << endl;
}

//����������� �����������
Binary:: Binary(const Binary& other) 
{
	if (this != &other)
	{
		Size = other.Size;
		Binnum = new int[Size] {};
		for (int i = 0; i < Size; i++)
			Binnum[i] = other.Binnum[i];
	}
	cout << "CopyConstructor:\t" << this << endl;
}

//����������� �����������
Binary::Binary(Binary&& other) : Size(other.Size), Binnum(other.Binnum)
{
	other.Binnum = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}

//����������� �������������� �� ����������� �����
Binary::Binary(int decnum)
{
	int Temp[100] = {};
	int i = 0;
	do
	{
		Temp[i]=decnum % 2;
		decnum = decnum / 2;
		i++;
	} 
	while (decnum!=0);
	Size = i;
	Binnum = new int[Size] {};
	for (int i = Size-1; i >=0; i--)
		Binnum[i] = Temp[Size-i-1];
	cout << "Decimalnumber Constructor:\t" << this << endl;
}

Binary::~Binary()  //����������
{
	delete[] Binnum;
	cout << "Destructor:\t" << this << endl;
}

void Binary::print() const
{
	cout << "Size: " << Size << "\t" << "Binnum: ";
	for (int i = 0; i < Size; i++)
		cout << Binnum [i];
	cout << "   "<< this << endl;
}

//�������������� ��������� ����� � ����������
int Binary::decconversion() const
{
	int Summa = 0;
	for (int i = 0; i < Size; i++)
		Summa+=Binnum[i] * pow(2, Size - i - 1);
	return Summa;
}

// �������������� � ����������� ������� - ���������� 0 �����
void Binary::sizeadding(int size)
{
	if (size > this->Size)
	{
		int s = size - Size;
		Binary temp;
		temp.Size = size;
		temp.Binnum = new int[size] {};
		for (int i = s; i < size; i++)
			temp.Binnum[i] = this->Binnum[i-s];
		*this = temp;
	}
	else if (size == this->Size) cout << *this << " - ������ �������������" << endl;
		else cout << *this << " - ������ ������ ���������" << endl;
}

// �������������� � ����������� �������
void Binary::sizereduction()
{
	int size = 1;
	for (int i = 0; i < Size; i++)
	{
		if (Binnum[i] == 1)
		{
			size = Size - i;
			break;
		}
	}
	if (size != Size)
	{
		Binary temp;
		temp.Size = size;
		temp.Binnum = new int[size] {};
		for (int i = 0; i < size; i++)
			temp.Binnum[i] = this->Binnum[i+Size-size];
		*this = temp;
	}
}

//�������� ������������ � ����������� �������
Binary& Binary::operator=(const Binary& other)
{
	if (this != &other)
	{
		delete[] Binnum;
		Size = other.Size;
		Binnum = new int[Size] {};
		for (int i = 0; i < Size; i++)
			Binnum[i] = other.Binnum[i];
	}
	return *this;
}

// �������� ������������ ������������
Binary& Binary::operator= (Binary&& other)
{
	delete Binnum;
	Size = other.Size;
	Binnum = other.Binnum;
	other.Binnum = nullptr;
	cout << "MoveAassignment:\t" << this << endl;
	return *this;
}

const int& Binary:: operator[] (const int ind)const
{ if (ind >= 0 && ind < Size) return Binnum[ind]; }

int& Binary:: operator[](int ind)
{ if (ind >= 0 && ind < Size) return Binnum[ind]; }




Binary singlesize(Binary& left, Binary& right)  // ���������� � ������ �������
{
	int size;
	if (left.getSize() >= right.getSize())
	{
		size=left.getSize();
		right.sizeadding(size);
	} 
	else
	{
		size=right.getSize();
		left.sizeadding(size);
	}
	left.print();
	right.print();
	return left, right;
}

ostream& operator<<(ostream& os, const Binary& binnum)
{
	//for (int i = 0; i < binnum.getSize(); i++)
	//	os << binnum[i];
	os <<binnum.decconversion();
	return os;
}

istream& operator>>(istream& is, Binary& obj)  //�� ����������
{
	
	return is;
}

Binary operator+(const Binary& left, const Binary& right)
{
	Binary templeft(left); //����� ������ �����
	Binary tempright(right);  //����� ������� �����
	singlesize(templeft, tempright); // ���������� � ������ �������
	// �������� ��������������� �������
	int* tempR = new int[templeft.getSize()+1]{};
	int s = 0;
	for (int i = templeft.getSize(); i >= 0; i--)
	{
		if (i != 0)
		{
			if (templeft[i - 1] == 0 && tempright[i - 1] == 0)
				if (s == 0) tempR[i] = 0;
				else { tempR[i] = 1; s = 0; }
			if (templeft[i - 1] == 0 && tempright[i - 1] == 1
				|| templeft[i - 1] == 1 && tempright[i - 1] == 0)
				if (s == 0) tempR[i] = 1;
				else tempR[i] = 0;
			if (templeft[i - 1] == 1 && tempright[i - 1] == 1)
			{
				if (s == 0) { tempR[i] = 0; s = 1; }
				else tempR[i] = 1;
			}
		}
		else tempR[i] = s;
	}
	Binary result(templeft.getSize() + 1, tempR);
	delete[] tempR;
	result.sizereduction();
	return result;
}

Binary operator-(const Binary& left, const Binary& right)
{
	Binary templeft(left); //����� ������ �����
	Binary tempright(right);  //����� ������� �����
	singlesize(templeft, tempright); // ���������� � ������ �������
	// �������� ��������������� �������
	int* tempR = new int[templeft.getSize()]{};
	int s = 0;
	for (int i = templeft.getSize() - 1; i >= 0; i--)
	{
		if (templeft[i] == 0 && tempright[i] == 0
			|| templeft[i] == 1 && tempright[i] == 1)
			if (s == 0) tempR[i] = 0;
			else tempR[i] = 1;
		if (templeft[i] == 1 && tempright[i] == 0)
			if (s == 0) tempR[i] = 1;
			else { tempR[i] = 0; s = 0; }
		if (templeft[i] == 0 && tempright[i] == 1)
		{
			if (s == 0) { tempR[i] = 1; s = 1; }
			else tempR[i] = 0;
		}
		cout << tempR[i] << endl;
	}
	Binary result(templeft.getSize(), tempR);
	delete[] tempR;
	result.sizereduction();
	return result;
}

Binary operator*(const Binary& left, const Binary& right)
{
	Binary result;
	int* tempI = new int[left.getSize() + right.getSize()] {};  //������������� ������
	int t = right.getSize(); //����� �������������� ������� 
	for (int j = right.getSize() - 1; j >= 0; j--)
	{
	//������������� ������ ��������� ���������� ������ �� ������ ������� �������
		for (int i = left.getSize()-1; i >= 0; i-- )
		{
			if (left.getBinnum()[i] == 1 && right.getBinnum()[j] == 1)
				tempI[i+t] = 1;
			else tempI[i+t] = 0;			
		}
		t--;
		Binary temp(left.getSize() + right.getSize(), tempI);
		result = result + temp;
	}
	delete[] tempI;
	result.sizereduction();
	return result;
}

Binary operator/(const Binary& left, const Binary& right)
{
	if(right> left) return 0;
	else
	{
		int* tempR = new int[left.getSize()]{};  //�������������� ������
		Binary tempL(left);  //������� �� �������������� ������� 
		Binary tempright(right); //�������� - ����� ������� �����
		int size = right.getSize(); //������ �������������� ������� - ��������
		int k = right.getSize() - 1; //������ ��������� ������ ����� 
		//��� ���������� ���� ��������� � �������������� �������-��������
		int I = 0; //������ ��������� ��������������� �������

		for (;I < left.getSize(); I++)
		{
			if (k >= left.getSize())

				break;
			int* tempI = new int[size] {};  //������������� ������ ��� �������� �������������� ��������
			for (int i = 0; i < size - 1; i++)
				tempI[i] = tempL.getBinnum()[i];
			tempI[size - 1] = left.getBinnum()[k];
			k++;
			Binary templeft(size, tempI); //������������� ��������
			templeft.print();
			delete[] tempI;
			cout << TAB;

			if (tempright > templeft)
			{
				tempR[I] = 0;
				tempL = templeft;
				size++;
				cout << "tempR[" << I << "]=" << tempR[I] << " " << size << " " << k << endl;
				continue;
			}
			else
			{
				tempR[I] = 1;
				tempL = templeft - tempright;
				size = tempL.getSize() + 1;
				cout << "tempR[" << I << "]=" << tempR[I] << " " << size << " " << k << endl;
			}
			cout << TAB;
		}
		cout << TAB;
		Binary result(I, tempR);
		result.print();
		delete[] tempR;
		result.sizereduction();
		return result;
	}
}

bool operator>(const Binary& left, const Binary& right)
{
	Binary templeft(left); //����� ������ �����
	Binary tempright(right);  //����� ������� �����
	singlesize(templeft, tempright);
	for (int i = 0; i < templeft.getSize(); i++)
	{
		if (templeft[i] > tempright[i]) return true;
		else if (templeft[i] < tempright[i]) return false;
	}
	return false;
}

Binary operator&(const Binary& left, const Binary& right)
{
	Binary templeft(left); //����� ������ �����
	Binary tempright(right);  //����� ������� �����
	singlesize(templeft, tempright); // ���������� � ������ �������
	// �������� ��������������� �������
	int* tempR = new int[templeft.getSize()] {};  
	for (int i = 0; i < templeft.getSize(); i++)
	{
		if (templeft.getBinnum()[i] == 1 && tempright.getBinnum()[i] == 1) tempR[i] = 1;
		else tempR[i] = 0;
		cout << tempR[i] << " ";
	}
	cout << endl;
	Binary result(templeft.getSize(), tempR);
	delete[] tempR;
	result.sizereduction();
	return result;
}

Binary operator|(const Binary& left, const Binary& right)
{
	Binary templeft(left); //����� ������ �����
	Binary tempright(right);  //����� ������� �����
	singlesize(templeft, tempright); // ���������� � ������ �������
	// �������� ��������������� �������
	int* tempR = new int[templeft.getSize()]{};  
	for (int i = 0; i < templeft.getSize(); i++)
	{
		if (templeft.getBinnum()[i] == 1 || tempright.getBinnum()[i] == 1) tempR[i] = 1;
		else tempR[i] = 0;
		cout << tempR[i] << " ";
	}
	cout << endl;
	Binary result(templeft.getSize(), tempR);
	delete[] tempR;
	result.sizereduction();
	return result;
}

Binary operator^(const Binary& left, const Binary& right)
{
	Binary templeft(left); //����� ������ �����
	Binary tempright(right);  //����� ������� �����
	singlesize(templeft, tempright); // ���������� � ������ �������
	// �������� ��������������� �������
	int* tempR = new int[templeft.getSize()]{};  
	for (int i = 0; i < templeft.getSize(); i++)
	{
		if (templeft.getBinnum()[i] == 1 && tempright.getBinnum()[i] == 0 
			|| templeft.getBinnum()[i] == 0 && tempright.getBinnum()[i] == 1) 
			tempR[i] = 1;
		else tempR[i] = 0;
		cout << tempR[i] << " ";
	}
	cout << endl;
	Binary result(templeft.getSize(), tempR);
	delete[] tempR;
	result.sizereduction();
	return result;
}

Binary operator~(const Binary& obj)
{
	Binary result(obj);
	for (int i = 0; i < result.getSize(); i++)
	{
		if (result.getBinnum()[i] == 1)
			result.getBinnum()[i] = 0;
		else result.getBinnum()[i] = 1;
	}
	return result;
}

