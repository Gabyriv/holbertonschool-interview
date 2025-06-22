#include "menger.h"

/**
 * should_fill - Determines if a position should be filled in the Menger sponge
 * @x: x coordinate
 * @y: y coordinate
 * @level: current level of recursion
 *
 * Return: 1 if position should be filled, 0 otherwise
 */
static int should_fill(int x, int y, int level)
{
    /* Base case: level 0 is always filled */
    if (level == 0)
        return (1);

    /* Calculate the size of the current level subdivision */
    int size = (int)pow(3, level - 1);

    /* Check if position is in the center of the 3x3 grid */
    if (x >= size && x < 2 * size && y >= size && y < 2 * size)
        return (0); /* Center is always empty */

    /* Recursively check the position in the next level down */
    return (should_fill(x % size, y % size, level - 1));
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 *
 * Description: Draws a Menger Sponge fractal pattern where:
 * - Level 0 is a 1x1 square (#)
 * - Level N is a 3x3 grid of Level N-1 sponges with center empty
 * - Size of level N sponge is 3^N
 */
void menger(int level)
{
    int i, j, size;

    /* Handle invalid level */
    if (level < 0)
        return;

    /* Calculate the total size of the sponge */
    size = (int)pow(3, level);

    /* Iterate through each position in the grid */
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            /* Determine if this position should be filled */
            if (should_fill(i, j, level))
                printf("#");
            else
                printf(" ");
        }
        /* Move to next line after each row */
        printf("\n");
    }
}
