class TwoDShape
{
    private double height;
    private double width;

    TwoDShape()
    {
        width=height=0.0;

    }
    TwoDShape(double w,double h)
    {
        width = w;
        height = h;

    }

    TwoDShape(double x)
    {
        width=height=x;
    }

    double getHeight(){
        return height;
    }
    double getWidth(){
        return width;
    }

    double setWidth(double w){
        width =w;

    }
    double setHeight(double h){
        height = h;
    }

    void showDim()
    {
        system.out.println("Width and height are " + width +" and " + height);
    }
}
class Circle extends TwoDShape
{
    Circle()
    {
        super();
    }
    Circle(double x)
    {
        super(x,)
    }
}