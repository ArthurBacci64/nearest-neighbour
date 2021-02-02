#include "nearest_neighbour.h"

float distance(struct data d1, struct data d2)
{
    int dx = d1.x - d2.x;
    int dy = d1.y - d2.y;

    if (dx < 0)
    {
        dx = -dx;
    }

    if (dy < 0)
    {
        dy = -dy;
    }

    return (float)dx * dy;
}

int nearest_neightbour(struct data d, struct data *dataset, unsigned int len)
{
    if (len < 1)
    {
        return 0;
    }

    unsigned int argmin = 0;
    float dif = -1;
    for (unsigned int i = 0; i < len; i++)
    {
        if (dif == -1 || distance(d, dataset[i]) < dif)
        {
            argmin = i;
            dif = distance(d, dataset[i]);
        }
    }
    return dataset[argmin].value;
}
