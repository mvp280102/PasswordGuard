#pragma once


#include <string>
using namespace std;


// Мощности алфавитов букв латинского алфавита и цифр:
const unsigned int numbers_pow = 10,
		letters_pow = 26;

/*
 * Функции, выполняющие шифрование и дешифрование.
 *
 * Параметры:
 * string raw     - исходная/зашифрованная строка
 * int/string key - ключ шифрования/дешифрования
 */

// Выполняет шифрование методом Цезаря.
string encrypt_caesar(string raw, int key);

// Выполняет дешифрование методом Цезаря.
string decrypt_caesar(string raw, int key);

// Выполняет шифрование методом Виженера.
string encrypt_vigenere(string raw, string key);

// Выполняет дешифрование методом Виженера.
string decrypt_vigenere(string raw, string key);

// Выполняет шифрование методом гаммирования.
string encrypt_gamming(string raw, int key);

// Выполняет дешифрование методом гаммирования.
string decrypt_gamming(string raw, int key);

// Выполняет шифрование и дешифрование методом Вернама.
string encrypt_decrypt_vernam(string raw, int key);