#include <iostream>
#include <math.h>

int main()
{
    int length = 0, width = 0, velocity = 0, accelaration = 0, angle = 0, time=0, time_used=0;
    do {
        std::cin >> length >> width >> velocity >> angle >> time;
        if (velocity == 0) break;
        accelaration = velocity / time;
        int vertical = 0, horizontal = 0, x=length/2, y=width/2;
        while (velocity != 0)
        {
            if ((sin(velocity) / width) > (cos(velocity) / length))
            {
                time_used = (sqrt(-sin(velocity) + sqrt(sin(velocity) * sin(velocity) + 4 * sin(accelaration) * (width - y))) / 2);
                vertical++;
                x += time_used * sin(velocity) - ((cos(accelaration) / 2) * (time_used * time_used));
                y+= time_used * cos(velocity) - ((sin(accelaration) / 2) * (time_used * time_used));
            }
            else if ((sin(velocity) / width) < (cos(velocity) / length))
            {
                time_used = (sqrt(-cos(velocity) + sqrt(cos(velocity) * cos(velocity) + 4 * cos(accelaration) * (length-x))) / 2);
                horizontal++;
                x += time_used * sin(velocity) - ((cos(accelaration) / 2) * (time_used * time_used));
                y += time_used * cos(velocity) - ((sin(accelaration) / 2) * (time_used * time_used));
            }
            else
            {
                horizontal++;
                vertical++;
                time_used = (sqrt(-sin(velocity) + sqrt(sin(velocity) * sin(velocity) + 4 * sin(accelaration) * (width - y))) / 2);
                x += time_used * sin(velocity) - ((cos(accelaration) / 2) * (time_used * time_used));
                y += time_used * cos(velocity) - ((sin(accelaration) / 2) * (time_used * time_used));
            }
            velocity -= accelaration * time_used;

        }
        std::cout << "Horizontal: " << horizontal << " Vertical: " << vertical << "\n";
    } while (velocity != 0);
}
