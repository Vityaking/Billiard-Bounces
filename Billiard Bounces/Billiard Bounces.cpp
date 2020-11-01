#include <iostream>
#include <math.h>

int next_stop() //gives back if stop was at which wall
{

    return 0;
}

int main()
{
    int length = 0, width = 0, velocity = 0, accelaration = 0, angle = 0, time=0;
    do {
        std::cin >> length >> width >> velocity >> angle >> time;
        if (velocity == 0) break;
        accelaration = velocity / time;
        int vertical = 0, horizontal = 0, x=length/2, y=width/2;
        bool vege = false;
        //creating references

        /*do {
            if (next_stop() == 0) vege = true;
            else if (next_stop() == 1) horizontal++;
            else vertical++;
            if (vege) break;
        } while (!vege);*/
    } while (velocity != 0);
}
