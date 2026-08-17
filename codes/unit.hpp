#pragma once
#include "raylib.h"
#include <string>

//Unit are the classes for the unit we want to drag and drop.
class Unit{
    public:
        Unit(const std::string& name, Color color,const Vector2& position,const Vector2& size)
        : m_unitName(name), m_color(color), m_position(position), m_size(size){}

        void Draw();
        bool IsMouseOver(Vector2 mousePosition) const;
        void StartDragging(Vector2 mousePosition);
        void UpdateDragging(Vector2 mousePosition);
        void StopDragging();

    private:
        std::string m_unitName;
        Color m_color;
        Vector2 m_position;
        Vector2 m_size;
        Vector2 m_dragOffset;
        bool m_isDragging = false;

}; 


//UnitZone is the place to put the Units in order.
class UnitZone{
    public:
        UnitZone(const Vector2& position, const Vector2& size) : m_position(position), m_size(size){};

        void Draw();
    
    private:
        Vector2 m_position;
        Vector2 m_size;

};