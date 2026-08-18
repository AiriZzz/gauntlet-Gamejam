#pragma once
#include "unit.hpp"
#include <vector>
#include <algorithm>

//UnitZone is the place to put the Units in order.
class UnitZone{
    public:
        UnitZone(const Vector2& position, const Vector2& size, const std::vector<UnitType>& solution) 
        : m_position(position), m_size(size), m_minWidth(size.x), m_puzzleSolution(solution){}

        void Draw(Vector2 mousePosition) const;
        void AddingUnit(Unit* unit);
        bool ContainUnit(Unit* unit);
        bool HasUnit(Unit* unit);

        void ArrangeUnits();
        void UpdateSize();

        void ReorderUnits(Unit* unit, float mouseX);
        void HandleDrop(Unit* unit, float mouseX);

        bool IsMouseOver(Vector2 mousePosition) const;
        bool isPuzzleSolved() const;
    
    private:
        Vector2 m_position;
        Vector2 m_size;

        std::vector<Unit*> m_units;
        float m_unitSpaces = 20.0f;
        float m_minWidth;
        std::vector<UnitType> m_puzzleSolution;
};