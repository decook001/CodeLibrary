// https://www.tutorialspoint.com/design_pattern/visitor_pattern.html

interface ComputerPart 
{
   public void accept(ComputerPartVisitor computerPartVisitor);
}

class Keyboard implements ComputerPart 
{
   @Override
   public void accept(ComputerPartVisitor computerPartVisitor) 
   {
      computerPartVisitor.visit(this);
   }
}

class Mouse implements ComputerPart 
{

   @Override
   public void accept(ComputerPartVisitor computerPartVisitor) 
   {
      computerPartVisitor.visit(this);
   }
}

interface ComputerPartVisitor 
{

	public void visit(Mouse mouse);
	public void visit(Keyboard keyboard);

}

class ComputerPartDisplayVisitor implements ComputerPartVisitor 
{

   @Override
   public void visit(Mouse mouse) {
      System.out.println("Displaying Mouse.");
   }

   @Override
   public void visit(Keyboard keyboard) {
      System.out.println("Displaying Keyboard.");
   }
    
}

public class VisitorPattern
{
   public static void main(String[] args) 
    {
        ComputerPart cp = new Mouse();
        ComputerPartVisitor dv = new ComputerPartDisplayVisitor();
        cp.accept( dv );

        cp = new Keyboard();
        cp.accept( dv );
   }
}



