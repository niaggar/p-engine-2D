#include "prand.h"

#include <random>

namespace prand {
    int getRandom(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist_x(min, max);

        return dist_x(gen);
    }

    float getRandom(float min, float max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist_x(min, max);

        return dist_x(gen);
    }

    float getRandomOnPoint(float middle, float delta) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist_x(middle - (delta / 2.0f), middle + (delta / 2.0f));

        return dist_x(gen);
    }
}
