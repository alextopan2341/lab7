//
// Created by Alex on 4/12/2022.
//

#include "Service.h"
#include <cstring>
#include <algorithm>
Service::Service()= default;

Service::Service(Repo& r){
    this->repo = r;
}

void Service::createEntity(Entity &ent) {
        repo.addItem(ent);
}

void Service::updateEntity(Entity oldEnt, Entity newEntity) {
    repo.updateItem(oldEnt,newEntity);
}

void Service::deleteEntity(Entity ent) {
    repo.deleteItem(ent.getId());
}

void Service::readEntity(Repo r) {
    r.getAll();
}

Entity Service::getByID(int i) {
    return repo.getById(i);
}

vector<Entity> Service::getAll() {
    vector<Entity> entities = this->repo.getAll();
    return entities;
}

void Service::deleteByNumber(int nr) {
    vector<Entity> entities = this->repo.getAll();
    for(auto entity: entities){
        if(entity.getNumber() == nr)
        {
            repo.deleteItem(entity.getId());
        }
    }

}

void Service::deleteByName(const char *name) {
    vector<Entity> entities = this->repo.getAll();
    for(auto entity: entities)
    {
        if(strcmp(entity.getName(),name)==0)
        {
            repo.deleteItem(entity.getId());
        }
    }
}

void Service::updateSum(int i,int nr,int sum, const char *name) {
    vector<Entity> entities = this->repo.getAll();
    Entity ent(i,name,nr,sum);
    for(auto entity: entities)
    {
        if(entity.getNumber()==ent.getNumber() && strcmp(entity.getName(),ent.getName())==0)
        {
            repo.updateItem(entity,ent);
        }
    }
}

vector<Entity> Service::getByNumber(int nr) {
    vector<Entity> entities;
    for(auto entity: this->repo.getAll())
    {
        if(entity.getNumber() == nr)
        {
            entities.push_back(entity);
        }
    }
    return entities;
}

vector<Entity> Service::getGreaterThanSum(int sum) {
    vector<Entity> entities;
    for(auto entity: this->repo.getAll())
    {
        if(entity.getSum() > sum)
        {
            entities.push_back(entity);
        }
    }
    return entities;
}

vector<Entity> Service::getEqualsSum(int sum) {
    vector<Entity> entities;
    for(auto entity: this->repo.getAll())
    {
        if(entity.getSum() == sum)
        {
            entities.push_back(entity);
        }
    }
    return entities;
}

int Service::getTotalSum(const char *name) {
    int sum=0;
    for(auto entity: this->repo.getAll())
    {
        if(strcmp(entity.getName(),name)==0)
        {
            sum += entity.getSum();
        }
    }
    return sum;
}

Entity Service::getBiggestExpense(int nr) {
    int max = 0;
    Entity ent;
    for (auto entity : this->repo.getAll())
    {
        if (entity.getNumber() == nr && entity.getSum() > max)
        {
            max = entity.getSum();
            ent = entity;
        }
    }

    return ent;
}

vector<Entity> Service::sortBySum(const char* name){
    vector<Entity> sortedEntities;
    for(auto entity: this->repo.getAll())
    {
        {
            if(strcmp(entity.getName(),name)==0)
                sortedEntities.push_back(entity);
        }
    }
    sort(sortedEntities.begin(), sortedEntities.end(), cmpSum);
    return sortedEntities;
}

vector<Entity> Service::getByExpense(const char* name) {
    vector<Entity> entities;
    for(auto entity: this->repo.getAll())
    {
        if(strcmp(entity.getName(),name)==0)
        {
            entities.push_back(entity);
        }
    }
    return entities;
}

vector<Entity> Service::getBySum(int sum) {
    vector<Entity> entities;
    for(auto entity: this->repo.getAll())
    {
        if(entity.getSum()< sum)
        {
            entities.push_back(entity);
        }
    }
    return entities;
}

Service::~Service() = default;
