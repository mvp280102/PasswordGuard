#include "core-func.h"


/*
 * Функции, выполняющие шифрование и дешифрование:
 * Pi - текущий символ исходной фразы
 * Ci - текущий символ зашифрованной фразы
 * K  - ключ (число - шифр Цезаря / кодовое слово - шифр Виженера, шифрование гаммированием, шифр Вернама)
 * Kj - текущий символ ключа (шифра Виженера, шифрование гаммированием, шифр Вернама)
 * N  - мощность алфавита (количество символов в алфавите)
 */


// Выполняет шифрование методом Цезаря по формуле Ci = (Pi + (K mod N)) mod N:
string encrypt_caesar(string raw, int key)
{
	string res = raw;								// результирующая строка

	for (unsigned int i = 0; i < raw.length(); i++)
		if (isalpha(raw.at(i)))
			if (isupper(raw.at(i)))
				res.at(i) = ((raw.at(i) - 'A') + (key % letters_pow)) % letters_pow;
			else
				res.at(i) = ((raw.at(i) - 'a') + (key % letters_pow)) % letters_pow;
		else if (isdigit(raw.at(i)))
			res.at(i) = ((raw.at(i) - '0') + (key % numbers_pow)) % numbers_pow;
		else
			res.at(i) = raw.at(i);

	return res;
}

// Выполняет дешифрование методом Цезаря по формуле Pi = (Ci - (K mod N) + N) mod N:
string decrypt_caesar(string raw, int key)
{
	string res = raw;								// результирующая строка

	for (unsigned int i = 0; i < raw.length(); i++)
		if (isalpha(raw.at(i)))
			if (isupper(raw.at(i)))
				res.at(i) = ((raw.at(i) - 'A') - (key % letters_pow) + letters_pow) % letters_pow;
			else
				res.at(i) = ((raw.at(i) - 'a') - (key % letters_pow) + letters_pow) % letters_pow;
		else if (isdigit(raw.at(i)))
			res.at(i) = ((raw.at(i) - '0') - (key % numbers_pow) + numbers_pow) % numbers_pow;
		else
			res.at(i) = raw.at(i);

	return res;
}

// Выполняет шифрование методом Виженера по формуле Ci = (Pi + Kj) mod N:
string encrypt_vigenere(string raw, string key)
{
	string res = raw;								// результирующая строка

	for (unsigned int i = 0, l = 0; i < raw.length(); i++)
	{
		if (isalpha(raw.at(i)))
			if (isupper(raw.at(i)))
			{
				key.at(l) = toupper(key.at(l));
				res.at(i) = ((raw.at(i) - 'A') + (key.at(l) - 'A')) % letters_pow;
			}
			else
			{
				key.at(l) = tolower(key.at(l));
				res.at(i) = ((raw.at(i) - 'a') + (key.at(l) - 'a')) % letters_pow;
			}
		else
			res.at(i) = raw.at(i);

		if (l++ == (key.length() - 1))
			l = 0;
	}

	return res;
}

// Выполняет дешифрование методом Виженера по формуле Pi = (Ci + N - Kj) mod N:
string decrypt_vigenere(string raw, string key)
{
	string res = raw;								// результирующая строка

	for (unsigned int i = 0, l = 0; i < raw.length(); i++)
	{
		if (isalpha(raw.at(i)))
			if (isupper(raw.at(i)))
			{
				key.at(l) = toupper(key.at(l));
				res.at(i) = ((raw.at(i) - 'A') + letters_pow - (key.at(l) - 'A')) % letters_pow;
			}
			else
			{
				key.at(l) = tolower(key.at(l));
				res.at(i) = ((raw.at(i) - 'a') + letters_pow - (key.at(l) - 'a')) % letters_pow;
			}
		else
			res.at(i) = raw.at(i);

		if (l++ == (key.length() - 1))
			l = 0;
	}

	return res;
}

// Выполняет шифрование методом гаммирования по формуле Ci = (Pi + Kj) mod N:
string encrypt_gamming(string raw, int key)
{
	string res = raw,						// результирующая строка
	keyword = raw;							// ключ шифрования

	srand(key);

	for (unsigned int i = 0; i < raw.length(); i++)
	{
		keyword.at(i) = (rand() % 26) + 65;

		if (isalpha(raw.at(i)))
			if (isupper(raw.at(i)))
				res.at(i) = ((raw.at(i) - 'A') + (keyword.at(i) - 'A')) % letters_pow;
			else
				res.at(i) = ((raw.at(i) - 'a') + (keyword.at(i) - 'a')) % letters_pow;
		else
			res.at(i) = raw.at(i);
	}

	return res;
}

// Выполняет дешифрование методом гаммирования по формуле Pi = (Ci + N - Kj) mod N:
string decrypt_gamming(string raw, int key)
{
	string res = raw,						// результирующая строка
	keyword = raw;							// ключ шифрования

	srand(key);

	for (unsigned int i = 0; i < raw.length(); i++)
	{
		keyword.at(i) = (rand() % 26) + 65;

		if (isalpha(raw.at(i)))
			if (isupper(raw.at(i)))
				res.at(i) = ((raw.at(i) - 'A') + letters_pow - (keyword.at(i) - 'A')) % letters_pow;
			else
				res.at(i) = ((raw.at(i) - 'a') + letters_pow - (keyword.at(i) - 'a')) % letters_pow;
		else
			res.at(i) = raw.at(i);
	}

	return res;
}

// Выполняет шифрование и дешифрование методом Вернама по формуле P/Ci = C/Pi XOR Kj.
string encrypt_decrypt_vernam(string raw, int key)
{
	string res = raw,						// результирующая строка
	keyword = raw;							// ключ шифрования

	srand(key);

	for (unsigned int i = 0; i < raw.length(); i++)
	{
		keyword.at(i) = (rand() % 26) + 65;

		raw.at(i) = toupper(raw.at(i));
		res.at(i) = (unsigned int)raw.at(i)^(unsigned int)keyword.at(i);
	}

	return res;
}