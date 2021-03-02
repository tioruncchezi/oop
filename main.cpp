#include <windows.h>
#include <iostream>

using namespace std;

struct Worker { // начало объявления структурного типа Worker

    char surname[30]; //объявление поля «фамилия работника»

    char position[15]; //объявление поля «название занимаемой должности»

    unsigned short int year; //объявление поля «год поступления на работу»

}; //конец объявление структуры Worker
int main()
{
    system("chcp 1251");
    int n = 3; // объявление константы n — числа элементов типа «Worker»

    bool people = false;

    unsigned short int now_year = 2020, seniority; // объявление переменных now_year — текущий год и seniority — стаж

    Worker* K = new Worker[n];

    Worker temp;

    for (int i = 0; i < n; i++)

    {
        cout << "Фамилия и инициалы: ";

        cin >> K[i].surname;

        cout << "\nНазвание занимаемой должности: ";

        cin >> K[i].position;

        cout << "\nГод поступления на работу: ";

        cin >> K[i].year;

        cout << "\n";
    }

    cout << "Введите стаж работы(лет): ";

    cin >> seniority;

    for (int i = 0; i < n; i++)

    {
        if ((now_year - K[i].year) > seniority)

        {
            cout << '\n' << K[i].surname;

            people = true;
        }
    }

    if (people == false) cout << "Нет таких работников!" << endl;

    cout << "\nСписок работников в алфавитном порядке" << endl;

    for (int i = 0; i < n - 1; i++)

    {
        for (int j = 0; j < n; j++)

            if (strcmp(K[i].surname, K[j].surname) > 0)

            {
                temp = K[i];

                K[i] = K[j];

                K[j] = temp;
            }
    }

    for (int i = 0; i < n; i++)

        cout << '\n' << K[i].surname << endl;

    system("pause");

    return 0;
}
