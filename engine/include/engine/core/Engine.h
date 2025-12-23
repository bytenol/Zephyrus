//
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_ENGINE_H
#define ZEPHYRUS_ENGINE_H

#ifdef __cplusplus
extern "C" {
#endif

    void engine_init(int width, int height);
    void engine_tick(float dt);
    int  entity_create();
    void entity_set_position(int id, float x, float y);

#ifdef __cplusplus
}
#endif


#endif //ZEPHYRUS_ENGINE_H