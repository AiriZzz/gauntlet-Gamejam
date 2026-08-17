#include "unit.hpp"

void Unit::Draw(){
                
    DrawRectangle(
            static_cast<int>(m_position.x),
            static_cast<int>(m_position.y),
            static_cast<int>(m_size.x),
            static_cast<int>(m_size.y),
            m_color //Using Raylib to draw the unit in rectangle, might need to change into images.
        );
}

void Unit::Update(){
                    
    Vector2 mousePosition = GetMousePosition(); //get the position of the mouse

    Rectangle unitRect{
            m_position.x,
            m_position.y,
            m_size.x,
            m_size.y
    };

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) //IF mouse left is pressed, dragging is true, enable dragging
        {
            if (CheckCollisionPointRec(mousePosition, unitRect)) //check the mouse is on top of the Unit
            {
                m_isDragging = true;
                m_dragOffset = {mousePosition.x - m_position.x,mousePosition.y - m_position.y}; //calculate the drag offset
            }
        }

        if (m_isDragging)
        {
            //the position of the Unit rectangle is the mouse and dragon offset
            m_position = {mousePosition.x - m_dragOffset.x,mousePosition.y - m_dragOffset.y};
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) //when left mouse release, dragging is false, no longer drags
        {
            m_isDragging = false;

        } 
}