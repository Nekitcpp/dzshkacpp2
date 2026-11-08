#include <iostream>
#include <Windows.h>
int main()
{
    SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
    const int size[2] = { 300, 1000 };        
    const int limit[2][3] = { { 750, 1500, 2000 },  
                               { 1000, 2000, 3000 } };
    const int litr[2][3] = { { 1, 4, 7 },        
                               { 2, 4, 6 } };
    const int bak = 100;                      

    int samolet;
    std::cout << "Выберите самолёт (1 или 2): ";
    std::cin >> samolet;

    if (samolet != 1 && samolet != 2)
    {
        std::cout << "Такого самолёта нет!" << std::endl;
        return 0;
    }
    int p = samolet - 1;  

    double distAB, distBC, weight;
    std::cout << "Введите расстояние A -> B (км): ";
    std::cin >> distAB;
    std::cout << "Введите расстояние B -> C (км): ";
    std::cin >> distBC;
    std::cout << "Введите вес груза (кг): ";
    std::cin >> weight;

    int rate = 0;
    bool fly = false;
    for (int i = 0; i < 3; i++)
    {
        if (weight <= limit[p][i])
        {
            rate = litr[p][i];
            fly = true;
            break;
        }
    }

    if (!fly)
    {
        std::cout << "Полет невозможен: самолет не поднимает такой вес." << std::endl;
        return 0;
    }

    double r1 = distAB * rate;  
    double r2 = distBC * rate;  

    if (r1 > size[p] + bak)
    {
        std::cout << "Полет невозможен: не хватит топлива на участке A -> B." << std::endl;
        return 0;
    }

    double main = size[p] - (r1 > bak ? r1 - bak : 0); 
    double temp = (r1 < bak) ? bak - r1 : 0;          

    double need = r2 - temp;     
    double d = 0;

    if (need > main)
    {
        d = need - main   ;
        if (need > size[p])  
        {
            std::cout << "Полет невозможен: не хватит топлива на участке B -> C." << std::endl;
            return 0;
        }
    }

    if (d > 0)
        std::cout << "Минимальная дозаправка в пункте B: " << d << " литров." << std::endl;
    else
        std::cout << "Дозаправка не нужна, топлива хватит на весь маршрут." << std::endl;

    return 0;
}
