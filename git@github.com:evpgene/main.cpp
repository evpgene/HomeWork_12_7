#include <string>
#include <iostream>
using namespace std;

bool IsKPeriodic(const std::string& str, int n, int K)
{
	system("chcp 1251");
	bool ret{ false };
	bool notRepeat{ false }; //подстрока не повторяется
	int count{ 0 }; //счётчик повторов

	//задаём исходное минимальное количество символов для проверки повторов
	int shift{ 2 }; //количество символов в подстроке

	string sample; //подстрока для поиска повторов

	//поиск смещения для первого повтора
	while (shift <= str.length() - shift)
	{
		sample = str.substr(0, shift);
		if (str.substr(shift, shift) != sample) // если не совпадают, добавляем одну позицию для сравнения
		{
			shift++;
		}
		else //если совпадают, то считаем количество повторений
		{
			for (int j = 0; j * shift <= str.length() - shift; j++)
			{
				if (str.substr(shift * j, shift) == sample)
				{
					count = j + 1;
				}
				else
				{
					notRepeat = true; // не повторяется
					count = 0;
					shift *= j; //уже проверенная подстрока
					shift++; // добавляем к уже проверенной подстроке ещё один символ
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

	//вывод результатов
	if (notRepeat)
	{
		std::cout << "подстрока не повторяется полностью" << std::endl;
	}
	else
	{
		std::cout << "подстрока : " << "'" << str.substr(0, shift) << "'" << std::endl;
		std::cout << "имеет кратность, [символов] = " << shift << std::endl;
		std::cout << "повторяется, [раз] = " << count << std::endl;


		if (!(K % shift) && !(str.length() % K))
		{
			ret = 1;
		}
	}
	return ret; //возврат кратности (=1 - строка кратна K)
}

int main()
{
	string str = "привет, я ваша тётя из Москвы привет, я ваша тётя из Москвы привет, я ваша тётя из Москвы ";
	int tmp_int = IsKPeriodic(str, str.length(), 30);
	std::cout << endl;
	std::cout << tmp_int;

	return 0;
}
