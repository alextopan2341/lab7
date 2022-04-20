//
// Created by Alex on 4/12/2022.
//

#ifndef LAB7_SERVICE_H
#define LAB7_SERVICE_H
#include "../Repo/Repo.h"
#include "../Entity/Entity.h"
#include <vector>

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo& r);
    ~Service();
    void createEntity(Entity &ent);
    void updateEntity(Entity oldEnt, Entity newEntity);
    void deleteEntity(Entity ent);
    void readEntity(Repo r);
    Entity getByID(int i);
    vector<Entity>getAll();
    void deleteByNumber(int nr);
    void deleteByName(const char* name);
    void updateSum(int i,int nr, int sum, const char *name);
    vector<Entity> getByNumber(int nr);
    vector<Entity> getGreaterThanSum(int sum);
    vector<Entity> getEqualsSum(int sum);
    int getTotalSum(const char *name);
    Entity getBiggestExpense(int nr);
    vector<Entity> sortBySum(const char* name);
    vector<Entity> getByExpense(const char* name);
    vector<Entity> getBySum(int sum);
};


#endif //LAB7_SERVICE_H
