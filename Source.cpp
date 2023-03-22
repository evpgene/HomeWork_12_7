#include <string>
#include <iostream>
using namespace std;

bool IsKPeriodic(const std::string& str, int n, int K)
{
	system("chcp 1251");
	bool ret{ false };
	bool notRepeat{ false }; //подстрока не повтор€етс€
	int count{ 0 }; //счЄтчик повторов

	//задаЄм исходное минимальное количество символов дл€ проверки повторов
	int shift{ 2 }; //количество символов в подстроке

	string sample; //подстрока дл€ поиска повторов

	//поиск смещени€ дл€ первого повтора
	while (shift <= str.length() - shift)
	{
		sample = str.substr(0, shift);
		if (str.substr(shift, shift) != sample) // если не совпадают, добавл€ем одну позицию дл€ сравнени€
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
					notRepeat = true; // не повтор€етс€
					count = 0;
					shift *= j; //уже проверенна€ подстрока
					shift++; // добавл€ем к уже проверенной подстроке ещЄ один символ
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
		std::cout << "подстрока не повтор€етс€ полностью" << std::endl;
	}
	else
	{
		std::cout << "подстрока : " << "'" << str.substr(0, shift) << "'" << std::endl;
		std::cout << "имеет кратность, [символов] = " << shift << std::endl;
		std::cout << "повтор€етс€, [раз] = " << count << std::endl;


		if (!(K % shift) && !(str.length() % K))
		{
			ret = 1;
		}
	}
	return ret; //возврат кратности (=1 - строка кратна K)
}

int main()
{
	string str = "привет, € ваша тЄт€ из ћосквы привет, € ваша тЄт€ из ћосквы привет, € ваша тЄт€ из ћосквы ";
	int tmp_int = IsKPeriodic(str, str.length(), 30);
	std::cout << endl;
	std::cout << tmp_int;

	return 0;
}