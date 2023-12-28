#include "bomb.h"


class Explosion {
public:
    int detonate(const std::vector<Bomb>& bombs, std::vector<bool>& detonated, int i);
    std::pair<int, Bomb> maximumDetonated(const std::vector<Bomb>& bombs);
};

int Explosion::detonate(const std::vector<Bomb>& bombs, std::vector<bool>& detonated, int i) {
    int booms = 0, n = bombs.size();
    for (int j = 0; j < n; j++) {
        if (!detonated[j]) {
            int x1 = bombs[i].x, y1 = bombs[i].y, r1 = bombs[i].r;
            int x2 = bombs[j].x, y2 = bombs[j].y;
            long dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
            if (dist <= (long)r1 * r1) {
                detonated[j] = true;
                booms += 1 + detonate(bombs, detonated, j);
            }
        }
    }
    return booms;
}

std::pair<int, Bomb> Explosion::maximumDetonated(const std::vector<Bomb>& bombs) {
    int maxDetonatedBombs = 0;
    Bomb maxDetonatedBomb;
    int n = bombs.size();

    for (int i = 0; i < n; ++i) {
        std::vector<bool> detonated(bombs.size(), false);
        detonated[i] = true;
        int r = 1 + detonate(bombs, detonated, i);
        if (r > maxDetonatedBombs) {
            maxDetonatedBombs = r;
            maxDetonatedBomb = bombs[i];
        }
    }
    return std::make_pair(maxDetonatedBombs, maxDetonatedBomb);
}

