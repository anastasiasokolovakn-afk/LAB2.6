#include <iostream>
#include <Windows.h>
#include "Lorry.h"

using namespace std;

#pragma pack(push, 1)
class LorryPacked {
private:
    Lorry::Car car;
    double capacity;
};
#pragma pack(pop)

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "===========================================" << endl;
    cout << "  1. ÄÅÌÎÍÑÒÐÀÖIß ÊÎÍÑÒÐÓÊÒÎÐ²Â ÒÀ ÎÏÅÐÀÒÎÐ²Â" << endl;
    cout << "===========================================" << endl;

    Lorry::Car car1("Audi", 4, 190.0);
    Lorry lorry1(car1, 20.0);
    cout << "Ñòâîðåíî lorry1: " << lorry1 << endl;

    cout << "\nÇìiíà ïàðàìåòðiâ ÷åðåç äåëåãóâàííÿ:" << endl;
    lorry1.ChangeCapacity(25.0);
    lorry1.ReassignBrand("Scania");
    cout << "Îíîâëåíèé lorry1: " << lorry1 << endl;

    cout << "\nÄåìîíñòðàö³ÿ ³íêðåìåíòó (++lorry1):" << endl;
    cout << ++lorry1 << endl;

    cout << "\n===========================================" << endl;
    cout << "  2. ÂÂÅÄÅÍÍß ÒÀ ÌÀÑÈÂ ÎÁ'ªÊÒIÂ" << endl;
    cout << "===========================================" << endl;

    const int SIZE = 2;
    Lorry fleet[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "\n--- Çàïîâíåííÿ âàíòàæiâêè #" << (i + 1) << " ---" << endl;
        cin >> fleet[i];
    }

    cout << "\n--- Ñïèñîê óñiõ âàíòàæiâîê ó àâòîïàðêó ---" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "[" << (i + 1) << "] " << fleet[i] << endl;
    }

    cout << "\n===========================================" << endl;
    cout << "  3. Ï²ÄÐÀÕÓÍÎÊ ÎÁ'ªÊÒ²Â ÒÀ ÐÎÇÌ²Ð ÏÀÌ'ßÒ²" << endl;
    cout << "===========================================" << endl;

    cout << "Ê³ëüê³ñòü ñòâîðåíèõ îá'ºêò³â Car: " << Lorry::Car::GetCarCount() << endl;
    cout << "Ê³ëüê³ñòü ñòâîðåíèõ îá'ºêò³â Lorry: " << Lorry::GetLorryCount() << endl;

    cout << "\nÐîçì³ð ñòàíäàðòíîãî Lorry: " << sizeof(Lorry) << " áàéò" << endl;
    cout << "Ðîçì³ð óïàêîâàíîãî Lorry (#pragma pack(1)): " << sizeof(LorryPacked) << " áàéò" << endl;

    return 0;
}