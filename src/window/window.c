/***********************************************************************************************************************
 *
 *                                                  I N C L U D E S
 *
 **********************************************************************************************************************/
/* Main Module Header */
#include "window.h"

/* Standard Includes */
#include <stdlib.h>

/* External Includes */
#include "../utils/utils.h"
#include "../engine/engine.h"

/* Private Module Includes */
#include "window_private.h"

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

static const char *const WINDOW_NAME = "ThreeBody";

static const Vector3 CAMERA_POSITION_INIT = {.x = SOLAR_RADIUS_MANTISSA * 10.0f, .y = SOLAR_RADIUS_MANTISSA * 10.0f, .z = SOLAR_RADIUS_MANTISSA * 10.0f};
static const Vector3 CAMERA_TARGET_INIT = {.x = 0.0f, .y = 0.0f, .z = 0.0f};
static const Vector3 CAMERA_UP_VECTOR_INIT = {.x = 0.0f, .y = 1.0f, .z = 0.0f};
static const float CAMERA_FOVY_INIT = 45.0f;

/***********************************************************************************************************************
 *
 *                                         P R I V A T E   F U N C T I O N S
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *
 *                                          P U B L I C   F U N C T I O N S
 *
 **********************************************************************************************************************/

void window__init(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
}

bool window__init_camera(Camera3D *camera) {
    if (camera == NULL) {
        return false;
    }

    camera->position = CAMERA_POSITION_INIT;
    camera->target = CAMERA_TARGET_INIT;
    camera->up = CAMERA_UP_VECTOR_INIT;
    camera->fovy = CAMERA_FOVY_INIT;
    camera->type = CAMERA_PERSPECTIVE;

    SetCameraMode(*camera, CAMERA_FREE);

    SetTargetFPS(FPS);

    return true;
}

void window__reset_camera(Camera3D *camera) {
    camera->target = CAMERA_TARGET_INIT;
}

void window__main_loop(main_loop_function_f main_loop_function, Camera3D *camera) {
    while (!WindowShouldClose())
    {
        UpdateCamera(camera);

        if (IsKeyDown('Z')) {
            window__reset_camera(camera);
        }

        BeginDrawing();

            ClearBackground(BLACK);

            BeginMode3D(*camera);

                main_loop_function();

            EndMode3D();

        EndDrawing();
    }
}

void window__close(void) {
    CloseWindow();
}
