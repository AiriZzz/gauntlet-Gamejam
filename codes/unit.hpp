#pragma once
#include "raylib.h"
#include <string>

//Enum class because its prevents type convertion
enum class UnitType{

    //Unitype only have these types, can add some more if want
    Firefighter,
    Police,
    Soldier,
    Ghost,
    Artist,

};

//Unit are the classes for the unit to drag and drop.
class Unit{
    public:
        Unit(const std::string& name, Color color,const Vector2& position,const Vector2& size, UnitType type , const std::string& texturePath);
        ~Unit();

        void Draw()const;
        bool IsMouseOver(Vector2 mousePosition) const;
        void StartDragging(Vector2 mousePosition);
        void UpdateDragging(Vector2 mousePosition);
        void StopDragging();
        void SetPosition(Vector2 position);
        UnitType GetType()const;
        
        //Returns
        Vector2 GetPosition() const;
        Vector2 GetSize() const;

    private:
        std::string m_unitName;
        Color m_color;
        Vector2 m_position;
        Vector2 m_size;
        Vector2 m_dragOffset;
        bool m_isDragging = false;
        UnitType m_unitType;
        Texture2D m_texture;
};

