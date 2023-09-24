import java.util.HashMap;

public class Main 
{
    public static void main(String[] args) 
    {
	      // write your code here   
        Director director=new Director();  

        Car car = director.constructSportsCar();
        
        Car car2 = director.constructSUV();
  
    }
}


class Car {
    String engine;
    Boolean GPS;
    int seat;
    int tyre;
}

class CarBuilder 
{
    
    Car car;
    
    CarBuilder()
    {
      car = new Car();
    }
    
    
    public void setEngine(String engine) 
    {
        car.engine=engine;
    }

    
    public void setTyre(int tyre) {
        car.tyre=tyre;
    }

    
    public void reset() {
        car=new Car();
    }

    
    public void setSeat(int seat) {
        car.seat=seat;
    }

    
    public void setGPS(Boolean yes) {
        car.GPS=yes;
    }

    Car getProduct()
    {
        return car;
    }
}



class Director {


    Car constructSportsCar()
    {
        CarBuilder builder= new CarBuilder();
        builder.reset();
        builder.setEngine("turbo");
        builder.setGPS(true);
        builder.setSeat(6);
        builder.setTyre(4);
        return builder.getProduct();
    }

    Car constructSUV()
    {
        CarBuilder builder= new CarBuilder();
        builder.reset();
        builder.setEngine("diesel");
        builder.setGPS(false);
        builder.setSeat(2);
        builder.setTyre(6);
        return builder.getProduct();
    }
    
    Car constructCustomizedCar( HashMap<String, Integer> features )
    {
      CarBuilder builder= new CarBuilder();
      if( features.containsKey( "Tyre" ) )
      {
        builder.setTyre( features.get("Tyre")  );
      }
      
      return builder.getProduct();
    }
}


