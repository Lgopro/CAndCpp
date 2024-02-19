typedef struct a
{

}A;


typedef struct Point
{
    int m_x;
    int m_y;
}point_t;


typedef struct b
{
    int x;
    int y;
    point_t p;
}B;

void PointDefaultCtor(point_t *this)
{
    this->m_x = 0;
    this->m_y = 0;
}

void PointNonDefaultCtor(point_t *this, int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

point_t AssignmentOperator(point_t *this)
{
    point_t new_point;
    new_point.m_x = this->m_x;
    new_point.m_y = this->m_y;
    return new_point;;
}

B AssignmentOperatorB(B *this)
{
    B new_point;
    new_point.x = this->x;
    new_point.y = this->y;
    new_point.p = this->p;
    return new_point;;
}

int main()
{
    A a;
    B b;
    PointDefaultCtor(&b.p);
    B b2 = AssignmentOperatorB(&b);
    b2 = b;
    return 0;
    


}


