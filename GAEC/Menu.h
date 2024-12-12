#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include "Student.h"
#include "ClubManager.h"
#include "StudentManager.h"
#include "LoginSystem.h"
#include "Admin.h"
#include "Userobisnuit.h"

using namespace std;

User* Login(LoginSystem& sistem,bool& succes)
{
    succes = false;
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
                break;
            }
                
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
    return nullptr;
}

void FirstUserMenu(LoginSystem& sistem,const string& loggedInUsername)
{
    int n,stop,stopthis,stopthiss;
    stop = 1;
    while (stop > 0)
    {
        system("cls");
        cout << '\n';
        cout << "===============================" << '\n';
        cout << "=         GAEC PROGRAM        =" << '\n';
        cout << "===============================" << '\n';
        cout << '\n';
        cout << "1. Inscrierea in program ca student." << '\n';
        cout << '\n';
        cout << "2. Vizualizarea profilului" << '\n';
        cout << '\n';
        cout << "3. Gestionarea Activitatilor" << '\n';
        cout << '\n';
        cout << "4. Inapoi la meniul de logare." << '\n';
        cout << '\n';
        cout << "5. Inchiderea programului." << '\n';
        cout << '\n';
        cout << "Alegeti un numar pentru a continua. (1-5)" << '\n';
        cout << '\n';
        cin >> n;
        cout << '\n';
        switch (n)
        {
        case 1: 
        {
            StudentManager manager;
            manager.Inregistrare();
            cin.ignore();
            break;
        }
        case 2: 
        {
            LoginSystem functie;
            functie.seeUserDetails();
            cin.ignore();
            cin.get();
            break;
        }
        case 3:
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
                {
                    ClubManager club;
                    stopthiss = 1;
                    while (stopthiss > 0)
                    {
                        system("cls");
                        cout << '\n';
                        cout << "===============================" << '\n';
                        cout << "=         GAEC PROGRAM        =" << '\n';
                        cout << "===============================" << '\n';
                        cout << '\n';
                        cout << "1. Creearea unui club de membri." << '\n';
                        cout << '\n';
                        cout << "2. Alatura-te unui club." << '\n';
                        cout << '\n';
                        cout << "3. Vizualizarea datelor unui club." << '\n';
                        cout << '\n';
                        cout << "4. Inapoi la meniul anterior." << '\n';
                        cout << '\n';
                        cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
                        cout << '\n';
                        cin >> n;
                        switch (n)
                        {
                        case 1:
                            club.Inregistrare();
                            cin.ignore();
                            break;
                        case 2:
                            club.join();
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            club.Afisaretext();
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            stopthiss = 0;
                            break;
                        default:
                            cout << "Optiune invalida.\n";
                            cin.ignore();
                            cin.get();
                            break;
                        }
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
            break;
        case 4:
            system("cls");
            sistem.updateUserStatus(loggedInUsername, 0);
            stop = 0;
            break;
        case 5:
            system("cls");
            sistem.updateUserStatus(loggedInUsername, 0);
            exit(0);
        default:
            cout << "Optiune invalida. Incercati din nou.\n";
            cin.ignore();
            cin.get();
            break;
        }
    }
}
void FirstMenu()
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
                cout << "1. Afisarea listei tuturor studentilor inscrisi in program." << '\n';
                cout << '\n';
                cout << "2. Schimbarea datelor unui student in program." << '\n';
                cout << '\n';
                cout << "3. Stergerea unui student din program." << '\n';
                cout << '\n';
                cout << "4. Inapoi la meniul principal." << '\n';
                cout << '\n';
                cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
                cout << '\n';
                cin >> n;
                cout << '\n';
                switch (n)
                {
                case 1:
                    manager.Afisaretext();
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    manager.Changedata();
                    cin.ignore();
                    cin.get();
                    break;
                case 3:
                    manager.StergereStudent();
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
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
                        ClubManager club;
                        system("cls");
                        cout << '\n';
                        cout << "===============================" << '\n';
                        cout << "=         GAEC PROGRAM        =" << '\n';
                        cout << "===============================" << '\n';
                        cout << '\n';
                        cout << "1. Afisarea tuturor cluburilor." << '\n';
                        cout << '\n';
                        cout << "2. Schimbarea datelor unui club." << '\n';
                        cout << '\n';
                        cout << "3. Stergerea unui club" << '\n';
                        cout << '\n';
                        cout << "4. Inapoi la meniul anterior." << '\n';
                        cout << '\n';
                        cout << "Alegeti un numar pentru a continua. (1-4)" << '\n';
                        cout << '\n';
                        cin >> n;
                        switch (n)
                        {
                        case 1:
                            club.Afisaretext();
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
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
