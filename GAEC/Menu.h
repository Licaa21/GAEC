#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "Student.h"
#include "StudentManager.h"
#include "LoginSystem.h"
#include "Admin.h"
#include "Userobisnuit.h"
User* Login(bool &succes)
{
    succes = false;
    LoginSystem sistem;
    sistem.loadUsersFromFile("users.txt");
    sistem.AdaugareUtilizator(new Admin("admin", "admin123"));
    int n, stop=1;
    while (stop > 0)
    {
        system("cls");
        cout << '\n';
        cout << "===============================" << '\n';
        cout << "=         GAEC PROGRAM        =" << '\n';
        cout << "===============================" << '\n';
        cout << '\n';
        cout << "1. Inregistrare." << '\n';
        cout << '\n';
        cout << "2. Login." << '\n';
        cout << '\n';
        cout << "3. Inchiderea programului." << '\n';
        cout << '\n';
        cout << "Alegeti un numar pentru a continua. (1-3)" << '\n';
        cout << '\n';
        cin >> n;
        switch (n)
        {
            case 1:
                system("cls");
                {
                    string username, password;
                    cout << '\n';
                    cout << "===============================" << '\n';
                    cout << "=         GAEC PROGRAM        =" << '\n';
                    cout << "===============================" << '\n';
                    cout << '\n';
                    cout << "Utilizator: ";
                    cin >> username;
                    cout << "Parola: ";
                    cin >> password;
                    sistem.inregistrare(username, password);
                    cout << "Utilizatorul a fost inregistrat cu succes!" << '\n';
                }
                break;
            case 2:
            {   
                system("cls");
                {
                    string username, password;
                    cout << '\n';
                    cout << "===============================" << '\n';
                    cout << "=         GAEC PROGRAM        =" << '\n';
                    cout << "===============================" << '\n';
                    cout << '\n';
                    cout << "Utilizator: ";
                    cin >> username;
                    cout << "Parola: ";
                    cin >> password;
                    User* loggedInUser = sistem.autentificare(username, password);
                    if (loggedInUser)
                    {
                        loggedInUser->displayRole();
                        succes = true;
                        return loggedInUser;
                    }
                    else
                    {
                        system("cls");
                        cout << '\n';
                        cout << "===============================" << '\n';
                        cout << "=         GAEC PROGRAM        =" << '\n';
                        cout << "===============================" << '\n';
                        cout << '\n';
                        cout << "Numele de utilizator sau parola sunt gresite, apasati tasta ENTER si incercati din nou!" << '\n';
                        cout << '\n';
                        cin.ignore();
                        cin.get();
                    }
                }
            }
                break;
            case 3:
                system("cls");
                exit(0);
            default:
                system("cls");
                cout << '\n';
                cout << "===============================" << '\n';
                cout << "=         GAEC PROGRAM        =" << '\n';
                cout << "===============================" << '\n';
                cout << '\n';
                cout << "Numar invalid, apasati tasta ENTER si incercati din nou!" << '\n';
                cout << '\n';
                cin.ignore();
                cin.get();
                break;
        }
    }
}

void FirstUserMenu(bool &backToLogin)
{
    cout << "PULA" << endl;
}
void FirstMenu(bool& backToLogin)
{
    int stop = 1;
    int n,stopthis,stopthiss;

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
        cout << "2. Gestionarea activitatilor." << '\n';
        cout << '\n';
        cout << "3. Meniul de administratie." << '\n';
        cout << '\n';
        cout << "4. Inapoi la meniul de logare." << '\n';
        cout << '\n';
        cout << "5. Inchiderea programului." << '\n';
        cout << '\n';
        cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
        cout << '\n';
        cin >> n;
        cout << '\n';
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
                cout << "1. Gestionarea cluburilor." << '\n';
                cout << '\n';
                cout << "2. Gestionarea evenimentelor." << '\n';
                cout << '\n';
                cout << "3. Inapoi la meniul principal." << '\n';
                cout << '\n';
                cout << "Alegeti un numar pentru a continua. (1-3)" << '\n';
                cout << '\n';
                cin >> n;
                cout << '\n';
                switch (n)
                {
                case 1:
                    stopthiss = 1;
                    while (stopthiss > 0)
                    {
                        system("cls");
                        cout << '\n';
                        cout << "===============================" << '\n';
                        cout << "=         GAEC PROGRAM        =" << '\n';
                        cout << "===============================" << '\n';
                        cout << '\n';
                        cout << "1. Creearea unui club." << '\n';
                        cout << '\n';
                        cout << "2. Afisarea tuturor cluburilor." << '\n';
                        cout << '\n';
                        cout << "3. Schimbarea datelor unui club." << '\n';
                        cout << '\n';
                        cout << "4. Stergerea unui club" << '\n';
                        cout << '\n';
                        cout << "5. Inapoi la meniul anterior." << '\n';
                        cout << '\n';
                        cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
                        cout << '\n';
                        cin >> n;
                        switch (n)
                        {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            stopthiss = 0;
                            break;
                        default:
                            cout << "Optiune invalida.\n";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    }
                    break;
                case 2:
                    // Add functionality for assigning a student to an club
                    break;
                case 3:
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
        case 3:
            system("cls");
            break;
        case 4:
            system("cls");
            backToLogin = true;
            stop = 0;
            break;
        case 5:
            system("cls");
            exit(0);
        default:
            cout << "Optiune invalida. Incercati din nou.\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
