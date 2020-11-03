#include <iostream>
#include <math.h>

int main()
{
    float length = 0, width = 0, velocity = 0, accelaration = 0, angle = 0, time=0, time_used=0;
    do {
        std::cin >> length >> width >> velocity >> angle >> time;
        if (velocity == 0 && angle==0 && length==0 && width==0 && time==0) break;  //checking if input is correct
        accelaration = velocity / time; //actually decelaration, but in equations it is negative
        float vertical = 0, horizontal = 0, x=length/2, y=width/2; //x,y represents current location of ball
        while (velocity != 0)  //there is an emerging need for vx and vy
        {
            if ((sinf(velocity) / width) > (cosf(velocity) / length))  // vertical hit
            {
                time_used = (sqrt(-sinf(velocity) + sqrt(sinf(velocity) * sinf(velocity) + 4 * sinf(accelaration) * (width - y))) / 2);  //páratlan hitek esetén x koordináta=length, páros esetén 0 etc.
                vertical++;
                x += time_used * sinf(velocity) - ((cosf(accelaration) / 2) * (time_used * time_used));
                y+= time_used * cosf(velocity) - ((sinf(accelaration) / 2) * (time_used * time_used));
                std::cout << "Megyen1";
                //angle += ((90 - (angle % 90)) * 2);
            }
            else if ((sinf(velocity) / width) < (cosf(velocity) / length))  // horizontal hit   57.296
            {
                time_used = (sqrt(-cosf(velocity) + sqrt(cosf(velocity) * cosf(velocity) + 4 * cosf(accelaration) * (length-x))) / 2);
                horizontal++;
                x += time_used * sinf(velocity) - ((cosf(accelaration) / 2) * (time_used * time_used));
                y += time_used * cosf(velocity) - ((sinf(accelaration) / 2) * (time_used * time_used));
                std::cout << "Megyen2";
                //angle += ((90 - (angle % 90)) * 2);
            }
            else  //corner hit
            {
                horizontal++;
                vertical++;
                time_used = (sqrt(-sinf(velocity) + sqrt(sinf(velocity) * sinf(velocity) + 4 * sinf(accelaration) * (width - y))) / 2);
                x += time_used * sinf(velocity) - ((cosf(accelaration) / 2) * (time_used * time_used));
                y += time_used * cosf(velocity) - ((sinf(accelaration) / 2) * (time_used * time_used));
                std::cout << "Megyen3";
                //angle += ((90 - (angle % 90)) * 2);
            }
            velocity -= accelaration * time_used;
            int temp;
            temp = round(angle);
            angle += ((90 - (temp % 90)) * 2);

        }
        std::cout << "Horizontal: " << horizontal << " Vertical: " << vertical << "\n";
    } while (velocity != 0);
}
