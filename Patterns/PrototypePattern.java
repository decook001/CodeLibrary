package PrototypePattern;

public class Main
{
    public static void main(String[] args) {
	// write your code here
        Application app=new Application();
        Shape[] re=app.copy();
        for(int i=0; i< re.length; i++)
        {
            System.out.println("aha");
        }
    }
}


class Application {
    Shape[] ArrayOShape = new Shape[4] ;
    Application()
    {
        ArrayOShape[0] = new Circle(10);
        ArrayOShape[1] = new Circle(34);
        ArrayOShape[2] = new Rectangle(5, 7);
        ArrayOShape[3] = new Rectangle(4, 8);


    }

    Shape[] copy()
    {
        Shape[] re=new Shape[4];
        for (int i=0;i<4;i++)
        {
            re[i]=ArrayOShape[i].cloneIt();
        }
        return re;
    }

}


class Circle extends Shape {

    double radius;

    Circle(double rad)
    {
        radius=rad;
    }

    Circle(Circle source)
    {
        super(source);
        radius=source.radius;
    }

    @Override
    Shape cloneIt()
    {
        return new Circle(this);
    }
}


class Rectangle extends Shape {
    int height, width;

    Rectangle(int h, int w)
    {
        height=h;
        width=w;
    }

    @Override
    Shape cloneIt() {
        return new Rectangle(this);
    }

    Rectangle(Rectangle source)
    {
        super(source);
        height=source.height;
        width=source.width;
    }


}


abstract class Shape {
    int X,Y;
    String color;

    Shape(){}

    Shape(Shape source)
    {
        X=source.X;
        Y=source.Y;
        color=source.color;
    }

    abstract Shape cloneIt();



}
