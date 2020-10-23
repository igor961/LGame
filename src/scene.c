#include "stdio.h"
#include "raylib.h"
#include "init.h"

int main() {
  const int winWidth = 1400;
  const int winHeight = 600;
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  InitWindow(winWidth, winHeight, "Hello, world!");

  Camera camera = { 0 };

  camera.position = (Vector3){4.0f, 4.0f, 4.0f};
  camera.target = (Vector3){ 0.0f, 1.0f, -1.0f };
  camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
  camera.fovy = 45.0f;
  camera.type = CAMERA_PERSPECTIVE;
  m_init();

  Vector3 position = { 0.0f, 0.0f, 0.0f };    // Set model position

  SetCameraMode(camera, CAMERA_FREE);         // Set an orbital camera mode

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateCamera(&camera);                  // Update camera
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    DrawModel(*ground_model, position, 0.2f, WHITE);   // Draw 3d model with texture

    DrawGrid(10, 1.0f);     // Draw a grid

    EndMode3D();

    DrawText("Hello, world!", winWidth - 210, winHeight - 20, 10, GRAY);

    DrawFPS(10, 10);

    EndDrawing();
  }

  m_destroy();

  CloseWindow();
  return 0;
}
