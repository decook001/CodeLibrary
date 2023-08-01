/*

https://www.freecodecamp.org/news/solid-principles-explained-in-plain-english/
   
public class InvoicePersistence 
{
    Invoice invoice;

    public InvoicePersistence(Invoice invoice) 
    {
        this.invoice = invoice;
    }

    public void saveToFile(String filename) 
    {
        // Creates a file with given name and writes the invoice
    }
}

------------------------------------------add new feature------------------------
public class InvoicePersistence 
{
    Invoice invoice;

    public InvoicePersistence(Invoice invoice) 
    {
        this.invoice = invoice;
    }

    public void saveToFile(String filename) 
    {
        // Creates a file with given name and writes the invoice
    }

    public void saveToDatabase() 
    {
        // Saves the invoice to database
    }
}

*/

interface InvoicePersistence 
{
    public void save(Invoice invoice);
}

public class DatabasePersistence implements InvoicePersistence 
{

    @Override
    public void save(Invoice invoice) 
    {
        // Save to DB
    }
}

public class FilePersistence implements InvoicePersistence 
{
    @Override
    public void save(Invoice invoice) 
    {
        // Save to file
    }
}


public class PersistenceManager {
    InvoicePersistence invoicePersistence;
    BookPersistence bookPersistence;
    
    public PersistenceManager(InvoicePersistence invoicePersistence,
                              BookPersistence bookPersistence) {
        this.invoicePersistence = invoicePersistence;
        this.bookPersistence = bookPersistence;
    }
}