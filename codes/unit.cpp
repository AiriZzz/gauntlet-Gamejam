#include "unit.hpp"

void Unit::Draw(){
                
    DrawRectangle(
            m_position.x,
            m_position.y,
            m_size.x,
            m_size.y,
            m_color //Using Raylib to draw the unit in rectangle, might need to change into images.
    );
}

bool Unit::IsMouseOver(Vector2 mousePosition)const{

    Rectangle unitRect{
        m_position.x,
        m_position.y,
        m_size.x,
        m_size.y
    }; //create a rectangle at the position

    return CheckCollisionPointRec(mousePosition, unitRect);
}

void Unit::StartDragging(Vector2 mousePosition){

    m_isDragging = true;

    m_dragOffset = {
        mousePosition.x - m_position.x,
        mousePosition.y - m_position.y
    };

}

void Unit::UpdateDragging(Vector2 mousePosition){

    if (!m_isDragging)
    return;

    m_position = {
        mousePosition.x - m_dragOffset.x,
        mousePosition.y - m_dragOffset.y
    };
}

void Unit::StopDragging(){

    m_isDragging = false;
}

Vector2 Unit::GetPosition()const{

    return m_position;
}

Vector2 Unit::GetSize()const{

    return m_size;
}

void Unit::SetPosition(Vector2 position){

    m_position = position;
}