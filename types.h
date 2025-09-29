// Game Objects
#ifndef MULTIBALLMADNESS_TYPES_H
#include <stddef.h>
#include <stdlib.h>

#include "raylib.h"

typedef struct ball {
    Vector2 position;
    Vector2 velocity;
    Color color;
} ball;

typedef struct ballArray {
    ball *values;
    size_t count;
    size_t capacity;
} ballArray;

inline void appendBall(ballArray *array, ball value) {
    if (array->count >= array->capacity) {
        if (array->capacity == 0) {
            array->capacity = 256;
            array->values = (ball*)malloc(array->capacity * sizeof(ball));
        }
        else {
            array->capacity *= 2;
            array->values = (ball*)realloc(array->values, array->capacity * sizeof(ball));
        }
    }
    array->values[array->count++] = value;
}

typedef struct block {
    Vector2 position;
    Color color;
} block;

typedef struct blockArray {
    block *values;
    size_t count;
    size_t capacity;
} blockArray;

inline void appendBlock(blockArray *array, block value) {
    if (array->count >= array->capacity) {
        if (array->capacity == 0) {
            array->capacity = 256;
            array->values = (block*)malloc(array->capacity * sizeof(block));
        }
        else {
            array->capacity *= 2;
            array->values = (block*)realloc(array->values, array->capacity * sizeof(block));
        }
    }
    array->values[array->count++] = value;
}

#define MULTIBALLMADNESS_TYPES_H
#endif //MULTIBALLMADNESS_TYPES_H