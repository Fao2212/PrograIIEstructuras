#ifndef RANDOM_H
#define RANDOM_H

struct Random{

    static int SeedGenerator(int i, int a, int b, int c, int d, int f);
    static int Random1(int seed,int range);
    static bool Probabilidad(int seed,int prob);
    static int RandomRange(int min,int max);
    static void Shuffle(int array[],int size);
    static int myrandom(int i);
    //static void Shuffle(Mesa * array[20],int nonulos);//luego puede hacerse un template
};
#endif // RANDOM_H
