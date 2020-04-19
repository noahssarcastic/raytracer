//
// Created by ninig on 4/7/2020.
//

#include <World.h>


int main (int argc, char **argv)
{
    World w;
    w.build();
    w.render_sampled();
    return 0;
}