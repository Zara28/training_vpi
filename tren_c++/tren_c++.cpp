// tren_c++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include <clocale>
#include <windows.h>
using namespace std;
int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "rus");

    int n = 0;
    int sum = 0;
    while (n != 101)
    {
        int ccount = 0;
        cout << "Введи номер предмета, по которому хочешь тренироваться\n 1.История\n 2.Философия\n 3.Английский \n для закрытия программы введи 101\n Для перевыбора предмета введи 100\n";
        string opr[50];
        string pon[50];
        string dop[50];
        string path = "";
        cin >> n;
        switch (n)
        {
        case 1:
            path += "hist.txt";
            break;
        case 2:

            path += "fil.txt";
            break;
        case 3:
            path += "eng.txt";
            break;
        case 101:
            continue;
            break;
        case 100:
            cout << "Вы еще не выбрали\n";
            continue;
        default:
            cout << "Произошла ошибка. Выберите снова\n";
            continue;
        }

        int i = 0;
        ifstream file(path);
        while (file.is_open() && i<50)
        {
            getline(file, dop[i]);
                pon[i] = dop[i].substr(0, dop[i].find(";"));
                opr[i] = dop[i].substr(dop[i].find(";") + 1, dop[i].find("\n"));
                i++;
            
        }

        file.close();
            while (n != 100)
            {
               
                int r = rand()%50+1;
                cout<<opr[r];
                string ans;
                cin >> ans;
                if (ans == pon[r])
                {
                    ccount += 1;
                }
                else if (ans == "100")
                {
                    n = 100;
                    cout<<"\nВаш счет: " << ccount;
                    continue;
                }
                else if (ans == "101") {
                    n = 101;
                    cout<<"\nВаш счет: " << ccount;
                    break;
                }
                sum += ccount;


            }


       cout<<"Ваш общий счет: "<< sum;


        
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
