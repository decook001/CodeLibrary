/*

"If the OCP states the goal of OO architecture, the DIP states the primary mechanism."
These two principles are indeed related and we have applied this pattern before while 
we were discussing the Open-Closed Principle.

We want our classes to be open to extension, so we have reorganized our dependencies
to depend on interfaces instead of concrete classes. Our PersistenceManager class
depends on InvoicePersistence instead of the classes that implement that interface.


Based on this idea, Robert C. Martin’s definition of the Dependency Inversion Principle consists of two parts:

1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
2. Abstractions should not depend on details. Details should depend on abstractions.

class CustomerBusinessLogic
{
    CustomerBusinessLogic()
    {

    }

    String GetCustomerName(int id)
    {
        DataAccess _dataAccess = DataAccessFactory.GetDataAccessObj();
        return _dataAccess.GetCustomerName(id);
    }
}

public class DataAccessFactory
{
    public static DataAccess GetDataAccessObj() 
    {
        return new DataAccess();
    }
}

public class DataAccess
{
    public DataAccess()
    {

    }

    public string GetCustomerName(int id) 
    {
        return "Dummy Customer Name"; // get it from DB in real app
    }
}



*/


interface ICustomerDataAccess
{
    string GetCustomerName(int id);
}

class CustomerDataAccess implements ICustomerDataAccess
{
    public String GetCustomerName(int id)
    {
        return "Dummy Customer Name";
    }
}

class DealerDataAccess implements ICustomerDataAccess
{
    public String GetCustomerName(int id)
    {
        return "Dummy Dealer Name";
    }
}

class DataAccessFactory
{
    public static ICustomerDataAccess GetCustomerDataAccessObj() 
    {
        return new CustomerDataAccess();
    }
}

public class CustomerBusinessLogic
{
    ICustomerDataAccess _custDataAccess;

    public CustomerBusinessLogic()
    {
        _custDataAccess = DataAccessFactory.GetCustomerDataAccessObj();
    }

    public String GetCustomerName(int id)
    {
        return _custDataAccess.GetCustomerName(id);
    }
}



