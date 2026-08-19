#pragma once
#include "unit.hpp"
#include <vector>
#include <algorithm>

class UnitZone
{
public:

    UnitZone(const Vector2& position, const Vector2& size)
    : m_position(position), m_size(size){}

    void Draw() const;
    void AddingUnit(Unit* unit);
    void RemoveUnit(Unit* unit);
    bool ContainUnit(Unit* unit) const;
    bool HasUnit(Unit* unit) const;

    void ArrangeUnits();
    void UpdateSize();

    void ReorderUnits(Unit* unit, float mouseX);
    void HandleDrop(Unit* unit, float mouseX);

private:

    Vector2 m_position;
    Vector2 m_size;

    std::vector<Unit*> m_units;

    float m_unitSpaces = 20.0f;
    float m_minWidth;
};