//�ļ�1����Ķ���
class Point{
public:
    Point(int x=0,int y=0):x(x),y(y){count++;}
    Point(const Point&p);
    int getX(){return x;}
    int gety(){return y;}
    static void showCount();    //��̬������Ա
private:
    int x,y;
    static int count;          //��̬���ݳ�Ա
};
