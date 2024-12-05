#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "Student.h"
#include "StudentManager.h"

void FirstMenu()
{
    int stop = 1;
    int n;

    while (stop > 0)
    {
        system("cls");
        cout << '\n';
        cout << "===============================" << '\n';
        cout << "=         GAEC PROGRAM        =" << '\n';
        cout << "===============================" << '\n';
        cout << '\n';
        cout << "1. Gestionarea studentilor." << '\n';
        cout << '\n';
        cout << "2. Meniul de administratie." << '\n';
        cout << '\n';
        cout << "3. Gestionarea evenimentelor." << '\n';
        cout << '\n';
        cout << "4. Inchiderea programului." << '\n';
        cout << '\n';
        cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
        cout << '\n';
        cin >> n;
        cout << '\n';

        int stopthis;
        switch (n)
        {
        case 1: {
            StudentManager manager;
            stopthis = 1;
            while (stopthis > 0)
            {
                system("cls");
                cout << '\n';
                cout << "===============================" << '\n';
                cout << "=         GAEC PROGRAM        =" << '\n';
                cout << "===============================" << '\n';
                cout << '\n';
                cout << "1. Inscrierea unui student in program." << '\n';
                cout << '\n';
                cout << "2. Afisarea listei tuturor studentilor inscrisi in program." << '\n';
                cout << '\n';
                cout << "3. Schimbarea datelor unui student in program." << '\n';
                cout << '\n';
                cout << "4. Stergerea unui student din program." << '\n';
                cout << '\n';
                cout << "5. Inapoi la meniul principal." << '\n';
                cout << '\n';
                cout << "Alegeti un numar pentru a continua. (1-5)" << '\n';
                cout << '\n';
                cin >> n;
                cout << '\n';
                switch (n)
                {
                case 1:
                    manager.Inregistrare();
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    manager.Afisaretext();
                    cin.ignore();
                    cin.get();
                    break;
                case 3:
                    manager.Changedata();
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
                    manager.StergereStudent();
                    cin.ignore();
                    cin.get();
                    break;
                case 5:
                    stopthis = 0;
                    break;
                default:
                    cout << "Optiune invalida.\n";
                    cin.ignore();
                    cin.get();
                    break;
                }
            }
            break;
        }
        case 2: {
            stopthis = 1;
            while (stopthis > 0)
            {
                system("cls");
                cout << '\n';
                cout << "===============================" << '\n';
                cout << "=         GAEC PROGRAM        =" << '\n';
                cout << "===============================" << '\n';
                cout << '\n';
                cout << "1. Creearea unui eveniment. " << '\n';
                cout << '\n';
                cout << "2. Asignarea unui student pentru participare la eveniment." << '\n';
                cout << '\n';
                cout << "3. Schimbarea datelor unui eveniment." << '\n';
                cout << '\n';
                cout << "4. Stergerea unui student din eveniment." << '\n';
                cout << '\n';
                cout << "5. Afisarea datelor unui eveniment" << '\n';
                cout << '\n';
                cout << "6. Inapoi la meniul principal." << '\n';
                cout << '\n';
                cout << "Alegeti un numar pentru a continua. (1-6)" << '\n';
                cout << '\n';
                cin >> n;
                cout << '\n';
                switch (n)
                {
                case 1:
                    // Add functionality for event creation here
                    break;
                case 2:
                    // Add functionality for assigning a student to an event
                    break;
                case 3:
                    // Add functionality for modifying event data
                    break;
                case 4:
                    // Add functionality for removing a student from an event
                    break;
                case 5:
                    // Add functionality for displaying event data
                    break;
                case 6:
                    stopthis = 0;
                    break;
                default:
                    cout << "Optiune invalida.\n";
                    cin.ignore();
                    cin.get();
                    break;
                }
            }
            break;
        }
        case 4:
            system("cls");
            stop = 0;
            break;
        default:
            cout << "Optiune invalida. Incercati din nou.\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
