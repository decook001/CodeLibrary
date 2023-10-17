

public class FacadePattern
{
   public static void main(String[] args) 
   {
      ShapeDrawer drawer = new ShapeDrawer();
      drawer.drawCircle();
      drawer.drawRectangle();
      drawer.drawSquare();
   }
}


public interface Shape 
{
   void draw();
}

public class Rectangle implements Shape 
{

   @Override
   public void draw() 
   {
      System.out.println("Rectangle::draw()");
   }
}

public class Square implements Shape 
{

   @Override
   public void draw() 
   {
      System.out.println("Square::draw()");
   }
}

public class Circle implements Shape 
{

   @Override
   public void draw() 
   {
      System.out.println("Circle::draw()");
   }
}

public class ShapeDrawer 
{
   private Shape circle;
   private Shape rectangle;
   private Shape square;

   public ShapeDrawer() 
   {
      circle = new Circle();
      rectangle = new Rectangle();
      square = new Square();
   }

   public void drawCircle(){
      circle.draw();
   }
   public void drawRectangle(){
      rectangle.draw();
   }
   public void drawSquare(){
      square.draw();
   }
}

