//
// Created by Alex on 4/5/2022.
//

#ifndef LAB7_ENTITY_H
#define LAB7_ENTITY_H
#include <vector>
using namespace std;
#include <iostream>

class Entity {
private:
    char* name;
    int number;
    int sum,id;
    const vector<const char*> possible_entities = {"apa", "curent", "gaz", "electricitate", "caldura","internet","altele"};
public:
    Entity();
    Entity(const Entity& ent);
    Entity(int i, const char *name1, int num, int s);
    const char *getName();
    void setName(const char *n);
    void setId(int i);
    int getId() const;
    int getNumber();
    void setNumber(int num);
    int getSum() const;
    void setSum(int s);
    Entity &operator=(const Entity &ent);
    bool operator==(const Entity &ent);
    ~Entity();
    friend ostream& operator<<(ostream& os, Entity ent);
};
bool cmpSum(Entity &ent1, Entity& ent2);


#endif //LAB7_ENTITY_H
