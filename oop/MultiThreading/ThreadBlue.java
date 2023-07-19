/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package MultiThreading;

public class ThreadBlue implements Runnable{
    
    int num;
    public ThreadBlue(int num)
    { 
        this.num=num;    
    }
    
    @Override
    public void run() 
    {
        for(int i=0;i<5;i++)
        {
            System.out.println(i+" from "+num);
        }
    }
}