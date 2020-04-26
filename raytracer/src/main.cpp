//
// Created by ninig on 4/7/2020.
//

#include <World.h>


int main ()
{
    World w;
    w.build();
    w.camera_ptr->render_scene(w);
    return 0;
}