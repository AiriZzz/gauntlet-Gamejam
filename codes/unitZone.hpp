#pragma once
#include "unit.hpp"
#include <vector>
#include <algorithm>

//UnitZone is the place to put the Units in order.
class UnitZone{
    public:
        UnitZone(const Vector2& position, const Vector2& size) : m_position(position), m_size(size), m_minWidth(size.x){};

        void Draw();
        void AddingUnit(Unit* unit);
        bool ContainUnit(Unit* unit);
        bool HasUnit(Unit* unit);

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