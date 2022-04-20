//
// Created by Alex on 4/5/2022.
//

#include <cassert>
#include <cstring>
#include "tests.h"
#include "../Entity/Entity.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"

void testConstructor(){
    Entity ent;
    assert(ent.getName() == nullptr);
    assert(ent.getSum() == 0);
    assert(ent.getNumber() == 0);
}

void testSetterAndGetter(){
    Entity ent;
    char s[4]= "gaz";
    ent.setSum(100);
    ent.setNumber(25);
    ent.setName(s);
    assert(strcmp(ent.getName(),s) == 0);
    assert(ent.getNumber() == 25);
    assert(ent.getSum() == 100);
}

void testRepo(){
    Repo repo;
    Entity ent0,ent1,ent2;
    const char *s2= "curent";
    const char *s1= "apa";
    const char *s0= "gaz";
    ent0.setSum(100);
    ent0.setNumber(25);
    ent0.setName(const_cast<char *>(s0));
    ent1.setSum(100);
    ent1.setNumber(25);
    ent1.setName(const_cast<char *>(s1));
    ent2.setSum(100);
    ent2.setNumber(25);
    ent2.setName(const_cast<char *>(s2));
    repo.addItem(ent0);
    repo.addItem(ent1);
    repo.addItem(ent2);
    assert(repo.getSize()==3);
}

void testDeleteEntities(){
    Repo repo;
    char s2[7]= "curent";
    char s1[4]= "apa";
    char s0[4]= "gaz";
    char s3[14] = "electricitate";
    Entity ent1(1,s0,25,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);
    Entity ent4(4,s3,22,100);
    repo.addItem(ent1);
    repo.addItem(ent2);
    repo.addItem(ent3);
    repo.addItem(ent4);
    repo.deleteItem(3);
    assert(repo.getSize() == 3);
}

void testUpdateItem(){
    Repo repo;
    const char *s2= "curent";
    const char *s1= "apa";
    const char *s0= "gaz";
    const char *s3= "electricitate";
    Entity ent1(1,s0,25,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);
    Entity ent4(4,s3,22,100);
    repo.addItem(ent1);
    repo.addItem(ent2);
    repo.addItem(ent3);
    repo.updateItem(ent1,ent4);
    assert(repo.getById(2) == ent2);
    assert(repo.getById(4) == ent4);
}

void testCreateService(){
    const char* s0= "gaz";
    Entity ent(1,s0,25,200);;
    Repo r;
    Service s;
    s.createEntity(ent);
    assert(s.getAll().size() == 1);
}

void testUpdateService(){
    Repo r;
    Service s;
    const char *s2= "curent";
    const char *s1= "apa";
    const char *s0= "gaz";
    const char *s3 = "electricitate";
    Entity ent1(1,s0,25,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);
    Entity ent4(4,s3,22,100);

    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.updateEntity(ent1,ent4);
    assert(s.getByID(4) == ent4);
}

void testDeleteService(){
    Repo r;
    Service s;
    const char *s2 = "curent";
    const char *s1 = "apa";
    const char *s0 = "gaz";
    Entity ent1(1,s0,25,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);

    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.deleteEntity(ent1);
    assert(s.getAll().size()==2);
}

void testReadService(){
    Repo r;
    Service s;
    const char *s2 = "curent";
    const char *s1  = "apa";
    const char *s0 = "gaz";
    const char *s3 = "electricitate";
    Entity ent1(1,s0,25,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);
    Entity ent4(4,s3,22,100);

    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.readEntity(r);
}

void test_operator(){
    const char* s = "curent";
    Entity entity(1, s, 10, 25);
    Entity entity1;
    entity1 = entity;
    assert(entity1.getNumber() == 10);
    assert(entity1.getSum() == 25);
}

void testUpdateSum(){
    Service s;
    const char *s2 = "curent";
    const char *s1  = "apa";
    const char *s0 = "gaz";
    const char *s3 = "electricitate";
    Entity ent1(1,s0,25,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);
    Entity ent4(4,s3,22,100);
    s.createEntity(ent1);
    s.createEntity(ent2);
    s.createEntity(ent3);
    s.createEntity(ent4);
    s.updateSum(1,25,5,s0);
    assert(s.getByID(1).getSum() == 5);
}

void testGetByNumber(){
    Service s;
    const char *s2 = "curent";
    const char *s1  = "apa";
    const char *s0 = "gaz";
    const char *s3 = "electricitate";
    Entity ent1(1,s0,22,150);
    Entity ent2(2,s2,24,90);
    Entity ent3(3,s1,23,76);
    Entity ent4(4,s3,22,100);
    Entity ent5(1,s1,22,100);
    Entity ent6(2,s2,25,100);
    Entity ent7(1,s2,22,100);
    vector<Entity> entities= s.getByNumber(22);
    assert(entities.size() == 0);
}

void tests(){
    testConstructor();
    testSetterAndGetter();
    testRepo();
    testDeleteEntities();
    testUpdateItem();
    testUpdateService();
    testCreateService();
    testDeleteService();
    test_operator();
    testUpdateSum();
    //testGetByNumber();
}