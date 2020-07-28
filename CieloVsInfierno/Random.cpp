#include "Random.h"
#include "QRandomGenerator"
#include "time.h"
#include "QDebug"

int Random::Random1(int seed,int range){
    std::uniform_int_distribution<int>dist(1,seed);
    int o =  1+dist(*QRandomGenerator::global())%range;
    return o;
}
bool Random :: Probabilidad(int seed,int prob){
    int rand = Random1(seed,100);
    if(rand <= prob)
        return true;
    else
        return false;
}

int Random :: RandomRange(int min, int max){
    std::uniform_int_distribution<int>dist(min,max);
    int o =  dist(*QRandomGenerator::global())%(max+1);
    return o;
}

int Random:: myrandom (int i) { return std::rand()%i;}

void Random::Shuffle(int array[],int size){
    std::srand ( unsigned ( std::time(nullptr) ) );
    for (int i = 0;i<RandomRange(0,100);i++) {
        std::random_shuffle(&array[0],&array[size],myrandom);
    }
}

/*void Random :: Shuffle(Mesa * array[20],int nonulos){
    nonulos -= 1;
    for(int i = 0; i < nonulos;i++){
        int index = RandomRange(0,nonulos);
        Mesa * temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }*/
