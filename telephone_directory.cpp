#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

vector<string> names;
vector<string> numbers;

void delete_contact()
{
  int choose;
  cout << "Список контактов указан ниже, выберите номер контакта который хотите удалить." << endl;
  for (size_t i = 1; i <= names.size(); ++i) {
    cout << i << ". Имя: " << names[i-1] << " Номер: " << numbers[i-1] << endl;
  }
  cin >> choose;

  if (choose >= 1 && choose <= names.size()) {
    auto it1 = names.begin() + choose - 1;
    auto it2 = numbers.begin() + choose - 1;
    names.erase(it1);
    numbers.erase(it2);

    cout << "Контакт успешно удалён." << endl;
  } else {
    cout << "Некорректный номер контакта." << endl;
  }
}

void show_contacts() 
{
  
  if (!numbers.empty() && !names.empty()) {
    cout << "Список контактов:" << endl;
    for (size_t i = 0; i <= names.size(); ++i) {
      cout << "Имя: " << names[i] << " Номер: " << numbers[i] << endl; 
    }
  } else cout << "Список контактов пуст. Добавьте туда кого-нибудь!" << endl;
}

void save_data(string name, string number)
{
  // Установка кодировки консоли в UTF-8
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

// Установка локали для поддержки русского языка
  setlocale(LC_ALL, "ru_RU.UTF-8");
  cout << "Отлично, данные получены, контакт создан." << endl;
  names.push_back(name);
  numbers.push_back(number);
  
}

void create_contact()
{ 
  // Установка кодировки консоли в UTF-8
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

// Установка локали для поддержки русского языка
  setlocale(LC_ALL, "ru_RU.UTF-8");
  string name;
  string number;

  cout << "Введите имя контакта: ";
  cin >> name;
  cout << "Введите номер: ";
  cin >> number;

  save_data(name, number);
}

void greetings()
{
  // Установка кодировки консоли в UTF-8
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

// Установка локали для поддержки русского языка
  setlocale(LC_ALL, "ru_RU.UTF-8");
  int choose_func;

  while (true) {
    cout << endl;
    cout << endl;
    cout << "Перед вами телефонный справочник." << endl;
    cout << "Сюда вы можете записывать свои контакты и удалять из этого." << endl;
    cout << "Выберите действие из предложенного функционала: " << endl;
    cout << '\t' << "1. Просмотреть список контактов" << endl;
    cout << "\t" << "2. Добавить новый контакт" << endl;
    cout << "\t" << "3. Удалить выбранный контакт" << endl;
    cout << "\t" << "4. Выйти" << endl;

  cin >> choose_func;

  switch (choose_func) {
    case 1:
      show_contacts();
      break;
    case 2:
      create_contact();
      break;
    case 3:
      delete_contact();
      break;
    case 4:
      cout << "Выход из программы..." << endl;
      return;
      break;
    default:
      cout << "Введите число от одного до четырёх!" << endl;
  }
  }
  
} 

int main() 
{
  /* Телефонный справочник.
 Что мне нужно: 
 1. Функция принимающая два аргумента: имя контакта и номер телефона 
 2. Функция которая сохраняет эти данные в векторе
 3. Функция демонстрирующая список контактов
 3. Функция которая удаляет контакт (вместе с номером)
 5. Функция которая изменяет контакт*/
 greetings();
 return 0;

}
