#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ratings[i];
    }

    int totalBonuses = 0;
    std::vector<int> bonuses(n, 500); // Инициализируем все бонусы водителей суммой минимального бонуса 500 рублей

    // Проходим по рейтингам водителей слева направо и обновляем бонусы
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            bonuses[i] = bonuses[i - 1] + 500; // Водитель получает бонус больше, чем у его соседа слева
        }
    }

    // Проходим по рейтингам водителей справа налево и обновляем бонусы
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1] && bonuses[i] <= bonuses[i + 1]) {
            bonuses[i] = bonuses[i + 1] + 500; // Водитель получает бонус больше, чем у его соседа справа
        }
    }

    // Вычисляем общую сумму бонусов
    for (int bonus : bonuses) {
        totalBonuses += bonus;
    }

    std::cout << totalBonuses << std::endl;

    return 0;
}