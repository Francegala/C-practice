//
//  main.cpp
//  Lesson 10
//
//  Created by Francesco Galassi on 13/11/2020.
//

#include <iostream>

using namespace std;

class Enemy{
public:
    Enemy (int hps);
    virtual ~Enemy();
    int get_hit_poins() const;
    int get_score() const;
    void set_hit_points(int new_hit_points);
    virtual void set_score (int new_score);
protected:
    int hit_points;
    int * score;
    
};


Enemy:: Enemy (int hps):
hit_points(hps){
    score = new int(0);
}

Enemy::~Enemy(){
    delete score;
}

int Enemy::get_hit_poins()const{
    return hit_points;
}

int Enemy:: get_score()const{
    return *score;
}

void Enemy::set_hit_points(int new_hit_points){
    hit_points = new_hit_points;
    
}

void Enemy::set_score(int new_score){
    *score = new_score;
}


class ArmedEnemy: public Enemy{
public:
    ArmedEnemy (int hps, int ammo);
    virtual ~ArmedEnemy();
    virtual void set_score (const int new_score);
    void shoot();

protected:
    int ammo_level;
    
};

ArmedEnemy::ArmedEnemy(int hps, int ammo):
Enemy(hps),
ammo_level(ammo){
    
}

ArmedEnemy::~ArmedEnemy()   {
    
}

void ArmedEnemy::set_score(const int new_score){
    *score = new_score;
    cout<<"score is now "<<*score<<endl;
    
}

void ArmedEnemy::shoot(){
    if(ammo_level > 0){
        cout<< " bang! \n";
        --ammo_level;
    }else{
        cout<<"out of ammo \n";
    }
}

void some_function(Enemy & enemy){
    enemy.set_score((enemy.get_score()+1));
}

int main(){
    ArmedEnemy * ae = new ArmedEnemy(2,1);
    
    
    cout << "hit points = "<< ae -> get_hit_poins()<<"\n";
    ae -> set_hit_points(30);
    cout << "hit points = "<< ae -> get_hit_poins()<<"\n";
    
    ae -> shoot();
    ae -> shoot();
    ae -> shoot();
    
    cout << "score = "<<ae -> get_score()<<"\n";
    some_function(*ae);
    ae->set_score(0);
    some_function(*ae);
    some_function(*ae);
    cout << "score = "<<ae -> get_score()<<"\n";

    cout << "hit points = "<< ae -> get_hit_poins()<<"\n";
    ae -> set_hit_points(ae->get_hit_poins()-10);
    ae -> set_hit_points(ae->get_hit_poins()-5);
    ae -> set_hit_points(ae->get_hit_poins()-1);
    cout << "hit points = "<< ae -> get_hit_poins()<<"\n";

    delete ae;
    ae = NULL;
    return 0;
    
    
}
