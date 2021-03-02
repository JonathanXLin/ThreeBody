/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Main Module Header */
#include "state.h"

/* Standard Includes */
#include <stdlib.h>

/* External Includes */

/* Private Module Includes */
#include "state_private.h"

/***********************************************************************************************************************
 *
 *                                                   D E F I N E S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                                                  T Y P E D E F S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                             P R I V A T E   F U N C T I O N   D E C L A R A T I O N S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                                  P R I V A T E   D A T A   D E F I N I T I O N S
 *
 **********************************************************************************************************************/

static star_list_s star_list;

/***********************************************************************************************************************
 *
 *                                         P R I V A T E   F U N C T I O N S
 *
 **********************************************************************************************************************/

point_object_s state__init_point_object(Vector3 pos, Vector3 vel, Vector3 acc, float mass) {
    point_object_s new_point_object = { .position = pos, .velocity = vel, .acceleration = acc, .mass = mass};

    return new_point_object;
}

/***********************************************************************************************************************
 *
 *                                          P U B L I C   F U N C T I O N S
 *
 **********************************************************************************************************************/

void state__init(void) {
    star_list.num_stars = 0U;
}

bool state__add_star(Vector3 pos, Vector3 vel, float mass, double radius, Color color) {
    if (star_list.num_stars >= MAX_STARS) {
        return false;
    }

    point_object_s new_point_object = state__init_point_object(pos, vel, (Vector3){0.0f, 0.0f, 0.0f}, mass);
    star_s new_star = {.point = new_point_object, .radius = radius, .color = color};

    star_list.stars[star_list.num_stars] = new_star;
    star_list.num_stars++;

    return true;
}

size_t state__get_star_list_size(void) {
    return star_list.num_stars;
}

bool state__get_star(size_t index, star_s *star_ptr) {
    if (index >= star_list.num_stars) {
        return false;
    }

    *star_ptr = star_list.stars[index];

    return true;
}

bool state__change_star_position(size_t index, Vector3 position_diff) {
    if (index >= star_list.num_stars) {
        return false;
    }

    star_list.stars[index].point.position.x += position_diff.x;
    star_list.stars[index].point.position.y += position_diff.y;
    star_list.stars[index].point.position.z += position_diff.z;

    return true;
}

bool state__change_star_velocity(size_t index, Vector3 velocity_diff) {
    if (index >= star_list.num_stars) {
        return false;
    }

    star_list.stars[index].point.velocity.x += velocity_diff.x;
    star_list.stars[index].point.velocity.y += velocity_diff.y;
    star_list.stars[index].point.velocity.z += velocity_diff.z;

    return true;
}
