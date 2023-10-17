
interface Strategy 
{
   public int doOperation(int num1, int num2);
}

class OperationAdd implements Strategy
{
   @Override
   public int doOperation(int num1, int num2) 
   {
      return num1 + num2;
   }
}

class OperationSubstract implements Strategy
{
   @Override
   public int doOperation(int num1, int num2) 
   {
      return num1 - num2;
   }
}

class OperationMultiply implements Strategy
{
   @Override
   public int doOperation(int num1, int num2) 
   {
      return num1 * num2;
   }
}


class Context 
{
   private Strategy strategy;
   
    Context()
    {
      
    }

    void setStrategy( Strategy stat )
    {
        this.strategy = stat;
    }

   public int executeStrategy(int num1, int num2){
      return strategy.doOperation(num1, num2);
   }
}

public class StrategyPattern {
   public static void main(String[] args) {
      Context context = new Context();		
      context.setStrategy( new OperationAdd() );
      System.out.println("10 + 5 = " + context.executeStrategy(10, 5));

      context.setStrategy( new OperationSubstract()  );
      System.out.println("10 - 5 = " + context.executeStrategy(10, 5));

   }
}
