#include "stdio.h"
#include "stdlib.h"
#include "init.h"
#include "utils/hashmap.h"

Model *ground_model;

Model *m_load_model(const char **name);

void m_init() { 
  const char *name = "ground.obj";
  ground_model = m_load_model(&name);
}

void m_destroy_model(Model *ptr);

void m_destroy() {
  m_destroy_model(ground_model);
}

Model *m_load_model(const char **name) {
  char file[30];
  sprintf(file, "assets/%s", *name);
  Model *m_ptr = malloc(sizeof(Model));
  *m_ptr = LoadModel(file);
  return m_ptr;
}

void m_destroy_model(Model *ptr) {
  if (ptr != 0) {
    UnloadModel(*ptr);
    free(ptr);
    ptr = 0;
    printf("Reset model's pointer\n");
  }
}

