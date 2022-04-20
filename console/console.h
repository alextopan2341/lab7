//
// Created by Alex on 4/5/2022.
//

#ifndef LAB7_CONSOLE_H
#define LAB7_CONSOLE_H
#include "../Repo/Repo.h"
#include "../Service/Service.h"

class Console{
private:
    Service ser;
public:
    void Options();
    Console();
    ~Console();
    void createEntity();
    void printEntities(const vector<Entity>& entities);
    void modifyExpense();
};

#endif //LAB7_CONSOLE_H
