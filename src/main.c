#include "window/window.h"
#include "engine/engine.h"

#include <assert.h>
#include <stdlib.h>

void main_init_function(void) {
    state__add_star((Vector3){SOLAR_RADIUS_MANTISSA * 5.0f, SOLAR_RADIUS_MANTISSA * 5.0f, SOLAR_RADIUS_MANTISSA * -5.0f}, (Vector3){0.1f, 0.0f, 0.0f}, SOLAR_MASS_MANTISSA, SOLAR_RADIUS_MANTISSA, YELLOW);
    state__add_star((Vector3){SOLAR_RADIUS_MANTISSA * -5.0f, SOLAR_RADIUS_MANTISSA * -5.0f, SOLAR_RADIUS_MANTISSA * 5.0f}, (Vector3){0.0f, 0.1f, 0.0f}, SOLAR_MASS_MANTISSA, SOLAR_RADIUS_MANTISSA, ORANGE);
}

void main_loop_function(void) {

    for (size_t i=0; i<state__get_star_list_size(); i++) {
        star_s current_star;
        bool get_result = state__get_star(i, &current_star);
        assert(get_result);

        DrawSphere(current_star.point.position, current_star.radius, current_star.color);

        bool iterate_result = engine__iterate_star(i);
        assert(iterate_result);
    }

    DrawGrid(100, SOLAR_RADIUS_MANTISSA);
}

int main(void)
{
    window__init();
    Camera3D camera;
    (void)window__init_camera(&camera);
    engine__init();

    main_init_function();
    window__main_loop(main_loop_function, &camera);

    window__close();

    return 0;
}