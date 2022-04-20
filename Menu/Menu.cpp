//
// Created by Alex on 4/20/2022.
//

#include "Menu.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include "../console/console.h"

int runMenu() {
    //Repo repo;
    Console con;
    Service ser;
    char option;
    int start, finish, num, sum, i;
    char name[50];
    bool ok = true;
    while (ok) {
        con.Options();
        cout << "Give the option you want: ";
        cin >> option;
        switch (option) {
            case 'c': {
                con.createEntity();
                break;
            }
            case 'p': {
                con.printEntities(ser.getAll());
                break;
            }
            case '1': {
                cout << "Give the apartment for which you want to eliminate all expenses: ";
                cin >> num;
                ser.deleteByNumber(num);
                break;
            }
            case '2': {
                cout << "Give the start and stop of apartments for which you want to delete expenses: ";
                cin >> start >> finish;
                for (int i = start; i < finish; i++) {
                    ser.deleteByNumber(i);
                }
                break;
            }
            case '3': {
                cout << "Give the expenses for which you want to delete from all of apartments: ";
                cin >> name;
                ser.deleteByName(name);
                break;
            }
            case '4': {
                cout << "Give the expenses,sum and number of the apartment for which you want to update: ";
                cin >> i >> name >> sum >> num;
                ser.updateSum(i, num, sum, name);
                break;
            }
            case '5': {
                cout << "Print all the expenses of the apartment you have to give: ";
                cin >> num;
                ser.getByNumber(num);
                break;
            }
            case '6': {
                cout << "Print all the expenses greater than a sum you give: ";
                cin >> sum;
                ser.getGreaterThanSum(sum);
                break;
            }
            case '7': {
                cout << "Print all the expenses equal with a sum you give: ";
                cin >> sum;
                ser.getEqualsSum(sum);
                break;
            }
            case '8': {
                cout << "Print the total sum of an expense you give from all of the apartments: ";
                cin >> name;
                ser.getTotalSum(name);
                break;
            }
            case '9': {
                cout << "Print the biggest expense from an apartment: ";
                cin >> num;
                ser.getBiggestExpense(num);
                break;
            }
            case 's': {
                cout << "Sorts the apartments by an expense you give: ";
                cin >> name;
                ser.sortBySum(name);
                break;
            }
            case 'e': {
                cout << "Print the entities with the same expense name you give: ";
                cin >> name;
                ser.getByExpense(name);
                break;
            }
            case '&': {
                cout << "Print the entities with smaller sum you give: ";
                cin >> sum;
                ser.getBySum(sum);
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong option! Try again!";
        }
    }
    return 0;
}
