//
// Created by Alex on 4/5/2022.
//

#include "console.h"
#include <iostream>
#include "../Service/Service.h"
#include "../Entity/Entity.h"
using namespace std;
void Console::Options(){
    cout<<endl<<"c. Add an entity"<<endl;
    cout<<"p. Show all of the entities"<<endl;
    cout << "m. modify etities" << endl;
    cout<<"x.Close app."<<endl;
}
void Console::createEntity(){
    int i,num,sum;
    char name[50];
    cout<<"Give the id of the expense:";
    cin >> i;
    cout<<"Give the name of the expense:";
    cin >> name;
    cout<<"Give the number of the apartment:";
    cin >> num;
    cout<<"Give the sum of the expense: ";
    cin >> sum;
    Entity ent(i, name, num, sum);
    ser.createEntity(ent);
}
void Console::printEntities(const vector<Entity>& entities){
    //if (entities.empty())
    //    cout << "Nu sunt entitati adaugate!" << endl;
    //else {
        cout << "Lista de cheltuieli este:" << endl;
        for (auto entity : entities)
        {
            cout << "ID: " << entity.getId() << " " << "Name: " << entity.getName() << " " << "Number: " << entity.getNumber() << " "
                 << "Sum: " << entity.getSum() << endl;
        }
    }
//}

void Console::modifyExpense() {
    cout << "1. Delete expenses from one apartment." << endl;
    cout << "2. Delete expenses from more apartements." << endl;
    cout << "3. Delete expenseses with a given name." << endl;
    cout << "4. Modify sum from a given apartment number and expense name." << endl;
    cout << "x. exit" << endl;
    char option;
    bool ok = true;
    while (true) {
        cout << "Give the option you want:";
        cin >> option;
        if(option == '1')
        {
            int nr;
            cout << "Give apartment number:";
            cin >> nr;
            ser.deleteByNumber(nr);
            break;
        }
        else if (option == '2')
        {
            int begin, end;
            cout << "Give the beginning:";
            cin >> begin;
            cout << "Give the end:";
            cin >> end;
            for (int i = begin; i <= end; i++) {
                ser.deleteByNumber(i);
            }
            break;
        }
        else if (option == '3')
        {
            char name[50];
            cout << "Give expense name:";
            cin >> name;
            ser.deleteByName(name);
            break;
        }
        else if (option == '4')
        {
            char name[50];
            int i;
            cout<<"Give expense id: ";
            cin>>i;
            cout << "Give expense name: ";
            cin >> name;
            int nr;
            cout << "Give apartment number:";
            cin >> nr;
            int sum;
            cout << "Give new sum:";
            cin >> sum;
            ser.updateSum(i,nr, sum, name);
            break;
        }
        else if (option == 'x'){
            ok = false;
            break;
        }
    }
}

Console::Console() = default;

Console::~Console() = default;
