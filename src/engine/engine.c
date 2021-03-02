/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Main Module Header */
#include "engine.h"

/* Standard Includes */
#include <stdlib.h>
#include <math.h>

/* External Includes */

/* Private Module Includes */
#include "engine_private.h"

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

/***********************************************************************************************************************
 *
 *                                         P R I V A T E   F U N C T I O N S
 *
 **********************************************************************************************************************/

double engine__get_relative_distance(point_object_s object_one, point_object_s object_two) {
    double relative_x = object_one.position.x - object_two.position.x;
    double relative_y = object_one.position.y - object_two.position.y;
    double relative_z = object_one.position.z - object_two.position.z;

    return sqrt(pow(relative_x, 2) + pow(relative_y, 2) + pow(relative_z, 2));
}

double engine__get_gravitational_acceleration(point_object_s target, point_object_s source) {
    double distance = engine__get_relative_distance(target, source);

    double gravitational_force = GRAVITATIONAL_CONSTANT * (target.mass * source.mass) / pow(distance, 2);

    return gravitational_force / target.mass;
}

/***********************************************************************************************************************
 *
 *                                          P U B L I C   F U N C T I O N S
 *
 **********************************************************************************************************************/

void engine__init(void) {
    state__init();
}

bool engine__iterate_star(size_t index) {
    

    return true;
}
