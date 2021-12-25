

#include <iostream>

using namespace std;

template <typename T,typename V>
class Pair{
    T x;
    V y;
    
    public:
    void setX(T x)
    {
        this->x = x;
    }
    
    T getX()
    {
        return x;
    }
    
    void setY(V y)
    {
        this->y = y;
    }
    
    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<Pair<int,int>,int> p1;
    Pair<int,int> p2;
    //creating a pair
    p2.setX(10);
    p2.setY(20);
    
    
    p1.setX(p2);
    p1.setY(25);
    
    cout<<p1.getX().getX()<<endl;
    cout<<p1.getX().getY()<<endl;
    cout<<p1.getY()<<endl;
    
    
    /*cout<<p1.getX()<<" "<<p1.getY()<<endl;
    
    Pair<int,double> p2;
    
    p2.setX(100.34);
    p2.setY(34.21);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;*/
    

    return 0;
}
