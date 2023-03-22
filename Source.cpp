#include <string>
#include <iostream>
using namespace std;

bool IsKPeriodic(const std::string& str, int n, int K)
{
	system("chcp 1251");
	bool ret{ false };
	bool notRepeat{ false }; //��������� �� �����������
	int count{ 0 }; //������� ��������

	//����� �������� ����������� ���������� �������� ��� �������� ��������
	int shift{ 2 }; //���������� �������� � ���������

	string sample; //��������� ��� ������ ��������

	//����� �������� ��� ������� �������
	while (shift <= str.length() - shift)
	{
		sample = str.substr(0, shift);
		if (str.substr(shift, shift) != sample) // ���� �� ���������, ��������� ���� ������� ��� ���������
		{
			shift++;
		}
		else //���� ���������, �� ������� ���������� ����������
		{
			for (int j = 0; j * shift <= str.length() - shift; j++)
			{
				if (str.substr(shift * j, shift) == sample)
				{
					count = j + 1;
				}
				else
				{
					notRepeat = true; // �� �����������
					count = 0;
					shift *= j; //��� ����������� ���������
					shift++; // ��������� � ��� ����������� ��������� ��� ���� ������
					break;
				}
			}
			if (!notRepeat)
				break;
			notRepeat = false;
		}
	};
	if (shift * count != str.length())
		notRepeat = true;

	//����� �����������
	if (notRepeat)
	{
		std::cout << "��������� �� ����������� ���������" << std::endl;
	}
	else
	{
		std::cout << "��������� : " << "'" << str.substr(0, shift) << "'" << std::endl;
		std::cout << "����� ���������, [��������] = " << shift << std::endl;
		std::cout << "�����������, [���] = " << count << std::endl;


		if (!(K % shift) && !(str.length() % K))
		{
			ret = 1;
		}
	}
	return ret; //������� ��������� (=1 - ������ ������ K)
}

int main()
{
	string str = "������, � ���� ��� �� ������ ������, � ���� ��� �� ������ ������, � ���� ��� �� ������ ";
	int tmp_int = IsKPeriodic(str, str.length(), 30);
	std::cout << endl;
	std::cout << tmp_int;

	return 0;
}