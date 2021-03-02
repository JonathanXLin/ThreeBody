/**
 * @file
 * Stores current simulation state and provides accessors/mutators
 */

#ifndef STATE_H
#define STATE_H

/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Standard Includes */
#include <stdlib.h>

/* External Includes */
#include "../../raylib/raylib.h"

/* Module Includes */
#include "state_private.h"

/***********************************************************************************************************************
 *
 *                                                   D E F I N E S
 *
 **********************************************************************************************************************/

#define MAX_STARS       999

/***********************************************************************************************************************
 *
 *                                                  T Y P E D E F S
 *
 **********************************************************************************************************************/

typedef struct point_object_s {
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;

    double mass;
} point_object_s;

typedef struct star_s {
    point_object_s point;

    double radius;
    Color color;
} star_s;

typedef struct star_list_s {
    star_s stars[MAX_STARS];

    size_t num_stars;
} star_list_s;

/***********************************************************************************************************************
 *
 *                                     F U N C T I O N   D E C L A R A T I O N S
 *
 **********************************************************************************************************************/

void state__init(void);

bool state__add_star(Vector3 pos, Vector3 vel, float mass, double radius, Color color);

size_t state__get_star_list_size(void);

bool state__get_star(size_t index, star_s *star_ptr);

bool state__change_star_position(size_t index, Vector3 position_diff);

bool state__change_star_velocity(size_t index, Vector3 velocity_diff);

#endif /* #ifdef STATE_H */
