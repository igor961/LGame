#include "stdio.h"
#include "stdlib.h"
#include "init.h"

Model *ground_model;

Model *m_load_model(const char **name) {
  char file[30];
  sprintf(file, "assets/%s", *name);
  Model *m_ptr = malloc(sizeof(Model));
  *m_ptr = LoadModel(file);
  return m_ptr;
}

void m_init() { 
  const char *name = "ground.obj";
  ground_model = m_load_model(&name);
}

void m_destroy() {
  UnloadModel(*ground_model);
  free(ground_model);
  ground_model = 0;
}

