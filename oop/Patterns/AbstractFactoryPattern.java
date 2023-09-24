

import java.util.Scanner;

public class Main 
{
    public static void main(String[] args)
    {
        AbstractFactory factory;
        
        System.out.println( "hello" );
        
        Scanner input=new Scanner( System.in );
        
        String fact=input.nextLine();
        String frn=input.nextLine();
        
        if( fact.equals("modern") )
        {
            factory=new ModernFactory();
        }
        else
        {
            factory=new VictorianFactory();
        }

        Furniture f1;
        
        if(frn.equals("chair") )
        {
            f1=factory.createChair();
        }
        else
        {
            f1=factory.createSofa();
        }

        f1.buy();


    }
}


abstract class AbstractFactory 
{
    abstract Furniture createChair();
    abstract Furniture createSofa();
}

interface Furniture 
{
    void buy();
}

abstract class Sofa implements Furniture 
{
    @Override
    public abstract void buy();

}

abstract class Chair implements Furniture 
{
    @Override
    public abstract void buy();
}


class ModernFactory extends AbstractFactory {

    @Override
    public Chair createChair() {
        return new ModernChair();
    }

    @Override
    public Sofa createSofa() {
        return new ModernSofa();
    }
}

class ModernSofa extends Sofa
{
    @Override
    public void buy() {
        System.out.println("modern sofa bought.");
    }
}

class ModernChair extends Chair
{
    @Override
    public void buy() {
        System.out.println("modern chair bought");
    }
}





class VictorianFactory extends AbstractFactory {
    @Override
    public Furniture createChair() {
        return new VictorianChair();
    }

    @Override
    public Furniture createSofa() {
        return new VictorianSofa();
    }
}


class VictorianSofa extends Sofa
{
    @Override
    public void buy() {
        System.out.println("Victorian sofa bought");
    }
}

class VictorianChair extends Chair
{

    @Override
    public void buy() {
        System.out.println("victorian chair bought");
    }
}
>>>>>>> 41ebdf2838b7a2cce9ea08a5f5f4e18ebec39a09:project/src/main/java/AbstractFactoryPattern/Main.java
