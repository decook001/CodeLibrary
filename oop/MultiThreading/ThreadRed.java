/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package MultiThreading;

import java.util.logging.Level;
import java.util.logging.Logger;





/**
 *
 * @author shoai
 */

public class ThreadRed extends Thread{
    
    int num;
    public ThreadRed(int num)
    {
        this.num=num;
    }
    
    @Override
    public void run()
    {
        for(int i=0;i<5;i++)
        {
            System.out.println(i+" from thread "+num );
            try 
            {
                Thread.sleep(0);
            } 
            catch (InterruptedException ex) 
            {
                Logger.getLogger(ThreadRed.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}