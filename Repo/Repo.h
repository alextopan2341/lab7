//
// Created by Alex on 4/5/2022.
//

#ifndef LAB7_REPO_H
#define LAB7_REPO_H
#include "../Entity/Entity.h"
#include <iostream>
#include <vector>
using namespace std;

class Repo {
private:
    Entity entities[100];
    int numberOfEntities;
public:
    Repo();
    ~Repo();
    void addItem(Entity &ent);
    int getSize() const;
    vector <Entity> getAll() const;
    void deleteItem(int id);
    void updateItem(Entity entOld, Entity entNew);
    Entity getById(int i);
};

#endif //LAB7_REPO_H
