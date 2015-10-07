/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package threadtest;

/**
 *
 * @author NRV
 */
public class ThreadTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        for(int i=0;i<50;i++){
            Mythread t=new Mythread(i);
            t.start();
        }
    }
    
    public static void printdata(String x) { 
    synchronized (ThreadTest.class) {
        System.out.println(x);
    }
  }
    
}
