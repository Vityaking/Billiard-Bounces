#include <iostream>
#include <math.h>

int main()
{
    int length = 0, width = 0, velocity = 0, accelaration = 0, angle = 0, time=0, time_used=0;
    do {
        std::cin >> length >> width >> velocity >> angle >> time;
        if (velocity == 0 && angle==0 && length==0 && width==0 && time==0) break;  //checking if input is correct
        accelaration = velocity / time; //actually decelaration, but in equations it is negative
        int vertical = 0, horizontal = 0, x=length/2, y=width/2; //x,y represents current location of ball
        while (velocity != 0)
        {
            if ((sin(velocity) / width) > (cos(velocity) / length))  // vertical hit
            {
                time_used = (sqrt(-sin(velocity) + sqrt(sin(velocity) * sin(velocity) + 4 * sin(accelaration) * (width - y))) / 2);  //páratlan hitek esetén x koordináta=length, páros esetén 0 etc.
                vertical++;
                x += time_used * sin(velocity) - ((cos(accelaration) / 2) * (time_used * time_used));
                y+= time_used * cos(velocity) - ((sin(accelaration) / 2) * (time_used * time_used));
                angle += ((90 - (angle % 90)) * 2);
            }
            else if ((sin(velocity) / width) < (cos(velocity) / length))  // horizontal hit
            {
                time_used = (sqrt(-cos(velocity) + sqrt(cos(velocity) * cos(velocity) + 4 * cos(accelaration) * (length-x))) / 2);
                horizontal++;
                x += time_used * sin(velocity) - ((cos(accelaration) / 2) * (time_used * time_used));
                y += time_used * cos(velocity) - ((sin(accelaration) / 2) * (time_used * time_used));
                angle += ((90 - (angle % 90)) * 2);
            }
            else  //corner hit
            {
                horizontal++;
                vertical++;
                time_used = (sqrt(-sin(velocity) + sqrt(sin(velocity) * sin(velocity) + 4 * sin(accelaration) * (width - y))) / 2);
                x += time_used * sin(velocity) - ((cos(accelaration) / 2) * (time_used * time_used));
                y += time_used * cos(velocity) - ((sin(accelaration) / 2) * (time_used * time_used));
                angle += ((90 - (angle % 90)) * 2);
            }
            velocity -= accelaration * time_used;
            //angle += ((90 - (angle % 90)) * 2);

        }
        std::cout << "Horizontal: " << horizontal << " Vertical: " << vertical << "\n";
    } while (velocity != 0);
}
