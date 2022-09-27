#pragma once

#include "Cell.h"


class Field {
public:
    explicit Field(int width = 10, int height = 10);

    Field(Field &&other) noexcept;

    Field(const Field &other);

    ~Field() = default;

    void create_field();

    [[nodiscard]] std::vector<int> get_size() const;

    [[nodiscard]] std::vector<std::vector<Cell>> get_field();

    Field &operator=(const Field &other);

    Field &operator=(Field &&other) noexcept;

    bool move_player(int x, int y);

    [[nodiscard]] int get_player_x() const;

    [[nodiscard]] int get_player_y() const;
    Cell get_cell(int x, int y) const;

private:
    int width{};
    int height{};
    int player_x{};
    int player_y{};
    std::vector<std::vector<Cell>> field;

    void swap(Field &other);

    [[nodiscard]] int get_new_x(int x) const;

    [[nodiscard]] int get_new_y(int y) const;
    void update_player(int prev_x, int prev_y);
};
