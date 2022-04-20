//
// Created by Alex on 4/5/2022.
//

#include "Repo.h"

Repo::Repo() {
    this->numberOfEntities = 0;
}

Repo::~Repo() = default;

void Repo::addItem(Entity &ent) {
        this->entities[this->numberOfEntities++] = ent;
}

int Repo::getSize() const {
    return this->numberOfEntities;
}

vector <Entity> Repo::getAll() const {
    vector <Entity> v;
    v.reserve(numberOfEntities);
for(int i=0;i<numberOfEntities;i++)
        v.push_back(entities[i]);
    return v;
}

void Repo::deleteItem(int id) {
    for(int i=0;i<numberOfEntities;i++)
    {
        if(id == entities[i].getId())
        {
            for (int j = i; j < numberOfEntities-1; j++)
                entities[j] = entities[j+1];
            numberOfEntities--;
        }
    }

}

void Repo::updateItem(Entity entOld, Entity entNew){
    for(int i=0; i<numberOfEntities;i++)
        if(entities[i] == entOld)
            entities[i] = entNew;

}

Entity Repo::getById(int i) {
    for(int j=0; j<numberOfEntities;j++)
    {
        if(i == entities[j].getId())
            return entities[j];
    }
    throw runtime_error("No entity with that id was found !");
}



