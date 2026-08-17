#pragma once
#include "unit.hpp"
#include <vector>

//UnitZone is the place to put the Units in order.
class UnitZone{
    public:
        UnitZone(const Vector2& position, const Vector2& size) : m_position(position), m_size(size){};

        void Draw();
        void AddingUnit(Unit* unit);
    
    private:
        Vector2 m_position;
        Vector2 m_size;

    std::vector<Unit*> m_units;

};