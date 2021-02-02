#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "nearest_neighbour.h"

#define LEN 10

int main()
{
    initscr();

    if (!has_colors())
    {
        return 1;
    }

    struct data d[LEN];

    srand(time(0));

    start_color();

    use_default_colors();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, -1, -1);

    for (unsigned int i = 0; i < LEN; i++)
    {
        if (rand() % 2 == 0)
        {
            d[i].value = -1;
        }
        else
        {
            d[i].value = 1;
        }
        d[i].x += rand() % (COLS + 1);
        d[i].y += rand() % (LINES + 1);
    }

    while (1)
    {

        for (unsigned int i = 0; i < LEN; i++)
        {
            
            if (rand() % 2 == 0)
            {
                d[i].x++;
            }
            else
            {
                d[i].x--;
            }

            if (rand() % 2 == 0)
            {
                d[i].y++;
            }
            else
            {
                d[i].y--;
            }

            if (d[i].x < 0)
            {
                d[i].x = 0;
            }
            else if (d[i].x >= COLS)
            {
                d[i].x = COLS - 1;
            }

            if (d[i].y < 0)
            {
                d[i].y = 0;
            }
            else if (d[i].y >= COLS)
            {
                d[i].y = COLS - 1;
            }
        }

        
        /*
        clear();
        for (unsigned int i = 0; i < LEN; i++)
        {
            if (d[i].value == 1)
            {
                move(d[i].y, d[i].x);
                attron(COLOR_PAIR(1));
                addch(' ');
                attroff(COLOR_PAIR(1));
            }
            else if (d[i].value == -1)
            {
                move(d[i].y, d[i].x);
                attron(COLOR_PAIR(2));
                addch(' ');
                attroff(COLOR_PAIR(2));
            }
        }
        
        refresh();
        getch();
        */

        for (unsigned int x = 0; x < COLS; x++)
        {
            for (unsigned int y = 0; y < LINES; y++)
            {
                struct data da = {x, y, 0};

                da.value = nearest_neightbour(da, d, LEN);

                if (da.value == 1)
                {
                    move(da.y, da.x);
                    attron(COLOR_PAIR(1));
                    addch(' ');
                    attroff(COLOR_PAIR(1));
                }
                else if (da.value == -1)
                {
                    move(da.y, da.x);
                    attron(COLOR_PAIR(2));
                    addch(' ');
                    attroff(COLOR_PAIR(2));
                }
                else
                {
                    return 1;
                }
            }
        }

        refresh();
        getch();
    }

    endwin();
    return 0;
}
