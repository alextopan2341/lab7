//
// Created by Alex on 4/5/2022.
//

#include "Entity.h"
#include <string.h>
#include <vector>

using namespace std;

const char *Entity::getName() {
    return name;
}

void Entity::setName(const char *n) {
    if(this->name)
    {
        delete[] this->name;
    }
    this->name= new char[strlen(n)+1];
    strcpy(this->name,n);
}

int Entity::getNumber() {
    return number;
}

void Entity::setNumber(int num) {
    this->number = num;
}

int Entity::getSum() const {
    return sum;
}

void Entity::setSum(int s) {
    this->sum= s;
}

Entity::Entity() {
    this->name = nullptr;
    this->number= 0;
    this->sum = 0;
    this->id = 0;
}

Entity::Entity(const Entity &ent) {
    this->name = new char[strlen(ent.name)+1];
    this->number = ent.number;
    this->sum = ent.sum;
    this->id = ent.id;
    strcpy_s(this->name,sizeof (this->name),ent.name);
}

Entity::Entity(int i,const char *name1, int num, int s) {
    this->name = new char[strlen(name1)+1];
    strcpy_s(this->name, sizeof(this->name), name1);
    this->id = i;
    this->number = num;
    this->sum = s;
}

Entity::~Entity() {
    if(this->name != nullptr)
    {
        this->name = nullptr;
        this->number = 0;
        this->sum = 0;
        this->id = 0;
    }
}

Entity &Entity::operator=(const Entity &ent) {
    if(this->name != nullptr){
        delete[] this->name;
    }
    this->name = new char[strlen(ent.name) +1];
    strcpy(this->name, ent.name);
    this->setSum(ent.sum);
    this->setNumber(ent.number);
    this->setId(ent.id);
    return *this;

}

void Entity::setId(int i) {
    this->id = i;
}

int Entity::getId() const {
    return id;
}

bool Entity::operator==(const Entity &ent) {
    return this->sum == ent.sum && this->number == ent.number && this->id == ent.id && strcmp(this->name, ent.name)==0;
}

ostream &operator<<(ostream &os, Entity ent) {
    os<<ent.getId()<<" "<<ent.getName()<<" "<<ent.getNumber()<<" "<<ent.getSum()<<endl;
    return os;
}

bool cmpSum(Entity& ent1, Entity& ent2) {
    return ent1.getSum() < ent2.getSum();
}

