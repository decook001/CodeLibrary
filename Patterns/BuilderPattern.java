package BuilderPattern;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Director director=new Director();

        CarBuilder builder=new CarBuilder();
        director.setBuilder(builder);

        director.constructSportsCar();
        Car car=builder.getProduct();

        director.constructSUV();
        Car car2=builder.getProduct();

        CarManualBuilder ManualBuilder = new CarManualBuilder();
        director.setBuilder(ManualBuilder);
        director.createManual();
        Manual manual=ManualBuilder.getProduct();
        
    }
}

interface Builder {
    void setEngine(String engine);
    void setTyre(int tyre);
    void reset();
    void setSeat(int seat);
    void setGPS(Boolean yes);
}

class Car {
    String engine;
    Boolean GPS;
    int seat;
    int tyre;
}

class CarBuilder implements Builder {

    Car car;
    @Override
    public void setEngine(String engine) {
        car.engine=engine;
    }

    @Override
    public void setTyre(int tyre) {
        car.tyre=tyre;
    }

    @Override
    public void reset() {
        car=new Car();
    }

    @Override
    public void setSeat(int seat) {
        car.seat=seat;
    }

    @Override
    public void setGPS(Boolean yes) {
        car.GPS=yes;
    }

    Car getProduct()
    {
        return car;
    }
}

class CarManualBuilder implements Builder {
    Manual manual;

    @Override
    public void setEngine(String engine) {
        manual.engine=engine;
    }

    @Override
    public void setTyre(int tyre) {
        manual.tyre=tyre;
    }

    @Override
    public void reset() {
        manual=new Manual();
    }

    @Override
    public void setSeat(int seat) {
        manual.seat=seat;
    }

    @Override
    public void setGPS(Boolean yes) {
        manual.GPS=yes;
    }

    Manual getProduct()
    {
        return manual;
    }
}

class Director {
    Builder builder;

    void setBuilder(Builder b)
    {
        builder=b;
    }

    void constructSportsCar()
    {
        builder.reset();
        builder.setEngine("turbo");
        builder.setGPS(true);
        builder.setSeat(6);
        builder.setTyre(4);

    }

    void constructSUV()
    {
        builder.reset();
        builder.setEngine("diesel");
        builder.setGPS(false);
        builder.setSeat(2);
        builder.setTyre(6);
    }

    void createManual()
    {
        builder.reset();
        builder.setEngine("diesel");
        builder.setGPS(false);
        builder.setSeat(2);
        builder.setTyre(6);

    }
}


class Manual {
    String engine;
    Boolean GPS;
    int seat;
    int tyre;
}


