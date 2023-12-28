#include "bomb.cpp"
#include <gtest/gtest.h>
#include <fstream>

TEST(ExplosionTest, MaximumDetonated) {
    Bomb bomb1(2, 1, 3);
    Bomb bomb2(6, 1, 4);

    std::vector<Bomb> bombs;
    bombs.push_back(bomb1);
    bombs.push_back(bomb2);

    Explosion explosion;

    auto result = explosion.maximumDetonated(bombs);

    ASSERT_EQ(result.first, 2);
    ASSERT_EQ(result.second.x, 6);
    ASSERT_EQ(result.second.y, 1);
    ASSERT_EQ(result.second.r, 4);
}

TEST(ExplosionTest, MaximumDetonated2) {
    Bomb bomb1(1, 1, 5);
    Bomb bomb2(10, 10, 5);

    std::vector<Bomb> bombs;
    bombs.push_back(bomb1);
    bombs.push_back(bomb2);

    Explosion explosion;

    auto result = explosion.maximumDetonated(bombs);

    ASSERT_EQ(result.first, 1);
    ASSERT_EQ(result.second.x, 1);
    ASSERT_EQ(result.second.y, 1);
    ASSERT_EQ(result.second.r, 5);
}

TEST(ExplosionTest, MultipleBombs) {
    std::vector<Bomb> bombs = {
        Bomb(1, 2, 3),
        Bomb(2, 3, 1),
        Bomb(3, 4, 2),
        Bomb(4, 5, 3),
        Bomb(5, 6, 4)
    };

    Explosion explosion;

    auto result = explosion.maximumDetonated(bombs);

    ASSERT_EQ(result.first, 5);
    ASSERT_EQ(result.second.x, 1);
    ASSERT_EQ(result.second.y, 2);
    ASSERT_EQ(result.second.r, 3);
}

int main(int argc, char **argv) {
    std::ifstream bombFile("bombs.txt");
    if (!bombFile.is_open()) {
        std::cerr << "Файл не открыт" << "\n";
        return 1;
    }

    std::vector<Bomb> bombs;
    int x, y, r;

    while (bombFile >> x >> y >> r) {
        bombs.push_back(Bomb(x, y, r));
    }

    Explosion explosion;

    int maxDetonatedBombs;
    Bomb maxDetonatedBomb;

    std::tie(maxDetonatedBombs, maxDetonatedBomb) = explosion.maximumDetonated(bombs);

    bombFile.close();

    std::ofstream resultFile("detonated.txt");
    if (!resultFile.is_open()) {
        std::cerr << "Файл не открыт" << "\n";
        return 1;
    }

    resultFile << "Координаты (x, y): " << maxDetonatedBomb.x << ", " << maxDetonatedBomb.y << "\n";
    resultFile << "Радиус: " << maxDetonatedBomb.r << "\n";
    resultFile << "Количество: " << maxDetonatedBombs << "\n";

    resultFile.close();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
