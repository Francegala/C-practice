//
//  main.cpp
//  Lesson 9
//
//  Created by Francesco Galassi on 29/10/2020.
//

#include <iostream>
using namespace std;

class Enemy{
public:
    Enemy (int hps, int score);
    Enemy (int hps);
    ~Enemy();
    int get_hit_poins() const;
    int get_score() const;
    void set_hit_points(int new_hit_points);
    void set_score (int new_score);
private:
    int hit_points;
    int * score;
    
};

class Player : public Enemy{
public:
    string get_name() const;
    void set_name(string new_name);

private:
    string * name;
};

string Player::get_name() const{
    return *name;
}
void Player::set_name(string new_name){
    this -> name = new string (new_name);
    
}


Enemy:: Enemy (int hps, int score):
hit_points(hps){
    this -> score = new int (score);}

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

int main() {
    
    Enemy e1(2);
    //cout << "hit points = "<<e1.get_hit_poins()<<endl;
    
    Enemy * e2 = new Enemy (2,9);
    // e2 -> set_hit_points(3);
    //cout << "hit points = "<< e2 -> get_hit_poins()<<endl;

   // e2 -> set_score( (e2 -> get_score() + 23));
    
    cout << "score = "<< e2 -> get_score() <<endl;

    delete e2;
    e2 = NULL;
    
    
    return 0;
}
