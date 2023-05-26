class Enemy{
public:
    static const int default_hps = 4;
    Enemy():hit_points(default_hps){score = new int(0);}
    Enemy (int hps):hit_points(hps){score = new int(0);}
    Enemy (const Enemy& src);
    Enemy& operator=(const Enemy& rhs);
    virtual ~Enemy(){delete score;}
    int get_hit_points() const {return hit_points;}
    int get_score() const {return *score;}
    void set_hit_points(int new_hit_points){hit_points = new_hit_points;}
    virtual void set_score(int new_score){ *score = new_score;}
protected:
    int hit_points;
    int* score;
};
Enemy::Enemy(const Enemy& src):
hit_points(src.hit_points),
score(new int(*src.score)){ }

Enemy& Enemy::operator=(const Enemy &rhs){
    if(this == &rhs){
        return (*this);
    }
    // free old memory
    delete score;
    
    // copy new memory
    hit_points = rhs.hit_points;
    score = new int(*rhs.score);
    
    return *this;
}
#include <iostream>
//#include "Enemy.h"
#include <vector>

using namespace std;
using std::vector; //unecessary here
int main(){
    
    vector<int> scores(5,0); // first how many elements; second value of all the elements
    
    scores[0] = 1; scores[1] = 2; scores[2] = 3;
    
    for(int i = 0; i< scores.size() ; i++){ // size function
        cout << "scores " << i << " = " << scores[i] << "\n";
    }
    vector <Enemy>* enemies = new vector<Enemy>(3);
    
    Enemy fourth, fifth;
    
    enemies->push_back(fourth);
    enemies->push_back(fifth);
    cout << "size of enemies = " << enemies->size() << "\n";
    int i = 0;
    for(vector<Enemy>::iterator it = enemies->begin(); it != enemies->end(); ++it) //we use iterator
    {
        it->set_score(scores[i]);
        cout << "score = " << it-> get_score() << "\n";
        ++i;
    }
    Enemy newthird;
    enemies->insert(enemies->begin() +2, newthird);
    enemies->erase(enemies->begin() +2 );
    Enemy& back = enemies->back();
    cout << "hit points last element = " << back.get_hit_points() << "\n";
    
    enemies->pop_back();
    cout<<"new size of enemies = " << enemies->size()<<"\n";
    enemies->clear();
    
    delete enemies;
    
    return 0;
}
